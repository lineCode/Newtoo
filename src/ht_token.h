#pragma once

#include "ht_active_id_table.h"

namespace newtoo
{
	struct ht_active_id_table;

	enum ht_flag {
		ht_flag_not_a_tag,
		ht_flag_open,
		ht_flag_close_self,
		ht_flag_close
	};

	const int ht_global_prefix = -1;

	struct boundary
	{
		char* begin;
		char* end;
	};

	struct ht_token
	{
		ht_token(char* begin_, ht_active_id_table& globalnames_);

		char* begin;
		char* end;
		long prefix;
		unsigned int id;
		short flag;
		char* attr_begin;
		char* attr_end;
		ht_active_id_table& globalnames;
	};
}