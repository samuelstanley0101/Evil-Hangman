CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o unit_test.o test_def.o generic_vector.o
BASIC_HEADERS = my_string.h status.h boolean.h

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c $(BASIC_HEADERS)
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c $(BASIC_HEADERS)
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
unit_test.o: unit_test.c unit_test.h generic_vector.h $(BASIC_HEADERS)
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c unit_test.h $(BASIC_HEADERS)
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
generic_vector.o: generic_vector.c generic_vector.h generic.h $(BASIC_HEADERS)
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
clean:
	-rm string_driver $(OBJECTS)
