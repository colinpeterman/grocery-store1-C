# target all means all targets currently defined in this file
all: lab4.zip lab4

#this target is the .zip file that must be submitted to Carmen
lab4.zip: Makefile lab4main.c getDataAndBuildList.c lab4Readme insert_node.c getUserOption.c lab4.h
	 zip lab4 lab4main.c lab4.h Makefile lab4Readme getDataAndBuildList.c getUserOption.c insert_node.c

lab4: lab4main.o getDataAndBuildList.o insert_node.o insert_node.o getUserOption.o
	gcc lab4main.o getDataAndBuildList.o insert_node.o getUserOption.o -o lab4	

lab4main.o: lab4main.c lab4.h
	gcc -ansi -pedantic -g -c lab4main.c

getDataAndBuildList.o: getDataAndBuildList.c lab4.h
	gcc -ansi -pedantic -g -c getDataAndBuildList.c

insert_node.o: insert_node.c lab4.h
	gcc -ansi -pedantic -g -c insert_node.c

getUserOption.o: getUserOption.c lab4.h
	gcc -ansi -pedantic -g -c getUserOption.c
