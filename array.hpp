#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>

namespace mini {
	template<class T, std::size_t N>
	std::size_t	size(const T (&array)[N]) {
		(void)array;
		return (N);
	}
}

#endif
