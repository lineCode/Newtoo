#pragma once

namespace Newtoo
{

    namespace SelectorSyntax
    {
        const char whitespace = ' ';
        const char split_list = ',';
        const char id = '#';
        const char class_char = '.';
        const char pseudo_class = ':';
        const char compare_open = '[';
        const char compare_close = ']';
        const char compare_equals = '=';
        const char compare_ends_with = '$';
        const char compare_starts_with = '^';
        const char compare_starts_with_prefix = '|';
        const char compare_contains = '*';
        const char compare_contains_item = '~';
        const char universal = '*';
        const char quote = '\"';
        const char quote_alternative = '\'';
        const char child_combinator = '>';
        const char next_sibling_combinator = '+';
        const char subsequent_sibling_combinator = '~';
        const char function_arg_begin = '(';
        const char function_arg_end = ')';
        const char prefix_end = '-';

        const char pseudo_element_prefix[2] = { ':' , ':' };
    }

}
