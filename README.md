# coffeeDS
NDS emulator written in C.

### Download

1. Grab the download from the releases page
2. Do `chmod a+x coffeeDS` (or run it as admin if you are on Windows)
3. Run it (if you plan on debugging, use the terminal as some debug features do not write to the log).

**Windows is experimental. coffeeDS is built especially for Linux**

### Controls

1: Debug -> Dump opcodes (**requires terminal**)
Q: Quit (does not work during debug functions)
M: Toggle macro mode (GBA mode)
N: Toggle macro mode screen

## Code Guidelines

1. Follow ANSI C where possible (some developers will use AStyle in some commits. Do **not** make styling commits; the commit must have another purpose.)
2. Avoid using complex flow constructs like `goto` and recursion
3. Use `<>` instead of `""` for headers
4. Avoid `malloc` and `free` (avoid heap memory allocation)
5. Compile with as few warnings as possible and address them in the commit description
6. Avoid using `__attribute__` where possible (except for removing warnings around static variables)
7. Only include headers if they are needed
8. Do not rely on headers which include headers - if you need a type definition, include it
9. Use header files for prototypes and variables, use source (.c) files for prototype definitions
10. Update the code prolog at the top of every file
11. Add important notes with `// NOTE:`, todos with `// TODO:` and fixmes with `// FIXME:`
12. If a function does not need to return any data and has not experienced any problems, it should return 0.
