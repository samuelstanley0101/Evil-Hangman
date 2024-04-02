#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "unit_test.h"
#include "status.h"
#include "boolean.h"
#include "generic.h"
#include "generic_vector.h"

struct associative_data
{
	GENERIC_VECTOR vector;
	MY_STRING key;
};
typedef struct associative_data Associative_data;

typedef struct node Node;
struct node
{
	Associative_data* data;
	Node* left;
	Node* right;
	int depth;
};

struct associative_array
{
	Node* root;
};
typedef struct associative_array Associative_array;

//Preconditon: key is a valid key My_string and word is a valid word of the same size as key.
//pStatus is either a pointer to a status variable or NULL.
//Postcondition: word has been inserted into the associative_array structure held by root
//recursively and array_balance has been called to balance the node according to the AVL tree
//property.
Node* associative_array_insert(Node** pRoot, MY_STRING key, MY_STRING word, Status* pStatus);

//Precondition: pRoot is the pointer to the root of an associative_array structure that has
//a balance factor of greater that 1 or less than -1, but neither of its children has a bad
//balance factor. balance is the balance factor of the root.
//Postcondition: The Associative_array pointed to by pRoot has been balanced according to the
//AVL tree property.
void associative_array_balance(Node** pRoot, int balance);

//Precondition: associative_array is an Associative array that satisfies the AVL tree property.
//Postcondition: The Node that contains the largest Generic_vector has been returned, and all
//the rest of the Nodes in the Associative_array have been destroyed.
Node* associative_array_largest(Node** pRoot);

int associative_array_calibrate_depth(Node* root);

int associative_array_calculate_balance(Node* root, int* unbalance_count);

void clear_keyboard_buffer(void);

int debug_count = 0; //DEBUG

