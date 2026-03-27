# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 10:30:33 by nakoriko          #+#    #+#              #
#    Updated: 2026/03/27 11:50:32 by nakoriko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv

SRCS = srcs/main.cpp srcs/Server.cpp srcs/Client.cpp srcs/CommandHandler.cpp \
		srcs/commands/Join.cpp  srcs/commands/Nick.cpp srcs/commands/Part.cpp \
		srcs/commands/Pass.cpp srcs/commands/Ping.cpp srcs/commands/PrivMsg.cpp \
		srcs/commands/Quit.cpp srcs/commands/User.cpp
	

OBJ = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
