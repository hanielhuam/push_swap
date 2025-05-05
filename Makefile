CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft
INCLUDE = -Iinclude -I${LIBFT_DIR}/include

SRCS = ${SRC_DIR}/push_swap.c ${SRC_DIR}/treat_args.c \
	   ${SRC_DIR}/to_integer.c ${SRC_DIR}/init_stack.c \
	   ${SRC_DIR}/sort_three.c ${SRC_DIR}/sort_five.c ${SRC_DIR}/quick_sort.c \
	   ${SRC_DIR}/sort_algorithm.c ${SRC_DIR}/clear_args.c \
	   ${SRC_DIR}/print_stack.c ${SRC_DIR}/check_order.c ${SRC_DIR}/rotate.c \
	   ${SRC_DIR}/swap.c ${SRC_DIR}/push.c ${SRC_DIR}/find_extremes.c \
	   ${SRC_DIR}/move_2b.c ${SRC_DIR}/move_2a.c ${SRC_DIR}/compare.c \
	   ${SRC_DIR}/find_minnodes.c ${SRC_DIR}/find_maxnodes.c \
	   ${SRC_DIR}/performance.c ${SRC_DIR}/handle_minorlist.c
OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = push_swap

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT}

re: fclean all
