CC := gcc

# Extra flags to give to the C compiler
CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

MAIN := gnl 

SRC := get_next_line.c

all: $(MAIN)

$(MAIN):
	$(CC) $(CFLAGS) $(SRC) -o $(MAIN)

clean:

fclean: clean
	$(RM) $(MAIN)

re: fclean all

.PHONY: all clean fclean re