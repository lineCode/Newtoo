#include "ht_parser_output.h"
#include "ht_identifier.h"
#include <iostream>

namespace newtoo
{
	size_t ht_parser_output::size() {
		return tokens.size();
	}

	ht_token* ht_parser_output::operator [] (size_t index){
		return &tokens[index];
	}

	ht_token* ht_parser_output::currentToken() {
		return &tokens[index];
	}

	bool ht_parser_output::nextToken() {
		index++;
		return index != tokens.size();
	}

	bool add_close_token(ht_token* instance, ht_token* last_open_tag_token, bool is_open)
	{
		if (instance->id != last_open_tag_token->id)
			return true;
		else return is_open;
	}

	void
	ht_parser_output::append(ht_token token_instance)
	{
		bool is_inline = token_instance.is_inline;
		bool is_open = token_instance.is_open();

		/* ѕустой текст не принимаетс€
		*/
		if (token_instance.id == ht_id_text && token_instance.begin == token_instance.end)
			return;

		/*   тегу, который сам закрываетс€ по-умолчанию, нельз€ добавить закрывающийс€ тег, 
		*/
		if (!is_open && tokens.size() > 1 && token_instance.id == tokens[tokens.size() - 2].id
			&& tokens[tokens.size() - 2].flag == ht_flag_close_self
			&& tokens[tokens.size() - 2].flag_taken_by_user == false) {
				return;
		}

		/* “еги в карантине добавл€ютс€ после строчных тегов
		*/
		if (quarantine) {
			add_after_inline_scope.push_back(token_instance);
			if (!is_open && quarantine_end_token_instance.id == token_instance.id)
				quarantine = false;
			return;
		}

		if (!is_inline && token_instance.id != ht_id_text)
		{
			if (last_open_tag_index == -1 || last_open_tag_token()->flag != ht_flag_close_self_auto)
				goto after_pre_check;

			if (inline_tag_level == 0) {
				if (add_close_token(&token_instance, last_open_tag_token(), is_open)) {
					close_tag(last_open_tag_token());
					last_open_tag_index = -1;
					for (size_t i = 0; i < add_after_inline_scope.size(); i++)
						append(add_after_inline_scope[i]);
				} else {
					last_open_tag_index = -1;
				}
			} else {
				add_after_inline_scope.push_back(token_instance);
				quarantine_end_token_instance = token_instance;
				quarantine = true;
				return;
			}
		}

	after_pre_check:

		tokens.push_back(token_instance);

		if (token_instance.flag == ht_flag_close_self) {
			close_tag(&token_instance);
		}

		if (!is_inline && token_instance.id != ht_id_text && inline_tag_level == 0)
		{
			if (is_open)
			{
				last_open_tag_index = size() - 1;
			} else
			{
				last_open_tag_index = -1;
			}
		} else if (last_open_tag_index != -1 && last_open_tag_token()->flag ==
			ht_flag_close_self_auto && token_instance.id != ht_id_text)
		{
			if (is_open)
				inline_tag_level++;
			else
				inline_tag_level--;
		}
	}

	ht_parser_output::ht_parser_output() : index(0), quarantine(false),
		inline_tag_level(0), last_open_tag_index(-1)
	{
	}

	ht_token* ht_parser_output::last_open_tag_token() {
		return last_open_tag_index == -1 ? 0 : &tokens[last_open_tag_index];
	}

	void
	ht_parser_output::close_tag(ht_token* token) {
		ht_token close_token;
		close_token.flag = ht_flag_close;
		close_token.id = token->id;
		close_token.prefix = token->prefix;
		close_token.globalnames = token->globalnames;
		tokens.push_back(close_token);
	}
}
