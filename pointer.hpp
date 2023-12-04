#include <ostream>

#ifndef POINTER_HPP
# define POINTER_HPP

namespace mini {
	template<typename T>
	class uniqueptr {
	public:
		explicit uniqueptr(T *ptr);
		uniqueptr(const uniqueptr& ptr);
		~uniqueptr();
		uniqueptr<T>&	operator=(T& other);

		T*	getPtr(void) const;

		T&	operator*(void);
		T*	operator->(void);
			operator T*(void) const;

	private:
		uniqueptr();
		uniqueptr(uniqueptr<T>& other);
		uniqueptr<T>&	operator=(uniqueptr& other);

		T* const	_ptr;
	};

	// ============================[ CONTRUCTOR ]============================ //

	template<typename T>
	uniqueptr<T>::uniqueptr(T *ptr) : _ptr(ptr) {}

	template<typename T>
	uniqueptr<T>&	uniqueptr<T>::operator=(T& other) {
		~uniqueptr();
		this->_ptr = other;
	}

	template<typename T>
	uniqueptr<T>::~uniqueptr(void) {
		delete (this->_ptr);
	}

	// =============================[ ACCESSORS ]============================ //

	template<typename T>
	T*	uniqueptr<T>::getPtr(void) const {
		return (this->_ptr);
	}

	// =============================[ OPERATORS ]============================ //

	template<typename T>
	T&	uniqueptr<T>::operator*(void) {
		return (*this->_ptr);
	}

	template<typename T>
	T*	uniqueptr<T>::operator->(void) {
		return (this->_ptr);
	}

	template<typename T>
	uniqueptr<T>::operator	T*(void) const {
		return (this->_ptr);
	}

	template<typename T>
	std::ostream&	operator<<(std::ostream& os, uniqueptr<T>& uniquePtr) {
		os << std::hex << uniquePtr.getPtr();
		return (os);
	}

	// =============================[ FUNCTIONS ]============================ //
	
	template<typename T>
	uniqueptr<T>	make_unique() {
		return (uniqueptr<T>(new T()));
	}
}

#endif