int main(int argc, char* argv[])
{
	//This is the array of functions to be tested, add items to this as needed.
	Status (*tests[])(char*, int) = {
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_sstanley_get_capacity_on_init_default_returns_7,
		test_sstanley_init_c_string_returns_nonNULL,
		test_sstanley_get_size_on_init_c_string_returns_0_for_empty_string,
		test_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string,
		test_sstanley_get_size_on_init_c_string_returns_3_for_string_the,
		test_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the,
		test_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity,
		test_sstanley_get_size_on_push_back_returns_1_more_than_previous,
		test_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity,
		test_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity,
		test_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity,
		test_sstanley_get_size_on_concat_returns_result_size_plus_append_size,
		test_sstanley_c_str_returns_address_of_correct_c_string,
		test_sstanley_get_size_on_pop_back_returns_1_less_than_previous,
		test_sstanley_compare_returns_negative_on_left_smaller_than_right,
		test_sstanley_compare_returns_positive_on_left_bigger_than_right,
		test_sstanley_compare_returns_0_on_left_equals_right,
		test_sstanley_compare_returns_negative_on_left_prefix_of_right,
		test_sstanley_at_returns_correct_address_for_index_in_bounds,
		test_sstanley_empty_returns_TRUE_if_string_empty,
		test_sstanley_extraction_writes_word_from_file_with_sentence_to_string,
		test_sstanley_insertion_writes_non_empty_string_to_file,
		test_sstanley_string_is_NULL_after_destroy,
		test_sstanley_get_size_on_assignment_returns_right_size,
		test_sstanley_get_capacity_on_assignment_returns_same_without_resize,
		test_sstanley_get_capacity_on_assignment_returns_right_with_resize,
		test_sstanley_get_size_on_init_copy_returns_copied_size,
		test_sstanley_get_capacity_on_init_copy_returns_copied_capacity,
		test_sstanley_at_returns_same_last_element_value_as_copied,
		test_sstanley_get_size_on_swap_returns_swapped_values,
		test_sstanley_get_capacity_on_swap_returns_swapped_values,
		test_sstanley_at_element_zero_returns_swapped_addresses
	};

	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;
	//Make this FALSE if you don't need to know when a test succeeds.
	Boolean display_success_messages = TRUE;
	//Make this FALSE when you don't want any messages to display
	Boolean display_error_messages = FALSE;
	
	//For the lab 6 testing program
	Boolean display_lab_6_result = FALSE;
	MY_STRING* my_array = NULL;

	//For the game itself, starting in lab 7
	Boolean play_game = TRUE;
	Boolean lab_7_checkpoint = FALSE;
	Boolean display_words_remaining = FALSE;
	Boolean is_in_word_family;
	Boolean is_in_letters_guessed;
	GENERIC_VECTOR* phMy_string_vectors = NULL;
	GENERIC_VECTOR hVector = NULL;
	MY_STRING hMy_string = NULL;
	MY_STRING hCurrent_word_family = NULL;
	MY_STRING hNew_key = NULL;
	MY_STRING hLetters_guessed = NULL;
	Associative_array* associative_array = NULL;
	Node* largest_node = NULL;
	FILE* fp = NULL;
	//int unbalance_count;
	int word_length;
	int number_of_guesses;
	char guess;
	char c;
	Status status;
	
	//Lab 8 checkpoint
	MY_STRING current_word_family = NULL;
	MY_STRING new_key = NULL;
	MY_STRING word = NULL;
	Boolean lab_8_checkpoint = FALSE;

	//Testing Program
	for (i = 0; i < number_of_functions; i++)
	{
		if(tests[i](buffer, 500) == FAILURE)
		{
			if (display_error_messages)
			{
				printf("FAILED: Test %d failed\n", i);
				printf("%s\n", buffer);
			}
			failure_count++;
		}
		else
		{
			if (display_success_messages && display_error_messages)
			{
				printf("PASS: Test %d passed\n", i);
				printf("%s\n", buffer);
			}
			success_count++;
		}
	}
	if (display_error_messages)
	{
		printf("Total number of tests: %d\n", number_of_functions);
		printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
	}

	//Lab 6 Testing program:
	my_array = (MY_STRING*)malloc(sizeof(MY_STRING) * 100);
	if (my_array == NULL)
	{
		printf("Failed to allocate space for array of MY_STRING handles\n");
		exit(1);
	}
	for (i = 0; i < 100; i++)
	{
		my_array[i] = NULL;
	}
	my_array[0] = my_string_init_c_string("COPY ME!");
	if (my_array[0] == NULL)
	{
		printf("Failed to allocate space for My_string object\n");
		exit(1);
	}
	for (i = 1; i < 100; i++)
	{
		my_array[i] = my_string_init_copy(my_array[0]);
		if (my_array[i] == NULL)
		{
			printf("Failed to allocate space for My_string object index %d\n", i);
			exit(1);
		}
	}
	my_string_destroy(my_array);
	my_array[0] = my_string_init_c_string("FIRST FIFTY!");
	if (my_array[0] == NULL)
	{
		printf("Failed to allocate space for 'FIRST FIFTY' My_string object\n");
		exit(1);
	}
	for (i = 1; i < 50; i++)
	{
		if (!my_string_assignment(my_array[i], my_array[0]))
		{
			printf("Failed to allocate space for my_string_assignment call for index %d\n", i);
			exit(1);
		}
	}
	for (i = 0; i < 50; i++)
	{
		my_string_swap(my_array[i], my_array[99-i]);
	}
	for (i = 0; i < 100; i++)
	{
		if (display_lab_6_result)
		{
			my_string_insertion(my_array[i], stdout);
		}
		my_string_destroy(my_array + i);
	}
	free(my_array); my_array = NULL;

	//Lab 8 testing program;
	if (lab_8_checkpoint)
	{
		current_word_family = my_string_init_c_string("---");
		new_key = my_string_init_c_string("---");
		word = my_string_init_c_string("The");
		if (get_word_key_value(current_word_family, new_key, word, 'T') == FAILURE)
		{
			printf("Failed to allocate space for get_word_key_value\n");
			exit(1);
		}
		my_string_insertion(new_key, stdout);
		printf("\n");
		my_string_destroy(&current_word_family);
		my_string_destroy(&new_key);
		my_string_destroy(&word);
		current_word_family = my_string_init_c_string("-----");
		new_key = my_string_init_c_string("---");
		word = my_string_init_c_string("Truck");
		if (get_word_key_value(current_word_family, new_key, word, 'r') == FAILURE)
		{
			printf("Failed to allocate space for get_word_key_value\n");
			exit(1);
		}
		my_string_insertion(new_key, stdout);
		printf("\n");
		my_string_destroy(&current_word_family);
		my_string_destroy(&new_key);
		my_string_destroy(&word);
		current_word_family = my_string_init_c_string("--ppy");
		new_key = my_string_init_c_string("---");
		word = my_string_init_c_string("happy");
		if (get_word_key_value(current_word_family, new_key, word, 'h') == FAILURE)
		{
			printf("Failed to allocate space for get_word_key_value\n");
			exit(1);
		}
		my_string_insertion(new_key, stdout);
		printf("\n");
		my_string_destroy(&current_word_family);
		my_string_destroy(&new_key);
		my_string_destroy(&word);
		current_word_family = my_string_init_c_string("--e---e");
		new_key = my_string_init_c_string("---");
		word = my_string_init_c_string("awesome");
		if (get_word_key_value(current_word_family, new_key, word, 'z') == FAILURE)
		{
			printf("Failed to allocate space for get_word_key_value\n");
			exit(1);
		}
		my_string_insertion(new_key, stdout);
		printf("\n");
		my_string_destroy(&current_word_family);
		my_string_destroy(&new_key);
		my_string_destroy(&word);
	}

	//The Game
	if (play_game)
	{
		phMy_string_vectors = (GENERIC_VECTOR*)malloc(sizeof(GENERIC_VECTOR) * 30);
		if (phMy_string_vectors == NULL)
		{
			printf("Failed to allocate space for array of Vectors of My_strings\n");
			exit(1);
		}
		fp = fopen("dictionary.txt", "r");
		if (fp == NULL)
		{
			printf("Failed to open file dictionary.txt for reading\n");
			exit(1);
		}
		/*associative_array = (Associative_array*)malloc(sizeof(Associative_array));
		if (associative_array == NULL)
		{
			printf("Failed to allocate space for associative_array\n");
			exit(1);
		}
		associative_array->root = NULL;*/
		for (i = 0; i < 30; i++)
		{
			phMy_string_vectors[i] = generic_vector_init_default(
					my_string_init_copy,
					my_string_destroy);
			if (phMy_string_vectors[i] == NULL)
			{
				printf("Failed to allocate space for Generic_vector at %d\n", i);
				exit(1);
			}
		}
		hCurrent_word_family = my_string_init_default();
		if (hCurrent_word_family == NULL)
		{
			printf("Failed to allocate memory for hCurrent_word_family object");
			exit(1);
		}
		hNew_key = my_string_init_default();
		if (hNew_key == NULL)
		{
			printf("Failed to allocate memory for hNew_key object");
			exit(1);
		}
		hLetters_guessed = my_string_init_default();
		if (hLetters_guessed == NULL)
		{
			printf("Failed to allocate memory for hLetters_guessed");
			exit(1);
		}
		hMy_string = my_string_init_default();
		if (hMy_string == NULL)
		{
			printf("Failed to allocate space for hMy_string object\n");
			exit(1);
		}
		while (my_string_extraction(hMy_string, fp) == SUCCESS)
		{
			if (generic_vector_push_back(phMy_string_vectors[my_string_get_size(hMy_string)], hMy_string) == FAILURE)
			{
				printf("Failed to allocate memory for generic_vector_push_back for string %s\n", my_string_c_str(hMy_string));
				exit(1);
			}
		}
		if (!feof(fp))
		{
			printf("Failed to resize My_string object during my_string_extraction\n");
			exit(1);
		}
		my_string_destroy(&hMy_string);
		fclose(fp); fp = NULL;
		
		//Prompting the user at the start of the game
		printf("Welcome to Evil Hangman!\n");
		printf("Enter the length of the word you want to guess: ");
		scanf("%d", &word_length);
		while (word_length > 30 || word_length < 1 || generic_vector_get_size(phMy_string_vectors[word_length]) < 1)
		{
			printf("That length is invalid, please enter another length of a word you want to guess: ");
			scanf("%d", &word_length);
		}
		hVector = phMy_string_vectors[word_length];
		//Destroy all unnecessary vectors
		for (i = 0; i < word_length; i++)
		{
			if (lab_7_checkpoint)
			{
				printf("There are %d items in vector index %d\n", generic_vector_get_size(phMy_string_vectors[i]), i);
			}
			generic_vector_destroy(phMy_string_vectors + i);
		}
		if (lab_7_checkpoint)
		{
			printf("There are %d items in vector index %d\n", generic_vector_get_size(phMy_string_vectors[word_length]), word_length);
		}
		for (i = word_length + 1; i < 30; i++)
		{
			if (lab_7_checkpoint)
			{
				printf("There are %d items in vector index %d\n", generic_vector_get_size(phMy_string_vectors[i]), i);
			}
			generic_vector_destroy(phMy_string_vectors + i);
		}
		free(phMy_string_vectors);
		printf("How many guesses do you want to have? ");
		scanf("%d", &number_of_guesses);
		while (number_of_guesses < 1)
		{
			printf("That is an invalid number of guesses, please enter a number greater than 0: ");
			scanf("%d", &number_of_guesses);
		}
		clear_keyboard_buffer();
		printf("Finally, do you want to know how many words you have remaining during the game? (y)es or (n)o ");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			display_words_remaining = TRUE;
		}
		else
		{
			display_words_remaining = FALSE;
		}
		clear_keyboard_buffer();
		for (i = 0; i < word_length; i++)
		{
			if (my_string_push_back(hCurrent_word_family, '-') == FAILURE)
			{
				printf("Failed to allocate memory for my_string_push_back\n");
				exit(1);
			}
		}
		
		//Looping the guesses
		while (number_of_guesses > 0 && my_string_compare(hCurrent_word_family, *generic_vector_at(hVector, 0)) != 0)
		{
			printf("You have %d guesses remaining.\n", number_of_guesses);
			printf("You have already guessed these letters:\n");
			for (i = 0; i < my_string_get_size(hLetters_guessed); i++)
			{
				printf("%c, ", *(my_string_at(hLetters_guessed, i)));
			}
			printf("\n");
			if (display_words_remaining)
			{
				printf("There are currently %d valid words remaining\n", generic_vector_get_size(hVector));
			}
			my_string_insertion(hCurrent_word_family, stdout);
			printf("\nEnter a letter: ");
			scanf("%c", &guess);
			clear_keyboard_buffer();
			if (isalpha(guess))
			{
				guess = tolower(guess);
			}
			is_in_letters_guessed = FALSE;
			for (i = 0; i < my_string_get_size(hLetters_guessed); i++)
			{
				if (*(my_string_at(hLetters_guessed, i)) == guess)
				{
					is_in_letters_guessed = TRUE;
				}
			}
			while (!isalpha(guess) || is_in_letters_guessed)
			{
				printf("Invalid answer, please enter a letter: ");
				scanf("%c", &guess);
				clear_keyboard_buffer();
				if (isalpha(guess))
				{
					guess = tolower(guess);
				}
				is_in_letters_guessed = FALSE;
				for (i = 0; i < my_string_get_size(hLetters_guessed); i++)
				{
					if (*(my_string_at(hLetters_guessed, i)) == guess)
					{
						is_in_letters_guessed = TRUE;
					}
				}
			}
			if (my_string_push_back(hLetters_guessed, guess) == FAILURE)
			{
				printf("Failed to allocate memory in my_string_push_back\n");
				exit(1);
			}
			associative_array = (Associative_array*)malloc(sizeof(Associative_array));
			if (associative_array == NULL)
			{
				printf("Failed to allocate space for associative_array\n");
				exit(1);
			}
			associative_array->root = NULL;
			for (i = 0; i < generic_vector_get_size(hVector); i++)
			{
				if (get_word_key_value(hCurrent_word_family, hNew_key, *generic_vector_at(hVector, i), guess) == FAILURE)
				{
					printf("Failed to allocate memory in get_word_key_value\n");
					exit(1);
				}
				/*my_string_insertion(hNew_key, stdout); //DEBUG
				printf("  "); //DEBUG
				my_string_insertion(*generic_vector_at(hVector, i), stdout); //DEBUG
				printf("\n"); //DEBUG*/
				//Insert into the array
				associative_array->root = associative_array_insert(&(associative_array->root), hNew_key, *generic_vector_at(hVector, i), &status);
				if (status == FAILURE)
				{
					printf("Failed to insert root for i %d\n", i);
					exit(1);
				}
				associative_array_calibrate_depth(associative_array->root);
			}
			largest_node = associative_array_largest(&(associative_array->root));
			if (hVector != NULL)
			{
				generic_vector_destroy(&hVector);
			}
			hVector = largest_node->data->vector;
			if (my_string_assignment(hCurrent_word_family, largest_node->data->key) == FAILURE)
			{
				printf("Failed to allocate memory for my_string_assignment\n");
				exit(1);
			}
			my_string_destroy(&(largest_node->data->key));
			free(largest_node->data);
			free(largest_node);
			free(associative_array); associative_array = NULL;
	
			is_in_word_family = FALSE;
			for (i = 0; i < my_string_get_size(hCurrent_word_family); i++)
			{
				if (*(my_string_at(hCurrent_word_family, i)) == guess)
				{
					is_in_word_family = TRUE;
				}
			}
			if (!is_in_word_family)
			{
				number_of_guesses--;
			}
		}

		if (my_string_compare(hCurrent_word_family, *generic_vector_at(hVector, 0)) == 0)
		{
			printf("Congratulations! You beat Evil Hangman!\n");
			printf("The word was: %s\n", my_string_c_str(*generic_vector_at(hVector, 0)));
		}
		else
		{
			printf("You Lose.\n");
			printf("The word was: %s\n", my_string_c_str(*generic_vector_at(hVector, 0)));
		}
		
		//Freeing memory after the game
		generic_vector_destroy(&hVector);
		free(associative_array); associative_array = NULL;
		my_string_destroy(&hCurrent_word_family);
		my_string_destroy(&hNew_key);
		my_string_destroy(&hLetters_guessed);
	}

	return 0;
}

