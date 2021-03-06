# Creating Static libs with Code::blocks

# What are libraries

Libraries usually contain functions that can be used by multiple programs. 
They can also contain icons like the shell32.dll file of Windows XP for example. 
There are two types of libraries: static libraries and dynamic libraries.

# Static libraries

In the case of static libraries, the functions contained in the library are loaded 
when editing the links. That is why the .h file is needed, it indicates which functions 
are useful. The functions are included in the executable file of your program, there is 
nothing else to provide so the program can be run on a computer that does not have the library.
Static libraries are .lib files or .a

# Dynamic libraries

For dynamic libraries, functions are not included in the executable. The functions are called
during program execution (hence the "dynamics"). The advantage is that the executable is lighter
but you have to provide the library with the program. So in the end the executable set + dll 
is heavier than the executable containing the library (as in the previous case).
You should also know that if several programs need the same dll, they can all 
access it while the library is only loaded once. In this case we speak of shared library.
On Windows, dynamic libraries are .dll files and under GNU / Linux are .so files.

There are two types of dynamic libraries: implicitly loaded libraries and explicitly 
loaded libraries (only works on Windows). The difference is that for an implicit load 
library you have to link with a .a file. If you want to use only the dll you have to make an 
explicit loading library. In fact the construction of the library is the same, it is the design 
of the executable that differs. The SDL for example is used by implicit loading. Indeed this is 
portable and easier to code.

# Static libraries

I will first talk about static libraries. Indeed it is the simplest to achieve.
The library project

In Code :: Blocks you have to create a new project by choosing "Static Library". Check the 
"Do not create any files" box and press the create button.
Add to your project a .c file that you can for example name lib.c.

As I told you that these libraries were simple to implement, we immediately go to practice. 
You need a function so we will take as an example a function that returns the square of a number 
passed as a parameter:

	#include "dll.h"
	int square (int integer) {
	    int square = 0;
	    square = integer * integer;
	    return square;
	}

Now you have to make a dll.h file that will contain the prototypes of your functions:
int square (int integer);

This file must be included in your lib.c this can be useful when your library contains 
several functions that make use of each other.

Well it's over, you just have to compile and you get a libstaticlib.a file. 
If the name does not please go to "Project", "Properties" and then in the "Target" tab. 
There you change "Output Filename".

# The project of your program

For this project you can do what you want (console, SDL, OpenGL, ...) but here I will 
take the example of a console project to make it simple. I hope you know how to create a 
console project with Code :: Blocks. Put in your project a main.c file which will contain 
your main () function. Since the goal is to use the function contained in the library, 
we must obviously make a code that uses this function:

	#include <stdio.h>
	#include <stdlib.h>
	#include "dll.h"

	int main (int argc, char * argv []) {
	   int result = 0;
	   result = square (3);
	   printf ("The result is% d \ n", result);
	   printf ("Press a key to continue ...");
	   getchar ();
	   return 0;
	}

# As you see I included dll.h file.

Then do not forget to link with your beautiful library. For that you go in "Project" then 
"Build options" and finally you go in the "Linker" tab. There you add your libstaticlib.a or other 
if you changed the name.

And now the long awaited moment, compilation and execution. If you have no problem and 
I hope (otherwise it is that this tutorial is zero;)) the console proudly displays:

```The result is 9```
```Press a key to continue ...```

And here you know how to create and use a static library. Now let's see together the case of dynamic libraries, well-known dlls.
