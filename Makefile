CC := cc

CFLAGS := -Wall -Wextra -Werror -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

SRC := so_long.c ft_utils.c ft_utils2.c ft_check.c ft_mlx_utils.c ft_mlx_move.c 

B_SRCS = bonus/so_long_bonus.c bonus/ft_utils_bonus.c bonus/ft_utils2_bonus.c bonus/ft_check_bonus.c bonus/ft_mlx_utils_bonus.c bonus/ft_mlx_move_bonus.c bonus/animation_bonus.c

NAME := so_long

BONUS := so_long_bonus

HEADER := so_long.h

MLX_LIB := minilibx_opengl/libmlx.a

B_HEADER := bonus/so_long_bonus.h
L_HEADER := ./libft/libft.h

GREEN = \033[32m
RESET = \033[0m

OBJ := $(SRC:.c=.o)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -c $< -o $@
B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(L_HEADER)
	@make -C libft
	@echo "libft $(GREEN)[Done]$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@echo "so_long $(GREEN)[Done]$(RESET)"

bonus : $(BONUS)

$(BONUS) : $(B_OBJS) $(B_HEADER) $(L_HEADER)
	@make -C libft
	@echo "libft $(GREEN)[Done]$(RESET)"
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) $(MLX_LIB) -o $(BONUS)
	@echo "so_long_bonus $(GREEN)[Done]$(RESET)"

clean :
	@make clean -C libft
	@echo "clean libft $(GREEN)[Done]$(RESET)"
	@rm -rf $(OBJ)
	@echo "clean so_long $(GREEN)[Done]$(RESET)"
	@rm -rf $(B_OBJS)
	@echo "clean so_long_bonus $(GREEN)[Done]$(RESET)"

fclean : clean
	@make fclean -C libft
	@echo "fclean libft $(GREEN)[Done]$(RESET)"
	@rm -rf $(NAME)
	@echo "fclean so_long $(GREEN)[Done]$(RESET)"
	@rm -rf $(BONUS)
	@echo "fclean so_long_bonus $(GREEN)[Done]$(RESET)"

re : clean fclean all

.PHONY : all clean fclean re