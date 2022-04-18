

To Check Preprocessor File of calc file
$ g++ -E calc.cpp



Building Library - static:
$ g++ -c main.cpp
$ g++ -c calc.cpp
$ g++ -o main calc.o main.o -lm   or   g++ -o main calc.o main.o /usr/lib/libm.a
$ ./main

To Check Assembly File of calc file
$ g++ -S calc.cpp

To see the content calc object file
$ nm calc.o


Now, let's build a new library using ar.
$ ar crv libcalc.a calc.o

Now we can make executable from the library we just built, libcalc.a
$ g++ -o main main.o libcalc.a -lm  
$ ./main


Building Library - shared (dynamic):
A typical shared library extension is so. For math library, it is /usr/lib/libm.so.

When a program uses shared library, the code itself is not included in the program, but it just links the library to refer it at run time. In that way, several program use the library without having it, and can save space. In other words, shared libraries address the disadvantages of static libraries. A shared library is an object module that can be loaded at run time at an arbitrary memory address, and it can be linked to by a program in memory. Shared libraries often are called as shared objects. On most UNIX systems they are denoted with a .so suffix and Microsoft refer to them as DLLs (dynamic link libraries).

Also, shared library has addition advantage over static library because it can be updated independently.


To make shared library with calc.o, we do the following:
$ g++ -shared -fPIC -o libcalc.so calc.o

The command tells the compiler driver to generate a shared library, libcalc.so, from the object module calc.o. The -fPIC option tells the compiler to generate position independent code (PIC).

Now, suppose the primary object module is main.o, which has dependencies on calc.o . In this case, the linker is invoked with:
$ g++ main.o ./libcalc.so -lm
$ ./a.out

The command above makes an executable file, a.out, in a form that can be linked to libcalc.so at load time. However, a.out does not contain the object module calc.o, which would have been included had we created a static library instead of a shared library. The executable simply contains some relocation and symbol table information that allow references to code and data in libcalc.so to be resolved at run time. Thus, a.out here is a partially executable file that still has its dependency in libcalc.so.

The executable also contains a .interp section that has the name of the dynamic linker, which itself is a shared object on Linux systems, ld-linux.so. So, when the executable is loaded into memory, the loader passes control to the dynamic linker. The dynamic linker contains some start-up code that maps the shared libraries to the program's address space.

We've already used some of the tools to explore object/executable files, here is the list of tools:

ar
creates static libraries.
ldd
lists the shared libraries on which the object binary is dependent.
nm
lists the symbols defined in the symbol table of an object file or a static library.
objdump
to display all the information in an object binary file.
strings
list all the printable strings in a binary file.
strip
deletes the symbol table information.
c++filt
demangle low-level names into user-level names (unix/linux command).

