#pragma once

#include <string>

namespace newtoo
{
	enum ht_pattern {
		ht_pattern_text,
		ht_pattern_only_text,
		ht_pattern_id_or_prefix,
		ht_pattern_id,
		ht_pattern_after,
		ht_pattern_after_in_quotes
	};

	struct ht_only_text_close_tag_index {
		short tag_id; // 0 = script, 1 = style
		size_t pos;

		void index(std::string& reference, size_t start);
		ht_only_text_close_tag_index();
	};

	struct ht_region {
		ht_pattern pattern;
		std::string text;
		char quotes;
		ht_region();
	};
}
