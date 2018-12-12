#include "ht_attribute.h"
#include <iostream>

#define add_to_list add_to_list_m(list, *attr); delete attr; attr = new ht_attribute

namespace newtoo
{
	void add_to_list_m(ht_attribute_list& list, ht_attribute item) {
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i].name == item.name)
				return;
		}
		list.push_back(item);
	}

	enum ht_attribute_pattern {
		name_or_prefix,
		name,
		pending_for_an_equals_sign,
		value,
		value_in_quotes
	};

	ht_attribute_list parse_attributes_scope(boundary scope, std::string& reference) {
		ht_attribute_list list;
		ht_attribute_pattern pattern = name_or_prefix;
		ht_attribute* attr = new ht_attribute;
		std::string text;
		char quotes = 0;

		for (size_t i = scope.begin; i <= scope.end; i++)
		{
			char sign = reference[i];
			switch (pattern)
			{
				case name_or_prefix:
				{
					if (sign == ' ') {
						if (!text.empty()) {
							pattern = pending_for_an_equals_sign;
							attr->name = text;
							text.clear();
						}
					}
					else if (sign == '=') {
						pattern = value;
						attr->name = text;
						text.clear();
					}
					else if (sign == ':') {
						pattern = name;
						attr->prefix = text;
						text.clear();
					}
					else {
						text += sign;
						if (i == scope.end) {
							attr->name = text;
							attr->value = "true";
							add_to_list();
						}
					}
					break;
				}
				case pending_for_an_equals_sign:
				{
					if (sign == '=')
						pattern = value;
					else if (sign != ' ') {
						pattern = name_or_prefix;
						attr->value = "true";
						text += sign;
						add_to_list();
					}
					break;
				}
				case name:
				{
					if (sign == ' ') {
						pattern = pending_for_an_equals_sign;
					}
					else if (sign == '=') {
						pattern = value;
					} else {
						attr->name += sign;
						if (i == scope.end) {
							attr->value = "true";
							add_to_list();
						}
					}
					break;
				}
				case value:
				{
					if (sign == ' ')
					{
						if (!attr->value.empty()) {
							pattern = name_or_prefix;
							add_to_list();
						}
					} else if (sign == '\"' || sign == '\'') {
						pattern = value_in_quotes;
						quotes = sign;
					} else {
						attr->value += sign;
						if (i == scope.end) {
							add_to_list();
						}
					}
					break;
				}
				case value_in_quotes:
				{
					if (sign == quotes)
					{
						pattern = value;
						if (i == scope.end) {
							add_to_list();
						}
					} else {
						attr->value += sign;
					}
					break;
				}
			} // end switch
		}
		return list;
	}
}
