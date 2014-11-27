
suma : main.o suma.o 
	gcc -o suma main.o suma.o

main.o: main.cpp suma.hpp
	gcc -c main.cpp
suma.o: suma.cpp suma.hpp
	gcc -c suma.cpp

clean: 
	rm suma \
		main.o suma.o


