#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *str, ...);

int main()
{
	char *s = "Salut";
	int i = 159;
	int x = 42;
	int res1;
	int res2;

	res1 = ft_printf("ft_printf == |%s, %d, %x|\n", s, i, x);
	res2 = printf("   printf == |%s, %d, %x|\n", s, i, x);

	printf("res1 == %d\nres2 == %d\n", res1, res2);

	i = 0;
	x = 0;
	s = 0;
	res1 = ft_printf("ft_printf == |%s, %d, %x|\n", s, i, x);
	res2 = printf("   printf == |%s, %d, %x|\n", s, i, x);

	printf("res1 == %d\nres2 == %d\n", res1, res2);
	
	i = INT_MAX;
	x = INT_MAX;
	s = "%max%";
	res1 = ft_printf("ft_printf == |%s, %d, %x|\n", s, i, x);
	res2 = printf("   printf == |%s, %d, %x|\n", s, i, x);

	printf("res1 == %d\nres2 == %d\n", res1, res2);
	
	i = INT_MIN;
	x = INT_MIN;
	s = "%min%";
	res1 = ft_printf("ft_printf == |%s, %d, %x|\n", s, i, x);
	res2 = printf("   printf == |%s, %d, %x|\n", s, i, x);

	printf("res1 == %d\nres2 == %d\n", res1, res2);
	
	i = -200;
	x = 200;
	s = "%neg%";
	res1 = ft_printf("ft_printf == |%s, %d, %x|\n", s, i, x);
	res2 = printf("   printf == |%s, %d, %x|\n", s, i, x);

	printf("res1 == %d\nres2 == %d\n", res1, res2);
	return 0;
}
