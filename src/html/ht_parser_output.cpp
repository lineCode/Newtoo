#include "ht_parser_output.h"
#include "ht_identifer.h"

namespace newtoo
{
	size_t ht_parser_output::size() {
		return tokens.size();
	}

	ht_token* ht_parser_output::operator [] (size_t index) {
		return &tokens[index];
	}

	ht_token* ht_parser_output::currentToken() {
		return &tokens.[index];
	}

	bool ht_parser_output::nextToken() {
		index++;
		return index != tokens.size();
	}

	void
	ht_parser_output::append(ht_token token_instance)
	{
		if (token_instance.id != ht_text and !token_instance.is_inline() and last_open_tag_token != 0)
		{
			if(last_open_tag_token->flag == ht_flag_close_self_auto)
				tokens.push_back
		}
		tokens.push_back(token_instance);

		if (token_instance.is_open())
		{
			if (!token_instance.is_inline())
				last_open_tag_token = tokens[size() - 1];
		} else
		{
			last_open_tag_token = 0;
		}
	}

	ht_parser_output::ht_parser_output() : index(0), last_open_tag_token(0)
	{
	}
}
