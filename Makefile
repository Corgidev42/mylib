CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# CATEGORY SOURCES
SRC_CONVERSION =	src/conversion/ft_atoi.c\
					src/conversion/ft_itoa.c\
					src/conversion/ft_litoa.c

SRC_CTYPE =	src/ctype/ft_isalnum.c\
			src/ctype/ft_isalpha.c\
			src/ctype/ft_isascii.c\
			src/ctype/ft_isdigit.c\
			src/ctype/ft_isprint.c\
			src/ctype/ft_tolower.c\
			src/ctype/ft_toupper.c

SRC_IO =	src/io/ft_putchar_fd.c\
			src/io/ft_putendl_fd.c\
			src/io/ft_putnbr_fd.c\
			src/io/ft_putstr_fd.c

SRC_LIST =		src/list/ft_lstadd_back.c \
				src/list/ft_lstadd_front.c \
				src/list/ft_lstclear.c \
				src/list/ft_lstdelone.c \
				src/list/ft_lstiter.c \
				src/list/ft_lstlast.c \
				src/list/ft_lstmap.c \
				src/list/ft_lstnew.c \
				src/list/ft_lstsize.c

SRC_MEMORY =	src/memory/ft_bzero.c\
				src/memory/ft_calloc.c\
				src/memory/ft_memchr.c\
				src/memory/ft_memcmp.c\
				src/memory/ft_memcpy.c\
				src/memory/ft_memmove.c\
				src/memory/ft_memset.c\
				src/memory/ft_realloc.c

SRC_NUMBER =	src/number/ft_long_size.c\
				src/number/ft_int_size.c

SRC_STRING =	src/string/ft_split.c\
				src/string/ft_strchr.c\
				src/string/ft_strnchr.c\
				src/string/ft_strdup.c\
				src/string/ft_striteri.c\
				src/string/ft_strjoin.c\
				src/string/ft_strlcat.c\
				src/string/ft_strlcpy.c\
				src/string/ft_strndup.c\
				src/string/ft_strncpy.c\
				src/string/ft_strlen.c\
				src/string/ft_strmapi.c\
				src/string/ft_strcmp.c\
				src/string/ft_strncmp.c\
				src/string/ft_strnstr.c\
				src/string/ft_strrchr.c\
				src/string/ft_strtrim.c\
				src/string/ft_substr.c

SRC_PRINTF =	src/printf/format.c\
				src/printf/formatted_flags.c\
				src/printf/ft_printf.c\
				src/printf/print.c\
				src/printf/print1.c\
				src/printf/utils1.c

# ALL SOURCES
SRC = $(SRC_CTYPE) $(SRC_STRING) $(SRC_MEMORY) $(SRC_NUMBER) $(SRC_CONVERSION) $(SRC_IO) $(SRC_PRINTF) $(SRC_LIST)

# OBJECTS OF SOURCES
OBJ = $(SRC:.c=.o)

# LIB NAME
TARGET = lib/libft.a

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p $(dir $(TARGET))
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf lib

re: fclean all

.PHONY: all clean fclean re
