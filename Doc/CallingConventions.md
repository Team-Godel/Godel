# Calling Conventions
Traditionally, C function calls are made with the caller pushing some parameters onto the stack, calling the function, and then popping the stack to clean up those pushed arguments.

	/* example of __cdecl */
	push arg1
	push arg2
	push arg3
	call function
	add sp,12 // effectively "pop; pop; pop"

Note: The default convention — shown above — is known as __cdecl.

The other most popular convention is __stdcall. In it the parameters are again pushed by the caller, but the stack is cleaned up by the callee. It is the standard convention for Win32 API functions (as defined by the WINAPI macro in ), and it's also sometimes called the "Pascal" calling convention.

	/* example of __stdcall */
	push arg1 
	push arg2 
	push arg3 
	call function // no stack cleanup - callee does this

This looks like a minor technical detail, but if there is a disagreement on how the stack is managed between the caller and the callee, the stack will be destroyed in a way that is unlikely to be recovered. Since __stdcall does stack cleanup, the (very tiny) code to perform this task is found in only one place, rather than being duplicated in every caller as it is in __cdecl. This makes the code very slightly smaller, though the size impact is only visible in large programs.
Variadic functions like printf() are almost impossible to get right with __stdcall, because only the caller really knows how many arguments were passed in order to clean them up. The callee can make some good guesses (say, by looking at a format string), but the stack cleanup would have to be determined by the actual logic of the function, not the calling-convention mechanism itself. Hence only __cdecl supports variadic functions so that the caller can do the cleanup.

# Linker symbol name decorations
As mentioned in a bullet point above, calling a function with the "wrong" convention can be disastrous, so Microsoft has a mechanism to avoid this from happening. It works well, though it can be maddening if one does not know what the reasons are. They have chosen to resolve this by encoding the calling convention into the low-level function names with extra characters (which are often called "decorations"), and these are treated as unrelated names by the linker. The default calling convention is __cdecl, but each one can be requested explicitly with the /G? parameter to the compiler.

```__cdecl (cl /Gd ...)```

All function names of this type are prefixed with an underscore, and the number of parameters does not really matter because the caller is responsible for stack setup and stack cleanup. It is possible for a caller and callee to be confused over the number of parameters actually passed, but at least the stack discipline is maintained properly.

```__stdcall (cl /Gz ...)```

These function names are prefixed with an underscore and appended with @ plus the number of bytes of parameters passed. By this mechanism, it's not possible to call a function with the "wrong" type, or even with the wrong number of parameters.

```__fastcall (cl /Gr ...)```

These function names start with an @ sign and are suffixed with the @parameter count, much like __stdcall.

Examples:

```Declaration                        ----------------------->    decorated name

void __cdecl foo(void);            ----------------------->    _foo

void __cdecl foo(int a);           ----------------------->    _foo

void __cdecl foo(int a, int b);    ----------------------->    _foo

void __stdcall foo(void);          ----------------------->    _foo@0

void __stdcall foo(int a);         ----------------------->    _foo@4

void __stdcall foo(int a, int b);  ----------------------->    _foo@8

void __fastcall foo(void);         ----------------------->    @foo@0

void __fastcall foo(int a);        ----------------------->    @foo@4

void __fastcall foo(int a, int b); ----------------------->    @foo@8```

# Note
I put it here because the __stdcall is defined by microsoft as the CALLBACK "flag", so, the CALLBACK work is explained here. 
