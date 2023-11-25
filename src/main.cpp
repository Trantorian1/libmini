#include <cstdlib>
#include <iostream>

#include "UniquePtr.hpp"

namespace {
	struct MyStruct {
	public:
		MyStruct(int x, int y) : x(x), y(y) {}

		int	x;
		int	y;
	};
}

int	main(void) {
	mini::UniquePtr<MyStruct>	ptr(new MyStruct(0, 2));

	std::cout << ptr->x << std::endl;
	
	return (EXIT_SUCCESS);
}

