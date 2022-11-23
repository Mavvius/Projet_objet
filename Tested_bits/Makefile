CC = g++
CFLAGS = -Wall -g
 
main: main.o class_localisation.o class_agent.o
	$(CC) $(CFLAGS) -o main main.o class_localisation.o class_agent.o
 
main.o: main.cpp class_localisation.hpp class_agent.hpp
	$(CC) $(CFLAGS) -c main.cpp
 
class_localisation.o: class_localisation.hpp
 
class_agent.o: class_localisation.hpp class_agent.hpp