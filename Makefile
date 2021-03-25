NAME = minesweeper

SOURCES = Sources/main.cpp Sources/Board.cpp Sources/Cell.cpp \
          Sources/Point.cpp Sources/Console.cpp Sources/UserInput.cpp

all: $(NAME)

$(NAME):
	@g++ $(SOURCES) -I Headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
