#include "gc_object.h"
#include "garbage_collector.h"

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

	reference_list::reference_list() : __registered(0)
	{
	}

	reference_list::~reference_list()
	{
		if (__registered == 0)
			return;

		for (size_t i = 0; i < GC.reflists.size(); i++) {
			if (GC.reflists[i] == this) {
				GC.reflists.erase(GC.reflists.begin() + i);
				break;
			}
		}
	}

	gc_object::gc_object() : __marked(0)
	{
		GC.heap.push_back(this);
	}

	gc_object::~gc_object()
	{
		for (size_t i = 0; i < GC.heap.size(); i++) {
			if (GC.heap[i] == this) {
				GC.heap.erase(GC.heap.begin() + i);
				break;
			}
		}
	}
}
