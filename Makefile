#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelage <mdelage@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/23 13:57:34 by mdelage           #+#    #+#              #
#    Updated: 2014/04/23 14:13:15 by mdelage          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CPATH = srcs
HPATH = includes
OPATH = obj

CC = /usr/bin/gcc
MKDIR = /bin/mkdir
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror -I $(HPATH)
LDFLAGS =

NAME = libftprintf.a
AR = /usr/bin/ar
RANLIB = /usr/bin/ranlib

HEADER = ft_printf_core.h \
	ft_struct.h

SRC = ft_func.c \
	ft_lib.c \
	ft_printf.c \
	ft_put_sc.c \
	ft_putbase.c \
	ft_putlong.c \
	ft_putpoint.c \
	ft_res.c \
	ft_which_param.c

HFILES = $(patsubst %,$(HPATH)/%, $(HEADER))
CFILES = $(patsubst %,$(CPATH)/%, $(SRC))
OFILES = $(patsubst %.c,$(OPATH)/%.o, $(SRC))

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@echo "Building $(NAME)"
	@$(AR) rc $(NAME) $^
	@$(RANLIB) $(NAME)

$(OPATH)/%.o: $(CPATH)/%.c $(HFILES)
	@echo "Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all

$(OPATH):
	@echo "Creation of building directory"
	@$(MKDIR) $(OPATH)
