#include "ht_token.h"

newtoo::ht_token::ht_token(char * begin_, ht_active_id_table & globalnames_)
	:begin(begin_), end(0), prefix(ht_global_prefix), id(0), flag(ht_flag_not_a_tag), globalnames(globalnames_)
{
}
