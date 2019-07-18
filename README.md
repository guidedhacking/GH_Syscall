# GH Syscall

Small class to help perform syscalls.

It's a tiny class that basically just holds a pointer to some allocated memory that we can read/write and execute code from.

Then it's just a matter of returning a std::function object of the proper type.

That's where the GetInvoke function comes in, it takes two arguments.

The name of the function you'd like to get call, and a pointer.

The pointer is a little hack to get the compiler to play nicely with std::function.

What it points to doesn't matter, since we're getting the address of the original function with GetProcAddress.


[More information in GH Thread](https://guidedhacking.com/threads/using-std-function-to-perform-syscalls-tutorial.12235/)