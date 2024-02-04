<h1 align="center">
	<br>
	<img src="https://raw.githubusercontent.com/Trantorian1/libmini/main/res/libmini.png" alt="libmini" width="200">
	<br>
    <h4 align="center">A Simple C++ utility library</h4>
</h1>

> Libmini is designed to bring simple quality of life features from later versions of C++ into C++98.

## Smart Pointers

```c++
#include "pointer.hpp"
#include <iostream>

int main() {
    mini::uniqueptr<int> myUniquePtr = mini::make_unique<int>();
    *myUniquePtr = 10;

    std::cout << "The value is: " << *myUniquePtr << std::endl;

    return 0;
}
```

## C-style array size at compile time

```c++
#include "array.hpp"
#include <iostream>

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Size of myArray is: " << mini::size(myArray) << std::endl;
    return 0;
}
```

## Terminal colors

```c++
#include "color.hpp"
#include <iostream>

int main() {
    std::cout << color::RED << "This text is red." << color::RESET << std::endl;
    std::cout << color::GREEN << "This text is green." << color::RESET << std::endl;
    std::cout << color::YELLOW << "This text is yellow." << color::RESET << std::endl;
    std::cout << color::BLUE << "This text is blue." << color::RESET << std::endl;
    std::cout << color::MAGENTA << "This text is magenta." << color::RESET << std::endl;
    std::cout << color::CYAN << "This text is cyan." << color::RESET << std::endl;
    std::cout << color::WHITE << "This text is white." << color::RESET << std::endl;

    // Background colors
    std::cout << color::RED_BG << "This has a red background." << color::RESET << std::endl;
    std::cout << color::GREEN_BG << "This has a green background." << color::RESET << std::endl;
    return 0;
}
```

## Function deletion

> Note that this is moslty syntactic sugar for cases where your are asked to follow the Orthodox Canonical Class form to fanatical levels :)

```c++
#include "define.hpp"
#include <iostream>

class MyClass {
public:
    MyClass() DELETE; // Delete the default constructor

    // Define a constructor with parameters
    MyClass(int value) : value_(value) {
        std::cout << "MyClass constructed with value: " << value_ << std::endl;
    }

private:
    int value_;
};

int main() {
    // MyClass myObject; // This line will cause a compile-time error
    MyClass myObject(10); // Correct way to instantiate MyClass
    return 0;
}
```