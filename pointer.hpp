#include <ostream>

#ifndef POINTER_HPP
# define POINTER_HPP

namespace mini {
	template<typename T>
	class UniquePtr {
	public:
		explicit UniquePtr(T *ptr);
		UniquePtr(const UniquePtr& ptr);
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

	// ============================[ CONTRUCTOR ]============================ //

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

	// =============================[ ACCESSORS ]============================ //

	template<typename T>
	T*	UniquePtr<T>::getPtr(void) const {
		return (_ptr);
	}

	// =============================[ OPERATORS ]============================ //

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

	// =============================[ FUNCTIONS ]============================ //
	
	template<typename T>
	UniquePtr<T>	make_unique() {
		return (UniquePtr<T>(new T()));
	}


	// =============================[ ACCESSORS ]============================ //

	template<typename T>
	class RawArrayPointer {
	public:
		explicit RawArrayPointer(std::size_t size);
		~RawArrayPointer(void);

		const T*	getPtr(void)	const;

		T&	operator*(void);
		T*	operator->(void);
		T&	operator[](std::size_t index);
			operator T*(void) const;

		void	construct(std::size_t index, T& value);

	private:
		const std::size_t	_size;
		T* const			_data;
	};

	// ============================[ CONTRUCTOR ]============================ //
	
	template<typename T>
	RawArrayPointer<T>::RawArrayPointer(std::size_t size) :
		_size(size),
		_data(static_cast<T*>(operator new[](size * sizeof(T))))
	{}

	template<typename T>
	RawArrayPointer<T>::~RawArrayPointer(void) {
		for (std::size_t index = 0; index < this->_size; index++) {
			this->_data[index].~T();
		}

		delete (this->_data);
	}

	// =============================[ ACCESSORS ]============================ //
	
	template<typename T>
	const T*	RawArrayPointer<T>::getPtr(void) const {
		return (this->_data);
	}

	// =============================[ OPERATORS ]============================ //

	template<typename T>
	T&	RawArrayPointer<T>::operator*(void) {
		return (*this->_data);
	}

	template<typename T>
	T*	RawArrayPointer<T>::operator->(void) {
		return (this->_data);
	}

	template<typename T>
	T&	RawArrayPointer<T>::operator[](std::size_t index) {
		if (index >= this->_size)
			throw (std::invalid_argument("index"));
		return (this->_data[index]);
	}

	template<typename T>
	RawArrayPointer<T>::operator T*(void) const {
		return (this->_data);
	}

	template<typename T>
	std::ostream&	operator<<(std::ostream& os, RawArrayPointer<T>& rawArray) {
		os << std::hex << rawArray.getPtr();
		return (os);
	}

	// =============================[ FUNCTIONS ]============================ //
	
	template<typename  T>
	void	RawArrayPointer<T>::construct(std::size_t index, T& value) {
		if (index >= this->_size)
			throw (std::invalid_argument("index"));
		new(this->_data[index]) T(value);
	}
}

#endif
