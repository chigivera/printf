#include "main.h"

/**
 * _printf - A function that selects the appropriate function to print.
 * @format: The format string that specifies how to format the output.
 * Return: The total length of the printed string.
 */
int _printf(const char * const format_str, ...)
{
    match functions[] = {
        {"%s", _string}, {"%c", _char},
        {"%%", _37}, {"%i", _int},
        {"%d", _dec}, {"%r", _srev},
        {"%R", _rot13}, {"%b", _bin},
        {"%u", _unsigned}, {"%o", _oct},
        {"%x", _hex}, {"%X", _HEX},
        {"%S", _exclusive}, {"%p", _pointer}
    };

    va_list args_list;
    int index = 0, func_index, total_length = 0;

    va_start(args_list, format_str);
    if (format_str == NULL || (format_str[0] == '%' && format_str[1] == '\0'))
        return (-1);

    while (format_str[index] != '\0')
    {
        func_index = sizeof(functions) / sizeof(functions[0]) - 1;
        while (func_index >= 0)
        {
            if (functions[func_index].id[0] == format_str[index] &&
                functions[func_index].id[1] == format_str[index + 1])
            {
                total_length += functions[func_index].f(args_list);
                index += 2;
                break;
            }
            func_index--;
        }
        if (func_index < 0)
        {
            _putchar(format_str[index]);
            total_length++;
            index++;
        }
    }
    va_end(args_list);
    return (total_length);
}