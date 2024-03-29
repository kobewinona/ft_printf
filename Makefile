.PHONY: all clean fclean re
MACHINE 	:= $(shell uname -m)

NAME 		= libftprintf-$(MACHINE).a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -MMD
RM			= rm -rf
LIBFT		= libft-$(MACHINE).a

INCLUDES	= ./includes
SRCS_DIR	= ./src
UTILS_DIR	= ./utils
OBJS_DIR	= ./obj
LIBFT_DIR	= ./libs/libft

rwildcard	= $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SRCS		= $(call rwildcard, $(SRCS_DIR)/, *.c) $(call rwildcard, $(UTILS_DIR)/, *.c)
OBJS 		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
DEPS 		= $(OBJS:.o=.d)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) rcs $(NAME) $^

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR)/includes -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJS_DIR) $(DEPS)
	@make -C $(LIBFT_DIR) clean
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all