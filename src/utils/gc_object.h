#pragma once

#include <vector>

namespace newtoo
{
	struct reference_list {
		std::vector<void**> list;
		short __registered : 1;
		void** operator[](size_t index);
		size_t size();

		void Unregister(size_t index);
		void Register(void** ref);

		reference_list();
		~reference_list();
	};

	struct gc_object {
		reference_list __own_references;
		short __marked : 1;

		gc_object();
		~gc_object();
	};
}
