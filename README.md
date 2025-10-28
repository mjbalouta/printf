# Printf
## Implementation of the <stdio.h> printf function

This project's purpose is understand how the original printf function works and to reproduce its behaviour. (Another function to be added to our Libft project for future implementations).

### How to use:
1) Inside your project's directory: `git clone https://github.com/mjbalouta/printf.git`
2) Add a rule to your makefile to compile it with your program:
```
$(PRINTF): $(PRINTF_SRC)
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF) $(OBJS)
	(...)
```
3) And you should already be able to use these functions in your own code!

### Notes from my Notebook:

The requirements for this project were to handle the conversions **cspdiuxX%**:

- **%c**: prints a single character;
- **%s**: prints a string;
- **%p**: the void* pointer argument has to be printed in hexadecimal format;
- **%d**: prints a decimal number (base 10);
- **%i**: prints an integer in base 10;
- **%u**: prints an unsigned decimal number (base 10);
- **%x**: prints a number in hexadecimal (base 16) lowercase format;
- **%X**: prints a number in hexadecimal (base 16) uppercase format;
- **%%**: prints the % sign.

The prototype for this function is `int ft_printf(const char *, ...);`

The ... parameter represents an undefined number of parameters, and, to understand this, you'll have to take a look at **Variadic Functions**:

1) `va_start` initializes a va_list to start accessing the variadic arguments (...):
```
va_start (va_list ap, last_fixed_arg);
```
- va_list ap: holds the info needed to retrieve the variadic arguments;
- last_fixed_arg: last fixed argument before the variadic arguments (the string that indicates the format). The va_start functions needs this parameter to know where to begin reading the unnamed (...) arguments in memory - without it, the compiler can't safely find or access the variadic arguments.

2) `va_arg` access the next variadic argument in the list:
```
type va_arg(va_list ap, type);
```
- va_list ap: initialized by va_start;
- type: the type of argument you want to extract.

3) `va_copy` creates a copy of a va_list to be used independently without affecting the original va_list:
```
va_copy(va_list dest, va_list src);
```
- va_list dest: the va_list to copy the contents to;
- va_list src: the original va_list to copy from.

4) `va_end` cleans up the va_list when you're done using it:

```
va_end(va_list ap);
```
- va_list ap: the va_list you used for accessing the variadic arguments.
- *You must call va_end before your function exits to prevent memory leaks or undefined behaviour!*


