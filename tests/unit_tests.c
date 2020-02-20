/*
** EPITECH PROJECT, 2019
** unit_tests.c
** File description:
** unit_tests_strlen
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int my_strlen(const char *);

// Passes if Condition is true.
Test(strlen, basic)
{
    char *str = "It's a simple test";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, empty)
{
    char *str = "";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, simple)
{

    char *str = "wo\nrld";

    cr_assert(my_strlen(str) == strlen(str));
}

Test(strlen, special_character)
{
    char *str = "\n\t\r";

    cr_assert(my_strlen(str) == strlen(str));
}