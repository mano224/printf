#include "main.h"

/**
 * get_fun - check the right specifier
 * to call its function
 * @format: passed string
 * @list: list of arguments
 * @funs: array of struct contains specifiers
 * with there print functions
 * Return: number of prints.
 **/

int get_fun(const char *format, va_list list, fmt_t *funs)
{
    int pr_count = 0, i = 0, j;

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            j = 0;

            while (funs[j].op != NULL)
            {
                if (format[i] == '%')
                {
                    pr_count += _putchar('%');
                    break;
                }

                else if (*(funs[j].op) == format[i])
                {
                    pr_count += funs[j].f(list);
                    if (pr_count == -1)
                        return (-1);
                    break;
                }
                j++;
            }
            if (funs[j].op == NULL)
            {
                pr_count += _putchar('%');
                pr_count += _putchar(format[i]);
            }
        }
        else
            pr_count += _putchar(format[i]);
        i++;
    }
    return (pr_count);
}

/**
 * _printf - prints output according to format
 * @format: passed string
 * Return: number of prints & -1 otherwise
 */
int _printf(const char *format, ...)
{
    int pr_count = 0;
    va_list list;

    fmt_t funs[] = {
        {"c", print_ch},
        {"s", print_str},
        {"d", print_int},
        {"i", print_int},
        {"b", print_bin},
        {"u", print_un},
        {"o", print_oct},
        {"x", print_hex},
        {"X", print_hex_up},
        {"S", print_exe_str},
        {"p", print_ptr},
        {"r", print_rev_str},
        {"R", print_rot_str},
        {NULL, NULL}};

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(list, format);

    pr_count = get_fun(format, list, funs);

    va_end(list);
    return (pr_count);
}
