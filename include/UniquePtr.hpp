#ifndef UNIQUE_PTR_HPP
# define UNIQUE_PTR_HPP

#include <iostream>

namespace mini {
	template<typename T>
	class UniquePtr {
	public:
		explicit UniquePtr(T *ptr);
		~UniquePtr();
		UniquePtr<T>&	operator=(T& other);

		T*	getPtr(void) const;

		T&	operator*(void);
		T*	operator->(void);
			operator T*(void) const;

	private:
		UniquePtr();
		UniquePtr(UniquePtr<T>& other);
		UniquePtr<T>&	operator=(UniquePtr& other);

		T* const	_ptr;
	};

	// =============================[CONTRUCTOR]============================= //

	template<typename T>
	UniquePtr<T>::UniquePtr(T *ptr) : _ptr(ptr) {}

	template<typename T>
	UniquePtr<T>&	UniquePtr<T>::operator=(T& other) {
		~UniquePtr();
		_ptr = other;
	}

	template<typename T>
	UniquePtr<T>::~UniquePtr(void) {
		delete _ptr;
	}

	// ==============================[ACCESSORS]============================= //

	template<typename T>
	T*	UniquePtr<T>::getPtr(void) const {
		return (_ptr);
	}

	// ==============================[OPERATORS]============================= //

	template<typename T>
	T&	UniquePtr<T>::operator*(void) {
		return (*_ptr);
	}

	template<typename T>
	T*	UniquePtr<T>::operator->(void) {
		return (_ptr);
	}

	template<typename T>
	UniquePtr<T>::operator	T*(void) const {
		return (_ptr);
	}

	template<typename T>
	std::ostream&	operator<<(std::ostream& os, UniquePtr<T>& uniquePtr) {
		os << std::hex << uniquePtr.getPtr();
		return (os);
	}
}

#endif
