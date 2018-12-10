#include "ht_parser_output.h"
#include "ht_identifier.h"

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

		if (token_instance.id == ht_id_text && token_instance.begin == token_instance.end)
			return;

		/* К тегу, который сам закрывается по-умолчанию, нельзя добавить закрывающийся тег, 
		*/
		if (tokens.size() > 1 && token_instance.id == tokens[tokens.size() - 2].id
			&& tokens[tokens.size() - 2].flag == ht_flag_close_self
			&& tokens[tokens.size() - 2].flag_taken_by_user == false) {
				return;
		}

		if (!is_inline)
		{
			if (is_open)
				close_all_inline_tags();

			if (last_open_tag_token != 0 && token_instance.id != ht_id_text
				&& last_open_tag_token->flag == ht_flag_close_self_auto)
			{
				if (add_close_token(&token_instance, last_open_tag_token, is_open))
				{
					ht_token close_token;
					close_token.is_inline = false;
					close_token.flag = ht_flag_close;
					close_token.id = last_open_tag_token->id;
					close_token.prefix = last_open_tag_token->prefix;
					close_token.globalnames = last_open_tag_token->globalnames;
					tokens.push_back(close_token);
				}
				last_open_tag_token = 0;
				inline_token_buff.clear();
			}

		} // end !is_inline

		tokens.push_back(token_instance);

		if (!is_inline)
		{
			if (is_open)
			{
				last_open_tag_token = &tokens[size() - 1];
				inline_token_buff.clear();
			} else
			{
				last_open_tag_token = 0;
				inline_token_buff.clear();
			}
		} else if (last_open_tag_token != 0 && last_open_tag_token->flag ==
			ht_flag_close_self_auto)
		{
			if (is_open)
				inline_token_buff.push_back(&tokens[size() - 1]);
			else
				inline_token_buff.pop_back();
		}
	}

	ht_parser_output::ht_parser_output() : index(0), last_open_tag_token(0)
	{
	}

	void
	ht_parser_output::close_all_inline_tags()
	{
		for (size_t i = 0; i < inline_token_buff.size(); i++) {
			ht_token& inline_token = *inline_token_buff[i];
			ht_token close_token;
			close_token.is_inline = true;
			close_token.id = inline_token.id;
			close_token.prefix = inline_token.prefix;
			close_token.globalnames = inline_token.globalnames;
			tokens.push_back(close_token);
		}
		inline_token_buff.clear();
	}
}
