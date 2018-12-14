#include "gc_object.h"
#include "garbage_collector.h"
#include <iostream>

namespace newtoo
{
	void** reference_list::operator[](size_t index) {
		return list[index];
	}

	size_t reference_list::size() {
		return list.size();
	}

	void reference_list::Unregister(size_t index) {
		list.erase(list.begin() + index);
	}

	void reference_list::Register(void** ref) {
		list.push_back(ref);
	}

	reference_list::reference_list() : __gc(0)
	{
	}

	reference_list::~reference_list()
	{
		if (__gc == 0)
			return;

		for (size_t i = 0; i < __gc->reflists.size(); i++) {
			if (__gc->reflists[i] == this) {
				__gc->reflists.erase(__gc->reflists.begin() + i);
				break;
			}
		}
	}

	gc_object::gc_object(requires_gc) : __gc(GC), __marked(0)
	{
		GC->heap.push_back(this);
	}

	gc_object::~gc_object()
	{
		for (size_t i = 0; i < __gc->heap.size(); i++) {
			if (__gc->heap[i] == this) {
				__gc->heap.erase(__gc->heap.begin() + i);
				break;
			}
		}
	}
}
