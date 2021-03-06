#include "garbage_collector.h"
#include <iostream>
#include <string>

#define gc_verbose

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

		//mark from references
		for (size_t i = 0; i < ptrs.size(); i++)
		{
			gc_object* ptri = ptrs[i];
			for (size_t i2 = 0; i2 < heap.size(); i2++) {
				if (ptri == heap[i2]) {
					heap[i2]->__marked = 1;
					break;
				}
			}
		}

#ifdef gc_verbose
		unsigned deleted = 0;
#endif

		//sweep
		size_t i = 0;
		while (i < heap.size())
		{
			if (heap[i]->__marked == 0) {
				delete heap[i];
				i = 0;
#ifdef gc_verbose
				deleted++;
#endif
			}
			else i++;
		}
#ifdef gc_verbose
		std::cout << "[GC]: Deleted " + std::to_string(deleted) +" objects\n";
#endif

	}

	void garbage_collector::Register(reference_list* reflist) {
		reflists.push_back(reflist);
		reflist->gc__ = this;
	}
}
