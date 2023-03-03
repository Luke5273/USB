flags = -Wall -Werror
fileIncludes = convert.c vector.c
objects = convert.o vector.o
target = main.exe

all: main.c
	gcc -c -Wall -Werror -fpic $(fileIncludes)  
	gcc main.c -o $(target) $(fileIncludes)

clean:
	rm $(target) $(objects)