#pragma once

#include "gc_object.h"

namespace newtoo
{
	class garbage_collector {

	public:
		std::vector<reference_list*> reflists;
		std::vector<gc_object*> heap;
		std::vector<gc_object*> ptrs;

		void Register(reference_list* reflist);

		void collect();
	};
}

#define $_GC_init newtoo::garbage_collector* GC = new newtoo::garbage_collector()

#define $_GC_collect GC->collect()