Node* associative_array_insert(Node** pRoot, MY_STRING key, MY_STRING word, Status* pStatus)
{
	//associative_array->root = associative_array_insert(&(associative_array->root), hNew_key, *generic_vector_at(hVector, i), &status);
	int balance;
	int right_depth = 0;
	int left_depth = 0;
	Node* root = *pRoot;
	//Create a new Node if needed
	if (root == NULL)
	{
		debug_count++;
		(*pRoot) = (Node*)malloc(sizeof(Node));
		if ((*pRoot) == NULL)
		{
			if (pStatus != NULL) *pStatus = FAILURE;
			return NULL;
		}
		(*pRoot)->data = (Associative_data*)malloc(sizeof(Associative_data));
		if ((*pRoot)->data == NULL)
		{
			free((*pRoot));
			if (pStatus != NULL) *pStatus = FAILURE;
			return NULL;
		}
		(*pRoot)->data->key = my_string_init_copy(key);
		if ((*pRoot)->data->key == NULL)
		{
			free((*pRoot)->data);
			free((*pRoot));
			if (pStatus != NULL) *pStatus = FAILURE;
			return NULL;
		}
		(*pRoot)->data->vector = generic_vector_init_default(
				my_string_init_copy,
				my_string_destroy);
		if ((*pRoot)->data->vector == NULL)
		{
			my_string_destroy(&((*pRoot)->data->key));
			free((*pRoot)->data);
			free((*pRoot));
			if (pStatus != NULL) *pStatus = FAILURE;
			return NULL;
		}
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		(*pRoot)->depth = 0;
	}

	//Find where to make a new node or insert into an existing one
	if (my_string_compare(key, (*pRoot)->data->key) < 0)
	{
		//traverse left
		(*pRoot)->left = associative_array_insert(&((*pRoot)->left), key, word, pStatus);
		//calculate current depth
		if ((*pRoot)->left != NULL && (*pRoot)->right != NULL)
		{
			if ((*pRoot)->left->depth >= (*pRoot)->right->depth)
			{
				(*pRoot)->depth = (*pRoot)->left->depth + 1;
			}
			else
			{
				(*pRoot)->depth = (*pRoot)->right->depth + 1;
			}
		}
		else if ((*pRoot)->left != NULL)
		{
			(*pRoot)->depth = (*pRoot)->left->depth + 1;
		}
		else if ((*pRoot)->right != NULL)
		{
			(*pRoot)->depth = (*pRoot)->right->depth + 1;
		}
		else
		{
			(*pRoot)->depth = 0;
		}
		//balance if necessary
		if ((*pRoot)->right != NULL)
		{
			right_depth = (*pRoot)->right->depth + 1;
		}
		if ((*pRoot)->left != NULL)
		{
			left_depth = (*pRoot)->left->depth + 1;
		}
		balance = right_depth - left_depth;
		if (balance > 1 || balance < -1)
		{
			associative_array_balance(pRoot, balance);
		}
		return (*pRoot);
	}
	else if (my_string_compare(key, (*pRoot)->data->key) > 0)
	{
		//traverse right
		(*pRoot)->right = associative_array_insert(&((*pRoot)->right), key, word, pStatus);
		//calculate current depth
		if ((*pRoot)->left != NULL && (*pRoot)->right != NULL)
		{
			if ((*pRoot)->left->depth >= (*pRoot)->right->depth)
			{
				(*pRoot)->depth = (*pRoot)->left->depth + 1;
			}
			else
			{
				(*pRoot)->depth = (*pRoot)->right->depth + 1;
			}
		}
		else if ((*pRoot)->left != NULL)
		{
			(*pRoot)->depth = (*pRoot)->left->depth + 1;
		}
		else if ((*pRoot)->right != NULL)
		{
			(*pRoot)->depth = (*pRoot)->right->depth + 1;
		}
		else
		{
			(*pRoot)->depth = 0;
		}
		//balance if necessary
		if ((*pRoot)->right != NULL)
		{
			right_depth = (*pRoot)->right->depth + 1;
		}
		if ((*pRoot)->left != NULL)
		{
			left_depth = (*pRoot)->left->depth + 1;
		}
		balance = right_depth - left_depth;
		if (balance > 1 || balance < -1)
		{
			associative_array_balance(pRoot, balance);
		}
		return (*pRoot);
	}
	else
	{
		//correct position
		if (generic_vector_push_back((*pRoot)->data->vector, word) == FAILURE)
		{
			if (pStatus != NULL) *pStatus = FAILURE;
		}
		if (pStatus != NULL) *pStatus = SUCCESS;
		return (*pRoot);
	}
	return NULL;
}

