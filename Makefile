##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make cat
##

CC=gcc

CFLAGS=-Wall -Werror -Wextra

C_FILES = src/main.c \
			src/my_split.c \
			src/commands.c \
			src/lidar.c \
			src/controls.c \
			src/drive.c \

O_FILES = $(C_FILES:.c=.o)

NAME=ai

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(O_FILES) -lm

all: $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

DOMAIN=https://downloads.coppeliarobotics.com
install:
	wget -O - $(DOMAIN)/V4_1_0/CoppeliaSim_Edu_V4_1_0_Ubuntu20_04.tar.xz \
		| tar -Jxpf -
	mv CoppeliaSim_Edu_V4_1_0_Ubuntu20_04 sim


.PHONY: all clean fclean re install
