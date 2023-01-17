CC = g++
# The -I flag tells the compiler to check the include folder for more header files
CFLAGS = -I /include -Wall
TARGET = application
FUNCTIONS = timeFunctions
GRAPHICS = graphics

main: main.o $(FUNCTIONS).o $(GRAPHICS).o
	$(CC) $(CFLAGS) -o ../bin/$(TARGET) main.o $(FUNCTIONS).o $(GRAPHICS).o

main.o: main.cpp $(FUNCTIONS).h $(GRAPHICS).h 
	$(CC) $(CFLAGS) -c main.cpp

timeFunctions.o: $(FUNCTIONS).h $(FUNCTIONS).cpp

graphics.o: $(FUNCTIONS).h 


clean: 
	$(RM) ../bin/$(TARGET)