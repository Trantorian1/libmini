#ifndef RAW_ARRAY_POINTER_HPP
# define RAW_ARRAY_POINTER_HPP

#include <cstddef>
#include <ostream>
#include <stdexcept>

namespace mini {
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
