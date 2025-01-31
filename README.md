# ft_printf

`ft_printf` is a custom implementation of the standard printf function in C. This project is part of the **42 curriculum** and aims to replicate the functionality of `printf`, handling various format specifiers and different data types.

## 📁 Project Structure
This project follows a simple structure with all source files in the root directory:

 - `ft_printf.h` – Header file containing function prototypes and necessary includes.
 - `ft_printf.c` – Core implementation of `ft_printf`, handling format specifiers.
 - `ft_printf_utils.c` – Utility functions for character and string output.
 - `ft_printf_hexas.c` – Functions for hexadecimal number formatting.
 - `wraps_utils.c` – Wrappers for handling different argument types.
 - `wraps_hexas.c` – Wrappers for hexadecimal formatting.
 - `Makefile` – Compilation rules to generate `libftprintf.a`.

## 📌 Implemented Functions
The functions in this project are categorized based on their logical role:

| Category | Functions |
|---------|-----------|
|Core Functionality|`ft_printf`, `handle_case`, `init_cases`.|
|Output Functions|`ft_putchar`, `ft_putstr`, `putnbr`, `putnbr_u`, `ft_putptr`, `puthexa`.|
|Wrapper Functions|`wrap_char`, `wrap_str`, `wrap_int`, `wrap_uint`, `wrap_ptr`, `wrap_hex_low`, `wrap_hex_up`.|

## ⚙️ Compilation and Usage
### Requirements
 - GCC or another compatible C compiler.
 - UNIX/Linux system recommended (tested in the 42 São Paulo environment).
### Available Commands
Use the `Makefile` to compile and manage the project:

| Command | Description |
|---------|-----------|
|`make`|Compiles the static library (`libftprintf.a`).|
|`make clean`|Removes object files (`.o`).|
|`make fclean`|Remmoves obj files and the compiled library (`libft.a`).|
|`make re`|Recompiles everything from scratch.|

### How to Use
 1. Compile the library using `make`.
 2. Include the `ft_printf.h` header in your project.
 3. Link the `libftprintf.a` library when compiling your program:
``` bash
gcc -Wall -Wextra -Werror -I . -L . -lftprintf main.c
```

## 🎓 Key Learnings (author's notes)
This project follows a simple structure with all source files in the root directory:

 - **Variadic Functions** (`stdarg.h`): I deepened my understanding of handling functions with a variable number of arguments, allowing greater flexibility in implementing `ft_printf`.
 - **Linked Lists & "Wildcard Functions"**: In an effort to strengthen my grasp of linked lists, I applied this structure in the project, which led me to explore generic functions (wich I like to call "wildcard functions") to make the code more versatile and modular.
 - **Function Pointers**: Although I had briefly encountered function pointers while developing my `libft`, this was the first time I actively applied them in a real project. Their use proved extremely valuable in making printf's structure more dynamic and efficient.
 - **Wrappers, Modularization & Abstraction**: Diving deeper into wrappers using function pointers led me to explore the importance of modularization and abstraction. I learned how to better segment my code to enhance organization, reusability, and maintainability.

## 👩‍💻 Author
This project was developed by Luiza Kormann (lukorman@student.42.fr) as part of the 42 São Paulo curriculum.
