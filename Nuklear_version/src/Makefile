# Always remember to clean the project before commiting and pushing 
#compiler
CC = gcc

#Flags
CFLAGS +=  -Iinclude -std=c89 -Wall -Wextra -pedantic -O2

TARGET = app

SRC = main.c \
		graphics.c \
		timeFunctions.c \


BIN := $(TARGET).exe
LIBS = -lglfw3 -lopengl32 -lm -lGLU32 -lGLEW32

$(BIN):  
	@mkdir -p ../bin
	$(RM) ../bin/$(BIN) $(OBJS)
	$(CC) $(SRC) $(CFLAGS) -o ../bin/$(BIN) $(LIBS)

debug:
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o ../bin/debug-$(BIN) -g 

timefunct:
	$(CC) timeFunctions.c $(CFLAGS) -o ../bin/Timefunct.exe

clean: 
	$(RM) ../bin/*.exe
	$(RM) *.o