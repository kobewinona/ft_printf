.PHONY: all clean fclean re bonus

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
LIBFTD	= ./libft
UTILSD	= ./utils
LIBFTA	= libft.a
SRCS 	= ft_printf.c print_ld.c record_ftags.c print_width.c print_with_width.c \
		print_c_with_tags.c print_s_with_tags.c print_di_with_tags.c \
		print_u_with_tags.c print_x_with_tags.c print_p_with_tags.c \
		$(UTILSD)/is_valid_fdata.c $(UTILSD)/is_char_in_set.c \
		$(UTILSD)/count_dec_len.c $(UTILSD)/count_hex_len.c \
		$(UTILSD)/print_precision.c $(UTILSD)/count_precision_len.c \
		$(UTILSD)/print_preceeding_flags.c $(UTILSD)/create_p_xstr.c $(UTILSD)/create_x_xstr.c
OBJS 	= $(SRCS:.c=.o)

$(NAME): $(OBJS) libftprintf.h libftprintf_internal.h
	$(MAKE) -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFTA) $(NAME)
	$(AR) rcs $(NAME) $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(OBJS_B)
	cd $(LIBFTD) && $(MAKE) clean
	
fclean: clean
	$(RM) $(NAME)
	cd $(LIBFTD) && $(MAKE) fclean
	
re: fclean all

bonus: all