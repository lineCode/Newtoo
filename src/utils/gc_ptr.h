#pragma once

#include "gc_object.h"

#define gc_ptr ptr

namespace newtoo
{
	template<typename T> class ptr {
		T& target;
	public:
		ptr(T& GC_OBJECT_);
		ptr(T* GC_OBJECT_);
		~ptr();

		T* get();
		T& operator->();
	};
}
