#include <stdio.h>

int	main () {
	// char *str;
	// int		a;
	// int		p;

	// p = 12;
	// printf("\n-----------------------------------\n");
	// printf("%%    d:     '%    d'\n", 1234);
	// printf("%%    d:     '%    d'\n", -1234);
	// printf("%% d:     '% d'\n", 1234);
	// printf("%% d:     '% d'\n", -1234);
	// printf("%% +d:    '%+d'\n", 1234);
	// printf("%%+d:  '%+d'\n", 123);
	// printf("%%+d:  '%+d'\n", -123);
	// printf("%%6d:  '%6d'\n", 123);
	// printf("%%-6d:  '%-6d'\n", 123);
	// printf("%%-6d:  '%-6d'\n", -123);
	// printf("%%06d:  '%06d'\n", 123);
	// printf("%%06d:  '%06d'\n", -123);
	// printf("%%+05d:  '%+05d'\n", 10);
	// printf("%%0+5d:  '%0+5d'\n", 10);
	// printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
	// printf("%%.1d:  '%.1d'\n", 123);
	// printf("%%.6d:  '%.6d'\n", -123);
	// printf("%%.6d:  '%.6d'//12345678\n", 12345678);
	// printf("%%.06d:  '%.06d'\n", 123);
	// printf("%%.6d:  '%.6d'\n", 123);
	// printf("%%8.10d: '%8.10d'\n", 12345);
	// printf("%%8.10d: '%8.10d'\n", 12345);

	// ft_printf("\n-----------------------------------\n");
	// ft_printf("%%    d:     '%    d'\n", 1234);
	// ft_printf("%%    d:     '%    d'\n", -1234);
	// ft_printf("%% d:     '% d'\n", 1234);
	// ft_printf("%% d:     '% d'\n", -1234);
	// ft_printf("%% +d:    '%+d'\n", 1234);
	// ft_printf("%%+d:  '%+d'\n", 123);
	// ft_printf("%%+d:  '%+d'\n", -123);
	// ft_printf("%%6d:  '%6d'\n", 123);
	// ft_printf("%%-6d:  '%-6d'\n", 123);
	// ft_printf("%%-6d:  '%-6d'\n", -123);
	// ft_printf("%%06d:  '%06d'\n", 123);
	// ft_printf("%%06d:  '%06d'\n", -123);
	// ft_printf("%%+05d:  '%+05d'\n", 10);
	// ft_printf("%%0+5d:  '%0+5d'\n", 10);
	// ft_printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
	// ft_printf("%%.1d:  '%.1d'\n", 123);
	// ft_printf("%%.6d:  '%.6d'\n", -123);
	// ft_printf("%%.6d:  '%.6d'//12345678\n", 12345678);
	// ft_printf("%%.06d:  '%.06d'\n", 123);
	// ft_printf("%%.6d:  '%.6d'\n", 123);
	// ft_printf("%%8.10d: '%8.10d'\n", 12345);
	// ft_printf("%%8.10d: '%8.10d'\n", 12345);
	// ft_printf("x = %x//1234  \nX = %X//1234  \no = %o//1234  \nu = %u//1234\n", 1234, 1234, 1234, 1234);
	//ft_printf("\n-----------------------------------\n");


//   ft_printf("%#x", 0);
// 	printf("\n");
//   ft_printf("%#08x", 42);
// printf("\n");
//   ft_printf("@moulitest: `%#.x` `%#.0x`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%.x` `%.0x`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%5.x` `%5.0x`", 0, 0);
// printf("\n");
//   ft_printf("%10s is a string", "this");
// printf("\n");
//   ft_printf("%5.2s is a string", "this");
// printf("\n");
//   ft_printf("%10s is a string", "");
// printf("\n");
//   ft_printf("%5.2s is a string", "");
// printf("\n");
//   ft_printf("%-10s is a string", "this");
// printf("\n");
//   ft_printf("%-5.2s is a string", "this");
// printf("\n");
//   ft_printf("%-10s is a string", "");
// printf("\n");
//   ft_printf("%-5.2s is a string", "");
// printf("\n");
//  ft_printf("`%.2c`", NULL);
// printf("\n");
//   printf("`%10.2c`", NULL);
// printf("\n");
//   ft_printf("`%c`", 42);
// printf("\n");
//   ft_printf("`%5c`", 42);
// printf("\n");
//   ft_printf("`%-5c`", 42);
// printf("\n");
//   ft_printf("@moulitest: `%c`", 0);
// printf("\n");
//   ft_printf("`%2c`", 0);
// printf("\n");
//   ft_printf("null `%c` and text", 0);
// printf("\n");
//   ft_printf("`% c`", 0);
// printf("\n");
//   ft_printf("@moulitest: `%.o` `%.0o`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%5.o` `%5.0o`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%#.o` `%#.0o`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%#.x` `%#.0x`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%.x` `%.0x`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%5.x` `%5.0x`", 0, 0);
// printf("\n");
//   ft_printf("`%+d`", 0);
// printf("\n");
//   ft_printf("%lld", -9223372036854775808);
// printf("\n");
//   ft_printf("`%10.5d`", 4242);
// printf("\n");
//   ft_printf("`%-10.5d`", 4242);
// printf("\n");
//   ft_printf("`% 10.5d`", 4242);
// printf("\n");
//   ft_printf("`%+10.5d`", 4242);
// printf("\n");
//   ft_printf("`%-+10.5d`", 4242);
// printf("\n");
//   ft_printf("@moulitest: `%.d` `%.0d`", 0, 0);
// printf("\n");
//   ft_printf("@moulitest: `%05.d` `%5.0d`", 0, 0);
// printf("\n");


ft_printf("%k\n");
ft_printf("%t\n");
ft_printf("`%#08x`\n", 42);
printf("`%#08x`\n", 42);


//////////////////////// UNDEFINED//////////////////////
// printf("\n");
//   printf("`%`");
// printf("\n");
// 	ft_printf("`%`");
// printf("\n---------------\n");
//   printf("`% `");
// printf("\n");
//  ft_printf("`% `");
// printf("\n---------------\n");
//   printf("`% h`");
// printf("\n");
// 	ft_printf("`% h`");
// printf("\n---------------\n");
//   printf("`%Z`");
// printf("\n");
// 	ft_printf("`%Z`");
// printf("\n---------------\n");
//   printf("`% hZ`");
// printf("\n");
// ft_printf("`% hZ`");
// printf("\n---------------\n");
//   printf("`% hZ%`");
// printf("\n");
// ft_printf("`% hZ%`");
// printf("\n---------------\n");
//   printf("`% Z`", "test");
// printf("\n");
// 	ft_printf("`% Z`", "test");
// printf("\n---------------\n");
//   printf("`% Z `", "test");
// printf("\n");
// 	ft_printf("`% Z `", "test");
// printf("\n---------------\n");
//   printf("`% h%s`", "test");
// printf("\n");
//  ft_printf("`% h%s`", "test");
// printf("\n---------------\n");
//   printf("`%%%`", "test");
// printf("\n");
// 	ft_printf("`%%%`", "test");
// printf("\n---------------\n");
//   printf("`%%   %`", "test");
// printf("\n");
// 	ft_printf("`%%   %`", "test");
// printf("\n---------------\n");
//   printf("`%x`", 4294967295);
// printf("\n");
//   ft_printf("`%x`", 4294967295);
// printf("\n---------------\n");
//   printf("`%x`", 4294967296);
// printf("\n");
//   ft_printf("`%x`", 4294967296);
// printf("\n---------------\n");
//   printf("`%x`", -4294967296);
// printf("\n");
// 	ft_printf("`%x`", -4294967296);
// printf("\n---------------\n");
//   printf("`%x`", -4294967297);
// printf("\n");
// 	ft_printf("`%x`", -4294967297);
// printf("\n---------------\n");
//   printf("`%ll#x`", 9223372036854775807);
// printf("\n");
//  	ft_printf("`%ll#x`", 9223372036854775807);
// printf("\n---------------\n");
//   printf("`%010s is a string`", "this");
// printf("\n");
// 	ft_printf("`%010s is a string`", "this");
// printf("\n---------------\n");
//   printf("`%05c`", 42);
// printf("\n");
//   ft_printf("`%05c`", 42);
// printf("\n---------------\n");
//   printf("`% Z`", 42);
// printf("\n");
//   ft_printf("`% Z`", 42);
// printf("\n---------------\n");
//   printf("`%5+d`", 42);
// printf("\n");
// 	ft_printf("`%5+d`", 42);
// printf("\n---------------\n");
//   printf("`%5+d`", -42);
// printf("\n");
// 	ft_printf("`%5+d`", -42);
// printf("\n---------------\n");
//   printf("`%-5+d`", 42);
// printf("\n");
// 	ft_printf("`%-5+d`", 42);
// printf("\n---------------\n");
//   printf("`%-5+d`", -42);
// printf("\n");
// 	ft_printf("`%-5+d`", -42);
// printf("\n---------------\n");
//   printf("`%jd`", 9223372036854775807);
// printf("\n");
// 	ft_printf("`%jd`", 9223372036854775807);
// printf("\n---------------\n");
//   printf("`%jd`", -9223372036854775808);
// printf("\n");
// 	ft_printf("`%jd`", -9223372036854775808);
// printf("\n---------------\n");
//   printf("`%zd`", 4294967295);
// printf("\n");
// 	ft_printf("`%zd`", 4294967295);
// printf("\n---------------\n");
//   printf("`%zd`", 4294967296);
// printf("\n");
// 	ft_printf("`%zd`", 4294967296);
// printf("\n---------------\n");
//   printf("`%zd`", -0);
// printf("\n");
// 	ft_printf("`%zd`", -0);
// printf("\n---------------\n");
//   printf("`%zd`", -1);
// printf("\n");
// 	ft_printf("`%zd`", -1);
// printf("\n---------------\n");
//   printf("`%ju`", 4999999999);
// printf("\n");
// 	ft_printf("`%ju`", 4999999999);
// printf("\n---------------\n");
//   printf("`%ju`", 4294967296);
// printf("\n");
// 	ft_printf("`%ju`", 4294967296);
// printf("\n---------------\n");
//   printf("`%U`", 4294967295);
// printf("\n");
// 	ft_printf("`%U`", 4294967295);
// printf("\n---------------\n");
//   printf("`%hU`", 4294967296);
// printf("\n");
// 	ft_printf("`%hU`", 4294967296);
// printf("\n---------------\n");
//   printf("`%U`", 4294967296);
// printf("\n");
// 	ft_printf("`%U`", 4294967296);
// printf("\n---------------\n");
//   printf("`%zhd`", 4294967296);
// printf("\n");
// 	ft_printf("`%zhd`", 4294967296);
// printf("\n---------------\n");
//   printf("`%jzd`", 9223372036854775807);
// printf("\n");
// 	ft_printf("`%jzd`", 9223372036854775807);
// printf("\n---------------\n");
//   printf("`%jhd`", 9223372036854775807);
// printf("\n");
// 	ft_printf("`%jhd`", 9223372036854775807);
// printf("\n---------------\n");
//   printf("`%lhl`", 9223372036854775807);
// printf("\n");
// 	ft_printf("`%lhl`", 9223372036854775807);
// printf("\n---------------\n");
//   printf("`%lhlz`", 9223372036854775807);
// printf("\n");
// 	ft_printf("`%lhlz`", 9223372036854775807);
// printf("\n---------------\n");


printf("\n");

	// printf("%%x = %x//1234  \n%%X = %X//1234  \n%%o = %o//1234  \n%%u = %u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: %%x = %x//1234  \nX = %X//1234  \no = %o//1234  \nu = %u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%010x = %010x//1234  \n%%010X = %010X//1234  \n%%010o = %010o//1234  \n%%010u = %010u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: %%010x = %010x//1234  \n%%010X= %010X//1234  \n%%010o = %010o//1234  \n%%010u = %010u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%#010.1x = '%#010.1x'//1234  \n%%#010.12X = '%#010.12X'//1234  \n%%#010x = '%#010o'//1234  \n%%#010.4u = '%#010.4u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: \n%%#010.1x = '%#010.1x'//1234  \n%%#010.12X = '%#010.12X'//1234  \n%%#010x = '%#010o'//1234  \n%%#010.4u = '%#010.4u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%#010.8x = '%#010.8x'//1234  \n%%#010.8X = '%#010.8X'//1234  \n%%#010.8o = '%#010.8o'//1234  \n%%#010.8u = '%#010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: \n%%#010.8x = '%#010.8x'//1234  \n%%#010.8X = '%#010.8X'//1234  \n%%#010.8o = '%#010.8o'//1234  \n%%#010.8u = '%#010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%010.8x = '%010.8x'//1234  \n%%010.8X = '%010.8X'//1234  \n%%010.8o = '%010.8o'//1234  \n%%010.8u = '%010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: \n%%010.8x = '%010.8x'//1234  \n%%010.8X = '%010.8X'//1234  \n%%010.8o = '%010.8o'//1234  \n%%010.8u = '%010.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%10.8x = '%10.8x'//1234  \n%%10.8X = '%10.8X'//1234  \n%%10.8o = '%10.8o'//1234  \n%%10.8u = '%10.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: \n%%10.8x = '%10.8x'//1234  \n%%10.8X = '%10.8X'//1234  \n%%10.8o = '%10.8o'//1234  \n%%10.8u = '%10.8u'//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%010.14x = %010.14x//1234  \n%%010.14X = %010.14X//1234  \n%%010.14o = %010.14o//1234  \n%%010.14u = %010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: %%010.14x = %010.14x//1234  \n%%010.14X = %010.14X//1234  \n%%010.14o = %010.14o//1234  \n%%010.14u = %010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("%%#010.14x = %#010.14x//1234  \n%%#010.14X= %#010.14X//1234  \n%%#010.14o = %#010.14o//1234  \n%%#010.14u = %#010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// ft_printf("FT: %%#010.14x = %#010.14x//1234  \n%%#010.14X = %#010.14X//1234  \n%%#010.14o = %#010.14o//1234  \n%%#010.14u = %#010.14u//1234\n\n\n", 1234, 1234, 1234, 1234);
	// printf("\n-----------------------------------\n");
	// printf("'#x = %#x//1234  \n#X = %#X//1234  \n#o = %#o//1234'\n", 1234, 1234, 1234);
	// printf("%%p: %p\n", &p);
	// ft_printf("'#x = %#x//1234  \n#X = %#X//1234  \n#o = %#o//1234'\n", 1234, 1234, 1234);
	// ft_printf("%%p: %p\n", &p);
	// printf("%010.8d", 1234);
	// ft_printf("%010.8d", 1234);
	return (0);
}