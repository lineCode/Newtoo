#pragma once

#include <string>
#include <vector>

namespace newtoo
{
	typedef std::vector <std::string> ht_keyword_list;

	/* Таблица числовых идентификаторов к названиям
	*/

	struct ht_active_id_table {
		ht_keyword_list list;

		long nameIdentifer(std::string name);
		std::string toString(long id);

	private:
		std::string recently_name;
		long recently_id;
	};
}
