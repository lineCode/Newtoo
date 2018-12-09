#include <string>

#define string_switch(str)  switch(str_sw::str_hash_for_switch(str))
#define string_case(str)    static_assert(str_sw::str_is_correct(str) && (str_sw::str_len(str) <= str_sw::max_len),\
"string_case contains wrong characters, or its length is greater than 9");\
case str_sw::str_hash(str, str_sw::str_len(str))
#define string_default  default

namespace str_sw
{
	const unsigned char max_len = 9;
	const unsigned long long n_hash = static_cast<unsigned long long>(-1); // аналогично с std::string::npos

	constexpr unsigned long long raise_128_to(const unsigned char power) {
		return 1ULL << 7 * power;
	}

	constexpr bool str_is_correct(const char* const str)
	{
		return (static_cast<signed char>(*str) > 0) ? str_is_correct(str + 1) : (*str ? false : true);
	}

	constexpr unsigned char str_len(const char* const str) {
		return *str ? (1 + str_len(str + 1)) : 0;
	}

	constexpr unsigned long long str_hash(const char* const str, const unsigned char current_len)
	{
		return *str ? (raise_128_to(current_len - 1) * static_cast<unsigned char>(*str) + str_hash(str + 1, current_len - 1)) : 0;
	}

	inline unsigned long long str_hash_for_switch(const char* const str)
	{
		return (str_is_correct(str) && (str_len(str) <= max_len)) ? str_hash(str, str_len(str)) : n_hash;
	}

	inline unsigned long long str_hash_for_switch(const std::string& str)
	{
		return (str_is_correct(str.c_str()) && (str.length() <= max_len)) ? str_hash(str.c_str(), str.length()) : n_hash;
	}
}