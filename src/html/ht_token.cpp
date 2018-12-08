#include "ht_token.h"

namespace newtoo
{
	ht_token::ht_token(char * begin_, ht_active_id_table & globalnames_)
		:begin(begin_), end(0), prefix(ht_global_prefix), id(0), flag(ht_flag_not_a_tag), globalnames(globalnames_)
	{
	}

	bool ht_token::is_inline()
	{
		return flag == ht_flag_close_inline or flag == ht_flag_close_self_inline or flag == ht_flag_open_inline;
	}
	bool ht_token::is_open()
	{
		return flag > 0 and flag < 6;
	}
}