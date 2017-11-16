# lib.h

	#ifndef EXEMPLE_H_INCLUDED
	#define EXEMPLE_H_INCLUDED

	int addition(int a, int b);

	int substraction(int a, int b);

	#endif // EXEMPLE_H_INCLUDED
	
	
# lib.c

	#include <iostream>

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
	
