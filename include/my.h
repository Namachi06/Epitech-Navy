/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** 	Header of my_lib code
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

char **my_split(char *str, char separator);
char *get_next_line(int fd);
char **my_str_to_word_array(char const *str);
int my_str_to_int(char *str);
int char_to_octal(unsigned char number);
char *number_to_str_base(long number, int base);
int find_char(const char *str, char c);
int find_special_char(const char *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char const *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2,  int n);
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
char *my_strncat(char *dest, char const *src,  int nb);
char *my_strdup(char const *src);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_printf(const char *format, ...);
int pb(int *array1, int *array2, int size);
int sa(int *array1, int size);
int sb(int *array2, int size);
void sc(int *array1, int *array2, int size);
int ra(int *array1, int size);
void pa(int *array1, int *array2, int size);
void pushswap(int *array1, int *array2, int size);
char *int_to_string(int nb);
