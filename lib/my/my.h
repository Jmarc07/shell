/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** headers for lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
int my_atoi(char *str);
void my_printf_f(double nb, int *count);
void my_convert_binary(int nb, int *count);
void my_convert_hexa(long int nb, int *count);
void my_convert_octal(int nb, int *count);
void flag(const char *format, va_list list_arg, int *count);
int my_printf(const char *format, ...);
void my_printf_f(double nb, int *count);
void recursive_f(int *ptr, int i, int *count);
void print_tab(int *tab, int i, int *count);
int my_printf_n(int *ptr, int *count);
void my_printf_p(long int nb, int *count);
int my_printf_u(unsigned int nb, int *count);
void decimal(const char *format, va_list list_arg, int i, int *count);
void string_s(const char *format, va_list list_arg, int i, int *count);
void character_c(const char *format, va_list list_arg, int i, int *count);
void percent(const char *format, int i, int *count);
void binary_b(const char *format, va_list list_arg, int i, int *count);
void hexadecimal_x(const char *format, va_list list_arg, int i, int *count);
void octal_o(const char *format, va_list list_arg, int i, int *count);
void pointer_p(const char *format, va_list list_arg, int i, int *count);
void float_f(const char *format, va_list list_arg, int i, int *count);
void number_n(const char *format, va_list list_arg, int i, int *count);
int my_print_digits(void);
int my_print_alpha(void);
int print_comb(void);
int my_print_revalpha(void);
int my_show_word_array(char *const *tab);
int my_compute_factorial_rec(int nb);
char *my_evil_str(char *str);
int my_compute_factorial_it(int nb);
char *concat_params(int argc, char **argv);
void my_putchar(char c, int *count);
int my_isneg(int nb);
int my_put_nbr(int nb, int *count);
void my_swap(int *a, int *b);
int my_putstr(char const *str, int *count);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
char *my_strstr(const char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int partition(int arr[], int low, int high);
int my_tablen(char **tab);
void my_tabcpy(char ***tab1, char **tab2);
char **my_tabdup(char **tab);
void my_tabfree(char **tab);
char *my_strchr(const char *s, int c);
char *my_strtok(char *str, char delim);

#endif /* !MY_H_ */
