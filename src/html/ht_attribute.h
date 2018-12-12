#pragma once

#include "ht_token.h"

namespace newtoo
{
	struct ht_attribute {
		std::string prefix, name, value;
	};

	typedef std::vector <ht_attribute> ht_attribute_list;

	ht_attribute_list parse_attributes_scope(boundary scope, std::string& reference);
}
