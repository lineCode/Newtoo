#prama once

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
		ht_token* last_open_tag_token;
	};
}
