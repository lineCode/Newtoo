#include "ht_identifier.h"
#include "ht_token.h"

namespace newtoo
{
	ht_identifier identify(std::string namestr, bool& is_inline_field, short& flag_field)
	{
		if ((ht_flag)flag_field == ht_flag_not_a_tag)
			return ht_id_text;

		return (ht_identifier)10; // TODO
	}
}
