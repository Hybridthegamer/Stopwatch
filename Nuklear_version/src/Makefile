# Always remember to clean the project before commiting and pushing 
#compiler
CC = gcc

#Flags
CPPFLAGS = -Iinclude -Wall -Wextra -pedantic -O2

TARGET = application
FUNCTIONS = timeFunctions
GRAPHICS = graphics
O = objectFiles

SRC = main.c
OBJ =   \
		graphics.o \
		timeFunctions.o \
		main.o \

BIN := $(TARGET).exe
LIBS = -lglfw3 -lopengl32 -lm -lGLU32 -lGLEW32

$(BIN): $(OBJ)
	@mkdir -p ../bin
	$(RM) ../bin/$(BIN) $(OBJS)
	$(CC) $(SRC) $(CPPFLAGS) -o ../bin/$(BIN) $(LIBS)

%.o:	%.c
	$(CC) $(CPPFLAGS) -c $< -o $@ $(LIBS)

graphics: graphics.c
	$(CC) $(CPPFLAGS) -c $< -o $@ $(LIBS)

clean: 
	$(RM) ../bin/$(TARGET)
	$(RM) *.o