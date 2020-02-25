#####     FT_PRINTF

<h2>Mandatory part:</h2>

* Manage the following conversions: `s`, `p`, `d`, `i`, `o`, `u`, `x`, `X` & `c` 
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+` & `space`
* Manage the minimum field-width
* Manage the precision
* Manage the flags `hh`, `h`, `l`, `ll`, & `L`.


<h2>Flags:</h2>
<b>\#0-+ and space</b>
<table>
  <tr>
    <td>-</td>
    <td>Left-justify within the given field width; Right justification is the default (see width sub-specifier).</td>
  </tr>
  <tr>
    <td>+</td>
    <td>Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.</td>
  </tr>
  <tr>
    <td>(space)</td>
    <td>If no sign is going to be written, a blank space is inserted before the value.</td>
  </tr>
  <tr>
    <td>#</td>
    <td>Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).</td>
  </tr>
</table>

<h2>Length sub-specifier:</h2>
<table>
  <tr>
    <td><b>length</b></td>
    <td><b>d i</b></td>
    <td><b>u o x X</b></td>
    <td><b>f F e E g G a A</b></td>
    <td><b>c</b></td>
    <td><b>s</b></td>
    <td><b>p</b></td>
  </tr>
  <tr>
    <td>hh</td>
    <td>int</td>
    <td>unsigned int</td>
    <td>double</td>
    <td>int</td>
    <td>char*</td>
    <td>void*</td>
  <tr>
    <td>h</td>
    <td>short int</td>
    <td>unsigned short int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>l</td>
    <td>long int</td>
    <td>unsigned long int</td>
    <td></td>
    <td>wint_t</td>
    <td>wchar_t*</td>
    <td></td>
  </tr>
  <tr>
    <td>ll</td>
    <td>long long int</td>
    <td>unsigned long long int</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>j</td>
    <td>intmax_t</td>
    <td>uintmax_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>z</td>
    <td>size_t</td>
    <td>size_t</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>L</td>
    <td></td>
    <td></td>
    <td>long double	</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>

<h2>Links:</h2>
1. https://stackoverflow.com/questions/1449805/how-to-format-a-number-from-1123456789-to-1-123-456-789-in-c
2. http://www.cplusplus.com/reference/cstdio/printf/
3. https://linux.die.net/man/3/stdarg
