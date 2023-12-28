MACHINE 	:= $(shell uname -m)
NAME 		= libftprintf-$(MACHINE).a
CC			= gcc
#CFLAGS		= -Wall -Wextra -Werror -MMD
CFLAGS		= -MMD
RM			= rm -rf
UTILS_DIR	= ./utils
SRCS		= $(wildcard *.c) $(wildcard $(UTILS_DIR)/*.c)
OBJS		= $(patsubst %.c,%.o,$(SRCS))
DEPS		= $(patsubst %.c,%.d,$(SRCS))

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $^

all: $(NAME)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all