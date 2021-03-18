NAME = minesweeper

SOURCES = Sources/main.cpp Sources/Board.cpp Sources/BeginnerBoard.cpp \
          Sources/IntermediateBoard.cpp Sources/ExpertBoard.cpp \
		  Sources/Cell.cpp

all: $(NAME)

$(NAME):
	@g++ $(SOURCES) -I Headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
