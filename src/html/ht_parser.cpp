#include "ht_parser.h"
#include <iostream>

namespace newtoo
{
	ht_token& ht_parser::token() {
		return *token_ptr;
	}

	void ht_parser::complete_tag_token() {
		token().attributes.begin = pos;
		token().attributes.end = pos;
		token().id = identify(region.text, token().is_inline, token().flag);
		region.text.clear();
	}

	void ht_parser::submit_token() {
		if(token().end != 0)
			token().end -= 1;
		output.append(token());
		delete token_ptr;
		token_ptr = new ht_token(pos + 1);
	}

	void ht_parser::submit_tag_token()
	{
		if (token().id == ht_id_tag_script && token().is_open()
	     || token().id == ht_id_tag_style && token().is_open()) {
			region.pattern = ht_pattern_only_text;
			only_text_close_tag_index.tag_id = token().id;
			only_text_close_tag_index.index(reference, pos);
		}
		else {
			region.pattern = ht_pattern_text;
		}
		token().attributes.end = token().flag != ht_flag_close_self ? pos - 1 : pos - 2;
		submit_token();
	}

	void ht_parser::set_pattern_after()
	{
		region.pattern = ht_pattern_after;
		complete_tag_token();
	}

	ht_parser::ht_parser(ht_parser_output& output_)
		: m_state(ht_parser_working), pos(0), region(),
		token_ptr(new ht_token(0)), output(output_)
	{
	}

	ht_parser::~ht_parser()
	{
		delete token_ptr;
	}

	std::string& ht_parser::text() {
		return reference;
	}

	void ht_parser::pushChunk(std::string chunk) {
		seen_last_augments = false;
		reference += chunk;
	}

	bool ht_parser::proceed()
	{
		if (pos == reference.size())
			return m_state == ht_parser_working;

		bool seen_last_augments_c = seen_last_augments;

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
				if (!seen_last_augments_c && pos == std::string::npos)
					only_text_close_tag_index.index(reference, pos);

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
				else if (sign == '/') {
					if (region.text.empty()) {
						token().flag_taken_by_user = true;
						token().flag = ht_flag_close;
					} else {
						token().flag_taken_by_user = true;
						token().flag = ht_flag_close_self;
					}
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
				else if (sign == '/') {
					if (region.text.empty()) {
						token().flag_taken_by_user = true;
						token().flag = ht_flag_close;
					} else {
						token().flag_taken_by_user = true;
						token().flag = ht_flag_close_self;
					}
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
					token().flag_taken_by_user = true;
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
		if (seen_last_augments_c == false) {
			seen_last_augments = true;
		}
		pos++;
		token().end++;
		return true;
	}

	ht_parser_state ht_parser::state() const {
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
