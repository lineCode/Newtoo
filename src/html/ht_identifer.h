#pragma once

#include <string>

namespace newtoo
{
	enum ht_identifer {
		ht_text,
		ht_comment,
		ht_document_type
	};

	ht_identifer identify(std::string namestr);
}
