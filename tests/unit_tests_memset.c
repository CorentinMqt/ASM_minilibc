/*
** EPITECH PROJECT, 2019
** unit_tests_memset.c
** File description:
** unit_tests_memset
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void *my_memset(void *, int, int);

//Passes if Condition is true.
Test(memset, basic)
{
    char *str = malloc(100);
    char *ret;

    ret = my_memset(str, 0, 100);
    cr_assert(str == ret);
    for (int i = 0; i < 100; i++)
        cr_assert(!str[i]);
    free(str);
}

Test(memset, size_zero)
{
    char *str = malloc(100);
    char *ret = NULL;

    ret = my_memset(str, 'a', 0);
    cr_assert(str == ret);
    free(str);
}

Test(memset, multiple_use)
{
    char *str = malloc(100);

    cr_assert(my_memset(str, 'A', 100) == memset(str, 'A', 100));
    cr_assert(my_memset(str, 'B', 80) == memset(str, 'B', 80));
    cr_assert(my_memset(str, 'C', 60) == memset(str, 'C', 60));
    cr_assert(my_memset(str, 'D', 40) == memset(str, 'D', 40));
    cr_assert(my_memset(str, 'E', 20) == memset(str, 'E', 20));
    free(str);
}

Test(memset, bigger)
{
    char *str = malloc(100);

    cr_assert(my_memset(str, 'Y', 130) == memset(str, 'Y', 130));
    free(str);
}