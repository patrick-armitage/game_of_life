FLAGS = -lncursesw
TITLE = gameOfLife
CPP = NcursesTools.cpp
CPP += GameBoard.cpp
CPP += Patterns.cpp
CPP += GameOfLife.cpp
CPP += main.cpp
DELETE = *.gch
DELETE += *.o

all:
	g++ ${FLAGS} ${CPP} -o ${TITLE}

clean:
	${RM} ${DELETE} ${TITLE}
