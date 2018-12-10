#pragma once

#include "ht_active_id_table.h"
#include "ht_identifier.h"

namespace newtoo
{
	enum ht_flag {
		ht_flag_not_a_tag,
		ht_flag_open,
		ht_flag_close_self,
		ht_flag_close_self_auto,
		ht_flag_close
	};

	const int ht_global_prefix = -1;

	struct boundary {
		char* begin;
		char* end;
	};

	struct ht_token
	{
		ht_token();
		ht_token(char* begin_, ht_active_id_table* globalnames_);

		char* begin;
		char* end;
		long prefix;
		ht_identifier id;
		short flag;
		bool flag_taken_by_user;
		boundary attributes;
		ht_active_id_table* globalnames;
		bool is_inline;

		bool has_attributes();
		bool is_open();
	};
}
