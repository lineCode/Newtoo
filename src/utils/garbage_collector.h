#pragma once

#include "gc_object.h"

namespace newtoo
{
	class garbage_collector {

	public:
		std::vector<reference_list*> reflists;
		std::vector<gc_object*> heap;

		void Register(reference_list* reflist);

		void collect();
	};

	static garbage_collector GC;
}
