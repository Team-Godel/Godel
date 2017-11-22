# Static Modificator
First of all, i want to start writing about what is a ```static``` variable, or rather, what is the ```static modificator```.
When you declare a simple variable, this lost its value when the program comes out of the scope within it is declared.
The ```static modificator``` is a feature of C and C++ for solve this problem (and other), it is very useful for a lot of things, first, how i said, with it you can keep the value of a variable out of the scope in that it is declared, it is a powerful feature, and can be applied into a function, into a class, and some other lot of kinds of structures in C/C++.
It is very used within classes and in the declaration of some functions, now i want to explain how it work, but first, its syntaxis:
```c++
static <data definition> ;
static <name of the function> <function definition> ;
```
# Static Member
The behaviour of the static members of classes are very different of the behaviour of the non-static member of the classes, a very interesting (and sometimes useful) fact about the static members, are that while the non-static members has one copy for each class, the static members share a only copy for all the instances of a class, this is, a non-static member of a class ```square``` can be ```size```, then, each instance of ```square``` will have one ```size``` variable, unique for each ```square```. Instead, a static member of a function can be ```numberOfInstances```, this static static member can be used for count all the instances of the class ```square```, this can be using the constructor of the class and adding one to the value of the static member each time that the class will be instanced in the code, so, this static member is shared by all the instances of the object of the kind ```square```.
See this example:
```c++
#include <iostream>

class someClass
{
public:
	static int value; // The member can not be initialized within the class
};

int someClass::value = 1; // The definition (out of main and out of the class definition)

int main (int argc, char** argv) {

	someClass exampleOne, exampleTwo;

	std::cout << "Shared value " << exampleOne.value << std::endl;
	std::cout << "Shared value " << exampleTwo.value << std::endl;
	
	exampleOne.value = 5;
	
	std::cout << "Shared value " << exampleOne.value << std::endl;
	std::cout << "Shared value " << exampleTwo.value << std::endl;
	
	exampleTwo.value = 10;
	
	std::cout << "Shared value " << exampleOne.value << std::endl;
	std::cout << "Shared value " << exampleTwo.value << std::endl;
	
	return 0;
}
```
This return the next output:
```
Shared value 1
Shared value 1
Shared value 5
Shared value 5
Shared value 10
Shared value 10
```
# Static Methods
More coming soon...
