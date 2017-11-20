# Factory Methods
In C++, the dynamic instance of a class is declared using the next syntaxis:
Class *dynamicObject = new Class;
Now, you can assign a class from the function through "Factory Methods", these methods are function members of a class that return a pointer to a class, more graphicly, the factory method look like this:
```c++
Class className
{
public:
	className();
	~className();
	static Class* FactoryMethod();
}
className *className::FactoryMethod() {return new className};
```
This pattern (the factory method is considerated as a pattern) is very useful for use the class for many other things, like add the class to an array, for example.
Next, in the code, you can see it 
```c++
class GDL
{
public:
	static GDL *CreateTestWindow(HINSTANCE hInstance);
	GDL() : m_hWnd(0) {}
	~GDL();
// Some another things here
};
```
And, later, the implementation of the function.
```c++
GDL *GDL::CreateTestWindow(HINSTANCE hInst)
{
    // Some code here... (Is not useful for the explaining)
    GDL *g_vars = new GDL; // Line 22 in the ClassTemplate3/GodelLib.h file
    // ...Some code here...
    if(hWnd == NULL) // See it! It is very important
    {
        delete g_vars; // Here, you can see the destroyer of the function, through the "delete" operator
		// The same method call its destructor if the windows can not be created
        MessageBox(NULL,"Problem creating the window.","Error",0);
        return 0; // If you can not create the window, you turn the pointer into a null pointer
    }
    return g_vars; // After create the instance, you can get the value of the class here, remind, you declare the
	// pointer to a class, and it are void, next, you should use this method (in this case) to put a value of type
	// class within the adress of the memory pointed by the pointer.
}
```
When you call the method without set any other class, you are calling a static method, in:
```c++
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    GDL *g_vars = GDL::CreateTestWindow(hInstance);
	// ...Some code more here...
}
```
GDL::CreateTestWindow are not a call to the method into a function, it is just a call to a static function allocated in the namespace of the function.
