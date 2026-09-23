# REPORT.md — Operating Systems Programming Assignment 01

## Part 2: Multi-file Project

**Q1: Explain the linking rule `$(TARGET): $(OBJECTS)`. How does it differ from linking against a library?**

This rule tells make that the final executable depends directly on all the object (.o) files. When linking, gcc combines all the .o files together to produce the executable — every function's compiled code comes straight from these object files. This differs from linking against a library, where the executable instead depends on a library file (like libmyutils.a or libmyutils.so). With static linking, the linker copies only the needed code out of the library into the executable, and with dynamic linking, the executable only stores a reference to the library, which the OS loader resolves at runtime.

**Q2: What is a git tag and why is it useful? Difference between simple and annotated tag?**

A git tag marks a specific commit as significant, usually to mark a release point in the project's history. It is useful because it lets you quickly refer back to a stable version instead of remembering a long commit hash. A simple tag is just a pointer to a commit (no extra data). An annotated tag stores additional metadata — the tagger's name, email, date, and a message — and is treated as a full object in git's database, which is why annotated tags are recommended for releases.

**Q3: What is the purpose of a GitHub Release? Why attach binaries?**

A GitHub Release packages a specific tagged version of the project into a shareable, downloadable page with release notes. Attaching binaries (like the compiled client executable) lets users download and run the program immediately without needing to clone the repository and build it themselves — this is especially useful for end users who just want to use the software, not modify its source code.

## Part 3: Static Library

**Q1: Compare the Makefile from Part 2 and Part 3.**

In Part 2, the Makefile compiled all .c files into .o files and linked them directly into the final executable. In Part 3, the .o files for the library functions (mystrfunctions.o, myfilefunctions.o) are first archived into libmyutils.a using the ar command, and the final executable links against this library using the -L (library path) and -l (library name) flags, instead of listing the object files directly.

**Q2: What is the purpose of the ar command? Why is ranlib often used after it?**

The ar command creates, modifies, and extracts from archive files — it bundles multiple object files into a single static library file (.a). ranlib is used after ar to generate/update an index inside the archive, which speeds up the linker's ability to find symbols in the library. This assignment used ar's `s` flag, which performs the same indexing that ranlib would do separately.

**Q3: When you run nm on client_static, are symbols like mystrlen present?**

Yes, running `nm bin/client_static | grep mystrlen` shows the symbol with a `T` (Text section) marker, confirming the function's actual compiled code is present inside the executable. This demonstrates that static linking copies the library code directly into the final binary at compile time, so the executable has no external runtime dependency on the library.

## Part 4: Dynamic Library

**Q1: What is Position-Independent Code (-fPIC) and why is it needed?**

Position-Independent Code is code that can execute correctly regardless of the memory address at which it is loaded. It is required for shared libraries because a .so file may be loaded at a different memory address in every process that uses it, unlike a static library whose code becomes a fixed part of one executable.

**Q2: Explain the file size difference between static and dynamic clients.**

client_static is larger because it contains a full copy of the library's compiled code within itself. client_dynamic is smaller because it only stores a reference to the shared library; the actual library code stays in the separate libmyutils.so file and is loaded into memory at runtime rather than being duplicated inside the executable.

**Q3: What is LD_LIBRARY_PATH and why was it necessary?**

LD_LIBRARY_PATH is an environment variable that tells the dynamic loader additional directories to search for shared libraries at runtime. It was necessary here because libmyutils.so was not installed in a standard system library location (like /usr/lib), so without it the loader could not find the library and the program failed with a "cannot open shared object file" error. This illustrates that the OS's dynamic loader is responsible for locating and linking shared libraries at program startup, not at compile time.

## Part 5: Man Pages

Man pages were created for the client program using groff formatting, covering the .TH, .SH NAME, .SH SYNOPSIS, .SH DESCRIPTION, and .SH AUTHOR sections. The Makefile's install target copies the compiled executable to /usr/local/bin and the man page to the system's man page directory, then refreshes the man database so the documentation becomes accessible system-wide via the `man` command.
