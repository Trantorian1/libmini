#ifndef UNIQUE_PTR_HPP
# define UNIQUE_PTR_HPP

#include <iostream>

namespace mini {
	template<typename T>
	class UniquePtr {
	public:
		explicit UniquePtr(T *ptr);
		~UniquePtr(void);
		UniquePtr<T>&	operator=(T& other);

		T*	getPtr(void) const;

		T&	operator*(void);
		T*	operator->(void);
			operator T*(void) const;

	private:
		T* const	_ptr;
	};

	// ============================[ CONTRUCTOR ]============================ //

	template<typename T>
	UniquePtr<T>::UniquePtr(T *ptr) : _ptr(ptr) {}

	template<typename T>
	UniquePtr<T>::~UniquePtr(void) {
		delete (this->_ptr);
	}

	// =============================[ ACCESSORS ]============================ //

	template<typename T>
	T*	UniquePtr<T>::getPtr(void) const {
		return (this->_ptr);
	}

	// =============================[ OPERATORS ]============================ //

	template<typename T>
	UniquePtr<T>&	UniquePtr<T>::operator=(T& other) {
		~UniquePtr();
		this->_ptr = other;
	}

	template<typename T>
	T&	UniquePtr<T>::operator*(void) {
		return (*this->_ptr);
	}

	template<typename T>
	T*	UniquePtr<T>::operator->(void) {
		return (this->ptr);
	}

	template<typename T>
	UniquePtr<T>::operator	T*(void) const {
		return (this->_ptr);
	}

	template<typename T>
	std::ostream&	operator<<(std::ostream& os, UniquePtr<T>& uniquePtr) {
		os << std::hex << uniquePtr.getPtr();
		return (os);
	}

	// =============================[ FUNCTIONS ]============================ //
	
	template<typename T>
	UniquePtr<T>	make_unique() {
		return (UniquePtr<T>(new T()));
	}
}

#endif
