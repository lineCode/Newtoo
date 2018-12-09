#pragma once

#include <string>

namespace newtoo
{
	enum ht_pallete {
		ht_pallete_text,
		ht_pallete_only_text,
		ht_pallete_id_or_prefix,
		ht_pallete_id,
		ht_pallete_after,
		ht_pallete_after_in_quotes
	};

	struct ht_only_text_close_tag_index {
		short tag_id; // 0 = script, 1 = style
		size_t pos;

		void index(std::string& reference, size_t start);
		ht_only_text_close_tag_index();
	};

	struct ht_region {
		ht_pallete pallete;
		std::string text;
		char quotes;
		ht_region();
	};
}
