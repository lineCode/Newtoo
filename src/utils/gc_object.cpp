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

	reference_list::reference_list() : gc__(0)
	{
	}

	reference_list::~reference_list()
	{
		if (gc__ == 0)
			return;

		for (size_t i = 0; i < gc__->reflists.size(); i++) {
			if (gc__->reflists[i] == this) {
				gc__->reflists.erase(gc__->reflists.begin() + i);
				break;
			}
		}
	}

	gc_object::gc_object(requires_gc) : gc__(GC), __marked(0)
	{
		GC->heap.push_back(this);
	}

	gc_object::~gc_object()
	{
		for (size_t i = 0; i < gc__->heap.size(); i++) {
			if (gc__->heap[i] == this) {
				gc__->heap.erase(gc__->heap.begin() + i);
				break;
			}
		}
	}
}
