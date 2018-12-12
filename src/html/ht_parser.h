#pragma once

#include "ht_parser_output.h"
#include "ht_region.h"

namespace newtoo
{
	enum ht_parser_state {
		ht_parser_working,
		ht_parser_finished,
		ht_parser_aborted
	};

	class ht_parser
	{
		std::string reference;
		ht_parser_state m_state;
		size_t pos;
		ht_region region;
		ht_token* token_ptr;
		ht_parser_output& output;
		ht_active_id_table globalnames;
		ht_only_text_close_tag_index only_text_close_tag_index;
		bool seen_last_augments;

		ht_token& token();

		void complete_tag_token();
		void submit_tag_token();
		void submit_token();

		void set_pattern_after();

	public:
		ht_parser(ht_parser_output& output_);
		~ht_parser();

		std::string& text();

		void pushChunk(std::string chunk);
		bool proceed();

		ht_parser_state state() const;
		void finish();
		void abort();
	};
}
