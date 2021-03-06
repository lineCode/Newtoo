#include "ht_active_id_table.h"
#include "ht_token.h"

namespace newtoo
{
	long ht_active_id_table::nameIdentifer(std::string name) {
		if (recently_name == name)
			return recently_id;

		for (size_t i = 0; i < list.size(); i++)
			if (list[i] == name)
				return i;

		list.push_back(name);
		return list.size() - 1;
	}

	std::string ht_active_id_table::toString(long id) {
		if (id > list.size() - 1 || id < 0) {
			return "";
		}
		return list[id];
	}
}
