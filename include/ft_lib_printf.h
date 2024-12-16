#ifndef FT_LIB_PRINTF_H
# define FT_LIB_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Boolean
# define FALSE 0
# define TRUE 1

// Flags
# define FLAG_MINUS '-'
# define FLAG_PLUS '+'
# define FLAG_SPACE ' '
# define FLAG_HASH '#'
# define FLAG_ZERO '0'

typedef struct s_format
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		flag_zero;
	int		width;
	int		precision;
	char	specifier;
}			t_format;

int			ft_printf(const char *format, ...);

t_format	*init_format(const char **ptr);

int			ft_putchar_size(char c);
int			ft_putstr_size(char *str);
char		*convert_to_hexa(unsigned long long nb, char *base);

int			print_c(t_format *format, char c);
int			print_s(t_format *format, char *str);
int			print_p(t_format *format, void *ptr);
int			print_d_i(t_format *format, int nb);
int			print_u(t_format *format, unsigned int nb);
int			print_x(t_format *format, unsigned long nb, int is_upper);

char		*formatted_width_minus_zero(char *str, int width, int has_minus,
				int has_zero);
char		*formatted_number_precision(char *str, int precision, int has_plus,
				int has_space);

#endif
