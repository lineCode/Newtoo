#pragma once

#include "ht_active_id_table.h"
#include "ht_identifier.h"

namespace newtoo
{
	typedef unsigned long ht_pos;
	const ht_pos ht_unset_pos = 2147483647;
	
	enum ht_flag {
		ht_flag_not_a_tag,
		ht_flag_open,
		ht_flag_close_self,
		ht_flag_close_self_auto,
		ht_flag_close
	};

	const int ht_global_prefix = -1;

	struct boundary {
		ht_pos begin;
		ht_pos end;
		boundary();
	};

	struct ht_token
	{
		ht_token();
		ht_token(ht_pos begin_);

		ht_pos begin;
		ht_pos end;
		long prefix;
		ht_identifier id;
		short flag;
		bool flag_taken_by_user;
		boundary attributes;
		bool is_inline;

		bool has_attributes();
		bool is_open();
	};
}
