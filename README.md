# ALX Software Engineering Custom Function Team Project

This team project focuses on creating a custom function for the C programming language named `custom_printf`. Designed to mimic the functionality of the standard `printf` function while optimizing performance and flexibility, this custom implementation has been developed as part of the ALX software engineering course requirements.

## Overview

The `custom_printf()` function is designed to output formatted data to the standard output stream (stdout) without relying on any standard library functions. It utilizes a local buffer of 1024 bytes for printing, capable of handling large datasets efficiently.

Upon successful execution, `custom_printf()` returns the total count of characters printed to stdout, excluding the null byte at the end of strings. In cases where an output error occurs, the function returns a negative value of -1.

The function prototype is defined as: **int custom_printf(const char *format, ...);**

This indicates that the function accepts one mandatory format argument and an unspecified number of additional arguments.

### Formatting String Details

The formatting string is a sequence of characters enclosed within double quotes. It consists of zero or more directives, including ordinary characters (non-% characters) and conversion specifications. Each directive instructs the function to fetch and process subsequent arguments accordingly.

Conversion specifications begin with the '%' character and conclude with a conversion specifier. Between these markers, the following elements may appear in sequence:

- Zero or more flags
- An optional field width
- An optional precision modifier
- An optional length modifier

#### Flags

| Flag | Description |
|------|-------------|
| **#** | Prefixes the output of 'o', 'x', and 'X' conversions with '0'. Adds '0x' or '0X' for nonzero outputs. |
| **0** | (Not Implemented) Pads numeric values with leading zeros. Ignored if combined with '-' or if precision is specified. |
| **-** | (Not Implemented) Left-aligns the output, padding with spaces on the right. Overrides '0' if both are set. |
| `' '` | Pads positive numbers or empty strings with a space. |
| **+** | Ensures a sign (+ or -) precedes all numeric outputs, except for positive numbers. |

#### Field Width

Specifies a minimum field width for the output. If the actual output is shorter than the specified width, it is padded with spaces (left-aligned if '-' is not set, right-aligned otherwise). A '*' can replace the numeric value, indicating that the next argument specifies the width.

Example:
```c
printf("%5d", num);
// or
printf("%*d", width, num);
```

#### Precision

Indicates the minimum number of digits for numeric conversions or the maximum number of characters for string conversions. Negative precision is treated as if omitted. A '*' can replace the numeric value, indicating that the next argument specifies the precision.

Example:
```c
printf("%.3d", num);
// or
printf("%.*d", precision, num);
```

#### Length Modifiers

| Modifier | Description |
|----------|-------------|
| **l** | Converts integers to long int or unsigned long int. |
| **h** | Converts integers to short int or unsigned short int. |

#### Conversion Specifiers

| Specifier | Description |
|-----------|-------------|
| **d, i** | Converts int to signed decimal notation. |
| **o, u, x, X** | Converts to unsigned octal ('o'), decimal ('u'), or hexadecimal ('x'/'X'). |
| **c** | Converts int to unsigned char and prints the corresponding ASCII character. |
| **s** | Prints a string until a null byte is reached. |
| **p** | Prints a void pointer as hexadecimal. |
| **%** | Outputs a literal '%'. Use '%%' for a single '%'. |
| **b** | Converts an unsigned int to binary. |
| **S** | Prints a string, replacing non-printable characters with '\x' followed by their ASCII codes. |
| **r** | Prints a string in reverse order. |
| **R** | Encodes a string to ROT13 and prints it. |

## Contributor

Ayman Benchamkha & Babafemi Adesina

