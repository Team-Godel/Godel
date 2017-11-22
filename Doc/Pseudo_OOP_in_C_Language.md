# Pseudo OOP in C languages with structures and pointers

In  C languages we can define a structure regrouping all the simple variables, other structures and even a pointeur on a function that's
going to allow us to call the function by citing the name of the pointer.

  ```
  #include <stdio.h>
  
  struct simpleStruct
  {
    char ch; 
  };
  
  struct pseudoObject
  {
   int var;
   struct simpleStruct st1;
   int (*ptrF)(int);  // Declare pointer/function
  };
  
  int MyFunc(int y)
  {
     printf("From MyFunc", y);
     
     return 0;
  }  
  
  int main()
  {
    struct pseudoObject pO;
    pO.var = 999;
    pO.st1.ch = 65;
    
    printf("%d %c\n", pO.var, pO.st1.ch);
    
    pO.ptrF = &MyFunc; // Target the function
    pO.ptrF(32000);    // Indirect call
    
    return 0;
  }
  
  ```
