OBJS	= main.o mitem.o executeItem.o config.o 

SOURCE  = main.cpp mitem.cpp executeItem.cpp config.cpp

HEADER  = mitem.h executeItem.h config.h compileOptions.h

OUT	= dwmenu
CC	= g++
FLAGS	= -g -c -Wall
LFLAGS	= 

all: $(OBJS)
		$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mitem.o: mitem.cpp
		$(CC) $(FLAGS) mitem.cpp 

executeItem.o: executeItem.cpp
		$(CC) $(FLAGS) executeItem.cpp

config.o: config.cpp
		$(CC) $(FLAGS) config.cpp
clean:
		rm -f $(OBJS) $(OUT)
