#pragma once

#include <string>

namespace newtoo
{
	enum ht_pallete {
		ht_pallete_text,
		ht_pallete_only_text,
		ht_pallete_id_or_prefix,
		ht_pallete_prefix,
		ht_pallete_after,
		ht_pallete_after_in_quotes
	};

	struct ht_region {
		ht_pallete pallete;
		std::string text;
		char quotes;
		ht_region();
	};
}
