CC = g++
CFLAGS = -Wall -g
 
main: main.o class_localisation.o class_agent.o class_personnel.o
	$(CC) $(CFLAGS) -o main main.o class_localisation.o class_agent.o class_personnel.o
 
main.o: main.cpp class_localisation.hpp class_agent.hpp class_personnel.hpp
	$(CC) $(CFLAGS) -c main.cpp
 
class_localisation.o: class_localisation.hpp

class_personnel.o: class_personnel.hpp

class_agent.o: class_localisation.hpp class_agent.hpp