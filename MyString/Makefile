All:lay

lay: main.o mystring.o 
	g++ main.o mystring.o -o lay

main.o: main.cpp
	g++ -c -g main.cpp  

mystring.o: mystring.cpp
	g++ -c -g mystring.cpp 
clean:
	rm *.o lay
