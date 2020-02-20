/*
** EPITECH PROJECT, 2019
** unit_tests_memmmove.c
** File description:
** unit_tests_memmove
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void *my_memmove(void *, const void *, int);

//Passes if Condition is true.
Test(memmove, basic)
{
    char *test = strdup("test");
    char *test2 = strdup("test");
    char *copy = strdup("copy");
    char *copy2 = strdup("copy");

    cr_assert(!strcmp(memmove(test, copy, 4), my_memmove(test2, copy2, 4)));
}

Test(memmove, empty_string)
{
    char *test = strdup("Simple test");
    char *test2 = strdup("");

    cr_assert(my_memmove(test, test2, 1) == test);
}

Test(memmove, empty_string2)
{
    char *test = strdup("");
    char *test2 = strdup("Simple test");

    cr_assert(my_memmove(test, test2, 1) == test);
}

Test(memmove, full_null)
{
    char *test = strdup("");
    char *test2 = strdup("");

    cr_assert(my_memmove(test, test2, 1) == test);
}

Test(memmove, return_value)
{
    char *test = strdup("azertyuiopqsdfghjkllmwxcvbn azertyuiop");

    cr_assert(memmove(test + 15, test + 20, 11) ==
        my_memmove(test + 15, test + 20, 11));
}