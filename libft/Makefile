# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhummel <mhummel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:03:31 by mhummel           #+#    #+#              #
#    Updated: 2024/10/30 09:20:30 by mhummel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = Obj_libft
OFILES	= $(addprefix $(OBJ_DIR)/,$(notdir $(FILES:.c=.o)))

FILES =		ft_atoi.c \
			ft_atol.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_print_error.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_split.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strtok.c \
			ft_isspace.c \
			ft_strndup.c \
			ft_strtok_r.c \
			ft_strspn.c \
			ft_strcspn.c \
			ft_strerror.c \
			ft_err.c \
			ft_strtrim.c \
			ft_realloc.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			ft_putchar_fd_printf.c \
			ft_putstr_fd_printf.c \
			ft_putnbr_fd_printf.c \
			ft_putnbr_base_p_printf.c \
			ft_putnbr_base_u_printf.c \
			ft_putnbr_base_x_printf.c \
			ft_strlen_printf.c \
			ft_error_printf.c

$(NAME): $(OBJ_DIR) $(OFILES)
	@ar rsc $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@echo "\033[35mCompiling $(NAME)\033[0m"
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re