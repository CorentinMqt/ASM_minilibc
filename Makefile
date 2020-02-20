##
## EPITECH PROJECT, 2019
## Minilibc
## File description:
## Makefile
##


NAME		=	libasm.so

TESTS       =   unit_tests

DIR		=	src

SRCS		=	$(DIR)/strlen.asm		\
			$(DIR)/strcmp.asm		    \
			$(DIR)/memset.asm		    \
            $(DIR)/memcpy.asm		    \
            $(DIR)/memmove.asm		    \
            $(DIR)/strchr.asm		    \
            $(DIR)/strncmp.asm		    \
            $(DIR)/strstr.asm           \
			# $(DIR)/rindex.asm		    \
			# $(DIR)/strcasecmp.asm		\
			# $(DIR)/strcspn.asm		\
			# $(DIR)/strpbrk.asm

SRCS2       =   ./tests/unit_tests.c        \
				./tests/unit_tests_memmove.c\
				./tests/unit_tests_memset.c	\
				./tests/unit_tests_strchr.c	\
				./tests/unit_tests_strcmp.c	\
                ./tests/memmove.asm         \
                ./tests/memcpy.asm          \
                ./tests/memset.asm          \
                ./tests/strchr.asm          \
                ./tests/strcmp.asm          \
                ./tests/strlen.asm          \
                ./tests/strncmp.asm         \
                ./tests/strstr.asm


ASMFLAGS	=	-f elf64

LDFLAGS		=	-shared

ASM		=	nasm

LD		=	gcc

RM		=	rm -f

OBJS		=	$(SRCS:.asm=.o)

OBJ2        =   $(SRCS2:.c=.o) $(SRCS2:.asm=.o)

%.o: %.asm
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(ASM) -o $@ $< $(ASMFLAGS)

all:		$(NAME)

tests_run:      $(TESTS)

$(NAME):	$(OBJS)
		@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) -nostdlib
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

$(TESTS):	$(OBJ2)
		@$(LD) -o $(TESTS) ./tests/*.o --coverage -lcriterion
		./$(TESTS)

clean:
		@$(RM) $(OBJS) ./tests/*.o
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAME) $(TESTS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re:		fclean all

.PHONY:		all clean fclean re tests_run