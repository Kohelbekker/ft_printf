#include <libc.h>

int main () {


	///////////// +-0' ' format  values //////////
	//
	printf("\n-----------------------------------\n");
	printf("%%+d:  '%+d'\n", 123);
	printf("%%+d:  '%+d'\n", -123);
	printf("%%6d:  '%6d'\n", 123);
	printf("%%-6d:  '%-6d'\n", 123);
	printf("%%-6d:  '%-6d'\n", -123);
	printf("%%06d:  '%06d'\n", 123);
	printf("%%06d:  '%06d'\n", -123);
	printf("%%+05d:  '%+05d'\n", 10);
	printf("%%0+5d:  '%0+5d'\n", 10);
	printf("%%-+5d: '%-+5d'\n", 10); // flag 0 is ignored when -(minus) is present
	printf("%%08.2f: '%08.2f'\n", 10.3456);	//Eight-wide, two positions after the decimal, zero-filled
	printf("%% d:     '% d'\n", 1234);
	printf("%% d:     '% d'\n", -1234);
	printf("%% +d:    '%+d'\n", 1234);
	printf("%%    d:     '%    d'\n", 1234);
	printf("%%    d:     '%    d'\n", -1234);
	printf("%%.6d:  '%.6d'\n", 123);
	printf("%%.6d:  '%.6d'\n", -123);
	printf("%%.6d:  '%.6d'//12345678\n", 12345678);
	printf("%%.06d:  '%.06d'\n", 123);
	printf("%%8.10d: '%8.10d'\n", 12345);
	printf("%.0d", 123);
	//////////////////////////


	////////////// # and * format values ////////////////
	printf("\n-----------------------------------\n");
	printf("x = %x//1234  \nX = %X//1234  \no = %o//1234  \nu = %u//1234\n", 1234, 1234, 1234, 1234);
	printf("\n-----------------------------------\n");
	printf("'#x = %#x//1234  \n#X = %#X//1234  \n#o = %#o//1234'\n", 1234, 1234, 1234);
	printf("\n-----------------------------------\n");
	printf("%%*d: 	'%*d'\n", 8, 12345);
	printf("%%.10d: '%.10d'\n", 98765);
	printf("%%.*X: 	'%.*X'\n", 10, 56565);
	printf("\n-----------------------------------\n");
	//////////////////////////////////////////////////////

	//////////// FLAGS ////////////////
	//	- Left-justify within the given field width; Right justification is the default (see width sub-specifier).
	//
	// 	+ Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers
	// 	   By default, only negative numbers are preceded with a - sign.
	//
	//	(space)  If no sign is going to be written, a blank space is inserted before the value.
	//
	//	*  Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero
	//	   Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more
	//	   digits follow. By default, if no digits follow, no decimal point is written.
	//
	//	0  	Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
	//
	//
	//
	//
	/////////////////////////////////
}
