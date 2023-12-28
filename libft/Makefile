NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
SRCS 	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isspace.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_atol.c \
		ft_strncmp.c ft_memcmp.c ft_bzero.c ft_memset.c \
		ft_memcpy.c ft_memmove.c ft_memchr.c ft_calloc.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_strlen.c \
		ft_strlcpy.c ft_strlcat.c ft_putlstr_fd.c ft_realloc.c
SRCS_B 	= ft_lstnew.c ft_lstlast.c ft_lstsize.c \
		ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS 	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

$(NAME): $(OBJS) libft.h
	$(AR) rcs $(NAME) $^

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

bonus: $(OBJS_B)
	$(AR) rcs $(NAME) $^