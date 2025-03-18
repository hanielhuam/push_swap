
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
NAME = push_swap
LIBFT_DIR = libft
STACK_DIR = libft/stack
LIST_DIR = libft/list
LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_separate.c ft_litoa_base.c ft_ulitoa_base.c
STACK_SRCS = ft_stcknew.c ft_stckadd_front.c ft_stcksize.c ft_stcklast.c \
	ft_stckadd_back.c ft_stckdelone.c ft_stckclear.c ft_stckiter.c \
	ft_stckmap.c ft_swap.c ft_push.c ft_rotate.c
LIST_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_LIBFT = $(LIBFT_SRCS:$(LIBFT_DIR)/%.c=$(LIBFT_DIR)/%.o)
OBJS_STACK = $(STACK_SRCS:$(STACK_DIR)/%.c=$(STACK_DIR)/%.o)
OBJS_LIST = $(LIST_SRCS:$(LIST_DIR)/%.c=$(LIST_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS_LIBFT)

%.c: %.o
	$(CC) $(CFLAGS) $< -c $@


