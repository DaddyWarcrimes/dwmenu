OBJS	= main.o mitem.o executeItem.o config.o menu.o

SOURCE  = main.cpp mitem.cpp executeItem.cpp config.cpp menu.cpp

HEADER  = mitem.h executeItem.h config.h compileOptions.h menu.h

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
		
menu.o: menu.cpp
		$(CC) $(FLAGS) menu.cpp

config.o: config.cpp
		$(CC) $(FLAGS) config.cpp
clean:
		rm -f $(OBJS) $(OUT)
