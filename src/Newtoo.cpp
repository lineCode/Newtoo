#include <iostream>

#include "html/ht_attribute.h"
#include "html/ht_parser.h"
#include "utils/garbage_collector.h"
#include "utils/gc_ptr.h"

namespace newtoo
{
}

int main()
{
	newtoo::ht_parser_output output;
	newtoo::ht_parser parser(output);
	parser.pushChunk("<!doctype html><html as:ndd = 'asd' required ar=11>Hello!</html>");
	parser.finish();
	while (parser.proceed())
	{}

	for (size_t i = 0; i < output.size(); i++)
	{
		if (output[i]->flag == newtoo::ht_flag_close)
			std::cout << "/";
		if(output[i]->id != newtoo::ht_id_text)
			std::cout << newtoo::ht_identifier_to_string(output[i]->id);
		else {
			for (size_t c = output[i]->begin; c < output[i]->end; c++)
				std::cout << parser.text()[c];
		}
		if (output[i]->flag == newtoo::ht_flag_close_self && output[i]->flag_taken_by_user) {
			std::cout << "/";
		}
		std::cout << "; ";
	}

	std::cout << "\n\n";
	newtoo::ht_attribute_list attr_list = newtoo::parse_attributes_scope(output[1]->attributes, parser.text());
	for (size_t i = 0; i < attr_list.size(); i++) {
		std::cout << attr_list[i].prefix << ":" << attr_list[i].name << "=" << attr_list[i].value << " ";
	}

	std::cout << "\n\nHappy new year!\n";
	
	$_GC_init;

	struct Object : newtoo::GarbageCollected
	{
		int a;

		Object
		
		(requires_gc):gc_super_class_init,

		a(7)
		{

		}
	};

	struct ObjectHndl : newtoo::GarbageCollected
	{
		Object* obj;

		ObjectHndl

		(requires_gc):gc_super_class_init,

		obj(new Object(shared_gc))
		{
			__own_references.Register((void**)&obj);
		}
	};

	ObjectHndl* hndl = new ObjectHndl(using_gc);

	auto object = newtoo::ptr <Object>( new Object(using_gc) );

	$_GC_collect;

	while (true) // pause
	{}
    return 0;
}
