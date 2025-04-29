# GH Syscall

Small class to help perform syscalls.

## Short Explanation

It's a tiny class that basically just holds a pointer to some allocated memory that we can read/write and execute code from.
Then it's just a matter of returning a std::function object of the proper type.
That's where the GetInvoke function comes in, it takes two arguments.
The name of the function you'd like to get call, and a pointer.
The pointer is a little hack to get the compiler to play nicely with std::function.
What it points to doesn't matter, since we're getting the address of the original function with GetProcAddress.

[More information in GH Thread](https://guidedhacking.com/threads/using-std-function-to-perform-syscalls-tutorial.12235/)

Welcome to the `GH_Syscall` repository. This repository is a treasure trove for those interested in the nitty-gritty of system calls in the Windows environment. It's a project that's not for the faint-hearted, but if you're a software engineer with a passion for understanding the inner workings of systems, you're in the right place.

Overview
--------

`GH_Syscall` is a project that provides a method for invoking system calls directly, bypassing the Windows API. This is particularly useful for those interested in reverse engineering, game hacking, or any other field where direct system interaction is required.

Key Features
------------

### 1\. Direct System Calls

The primary feature of this repository is the ability to make direct system calls. This is achieved through the `Syscall` function in the `gh_syscall.cpp` file. This function takes the syscall number and an array of arguments, then invokes the system call directly using inline assembly.

### 2\. System Call Number Lookup

The repository also includes a method for looking up system call numbers. This is done through the `GetSyscallNumber` function, also in the `gh_syscall.cpp` file. This function takes the name of a system call and returns its number, allowing for dynamic system call invocation.

### 3\. NT Definitions

The `nt_defs.h` file contains a number of definitions for structures and types used in NT system calls. This includes definitions for things like `PEB` and `TEB`, as well as various system call argument structures.

Experience Level Required
-------------------------

This repository is not for beginners. A solid understanding of C++ and assembly language is required, as well as a good understanding of Windows internals. If you're comfortable with these topics and are interested in diving deeper into the world of system calls, this repository is for you.

End Goal
--------

The end goal of this source code is to provide a method for invoking system calls directly, bypassing the Windows API. This can be useful in a number of scenarios, such as reverse engineering or game hacking, where direct system interaction is required.

Key Pieces of Code
------------------

### 1\. Syscall Function

The `Syscall` function in the `gh_syscall.cpp` file is the heart of this repository. This function takes a system call number and an array of arguments, then invokes the system call directly using inline assembly. This allows for direct interaction with the system, bypassing the Windows API.

### 2\. GetSyscallNumber Function

The `GetSyscallNumber` function, also in the `gh_syscall.cpp` file, is another key piece of code. This function takes the name of a system call and returns its number. This allows for dynamic system call invocation, where the system call to be invoked can be determined at runtime.

### 3\. NT Definitions

The `nt_defs.h` file contains a number of definitions for structures and types used in NT system calls. These definitions are crucial for understanding and using the system calls that this repository allows you to invoke.


FAQ
---

1\. "System call" - sounds fancy, what's that?

Well, imagine you're a program and you need to chat with the operating system. How do you do it? Through system calls! They're like the secret handshake between a process and the operating system. Pretty cool, right?

2\. So, why on earth would I want to bypass the Windows API?

Great question! Sometimes, you want to get your hands dirty and interact with the system directly. This can be super useful for things like reverse engineering or game hacking. It's like taking the scenic route instead of the highway.

3\. What's this "inline assembly" you speak of?

Inline assembly is like a secret weapon in some programming languages. It lets you mix high-level language statements with assembly code snippets. It's like being able to speak two languages at once!

4\. Syscall number - what's that?

Every system call has a unique ID, kind of like a phone number. The system uses this number to figure out which system call to invoke. It's all very organized!

5\. What about NT system calls?

GuidedHacking® - The Game Hacking Bible® - © 2025 Guided Hacking LLC. All Rights Reserved.

NT system calls are the system calls used in the Windows NT family of operating systems. This includes classics like Windows XP and modern hits like Windows 10.
