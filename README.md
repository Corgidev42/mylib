# MyLib42 🛠️

## Your C Toolbox 🎓

MyLib42 is a personal C library developed during my studies at 42. It gathers essential utility functions implemented from scratch, meant to be reused across various projects. The library is designed to comply with **Norminette** standards, ensuring clean and maintainable code.

## 💡 Objectives

- **Learning:** Strengthen understanding of core C concepts.
- **Reusability:** Have a reliable toolkit for future projects.
- **Practical Use:** Serve as a foundation throughout my development journey.

## 🔧 Key Features

### 1. Character Type Functions
- `ft_isalpha` ✨ - Check if a character is alphabetic.
- `ft_isdigit` 0 - Check if a character is numeric.
- `ft_isalnum` 🅐 - Check if a character is alphanumeric.
- `ft_isascii` 🌐 - Check if a character is part of the ASCII table.
- `ft_isprint` 💮 - Check if a character is printable.
- `ft_toupper` ↑ - Convert a character to uppercase.
- `ft_tolower` ↓ - Convert a character to lowercase.

### 2. String Functions
- `ft_strlen` 💡 - Get string length.
- `ft_strlcpy` 🎨 - Copy a string with size limit.
- `ft_strlcat` 💣 - Concatenate strings with size limit.
- `ft_strnchr` 🔍 - Locate a character within `n` characters.
- `ft_strchr` 🔎 - Locate the first occurrence of a character.
- `ft_strrchr` 🔄 - Locate the last occurrence of a character.
- `ft_strcmp` 🗒️ - Compare two strings.
- `ft_strncmp` - Compare two strings up to `n` characters.
- `ft_strndup` -
- `ft_strncat` - 
- `ft_strnstr` 💧 - Find a substring with length limit.
- `ft_strdup` 💾 - Duplicate a string.
- `ft_substr` - Extract a substring.
- `ft_strjoin` ➕ - Join two strings.
- `ft_strtrim` 🧰 - Trim characters from both ends.
- `ft_split` 💮 - Split a string.
- `ft_strmapi` - Apply a function to each character to create a new string.
- `ft_striteri` - Apply a function to each character in place.

### 3. Number Functions
- `ft_long_size` 📊 - Get the size of a long integer.
- `ft_int_size` - Get the size of an integer.

### 4. Conversion Functions
- `ft_atoi` 💰 - Convert a string to an integer.
- `ft_itoa` - Convert an integer to a string.
- `ft_litoa` - Convert a long integer to a string.

### 5. Memory Functions
- `ft_memset` 🛠️ - Fill memory with a byte.
- `ft_bzero` - Zero out memory.
- `ft_memcpy` 💡 - Copy memory.
- `ft_memmove` - Move memory safely.
- `ft_memchr` 🔍 - Locate a byte in memory.
- `ft_memcmp` - Compare memory blocks.
- `ft_calloc` 📦 - Allocate and zero memory.
- `ft_realloc` - Reallocate memory.

### 6. Input/Output Functions
- `ft_putchar_fd` 🔊 - Output a character.
- `ft_putstr_fd` - Output a string.
- `ft_putendl_fd` - Output a string with newline.
- `ft_putnbr_fd` - Output a number.

### 7. Printf Utility 💨
- `ft_printf` - Format and print output.
- Supports:
  - Characters (`%c`)
  - Strings (`%s`)
  - Pointers (`%p`)
  - Integers (`%d`/`%i`)
  - Unsigned integers (`%u`)
  - Hexadecimals (`%x`/`%X`)
- Additional:
  - Width, precision, and flag support (`-`, `+`, `#`, `0`, space).

## 📈 Benefits
- Saves development time with pre-tested, reusable components.
- Reduces bugs by relying on validated functions.
- Compliant with 42's Norminette standards.

## 💡 Technologies Used
- **Language:** C
- **Tools:** Makefile, Norminette, Unit tests

## 🗃️ Deliverables
- Organized `.c` and `.h` files.
- Documentation for each function.
- Unit tests for reliability.

---
**EnV Team** – by Vincent and Even

*Ready to code 🚀*

