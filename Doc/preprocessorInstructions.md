# Preprocessors instructions.
Here is an example of how you can use the preprocessors instructions.
```c++
#include <iostream>
// Define the macro, with it you can define every thing, notice that i do not 
// go to declare the main function explicitly.
#define MAIN_TEST(a,b) int main(){auto a = b; std::cout << a << std::endl;
// Here, the end of the scope, only for show you how it work
#define END_OF_SCOPE return 0;}

// Here is not declared expliticly the main function (we can use it for make the main function)
// without the "graphic" parameters
MAIN_TEST(name, 100)
// The another macro
END_OF_SCOPE

// End of the program.
```
