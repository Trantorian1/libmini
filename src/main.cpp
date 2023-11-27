#include <cstdlib>
#include <iostream>

#include "UniquePtr.hpp"

struct MyStruct {
public:
	MyStruct() : x(0), y(0) {}
	MyStruct(int x, int y) : x(x), y(y) {}

	int	x;
	int	y;
};

int	main(void) {
	mini::UniquePtr<MyStruct>	ptr = mini::make_unique<MyStruct>();

	std::cout << ptr->x << std::endl;
	
	return (EXIT_SUCCESS);
}

