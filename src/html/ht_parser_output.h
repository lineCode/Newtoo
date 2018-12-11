#pragma once

#include "ht_token.h"

namespace newtoo
{
	struct ht_parser_output
	{
		size_t size();
		ht_token* operator [] (size_t index);
		ht_token* currentToken();
		bool nextToken();
		unsigned long index;

		void append(ht_token token_instance);

		ht_parser_output();
	private:
		std::vector<ht_token> tokens;
		std::vector<ht_token> add_after_inline_scope;
		ht_token quarantine_end_token_instance;
		bool quarantine;

		unsigned long inline_tag_level;
		long last_open_tag_index;
		ht_token* last_open_tag_token();

		void close_tag(ht_token* token);
	};
}
