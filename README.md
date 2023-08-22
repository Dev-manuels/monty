#  C - Stacks, Queues - LIFO, FIFO
Stacks, Queues - LIFO, FIFO. The goal of this project is to create an interpreter for Monty ByteCodes files that would contain stack and queue related commands.

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument. Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

**Example** of byte codes files can be seen [here](https://github.com/Dev-manuels/monty/tree/master/bytecodes)

## The Monty program

**Usage: monty file**
- Usage: monty file
    - where file is the path to the file containing Monty byte code

- if the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE

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

## Compilation & Output
- The code Should be compiled this way:
    ```$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty ```
