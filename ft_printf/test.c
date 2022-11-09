#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

void	ft2(va_list args)
{
	int	b = va_arg(args, int);
	printf("%d\n", b);
}

void	ft(char *str, ...)
{
	va_list	args;

	va_start(args, str);
	ft2(args);
	ft2(args);
	ft2(args);
}

int	main(int argc, char **argv)
{
	unsigned long	n;
	int				r1;
	int				r2;
	char			*test;

	n = 48;
	test = ft_strdup("test '\% o' %s\n");
	r1 = ft_printf("test: %+s'\n", -1);
	r2 = printf("test: %+s\n", -1);
	printf("%d\n%d\n", r1, r2);
	free(test);
	//printf("X:'%05x'\n", n);
//	printf("p:'%0-5d'\n", n);
//	printf("x:'%0-5x'\n", n);
//	printf("s:'%05s'\n", "t");
}
