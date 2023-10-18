CC := gcc

CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

MAIN := gnl 

SRC := get_next_line.c get_next_line_utils.c

OBJ := $(SRC:.c=.o)

all: $(MAIN)

$(MAIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:

fclean: clean
	$(RM) $(MAIN)

re: fclean all

.PHONY: all clean fclean re