# lib.h

	#ifndef EXEMPLE_H_INCLUDED
	#define EXEMPLE_H_INCLUDED

	int addition(int a, int b);

	int substraction(int a, int b);

	#endif // EXEMPLE_H_INCLUDED
	
	
# lib.c

	#include <iostream>
	#include <lib.h>

	using namespace std;

	int addition(int a, int b)
	{
    	 int result = a + b;
   	 cout << result << endl;
	}


	int substraction(int a, int b)
	{
    	 int result = a - b;
    	 cout << result << endl;
	}
	

When you run the program, Code::Blocks will create a .a file. Then, you just have to link the .a and the .h file in
a project and include the .h file with ```#include <lib.h>``` to use the library. See the doc "How to Create a Library with CodeBlocks".
