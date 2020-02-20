/*
** EPITECH PROJECT, 2019
** all_tests
** File description:
** all_tests
*/

#include <stdio.h>
#include <stdlib.h>

int strlen(const char *);
int strcmp(char *, char *);
void *memset(void *, int, int);
void *memcpy(void *, const void *, int);
int strncmp(char *s1, char *s2, int);
char *strchr(const char *s, int);

static void strlen_tests(void)
{
    printf("TEST 1 - strlen:\n");
    printf("TRY 1.1 : [4] [%ld]\n", strlen("toto"));
    printf("TRY 1.2 : [0] [%ld]\n", strlen(""));
    printf("TRY 1.3 : [11] [%ld]\n", strlen("tototodjkli"));
    printf("TRY 1.4 : [0] [%ld]\n", strlen("\0"));
}

static void strcmp_tests(void)
{
    printf("TEST 2 - strcmp:\n");
    printf("TRY 2.1 : [%d] [%d]\n", strcmp("1234", "1234"),
        strcmp("1234", "1234"));
    printf("TRY 2.2 : [%d] [%d]\n", strcmp("12345", "1234"),
        strcmp("12345", "1234"));
    printf("TRY 2.3 : [%d] [%d]\n", strcmp("1234", "12345"),
        strcmp("1234", "12345"));
    printf("TRY 2.4 : [%d] [%d]\n", strcmp("12345", ""), strcmp("12345", ""));
    printf("TRY 2.5 : [%d] [%d]\n", strcmp("", "1"), strcmp("", "1"));
    printf("TRY 2.6 : [%d] [%d]\n", strcmp("abc", "abbcde"),
        strcmp("abc", "abbcde"));
    printf("TRY 2.7 : [%d] [%d]\n", strcmp("abc", "bbbbcde"),
        strcmp("abc", "bbbbcde"));
    strcmp(NULL, "jk");
    printf("TRY 2.8 : [NO SEG FAULT]\n");
    strcmp("hj", NULL);
    printf("TRY 2.9 : [NO SEG FAULT]\n");
}

static void memset_tests(void)
{
    char test[42];

    printf("TEST 3 - memset:\n");
    memset(test, '\0', 42);
    printf("TRY 3.1 : [1111] [%s]\n", (char *)memset(test, '1', 4));
    memset(test, '\0', 42);
    printf("TRY 3.2 : [k] [%s]\n", (char *)memset(test, 'k', 1));
    memset(test, '\0', 42);
    printf("TRY 3.3 : [] [%s]\n", (char *)memset(test, '1', 0));
    memset(test, '\0', 42);
    printf("TRY 3.4 : [ppppppppppp] [%s]\n", (char *)memset(test, 'p', 11));
}

static void memcpy_tests(void)
{
    char test[42];

    printf("TEST 4 - memcpy:\n");
    memset(test, '\0', 42);
    printf("TRY 4.1 : [1234] [%s]\n", (char *)memcpy(test, "1234", 4));
    memset(test, '\0', 42);
    printf("TRY 4.2 : [1234] [%s]\n", (char *)memcpy(test, "1234", 8));
    memset(test, '\0', 42);
    printf("TRY 4.3 : [12] [%s]\n", (char *)memcpy(test, "12", 2));
    memset(test, '\0', 42);
    printf("TRY 4.4 : [1234] [%s]\n", (char *)memcpy(test, "1234", 4));
}

static void strncmp_tests(void)
{
    printf("TEST 5 - strncmp:\n");
    printf("TRY 5.1 : [0] [%d]\n", strncmp("1234", "1234", 4));
    printf("TRY 5.2 : [0] [%d]\n", strncmp("1234", "1234", 1));
    printf("TRY 5.3 : [53] [%d]\n", strncmp("12345", "1234", 5));
    printf("TRY 5.4 : [0] [%d]\n", strncmp("12345", "1234", 4));
    printf("TRY 5.5 : [0] [%d]\n", strncmp("12345", "1234", 0));
    printf("TRY 5.6 : [-53] [%d]\n", strncmp("1234", "12345", 5));
    printf("TRY 5.7 : [49] [%d]\n", strncmp("12345", "", 5));
    printf("TRY 5.8 : [0] [%d]\n", strncmp("12345", "", 0));
    printf("TRY 5.9 : [-49] [%d]\n", strncmp("", "1", 1));
    printf("TRY 5.10 : [1] [%d]\n", strncmp("abc", "abbcde", 6));
    printf("TRY 5.11 : [-1] [%d]\n", strncmp("abc", "bbbbcde", 7));
    printf("TRY 5.12 : [69] [%d]\n", strncmp("ABCD", "ABCDE", 5));
    strncmp("\0", "jk", 0);
    printf("TRY 5.13 : [DON'T SEG FAULT]\n");
    strncmp("hj", "\0", 0);
    printf("TRY 5.14 : [DON'T SEG FAULT]\n");
    strncmp("hj", "j", -1);
    printf("TRY 6.15 : [DON'T SEG FAULT]\n");
}

static void strchr_tests(void)
{
    printf("TEST 6 - strchr:\n");
    printf("TRY 6.1 : [t] [%c]\n", *strchr("toto", 't'));
    printf("TRY 6.2 : [o] [%c]\n", *strchr("toto", 'o'));
    if (strchr("toto", 'k') == NULL)
        printf("TRY 6.3 : [NULL] [NULL]\n");
    else
        printf("TRY 6.3 : [NULL] [NOT NULL]\n");
    if (strchr("", 'k') == NULL)
        printf("TRY 6.4 : [NULL] [NULL]\n");
    else
        printf("TRY 6.4 : [NULL] [NOT NULL]\n");
    if (strchr("\0", 'k') == NULL)
        printf("TRY 6.5 : [NULL] [NULL]\n");
    else
        printf("TRY 6.5 : [NULL] [NOT NULL]\n");
    printf("TRY 6.6 : [w] [%c]\n", *strchr("aaaaaaaaaaaaaaaaaaaaw", 'w'));
}


int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    printf("Executing all tests...:\n");
    strlen_tests();
    strcmp_tests();
    memset_tests();
    memcpy_tests();
    strncmp_tests();
    strchr_tests();
    return (0);
}