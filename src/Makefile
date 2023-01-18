# Always remember to clean the project before commiting and pushing 
CC = g++
LIBS = -lglfw3 -lopengl32 -lm -lGLU32 -lGLEW32
# The -I flag tells the compiler to check the include folder for more header files
CFLAGS = -Iinclude -Wall -Wextra -pedantic 
TARGET = application
FUNCTIONS = timeFunctions
GRAPHICS = graphics
O = objectFiles


main: main.o $(FUNCTIONS).o $(GRAPHICS).o
	$(CC) $(CFLAGS) -o ../bin/$(TARGET) main.o $(FUNCTIONS).o $(GRAPHICS).o $(LIBS)

main.o: main.cpp $(FUNCTIONS).h $(GRAPHICS).h 
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

timeFunctions.o: $(FUNCTIONS).h 
	$(CC) $(CFLAGS) -c $(FUNCTIONS).h 

graphics.o: $(GRAPHICS).h 
	$(CC) $(CFLAGS) -c $(GRAPHICS).h $(LIBS)

clean: 
	$(RM) ../bin/$(TARGET)
	$(RM) *.o