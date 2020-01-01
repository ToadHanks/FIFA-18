worldcup: country.o worldcup.o
	gcc -Wall -o worldcup  worldcup.c country.c
country.o: country.c country.h
	gcc -c country.c
worldcup.o: worldcup.c country.h
	gcc -c worldcup.c
clean:
	rm country.o worldcup.o worldcup
