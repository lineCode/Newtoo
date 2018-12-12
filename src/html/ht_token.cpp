#include "ht_token.h"

namespace newtoo
{
	boundary::boundary() : begin(ht_unset_pos), end(ht_unset_pos)
	{
	}

	ht_token::ht_token() : begin(ht_unset_pos), end(ht_unset_pos), prefix(ht_global_prefix), id((ht_identifier)0),
		flag(ht_flag_not_a_tag), flag_taken_by_user(false), attributes(), globalnames(0), is_inline(false)
	{
	}

	ht_token::ht_token(ht_pos begin_, ht_active_id_table* globalnames_)
		:begin(begin_), end(begin_), prefix(ht_global_prefix), id((ht_identifier)0), flag(ht_flag_not_a_tag),
		flag_taken_by_user(false), attributes(), globalnames(globalnames_), is_inline(false)
	{
	}

	bool ht_token::has_attributes()
	{
		return attributes.begin != 0 && attributes.end != 0;
	}

	bool ht_token::is_open()
	{
		return flag > 0 && flag < 4;
	}
}
