CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# CATEGORY SOURCES
SRC_CHAR =	src/char/ft_isalnum.c\
			src/char/ft_isalpha.c\
			src/char/ft_isascii.c\
			src/char/ft_isdigit.c\
			src/char/ft_isprint.c\
			src/char/ft_tolower.c\
			src/char/ft_toupper.c

SRC_STRING =	src/string/ft_split.c\
				src/string/ft_strchr.c\
				src/string/ft_strdup.c\
				src/string/ft_striteri.c\
				src/string/ft_strjoin.c\
				src/string/ft_strlcat.c\
				src/string/ft_strlcpy.c\
				src/string/ft_strlen.c\
				src/string/ft_strmapi.c\
				src/string/ft_strncmp.c\
				src/string/ft_strnstr.c\
				src/string/ft_strrchr.c\
				src/string/ft_strtrim.c\
				src/string/ft_substr.c

SRC_MEMORY =	src/memory/ft_bzero.c\
				src/memory/ft_calloc.c\
				src/memory/ft_memchr.c\
				src/memory/ft_memcmp.c\
				src/memory/ft_memcpy.c\
				src/memory/ft_memmove.c\
				src/memory/ft_memset.c

SRC_NUMBER =	src/number/ft_long_size.c

SRC_CAST =	src/cast/ft_atoi.c\
					src/cast/ft_itoa.c\

SRC_PUT =	src/put/ft_putchar_fd.c\
			src/put/ft_putendl_fd.c\
			src/put/ft_putnbr_fd.c\
			src/put/ft_putstr_fd.c

SRC_PRINTF =	src/printf/format.c\
				src/printf/formatted_flags.c\
				src/printf/ft_printf.c\
				src/printf/print.c\
				src/printf/print1.c\
				src/printf/utils1.c

# ALL SOURCES
SRC = $(SRC_CHAR) $(SRC_STRING) $(SRC_MEMORY) $(SRC_NUMBER) $(SRC_CAST) $(SRC_PUT) $(SRC_PRINTF)

# OBJECTS OF SOURCES
OBJ = $(SRC:.c=.o)

# LIB NAME
TARGET = lib/libft.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
