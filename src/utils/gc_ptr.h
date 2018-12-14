#pragma once

#include "gc_object.h"

#define gc_ptr ptr

namespace newtoo
{
	template<typename T> class ptr {
		T& target;
	public:
		ptr(T* GC_OBJECT_) : target(*GC_OBJECT_)
		{
			gc_object* go = (gc_object*)&target;
			go->gc__->ptrs.push_back(go);
		}

		~ptr()
		{
			gc_object* go = &target;
			for (size_t i = 0; go->gc__->ptrs.size(); i++) {
				if (go->gc__->ptrs[i] == go) {
					go->gc__->ptrs.erase(go->gc__->ptrs.begin() + i);
					break;
				}
			}
		}

		T* get()
		{
			return &target;
		}

		T& operator->()
		{
			return target;
		}
	};
}
