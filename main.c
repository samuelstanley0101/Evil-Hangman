#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "status.h"
#include "boolean.h"

/*
//Precondition: status holds the Status of the last function to run.
//Postcondition: A header has been printed that reads either FAILURE: or SUCCESS: depending on the status inputted.
void debug_status_header(Status status);

//Precondition: None.
//Postcondition: A dividing line has been printed for better formatting.
void debug_divider(void);

//Precondition: hMy_string is the handle to a My_string object and capacity and size are what the capacity and size of hMy_string should be.
//Postcondition: Whether hMy_string is a valid handle and capacity and size are the correct values has been printed.
void debug_values(MY_STRING hMy_string, int capacity, int size);

int main(int argc, char* argv[])
{
	MY_STRING hMy_string = NULL;
	MY_STRING hLeft_string = NULL;
	MY_STRING hRight_string = NULL;
	FILE* fpi;
	FILE* fpo;
	char c;
	char* pc;

	//BEGIN TESTING BASIC FUNCTIONS HERE.
	
	printf("\nFIRST TEST: INITIALIZING AN EMPTY STRING, GETTING DATA ABOUT IT, CHANGING IT, GETTING DATA ABOUT IT AGAIN, PRINTING IT, AND THEN DESTROYING IT.\n\n");
	
	printf("\nINITIALIZE AN EMPTY STRING AND GET DATA ABOUT IT\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);

	printf("\nCHANGE THE EMPTY STRING, GET DATA ABOUT IT, AND PRINT IT\n\n");
	c = 'f';
	debug_status_header(my_string_push_back(hMy_string, c));
	printf("my_string_push_back for character %c\n", c);
	debug_values(hMy_string, 7, 1);
	debug_status_header(my_string_insertion(hMy_string, stdout));
	printf("my_string_insertion for stdout\n");

	printf("\nDESTROY THE STRING\n\n");
	my_string_destroy(&hMy_string);
	if (hMy_string == NULL)
	{
		printf("my_string_destroy successfully destroys a string.\n");
	}
	debug_divider();

	printf("\nSECOND TEST: INITIALIZING A STRING WITH A C-STRING, GETTING DATA ABOUT IT AND PRINTING IT, CHANGING IT, GETTING DATA ABOUT IT AGAIN, INITIALIING ANOTHER C-STRING, COMPARING THE TWO, AND THEN DESTROYING THEM.\n\n");

	printf("\nINITIALIZE A STRING WITH A C-STRING, GET DATA ABOUT IT AND PRINT IT\n\n");

	hLeft_string = my_string_init_c_string("Skill Issue");
	debug_values(hLeft_string, 12, 11);
	debug_status_header(my_string_insertion(hLeft_string, stdout));
	printf("my_string_insertion for stdout\n");

	printf("\nCHANGE THE STRING, GET DATA ABOUT IT, AND PRINT IT\n\n");

	c = 's';
	debug_status_header(my_string_push_back(hLeft_string, c));
	printf("my_string_push_back for character %c\n", c);
	debug_values(hLeft_string, 12, 12);
	debug_status_header(my_string_insertion(hLeft_string, stdout));
	printf("my_string_insertion for stdout\n");

	printf("\nINITIALIZE ANOTHER STRING WITH A C-STRING AND COMPARE THE TWO\n\n");

	hRight_string = my_string_init_c_string("Skillfull");
	debug_values(hRight_string, 10, 9);
	printf("Comparing hLeft_string and hRight_string results in a value of %d and should result in an integer less than 0.\n", my_string_compare(hLeft_string, hRight_string));
	printf("Comparing hRight_string and hLeft_string results in a value of %d and should result in an integer greater than 0.\n", my_string_compare(hRight_string, hLeft_string));

	printf("\nDESTROY THE STRINGS\n\n");
	my_string_destroy(&hLeft_string);
	if (hLeft_string == NULL)
	{
		printf("hLeft_string successfully destroyed by my_string_destroy\n");
	}
	my_string_destroy(&hRight_string);
	if (hRight_string == NULL)
	{
		printf("hRight_string successfully destroyed by my_string_destroy\n");
	}

	debug_divider();

	printf("\nTHIRD TEST: TESTING ALL CASES OF THE my_string_compare FUNCTION.\n\n");

	printf("\nINITIALIZE TWO IDENTICAL STRINGS AND COMPARE THEM\n\n");

	hLeft_string = my_string_init_c_string("test");
	debug_values(hLeft_string, 5, 4);
	debug_status_header(my_string_insertion(hLeft_string, stdout));
	printf("my_string_insertion for hLeft_string and stdout\n");
	hRight_string = my_string_init_c_string("test");
	debug_status_header(my_string_insertion(hRight_string, stdout));
	printf("my_string_insertion for hRight_string and stdout\n");
	debug_values(hRight_string, 5, 4);
	printf("Comparing hLeft_string and hRight_string when they are identical results in a value of %d, which should be 0, and in the opposite order the value is %d, which should also be 0\n", my_string_compare(hLeft_string, hRight_string), my_string_compare(hRight_string, hLeft_string));

	printf("\nADD THE CHARACTER '1' TO hLeft_string AND COMPARE THEM AGAIN\n\n");

	debug_status_header(my_string_push_back(hLeft_string, '1'));
	printf("my_string_push_back for hLeft_string and '1'\n");
	printf("Comparing hLeft_string and hRight_string when hLeft_string has one more character than hRight_string results in a value of %d, which should be positive, and in the opposite order the value is %d, which should be negative\n", my_string_compare(hLeft_string, hRight_string), my_string_compare(hRight_string, hLeft_string));
	
	printf("\nADD THE CHARACTER '2' TO hRight_string AND COMPARE THEM AGAIN\n\n");

	debug_status_header(my_string_push_back(hRight_string, '2'));
	printf("my_string_push_back for hRight_string and '2'\n");
	printf("Comparing hLeft_string and hRight_string when they are identical aside from a 1 at the end of hLeft_string and a 2 at the end of hRight_string results in a value of %d, which should be -1, and in the opposite order the value is %d, which should be 1\n", my_string_compare(hLeft_string, hRight_string), my_string_compare(hRight_string, hLeft_string));

	printf("\nMAKE hLeft_string THE EMPTY STRING AND COMPARE THEM AGAIN\n\n");

	my_string_destroy(&hLeft_string);
	hLeft_string = my_string_init_default();
	debug_values(hLeft_string, 7, 0);
	printf("Comparing hLeft_string and hRight_string when hLeft_string is empty results in a value of %d, which should be negative, and in the opposite order the value is %d, which should be positive\n", my_string_compare(hLeft_string, hRight_string), my_string_compare(hRight_string, hLeft_string));
	
	printf("\nMAKE hRight_string THE EMPTY STRING AND COMPARE THEM FOR THE LAST TIME\n\n");

	my_string_destroy(&hRight_string);
	hRight_string = my_string_init_default();
	debug_values(hRight_string, 7, 0);
	printf("Comparing hLeft_string and hRight_string when they are both empty results in a value of %d, which should be 0, and in the opposite order the value is %d, which should also be 0\n", my_string_compare(hLeft_string, hRight_string), my_string_compare(hRight_string, hLeft_string));

	printf("\nDESTROY THE STRINGS\n\n");

	my_string_destroy(&hLeft_string);
	if (hLeft_string == NULL)
	{
		printf("hLeft_string successfully destroyed by my_string_destroy\n");
	}
	my_string_destroy(&hRight_string);
	if (hRight_string == NULL)
	{
		printf("hRight_string successfully destroyed by my_string_destroy\n");
	}

	debug_divider();

	printf("\nFOURTH TEST: TESTING ALL CASES OF THE my_string_extraction FUNCTION.\n\n");

	printf("\nINITIALIZE AN EMPTY STRING\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);

	printf("\nATTEMPT TO EXTRACT A STRING FROM test_input_empty.txt AND CHECK THAT VALUES ARE CORRECT\n\n");

	fpi = fopen("test_input_empty.txt", "r");
	if (fpi == NULL)
	{
		printf("Failed to open test_input_empty.txt\n");
		exit(1);
	}
	debug_status_header(my_string_extraction(hMy_string, fpi));
	printf("my_string_extraction for hMy_string and test_input_empty.txt\n");
	debug_values(hMy_string, 7, 0);
	fclose(fpi); fpi = NULL;

	printf("\nATTEMPT TO EXTRACT A STRING FROM test_input_whitespace.txt AND CHECK THAT VALUES ARE CORRECT\n\n");

	fpi = fopen("test_input_whitespace.txt", "r");
	if (fpi == NULL)
	{
		printf("Failed to open test_input_whitespace.txt\n");
		exit(1);
	}
	debug_status_header(my_string_extraction(hMy_string, fpi));
	printf("my_string_extraction for hMy_string and test_input_whitespace.txt\n");
	debug_values(hMy_string, 7, 0);
	fclose(fpi); fpi = NULL;

	printf("\nATTEMPT TO EXTRACT A STRING FROM test_input_word.txt AND CHECK THAT VALUES ARE CORRECT\n\n");

	fpi = fopen("test_input_word.txt", "r");
	if (fpi == NULL)
	{
		printf("Failed to open test_input_word.txt\n");
		exit(1);
	}
	debug_status_header(my_string_extraction(hMy_string, fpi));
	printf("my_string_extraction for hMy_string and test_input_word.txt\n");
	debug_values(hMy_string, 7, 5);
	debug_status_header(my_string_insertion(hMy_string, stdout));
	printf("my_string_insertion for hMy_string and stdout\n");
	fclose(fpi); fpi = NULL;

	printf("\nATTEMPT TO EXTRACT A STRING FROM test_input_sentence AND CHECK THAT VALUES ARE CORRECT\n\n");

	fpi = fopen("test_input_sentence.txt", "r");
	if (fpi == NULL)
	{
		printf("Failed to open test_input_sentence.txt\n");
		exit(1);
	}
	debug_status_header(my_string_extraction(hMy_string, fpi));
	printf("my_string_extraction for hMy_string and test_input_sentence.txt\n");
	debug_values(hMy_string, 7, 3);
	debug_status_header(my_string_insertion(hMy_string, stdout));
	printf("my_string_insertion for hMy_string and stdout\n");
	fclose(fpi); fpi = NULL;

	printf("\nATTEMPT TO EXTRACT A STRING OF SPECIFIC LENGTH FROM dictionary.txt AND CHECK THAT VALUES ARE CORRECT\n\n");

	fpi = fopen("dictionary.txt", "r");
	if (fpi == NULL)
	{
		printf("Failed to open dictionary.txt\n");
		exit(1);
	}
	while(my_string_extraction(hMy_string, fpi))
	{
		if (my_string_get_size(hMy_string) == 29)
		{
			debug_status_header(my_string_insertion(hMy_string, stdout));
			printf("my_string_insertion for hMy_string and stdout\n");
			break;
		}
	}
	debug_values(hMy_string, 56, 29);
	fclose(fpi); fpi = NULL;

	printf("\nDESTROY THE STRING\n\n");

	my_string_destroy(&hMy_string);
	if (hMy_string == NULL)
	{
		printf("hMy_string successfully destroyed by my_string_destroy\n");
	}

	debug_divider();

	printf("\nFIFTH TEST: TESTING ALL CASES OF THE my_string_insertion FUNCTION.\n\n");

	printf("\nINITIALIZE AN EMPTY STRING AND OPEN A FILE FOR WRITING\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);
	fpo = fopen("test_output.txt", "w");
	if (fpo == NULL)
	{
		printf("Failed to open test_output.txt for writing.\n");
		exit(1);
	}

	printf("\nATTEMPT TO INSERT THE EMPTY STRING INTO test_output.txt\n\n");

	debug_status_header(my_string_insertion(hMy_string, fpo));
	printf("my_string_insertion for hMy_string and fpo\n");
	fputc('\n', fpo);
	my_string_destroy(&hMy_string);

	printf("\nATTEMPT TO INSERT A STRING OF ONE WORD INTO test_output.txt\n\n");

	hMy_string = my_string_init_c_string("gaming.");
	debug_values(hMy_string, 8, 7);
	debug_status_header(my_string_insertion(hMy_string, fpo));
	printf("my_string_insertion for hMy_string and fpo\n");
	fputc('\n', fpo);
	my_string_destroy(&hMy_string);

	printf("\nATTEMPT TO INSERT A STRING OF A SENTENCE INTO test_output.txt\n\n");

	hMy_string = my_string_init_c_string("I am very tired and want to go to bed.");
	debug_values(hMy_string, 39, 38);
	debug_status_header(my_string_insertion(hMy_string, fpo));
	printf("my_string_insertion for hMy_string and fpo\n");
	my_string_destroy(&hMy_string);

	printf("\nCLOSE THE FILE test_output.txt\n\n");

	fclose(fpo); fpo = NULL;

	debug_divider();

	printf("\nSIXTH TEST: TESTING ALL CASES OF THE my_string_push_back FUNCTION.\n\n");

	printf("\nATTEMPT TO PUSH A CHARACTER INTO A STRING WITH CAPACITY 1 MORE THAN SIZE\n\n");

	hMy_string = my_string_init_c_string("test");
	debug_values(hMy_string, 5, 4);
	debug_status_header(my_string_push_back(hMy_string, 's'));
	printf("my_string_push_back for hMy_string and 's'\n");
	debug_values(hMy_string, 5, 5);

	printf("\nATTEMPT TO PUSH A CHARACTER INTO A STRING WITH INSUFFICIENT CAPACITY\n\n");

	debug_status_header(my_string_push_back(hMy_string, '!'));
	printf("my_string_push_back for hMy_string and '!'\n");
	debug_values(hMy_string, 10, 6);
	my_string_destroy(&hMy_string);

	printf("\nATTEMPT TO PUSH A CHARACTER INTO THE EMPTY STRING\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);
	debug_status_header(my_string_push_back(hMy_string, 'F'));
	printf("my_string_push_back for hMy_string and 'F'\n");
	debug_values(hMy_string, 7, 1);
	my_string_destroy(&hMy_string);

	debug_divider();

	printf("\nSEVENTH TEST: TESTING ALL CASES OF THE my_string_pop_back FUNCTION.\n\n");

	printf("\nATTEMPT TO POP A CHARACTER FROM A STRING WITH SIZE GREATER THAN 0\n\n");

	hMy_string = my_string_init_c_string("test.");
	debug_values(hMy_string, 6, 5);
	debug_status_header(my_string_pop_back(hMy_string));
	printf("my_string_pop_back for hMy_string\n");
	debug_values(hMy_string, 6, 4);
	my_string_destroy(&hMy_string);

	printf("\nATTEMPT TO POP A CHARACTER FROM THE EMPTY STRING\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);
	debug_status_header(my_string_pop_back(hMy_string));
	printf("my_string_pop_back for hMy_string\n");
	debug_values(hMy_string, 7, 0);
	my_string_destroy(&hMy_string);

	debug_divider();

	printf("\nEIGHTH TEST: TESTING ALL CASES OF THE my_string_at FUNCTION.\n\n");

	printf("\nTHE INDEX IS IN BOUNDS, CHANGE THE CHARACTER\n\n");

	hMy_string = my_string_init_c_string("test.");
	debug_values(hMy_string, 6, 5);
	pc = my_string_at(hMy_string, 3);
	if (*pc == 't')
	{
		printf("my_string_at works for an index in bounds.\n");
		*pc = 's';
		debug_status_header(my_string_insertion(hMy_string, stdout));
	}
	pc = NULL;

	printf("\nTHE INDEX IS OUT OF BOUNDS\n\n");

	if (my_string_at(hMy_string, 6) == NULL)
	{
		printf("my_string_at returns NULL for an index out of bounds.\n");
	}
	my_string_destroy(&hMy_string);

	debug_divider();

	printf("\nNINTH TEST: TESTING ALL CASES OF THE my_string_c_str FUNCTION\n\n");

	printf("\nTHE STRING IS EMPTY\n\n");

	hMy_string = my_string_init_default();
	printf("the string in hMy_string is %s\n", my_string_c_str(hMy_string));
	debug_values(hMy_string, 7, 0);
	my_string_destroy(&hMy_string);

	printf("\nTHE STRING HAS CAPACITY 1 MORE THAN SIZE\n\n");

	hMy_string = my_string_init_c_string("test string");
	debug_values(hMy_string, 12, 11);
	printf("the string in hMy_string is %s\n", my_string_c_str(hMy_string));
	debug_values(hMy_string, 12, 11);

	printf("\nTHE STRING HAS CAPACITY == SIZE\n\n");

	debug_status_header(my_string_push_back(hMy_string, '.'));
	printf("my_string_push_back for hMy_string and '.'\n");
	debug_values(hMy_string, 12, 12);
	printf("the string in hMy_string is %s\n", my_string_c_str(hMy_string));
	debug_values(hMy_string, 13, 12);
	my_string_destroy(&hMy_string);

	debug_divider();

	printf("\nTENTH TEST: TESTING ALL CASES OF THE my_string_concat FUNCTION.\n\n");

	printf("\nBOTH STRINGS ARE EMPTY\n\n");

	hLeft_string = my_string_init_default();
	debug_values(hLeft_string, 7, 0);
	hRight_string = my_string_init_default();
	debug_values(hRight_string, 7, 0);
	debug_status_header(my_string_concat(hLeft_string, hRight_string));
	printf("my_string_concat for two empty strings\n");
	debug_values(hLeft_string, 7, 0);
	debug_values(hRight_string, 7, 0);
	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);

	printf("\nEITHER OF THE STRINGS IS EMPTY, AND IN THE SECOND INSTANCE THE RESULT STRING HAS INSUFFICIENT CAPACITY\n\n");

	hLeft_string = my_string_init_c_string("test string");
	debug_values(hLeft_string, 12, 11);
	hRight_string = my_string_init_default();
	debug_values(hRight_string, 7, 0);
	debug_status_header(my_string_concat(hLeft_string, hRight_string));
	printf("my_string_concat for hLeft_string and an empty string\n");
	debug_values(hLeft_string, 12, 11);
	debug_values(hRight_string, 7, 0);
	debug_status_header(my_string_concat(hRight_string, hLeft_string));
	printf("my_string_concat for an empty string and hLeft_string\n");
	debug_status_header(my_string_insertion(hRight_string, stdout));
	printf("my_string_insertion for hLeft_string and stdout\n");
	debug_values(hRight_string, 19, 11);
	debug_values(hLeft_string, 12, 11);
	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);

	printf("\nBOTH STRINGS ARE NONEMPTY, AND IN BOTH CASES THE RESULT STRING DOES NOT HAVE ENOUGH CAPACITY TO APPEND THE OTHER STRING\n\n");

	hLeft_string = my_string_init_c_string("test");
	debug_values(hLeft_string, 5, 4);
	hRight_string = my_string_init_c_string("string");
	debug_values(hRight_string, 7, 6);
	debug_status_header(my_string_concat(hLeft_string, hRight_string));
	printf("my_string_concat for hLeft_string and hRight_string\n");
	debug_values(hLeft_string, 12, 10);
	debug_values(hRight_string, 7, 6);
	debug_status_header(my_string_insertion(hLeft_string, stdout));
	printf("my_string_insertion for hLeft_string and stdout\n");
	debug_status_header(my_string_concat(hRight_string, hLeft_string));
	printf("my_string_concat for an hRight_string and hLeft_string\n");
	debug_values(hRight_string, 19, 16);
	debug_values(hLeft_string, 12, 10);
	debug_status_header(my_string_insertion(hRight_string, stdout));
	printf("my_string_insertion for hRight_string and stdout\n");
	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);

	debug_divider();

	printf("\nELEVENTH TEST: TESTING ALL CASES OF THE my_string_empty FUNCTION\n\n");

	printf("\nTHE STRING IS EMPTY\n\n");

	hMy_string = my_string_init_default();
	debug_values(hMy_string, 7, 0);
	if (my_string_empty(hMy_string))
	{
		printf("hMy_string is empty\n");
	}
	my_string_destroy(&hMy_string);

	printf("\nTHE STRING IS NOT EMPTY\n\n");

	hMy_string = my_string_init_c_string("test");
	debug_values(hMy_string, 5, 4);
	if (!my_string_empty(hMy_string))
	{
		printf("hMy_string is not empty\n");
	}
	my_string_destroy(&hMy_string);

	debug_divider();
	
	return 0;
}

void debug_status_header(Status status)
{
	if (status == FAILURE)
	{
		printf(" | FAILURE: ");
	}
	else
	{
		printf(" | SUCCESS: ");
	}
}

void debug_divider(void)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		printf("-");
	}
	printf("\n");
}

void debug_values(MY_STRING hMy_string, int capacity, int size)
{
	if (hMy_string != NULL)
	{
		printf("hMy_string successfully allocated.\n");
	}
	else
	{
		printf("hMy_string failed to be allocated correctly.\n");
		exit(1);
	}
	if (my_string_get_capacity(hMy_string) == capacity)
	{
		printf("my_string_get_capacity works for capacity %d.\n", capacity);
	}
	else
	{
		printf("The capacity should be %d, but it's actually %d.\n", capacity, my_string_get_capacity(hMy_string));
	}
	if (my_string_get_size(hMy_string) == size)
	{
		printf("my_string_get_size works for size %d.\n", size);
	}
	else
	{
		printf("The size should be %d, but it's actually %d.\n", size, my_string_get_size(hMy_string));
	}

}
*/