void associative_array_balance(Node** pRoot, int balance)
{
	Node* temp = NULL;
	Node* orphan = NULL;
	if ((*pRoot) != NULL)
	{
		if (balance > 1)
		{
			//Left Rotation
			if ((*pRoot)->right != NULL && (*pRoot)->right->right != NULL && (*pRoot)->right->left != NULL)
			{
				if ((*pRoot)->right->right->depth - (*pRoot)->right->left->depth < 0)
				{
					//right rotate root->right
					orphan = (*pRoot)->right->left->right;
					temp = (*pRoot)->right;
					(*pRoot)->right = (*pRoot)->right->left;
					(*pRoot)->right->right = temp;
					(*pRoot)->right->right->left = orphan;
				}
			}
			orphan = (*pRoot)->right->left;
			temp = (*pRoot);
			(*pRoot) = (*pRoot)->right;
			(*pRoot)->left = temp;
			(*pRoot)->left->right = orphan;
		}
		else if (balance < -1)
		{
			//Right Rotation
			if ((*pRoot)->left != NULL && (*pRoot)->left->left != NULL && (*pRoot)->left->right != NULL)
			{
				if ((*pRoot)->left->left->depth - (*pRoot)->left->right->depth > 0)
				{
					//left rotate root->left
					orphan = (*pRoot)->left->right->left;
					temp = (*pRoot)->left;
					(*pRoot)->left = (*pRoot)->left->right;
					(*pRoot)->left->left = temp;
					(*pRoot)->left->left->right = orphan;
				}
			}
			orphan = (*pRoot)->left->right;
			temp = (*pRoot);
			(*pRoot) = (*pRoot)->left;
			(*pRoot)->right = temp;
			(*pRoot)->right->left = orphan;
		}
	}
	return;
}

