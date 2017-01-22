NAME=		ROG

SRC=		src/main.cc 	\
		src/enemy.cc 	\
		src/tower.cc    \
		src/world.cc 	\
		src/readmap.cc 	\
		src/game.cc

OBJ=		$(SRC:.cc=.o)

CXX= clang++
CXXFLAGS= -Wall -Wextra -std=c++14 -Iinclude -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -Wno-c++98-compat -g3

all:		$(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
			rm -f $(OBJ)

fclean:         clean
			rm -f $(NAME)

re:			fclean all
