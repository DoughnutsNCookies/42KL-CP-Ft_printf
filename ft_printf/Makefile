# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:52:13 by schuah            #+#    #+#              #
#    Updated: 2022/08/23 21:25:01 by schuah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft.a
ARRC		=	ar rcs
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror
SRCS_FILES	=	ft_printf \
				ft_flags \
		  		ft_print_pointer \
		  		ft_prints_with_flags \
		  		ft_printn_with_flags \
		  		ft_printun_with_flags \
		  		ft_printh_with_flags
SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= 	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR	=	srcs/
LIBFT_DIR	=	libft
OBJS_DIR	=	objs/

all:			
				mkdir -p $(OBJS_DIR)
				make create_libft	
				make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(ARRC) $(NAME) $(OBJS)

bonus:			$(NAME)

create_libft:
				make -C $(LIBFT_DIR)
				cp $(LIBFT_DIR)/$(LIBFT) .
				mv $(LIBFT) $(NAME)

clean:
				rm -rf $(OBJS_DIR)
				make fclean -C $(LIBFT_DIR)

fclean:			clean
				rm -rf $(NAME)
				rm -rf $(LIBFT)

re:				fclean all
