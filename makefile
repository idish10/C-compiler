assembler: after_running.o to_code.o to_binar.o reading_code.o reading_data.o builiding_symbol_table.o main.o

	gcc -ansi -Wall -pedantic -g main.o builiding_symbol_table.o reading_data.o reading_code.o to_binar.o to_code.o after_running.o -o assembler -lm

main.o: main.c header.h
	gcc -c -ansi -Wall -pedantic main.c -o main.o

builiding_symbol_table.o: builiding_symbol_table.c header.h
	gcc -c -ansi -Wall -pedantic builiding_symbol_table.c -o builiding_symbol_table.o

reading_data.o: reading_data.c header.h
	gcc -c -ansi -Wall -pedantic reading_data.c -o reading_data.o

reading_code.o: reading_code.c header.h
	gcc -c -ansi -Wall -pedantic reading_code.c -o reading_code.o


to_binar.o: to_binar.c header.h
	gcc -c -ansi -Wall -pedantic to_binar.c -o to_binar.o

to_code.o: to_code.c header.h
	gcc -c -ansi -Wall -pedantic to_code.c -o to_code.o

after_running.o: after_running.c header.h
	gcc -c -ansi -Wall -pedantic after_running.c -o after_running.o