Node* associative_array_largest(Node** pRoot)
{
	Node* root = *pRoot;
	Node* largest_left = NULL;
	Node* largest_right = NULL;
	Node* largest = NULL;
	debug_count++;
	//recursively call on left child, recieve largest node of left subtree
	if (root->left != NULL)
	{
		largest_left = associative_array_largest(&(root->left));
	}
	//recursively call on right child, recieve largest node of right subtree
	if (root->right != NULL)
	{
		largest_right = associative_array_largest(&(root->right));
	}
	//compare left and right and delete smallest
	if (largest_right == NULL)
	{
		largest = largest_left;
	}
	else if (largest_left == NULL)
	{
		largest = largest_right;
	}
	else if (largest_left == NULL && largest_right == NULL)
	{
		largest = NULL;
	}
	else if (generic_vector_get_size(largest_left->data->vector) >= generic_vector_get_size(largest_right->data->vector))
	{
		largest = largest_left;
		generic_vector_destroy(&(largest_right->data->vector));
		my_string_destroy(&(largest_right->data->key));
		free(largest_right->data);
		free(largest_right);
	}
	else
	{
		largest = largest_right;
		generic_vector_destroy(&(largest_left->data->vector));
		my_string_destroy(&(largest_left->data->key));
		free(largest_left->data);
		free(largest_left);
	}
	//compare largest of the two and the current node and delete smallest
	if (largest == NULL)
	{
		largest = root;
	}
	else if (generic_vector_get_size(largest->data->vector) >= generic_vector_get_size(root->data->vector))
	{
		generic_vector_destroy(&(root->data->vector));
		my_string_destroy(&(root->data->key));
		free(root->data);
		free(root);
	}
	else
	{
		generic_vector_destroy(&(largest->data->vector));
		my_string_destroy(&(largest->data->key));
		free(largest->data);
		free(largest);
		largest = root;
	}
	//largest is now the largest node in this subtree
	//set parent pointer to null and return with largest
	root = NULL;
	return largest;
}

//Returns how many levels to the max depth
int associative_array_calibrate_depth(Node* root)
{
	int left_depth;
	int right_depth;
	if (root == NULL)
	{
		return 0;
	}
	left_depth = associative_array_calibrate_depth(root->left);
	right_depth = associative_array_calibrate_depth(root->right);
	if (left_depth >= right_depth)
	{
		root->depth = left_depth;
		return left_depth + 1;
	}
	else
	{
		root->depth = right_depth;
		return right_depth + 1;
	}
}

//returns the depth of the root given, adds 1 to unbalance_count if the root is unbalanced
int associative_array_calculate_balance(Node* root, int* unbalance_count)
{
	int left_depth;
	int right_depth;
	int balance;
	if (root == NULL)
	{
		return 0;
	}
	left_depth = associative_array_calculate_balance(root->left, unbalance_count);
	right_depth = associative_array_calculate_balance(root->right, unbalance_count);
	balance = right_depth - left_depth;
	if (balance > 1 || balance < -1)
	{
		(*unbalance_count)++;
	}
	if (left_depth >= right_depth)
	{
		return left_depth + 1;
	}
	else
	{
		return right_depth + 1;
	}
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
