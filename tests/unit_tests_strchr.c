/*
** EPITECH PROJECT, 2019
** unit_tests_strchr.c
** File description:
** unit_tests_strchr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *my_strchr(const char *s, int);

// Passes if Actual is lexicographically equal to Expected.
Test(strchr, simple)
{
    cr_assert_str_eq(my_strchr("azerty", 'e'), "erty");
}

// Passes if Value is NULL.
Test(strchr, char_not_in_str)
{
    cr_assert_null(my_strchr("azerty", 'b'));
}

Test(strchr, multiple_matches)
{
    cr_assert_str_eq(my_strchr("azeerty", 'e'), "eerty");
}

Test(strchr, empty)
{
    cr_assert_null(my_strchr("", 'a'));
}