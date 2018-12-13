#include "garbage_collector.h"

namespace newtoo
{
	void garbage_collector::collect()
	{
		//unmark
		for (size_t i = 0; i < heap.size(); i++)
			heap[i]->__marked = 0;

		//mark from heap objects references
		for (size_t i = 0; i < heap.size(); i++)
		{
			gc_object* obj = heap[i];
			for (size_t i1 = 0; i1 < obj->__own_references.size(); i1++) {
				void* ref = *obj->__own_references[i1];

				if (ref == obj)
					continue;

				for (size_t i2 = 0; i2 < heap.size(); i2++) {
					if (ref == heap[i2]) {
						heap[i2]->__marked = 1;
						break;
					}
				}
			}
		}

		//mark from reference lists
		for (size_t i = 0; i < reflists.size(); i++)
		{
			reference_list& reflist = *reflists[i];
			for (size_t i1 = 0; i1 < reflists.size(); i1++) {
				void* ref = *reflist[i1];

				for (size_t i2 = 0; i2 < heap.size(); i2++) {
					if (ref == heap[i2]) {
						heap[i2]->__marked = 1;
						break;
					}
				}
			}
		}

		//sweep
		for (size_t i = 0; i < reflists.size(); i++)
		{
			if(heap[i]->__marked == 0)
				delete heap[i];
		}

	}

	void garbage_collector::Register(reference_list* reflist) {
		reflists.push_back(reflist);
		reflist->__registered = 1;
	}
}
