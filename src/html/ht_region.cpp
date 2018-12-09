#include "ht_region.h"

namespace newtoo
{
	void
	ht_only_text_close_tag_index::index(std::string& reference, size_t start)
	{
		pos = reference.find(tag_id == 0 ? "</script>" : "</style>", start);
	}

	ht_only_text_close_tag_index::ht_only_text_close_tag_index() :pos(std::string::npos)
	{
	}

	ht_region::ht_region() : pattern(ht_pattern_text), quotes(0)
	{
	}
}
