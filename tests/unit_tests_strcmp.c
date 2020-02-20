/*
** EPITECH PROJECT, 2019
** unit_tests_strcmp.c
** File description:
** unit_tests_strcmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int my_strcmp(char *, char *);

//Test(strcmp, basic)
//{
//    char *s1 = "HelloWorld";
//    char *s2 = "EPITECH";
//
//    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
//    cr_assert(my_strcmp(s2, s1) == strcmp(s2, s1));
//}

//Test(strcmp, empty_string)
//{
//    char *s1 = "";
//    char *s2 = "Hello World!";
//
//    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
//    cr_assert(my_strcmp(s2, s1) == strcmp(s2, s1));
//    cr_assert(my_strcmp(s2, s2) == strcmp(s2, s2));
//}
//
//Test(strcmp, empty_string2)
//{
//    char *s1 = "Hello World!";
//    char *s2 = "";
//
//    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
//    cr_assert(my_strcmp(s2, s1) == strcmp(s2, s1));
//    cr_assert(my_strcmp(s2, s2) == strcmp(s2, s2));
//}

Test(strcmp, full_null)
{
    char *s1 = "";
    char *s2 = "";

    cr_assert(my_strcmp(s1, s2) == strcmp(s1, s2));
    cr_assert(my_strcmp(s2, s1) == strcmp(s2, s1));
    cr_assert(my_strcmp(s2, s2) == strcmp(s2, s2));
}

Test(strcmp, same)
{
    char *s1 = "aer";

    cr_assert(my_strcmp(s1, s1) == strcmp(s1, s1));
}