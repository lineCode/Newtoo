#include "gc_ptr.h"

namespace newtoo
{
	template<typename T> ptr::ptr(T& GC_OBJECT_) : target(*GC_OBJECT_)
	{
		gc_object* go = *GC_OBJECT_;
		go->__gc->ptrs.push_back(go);
	}

	template<typename T> ptr::ptr(T* GC_OBJECT_) : target(GC_OBJECT_)
	{
		gc_object* go = *GC_OBJECT_;
		go->__gc->ptrs.push_back(go);
	}

	template<typename T> ptr::~ptr()
	{
		gc_object* go = *target;
		for (size_t i = 0; go->__gc->ptrs.size(); i++) {
			if (go->__gc->ptrs[i] == go) {
				go_->__gc->ptrs.erase(go_->__gc->ptrs.begin() + i);
				break;
			}
		}
	}

	template<typename T> T* ptr::get()
	{
		return &target;
	}
	template<typename T> T& ptr::operator->()
	{
		return target;
	}
}
