#include "ht_parser.h"

namespace newtoo
{
	ht_token& ht_parser::token() {
		return *token_ptr;
	}

	void ht_parser::submit_token() {
		output.append(token());
		delete token_ptr;
		token_ptr = new ht_token(&reference[pos + 1], &globalnames);
	}

	ht_parser::ht_parser(ht_parser_output& output_)
		: m_state(ht_parser_working), pos(0), region(),
		token_ptr(new ht_token(&reference[0], &globalnames)), output(output_)
	{
	}

	ht_parser::~ht_parser()
	{
		delete token_ptr;
	}

	void ht_parser::pushChunk(std::string chunk) {
		reference += chunk;
	}

	bool ht_parser::proceed()
	{
		if (pos == reference.size())
			return m_state != ht_parser_working;

		char sign = reference[pos];

		switch (region.pallete)
		{
			case ht_pallete_text:
			{

				break;
			}
			case ht_pallete_only_text:
			{
				
				break;
			}
			case ht_pallete_id_or_prefix:
			{

				break;
			}
			case ht_pallete_id:
			{

				break;
			}
			case ht_pallete_after:
			{

				break;
			}
			case ht_pallete_after_in_quotes:
			{

				break;
			}
		}

		pos++;
		token().end++;
		return true;
	}

	ht_parser_state ht_parser::state() {
		return m_state;
	}

	void ht_parser::finish() {
		if(m_state == ht_parser_working)
			m_state = ht_parser_finished;
	}
	void ht_parser::abort() {
		if (m_state == ht_parser_working)
			m_state = ht_parser_aborted;
	}
}
