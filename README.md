## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
user@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
user@ubuntu:~/monty$
```
# The monty program
- Usage: monty file
  - where file is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
- You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)
  
  ## Functions used in this project<br>
  
  
| Function | Description |
| --- | --- | 
| [execute](/execute.c) | Executes the opcode. |
| [get_op](/get_opcode.c) | Catch the opcode with strtok. |
| [pushStack](/functions.c) | Push a new member onto the stack. |
| [pintStack](/functions.c) | Print the top member of the stack. |
| [pallStack](/functions.c) | print all the stack. |
| [freestack](/functions.c) | Frees the entire stack. |
| [freeNode](/functions.c)  | Frees a node. |
| [popStack](/more_functions.c) | Removes the Stack top member. |
| [swapStack](/more_functions.c) | Swap the two toppest stack members. |
| [addStack](/more_functions.c) | Adds the values of the two toppest stack members. |
| [nopStack](/more_functions.c) | Doesn´t do anything. |
  
  ## Our files
  
- [execute.c](/execute.c) - Contains the function wich is in charge of execute the opcode.
- [functions.c](/functions.c) - Contains some of our stack functions.
- [more_functions.c](/more_functions.c) - Some more functions.
- [get_opcode.c](/get_opcode.c) - Contains the function that catch the opcode.
- [monty.c](/monty.c) - main function.
- [monty.h](/monty.h) - Header file.
  
  ## AUTHORS
  [Gabriel Delgado](https://github.com/Gisezegk)
  
  [Giselle Nieves](https://github.com/Gabr1el20)
