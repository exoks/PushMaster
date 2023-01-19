SRC := t/main.c
OBJ := $(SRC:.c=.o)
NAME := main

all: $(NAME)

$(NAME) : $(OBJ)
	gcc $^ -o $@

%.o : %.c
	gcc -Wall -Wextra -Werror -c $^
