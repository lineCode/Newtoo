#include "ht_parser.h"

namespace newtoo
{
	ht_token& ht_parser::token() {
		return *token_ptr;
	}

	void ht_parser::complete_tag_token() {
		token().attributes.begin = &reference[pos];
		token().attributes.end = &reference[pos];
		token().id = identify(region.text, token().is_inline, token().flag);
		region.text.clear();
	}

	void ht_parser::submit_token() {
		token().end -= 1;
		output.append(token());
		delete token_ptr;
		token_ptr = new ht_token(&reference[pos + 1], &globalnames);
	}

	void ht_parser::submit_tag_token()
	{
		//TODO: script id instead of 0 and style id instead of 1
		if (token().id == 0 || token().id == 1) {
			region.pattern = ht_pattern_only_text;
			only_text_close_tag_index.tag_id = token().id;
			only_text_close_tag_index.index(reference, pos);
		}
		else {
			region.pattern = ht_pattern_text;
		}
		token().attributes.end = token().flag != ht_flag_close_self ? &reference[pos - 1] : &reference[pos - 2];
		submit_token();
	}

	void ht_parser::set_pattern_after()
	{
		region.pattern = ht_pattern_after;
		complete_tag_token();
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

		switch (region.pattern)
		{
			case ht_pattern_text:
			{
				if (sign == '<') {
					submit_token();
					token().flag = ht_flag_open;
					region.pattern = ht_pattern_id_or_prefix;
				}
				break;
			}
			case ht_pattern_only_text:
			{
				if (pos == only_text_close_tag_index.pos) {
					submit_token();
					token().flag = ht_flag_open;
					region.pattern = ht_pattern_id_or_prefix;
				}
				break;
			}
			case ht_pattern_id_or_prefix:
			{
				if (sign == ':') {
					token().prefix = globalnames.nameIdentifer(region.text);
					region.pattern = ht_pattern_id;
					region.text.clear();
				} else if (sign == ' ')
				{
					set_pattern_after();
				}
				else if (sign == '/' && region.text.empty()) {
					token().flag = ht_flag_close;
				}
				else if (sign == '>') {
					complete_tag_token();
					submit_tag_token();
				}
				else
				{
					region.text += sign;
				}
				break;
			}
			case ht_pattern_id:
			{
				if (sign == ' ')
				{
					set_pattern_after();
				}
				else if (sign == '>') {
					complete_tag_token();
					submit_tag_token();
				}
				else
					region.text += sign;
				break;
			}
			case ht_pattern_after:
			{
				if (sign == '\"' || sign == '\'')
				{
					region.pattern = ht_pattern_after_in_quotes;
					region.quotes = sign;
				}
				else if (sign == '/')
				{
					token().flag = ht_flag_close_self;
				}
				else if (sign == '>') {
					submit_tag_token();
				}
				break;
			}
			case ht_pattern_after_in_quotes:
			{
				if (sign == region.quotes)
					region.pattern = ht_pattern_after;
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
