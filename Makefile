NAME = minesweeper

SOURCES = Sources/main.cpp Sources/BeginnerBoard.cpp \
          Sources/IntermediateBoard.cpp Sources/ExpertBoard.cpp \
		  Sources/Board.cpp Sources/Cell.cpp Sources/Point.cpp

all: $(NAME)

$(NAME):
	@g++ $(SOURCES) -I Headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
