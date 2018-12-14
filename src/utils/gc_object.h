#pragma once

#include <vector>

#define GarbageCollected gc_object
#define gc_super_class_init gc_object(shared_gc)
#define requires_gc newtoo::garbage_collector* GC
#define shared_gc GC
#define using_gc GC

namespace newtoo
{
	class garbage_collector;

	struct reference_list {
		std::vector<void**> list;
		garbage_collector* __gc;
		void** operator[](size_t index);
		size_t size();

		void Unregister(size_t index);
		void Register(void** ref);

		reference_list();
		~reference_list();
	};

	struct gc_object {
		reference_list __own_references;
		garbage_collector* __gc;
		short __marked : 1;

		gc_object(requires_gc);
		~gc_object();
	};
}
