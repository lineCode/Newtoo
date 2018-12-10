#include <iostream>

#include "html/ht_parser.h"

namespace newtoo
{
}

int main()
{
	newtoo::ht_parser_output output;
	newtoo::ht_parser parser(output);
	parser.pushChunk("<html><p>Hello!</html>");
	parser.finish();
	while (parser.proceed())
	{}

	for (size_t i = 0; i < output.size(); i++)
	{
		if (output[i]->flag == newtoo::ht_flag_close)
			std::cout << "/";
		std::cout << newtoo::ht_identifier_to_string(output[i]->id);
		if (output[i]->flag == newtoo::ht_flag_close_self && output[i]->flag_taken_by_user) {
			std::cout << "/";
		}
		std::cout << "; ";
	}

	std::cout << "\n\nHappy new year!\n";
	while (true) // pause
	{}
    return 0;
}
