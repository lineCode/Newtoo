#include <iostream>

#include "html/ht_parser.h"

namespace newtoo
{
}

int main()
{
	newtoo::ht_parser_output output;
	newtoo::ht_parser parser(output);
	parser.pushChunk("<html><head><title>asdasd</title></head><body>Hello world!</body></html>");
	parser.finish();
	while (parser.proceed())
	{}

	for (size_t i = 0; i < output.size(); i++)
	{
		std::cout << std::to_string(output[i]->flag) + "; ";
	}

	std::cout << "\n\nHappy new year!\n";
	while (true) // pause
	{}
    return 0;
}
