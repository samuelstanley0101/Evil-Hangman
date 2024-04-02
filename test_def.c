#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "status.h"
#include "boolean.h"
#include "unit_test.h"

/*
Copy paste-able code to lesson the monotony of it all

		strncpy(buffer,
			"\t \n"
			length);

*/

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	
	hMy_string = my_string_init_default();

	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_init_default_returns_nonNULL\n"
			"\tmy_string_init_default_returns NULL\n",
			length);
		return FAILURE;
	}
	else
	{
		my_string_destroy(&hMy_string);
		strncpy(buffer,
			"\ttest_init_default_returns_nonNULL\n",
			length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_default();
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_get_size_on_init_default_returns_0\n"
			"\tfailed allocation of init_default\n",
			length);
		return FAILURE;
	}

	if(my_string_get_size(hMy_string) != 0)
	{
		status = FAILURE;
		printf("ERROR: Expected a size of 0 but got %d\n", my_string_get_size(hMy_string));
		strncpy(buffer,
			"\ttest_get_size_on_init_default_returns_0\n"
			"\tDid not recieve 0 from get_size after init_default\n",
			length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer,
			"\ttest_get_size_on_init_default_returns_0\n",
			length);
	}

	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_default();
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_default_returns_7\n"
			"\tfailed allocation of init_default\n",
			length);
		return FAILURE;
	}

	if(my_string_get_capacity(hMy_string) != 7)
	{
		status = FAILURE;
		printf("ERROR: Expected a capacity of 7 but got %d\n", my_string_get_capacity(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_default_returns_7\n"
			"\tDid not recieve 7 from get_capacity after init_default\n",
			length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_default_returns_7\n",
			length);
	}

	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_init_c_string_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;

	hMy_string = my_string_init_c_string("Test_string");

	if(hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_init_c_string_returns_nonNULL\n"
			"\tmy_string_init_c_string returns NULL\n",
			length);
		return FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_init_c_string_returns_nonNULL\n",
			length);
		my_string_destroy(&hMy_string);
		return SUCCESS;
	}
}

Status test_sstanley_get_size_on_init_c_string_returns_0_for_empty_string(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_0_for_empty_string\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (my_string_get_size(hMy_string) != 0)
	{
		printf("ERROR: Expected a size of 0 but got %d\n", my_string_get_size(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_0_for_empty_string\n"
			"\tdid not recieve 0 from my_string_get_size after my_string_init_c_string for the empty string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_0_for_empty_string\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string(char* buffer, int length)
{	
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (my_string_get_capacity(hMy_string) != 1)
	{
		printf("ERROR: Expected a size of 1 but got %d\n", my_string_get_capacity(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string\n"
			"\tdid not recieve 1 from my_string_get_capacity after my_string_init_c_string for the empty string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_size_on_init_c_string_returns_3_for_string_the(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_3_for_string_the\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (my_string_get_size(hMy_string) != 3)
	{
		printf("ERROR: Expected a size of 3 but got %d\n", my_string_get_size(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_3_for_string_the\n"
			"\tdid not recieve 3 from my_string_get_size after my_string_init_c_string for string 'the'\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_c_string_returns_3_for_string_the\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (my_string_get_capacity(hMy_string) != 4)
	{
		printf("ERROR: Expected a capacity of 4 but got %d\n", my_string_get_capacity(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the\n"
			"\tdid not recieve 4 from my_string_get_capacity after my_string_init_c_string for the empty string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	status = my_string_push_back(hMy_string, 's');
	if (status == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity\n"
			"\tmy_string_push_back returns FAILURE when there is sufficient capacity for another character\n",
			length);
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity\n",
			length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_size_on_push_back_returns_1_more_than_previous(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_push_back_returns_1_more_than_previous\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (!my_string_push_back(hMy_string, 's'))
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_push_back_returns_1_more_than_previous\n"
			"\tmy_string_push_back failed a resize operation, a re-run is recommended.\n",
			length);
		status = FAILURE;
	}

	if (my_string_get_size(hMy_string) != 4)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_push_back_returns_1_more_than_previous\n"
			"\tdid not recieve 4 from get_size after push_back on a string with size 3\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_push_back_returns_1_more_than_previous\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	if (!my_string_push_back(hMy_string, 's'))
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity\n"
			"\tmy_string_push_back failed a resize operation, a re-run is recommended.\n",
			length);
		status = FAILURE;
	}
	else if (my_string_get_capacity(hMy_string) != 4)
	{
		printf("ERROR: Expected a capacity of 4 but got %d\n", my_string_get_capacity(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity\n"
			"\tdid not recieve 4 from get_capacity after push_back on a string with size 3 and capacity 4\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	my_string_push_back(hMy_string, 's');

	status = my_string_push_back(hMy_string, 'e');
	if (status == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity\n"
			"\tmy_string_push_back returns FAILURE when a resize operation is required\n",
			length);
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity\n",
			length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("the");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	my_string_push_back(hMy_string, 's');

	my_string_push_back(hMy_string, 'e');
	if (my_string_get_capacity(hMy_string) != 8)
	{
		printf("ERROR: Expected a capacity of 8 but got %d\n", my_string_get_capacity(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity\n"
			"\tdid not recieve 8 from get_capacity after push_back on a string with size 4 and capacity 4\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_size_on_concat_returns_result_size_plus_append_size(char* buffer, int length)
{
	MY_STRING hResult = NULL;
	MY_STRING hAppend = NULL;
	int result_size;
	int append_size;
	Status status;

	hResult = my_string_init_c_string("this is");
	if (hResult == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_concat_returns_result_size_plus_append_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hAppend = my_string_init_c_string(" the appended string");
	if (hAppend == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_concat_returns_result_size_plus_append_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hResult);
		return FAILURE;
	}

	result_size = my_string_get_size(hResult);
	append_size = my_string_get_size(hAppend);

	if (my_string_concat(hResult, hAppend) == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_concat_returns_result_size_plus_append_size\n"
			"\tfailed allocation of memory for my_string_concat\n",
			length);
		my_string_destroy(&hResult);
		my_string_destroy(&hAppend);
		return FAILURE;
	}

	if (my_string_get_size(hResult) != result_size + append_size)
	{
		printf("ERROR: expected a capacity of %d, but recieved %d instead\n", result_size + append_size, my_string_get_size(hResult));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_concat_returns_result_size_plus_append_size\n"
			"\tdid not recieve result_size + append_size from get_size after concat\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_concat_returns_result_size_plus_append_size\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hResult);
	my_string_destroy(&hAppend);
	return status;
}

Status test_sstanley_c_str_returns_address_of_correct_c_string(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	char* c_str = NULL;
	Status status;
	int i;

	hMy_string = my_string_init_c_string("this is a c string");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_c_str_returns_address_of_correct_c_string\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	c_str = my_string_c_str(hMy_string);
	if (c_str == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_c_str_returns_address_of_correct_c_string\n"
			"\tfailed a resize operation by c_str\n",
			length);
		my_string_destroy(&hMy_string);
		return FAILURE;
	}

	i = 0;
	status = SUCCESS;
	while (i < my_string_get_size(hMy_string) && status == SUCCESS)
	{
		if (c_str[i] != *(my_string_at(hMy_string, i)))
		{	
			printf("ERROR: expected a c_str value of %c at index %d, but recieved %c\n", *(my_string_at(hMy_string, i)), i, c_str[i]);
			strncpy(buffer,
				"\ttest_sstanley_c_str_returns_address_of_correct_c_string\n"
				"\tc_str did not point to the same value as hMy_string->data\n",
				length);
			status = FAILURE;
		}
		i++;
	}
	if (status != FAILURE && c_str[i] != '\0')
	{
		strncpy(buffer,
			"\ttest_sstanley_c_str_returns_address_of_correct_c_string\n"
			"\tc_str is not NULL-terminated\n",
			length);
		status = FAILURE;
	}

	if (status == SUCCESS)
	{	
		strncpy(buffer,
			"\ttest_sstanley_c_str_returns_address_of_correct_c_string\n",
			length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_get_size_on_pop_back_returns_1_less_than_previous(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("tests");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_pop_back_returns_1_less_than_previous\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	my_string_pop_back(hMy_string);
	if (my_string_get_size(hMy_string) != 4)
	{
		printf("ERROR: expected a size value of 4 but recieved %d\n", my_string_get_size(hMy_string));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_pop_back_returns_1_less_than_previous\n"
			"\tdid not recieve 4 from get_size after pop_back of a string with size 5\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_pop_back_returns_1_less_than_previous\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_compare_returns_negative_on_left_smaller_than_right(char* buffer, int length)
{
	MY_STRING hLeft_string = NULL;
	MY_STRING hRight_string = NULL;
	Status status;

	hLeft_string = my_string_init_c_string("greater");
	if (hLeft_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_smaller_than_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight_string = my_string_init_c_string("smaller");
	if (hRight_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_smaller_than_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft_string);
		return FAILURE;
	}

	if (my_string_compare(hLeft_string, hRight_string) >= 0)
	{
		printf("ERROR: expected a compare value less than 0 but recieved %d\n", my_string_compare(hLeft_string, hRight_string));
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_smaller_than_right\n"
			"\tdid not recieve a negative value from compare of a lexiographically smaller left string than right string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_smaller_than_right\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);
	return status;
}

Status test_sstanley_compare_returns_positive_on_left_bigger_than_right(char* buffer, int length)
{
	MY_STRING hLeft_string = NULL;
	MY_STRING hRight_string = NULL;
	Status status;

	hLeft_string = my_string_init_c_string("smaller");
	if (hLeft_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_positive_on_left_bigger_than_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight_string = my_string_init_c_string("greater");
	if (hRight_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_positive_on_left_bigger_than_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft_string);
		return FAILURE;
	}

	if (my_string_compare(hLeft_string, hRight_string) <= 0)
	{
		printf("ERROR: expected a compare value greater than 0 but recieved %d\n", my_string_compare(hLeft_string, hRight_string));
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_positive_on_left_greater_than_right\n"
			"\tdid not recieve a positive value from compare of a lexiographically bigger left string than right string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_positive_on_left_bigger_than_right\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);
	return status;
}

Status test_sstanley_compare_returns_0_on_left_equals_right(char* buffer, int length)
{
	MY_STRING hLeft_string = NULL;
	MY_STRING hRight_string = NULL;
	Status status;

	hLeft_string = my_string_init_c_string("different");
	if (hLeft_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_0_on_left_equals_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight_string = my_string_init_c_string("different");
	if (hRight_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_0_on_left_equals_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft_string);
		return FAILURE;
	}

	if (my_string_compare(hLeft_string, hRight_string) != 0)
	{
		printf("ERROR: expected a compare value equal to 0 but recieved %d\n", my_string_compare(hLeft_string, hRight_string));
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_0_on_left_equals_right\n"
			"\tdid not recieve a value of 0 from compare of a lexiographically equal left and right string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_0_on_left_equals_than_right\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);
	return status;
}

Status test_sstanley_compare_returns_negative_on_left_prefix_of_right(char* buffer, int length)
{
	MY_STRING hLeft_string = NULL;
	MY_STRING hRight_string = NULL;
	Status status;

	hLeft_string = my_string_init_c_string("short");
	if (hLeft_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_prefix_of_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight_string = my_string_init_c_string("shorter");
	if (hRight_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_prefix_of_right\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft_string);
		return FAILURE;
	}

	if (my_string_compare(hLeft_string, hRight_string) >= 0)
	{
		printf("ERROR: expected a compare value less than 0 but recieved %d\n", my_string_compare(hLeft_string, hRight_string));
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_prefix_of_right\n"
			"\tdid not recieve a negative value from compare of a left string that is a prefix of the right string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_compare_returns_negative_on_left_prefix_of_right\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hLeft_string);
	my_string_destroy(&hRight_string);
	return status;
}

Status test_sstanley_at_returns_correct_address_for_index_in_bounds(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;
	char* str_at = NULL;

	hMy_string = my_string_init_c_string("abcdef");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_correct_address_for_index_in_bounds\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}

	str_at = my_string_at(hMy_string, 3);
	if (str_at == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_correct_address_for_index_in_bounds\n"
			"\tthe index given to my_string_at is out of bounds\n",
			length);
		my_string_destroy(&hMy_string);
		return FAILURE;
	}

	if (*str_at != 'd')
	{
		printf("ERROR: expected str_at to point to the character d, but it actually points to %c\n", *str_at);
		strncpy(buffer,
			"\ttest_sstanley_at_returns_correct_address_for_index_in_bounds\n"
			"\tdid not recieve the address of the correct element of the string through my_string_at\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_correct_address_for_index_in_bounds\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_sstanley_empty_returns_TRUE_if_string_empty(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_default();
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_empty_returns_TRUE_if_string_empty\n"
			"\tfailed allocation of init_default\n",
			length);
		return FAILURE;
	}

	if (!my_string_empty(hMy_string))
	{
		strncpy(buffer,
			"\ttest_sstanley_empty_returns_TRUE_if_string_empty\n"
			"\tempty returns FALSE when the string is initialized with size 0 by init_default\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_empty_returns_TRUE_if_string_empty\n",
			length);
		status = SUCCESS;
	}
	my_string_destroy(&hMy_string);
	return status;
}

//Requires a file called "test_input_sentence.txt" to be in the same directory as the code files with a sentence "The quick brown fox jumped over the lazy dogs."
Status test_sstanley_extraction_writes_word_from_file_with_sentence_to_string(char* buffer, int length)
{
	MY_STRING hExtracted = NULL;
	MY_STRING hCompare = NULL;
	Status status = SUCCESS;
	FILE* fp = NULL;

	fp = fopen("test_input_sentence.txt", "r");
	if (fp == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n"
			"\tfailed to open file 'test_input_sentence.txt' for reading\n",
			length);
		return FAILURE;
	}
	hCompare = my_string_init_c_string("The");
	if (hCompare == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n"
			"\tfailed allocation of init_c_string\n",
			length);
		fclose(fp); fp = NULL;
		return FAILURE;
	}
	hExtracted = my_string_init_default();
	if (hExtracted == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n"
			"\tfailed allocation of init_default\n",
			length);
		my_string_destroy(&hCompare);
		fclose(fp); fp = NULL;
		return FAILURE;
	}

	if (my_string_extraction(hExtracted, fp) == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n"
			"\tfailed extraction operation\n",
			length);
		status = FAILURE;
	}
	if (status == SUCCESS && my_string_compare(hExtracted, hCompare) != 0)
	{
		printf("ERROR: expected my_string_compare to return 0, but it returned %d\n", my_string_compare(hExtracted, hCompare));
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n"
			"\textraction does not accurately extract the first word after a file pointer\n",
			length);
		status = FAILURE;
	}
	else if (status == SUCCESS)
	{
		strncpy(buffer,
			"\ttest_sstanley_extraction_writes_word_from_file_with_sentence_to_string\n",
			length);
	}
	my_string_destroy(&hExtracted);
	my_string_destroy(&hCompare);
	fclose(fp); fp = NULL;
	return status;
}

//Requires a file called "test_output.txt" to be in the same directory as the code files.
Status test_sstanley_insertion_writes_non_empty_string_to_file(char* buffer, int length)
{
	MY_STRING hInserted = NULL;
	MY_STRING hExtracted = NULL;
	FILE* fp = NULL;
	Status status = SUCCESS;

	fp = fopen("test_output.txt", "w");
	if (fp == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed to open file 'test_output.txt' for writing\n",
			length);
		return FAILURE;
	}
	hInserted = my_string_init_c_string("non_empty_string");
	if (hInserted == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed allocation of init_c_string\n",
			length);
		fclose(fp); fp = NULL;
		return FAILURE;
	}

	if (my_string_insertion(hInserted, fp) == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed insertion operation\n",
			length);
		my_string_destroy(&hInserted);
		my_string_destroy(&hExtracted);
		fclose(fp); fp = NULL;
		return FAILURE;
	}
	fclose(fp);
	fp = fopen("test_output.txt", "r");
	if (fp == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed to open file 'test_output.txt' for reading\n",
			length);
		my_string_destroy(&hInserted);
		my_string_destroy(&hExtracted);
		return FAILURE;
	}


	hExtracted = my_string_init_default();
	if (hExtracted == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed allocation of init_default\n",
			length);
		my_string_destroy(&hInserted);
		fclose(fp); fp = NULL;
		return FAILURE;
	}

	if (my_string_extraction(hExtracted, fp) == FAILURE)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tfailed extraction operation\n",
			length);
		status = FAILURE;
	}
	if (status == SUCCESS && my_string_compare(hExtracted, hInserted) != 0)
	{
		printf("ERROR: expected my_string_compare to return 0, but it returned %d\n", my_string_compare(hExtracted, hInserted));
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n"
			"\tinsertion does not accurately insert its string into a file\n",
			length);
		status = FAILURE;
	}
	else if (status == SUCCESS)
	{
		strncpy(buffer,
			"\ttest_sstanley_insertion_writes_non_empty_string_to_file\n",
			length);
	}
	my_string_destroy(&hExtracted);
	my_string_destroy(&hInserted);
	fclose(fp); fp = NULL;
	return status;
}

Status test_sstanley_string_is_NULL_after_destroy(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;

	hMy_string = my_string_init_default();
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_string_is_NULL_after_destroy\n"
			"\tfailed allocation of init_default\n",
			length);
		return FAILURE;
	}

	my_string_destroy(&hMy_string);
	if (hMy_string != NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_string_is_NULL_after_destroy\n"
			"\thMy_string is not NULL after being destroyed\n",
			length);
		return FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_string_is_NULL_after_destroy\n",
			length);
		return SUCCESS;
	}
}

Status test_sstanley_get_size_on_assignment_returns_right_size(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	Status status;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_assignment_returns_right_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight = my_string_init_c_string("string");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_assignment_returns_right_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}

	if (my_string_assignment(hLeft, hRight) == FAILURE)
	{
		my_string_destroy(&hLeft);
		my_string_destroy(&hRight);
		return FAILURE;
	}

	if (my_string_get_size(hLeft) != my_string_get_size(hRight))
	{
		printf("ERROR: expected my_string_get_size to return %d, but it returned %d\n", my_string_get_size(hRight), my_string_get_size(hLeft));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_assignment_returns_right_size\n"
			"\tassignment does not accurately change size of left string to be right string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_assignment_returns_right_size\n",
			length);
		status = SUCCESS;
	}
	
	my_string_destroy(&hLeft);
	my_string_destroy(&hRight);
	return status;
}

Status test_sstanley_get_capacity_on_assignment_returns_same_without_resize(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	Status status;
	int former_capacity;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_same_without_resize\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	former_capacity = my_string_get_capacity(hLeft);
	hRight = my_string_init_c_string("str");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_same_without_resize\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}

	if (my_string_assignment(hLeft, hRight) == FAILURE)
	{
		my_string_destroy(&hLeft);
		my_string_destroy(&hRight);
		return FAILURE;
	}

	if (my_string_get_capacity(hLeft) != former_capacity)
	{
		printf("ERROR: expected my_string_get_capacity to return %d, but it returned %d\n", former_capacity, my_string_get_capacity(hLeft));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_same_without_resize\n"
			"\tassignment changes the capacity of left string when size of right is less than size of left\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_same_without_resize\n",
			length);
		status = SUCCESS;
	}
	
	my_string_destroy(&hLeft);
	my_string_destroy(&hRight);
	return status;
}

Status test_sstanley_get_capacity_on_assignment_returns_right_with_resize(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	Status status;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_right_with_resize\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hRight = my_string_init_c_string("string");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_right_with_resize\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}

	if (my_string_assignment(hLeft, hRight) == FAILURE)
	{
		my_string_destroy(&hLeft);
		my_string_destroy(&hRight);
		return FAILURE;
	}

	if (my_string_get_capacity(hLeft) != my_string_get_capacity(hRight))
	{
		printf("ERROR: expected my_string_get_capacity to return %d, but it returned %d\n", my_string_get_capacity(hRight), my_string_get_capacity(hLeft));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_right_with_resize\n"
			"\tassignment does not accurately change capacity of left string to be right string when size of right is greater than size of left\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_assignment_returns_right_with_resize\n",
			length);
		status = SUCCESS;
	}
	
	my_string_destroy(&hLeft);
	my_string_destroy(&hRight);
	return status;
}

Status test_sstanley_get_size_on_init_copy_returns_copied_size(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	MY_STRING hCopy = NULL;
	Status status;

	hMy_string = my_string_init_c_string("test_string");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_copy_returns_copied_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hCopy = my_string_init_copy(hMy_string);
	if (hCopy == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_copy_returns_copied_size\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hMy_string);
		return FAILURE;
	}

	if (my_string_get_size(hCopy) != my_string_get_size(hMy_string))
	{
		printf("ERROR: expected my_string_get_size to return %d, but it returned %d\n", my_string_get_size(hMy_string), my_string_get_size(hCopy));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_copy_returns_copied_size\n"
			"\tcopy does not accurately copy size from the origin My_string to the copy My_string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_init_copy_returns_copied_size\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hMy_string);
	my_string_destroy(&hCopy);
	return status;
}

Status test_sstanley_get_capacity_on_init_copy_returns_copied_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	MY_STRING hCopy = NULL;
	Status status;

	hMy_string = my_string_init_c_string("test_string");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_copy_returns_copied_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hCopy = my_string_init_copy(hMy_string);
	if (hCopy == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_copy_returns_copied_capacity\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hMy_string);
		return FAILURE;
	}

	if (my_string_get_capacity(hCopy) != my_string_get_capacity(hMy_string))
	{
		printf("ERROR: expected my_string_get_capacity to return %d, but it returned %d\n", my_string_get_capacity(hMy_string), my_string_get_capacity(hCopy));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_copy_returns_copied_capacity\n"
			"\tcopy does not accurately copy capacity from the origin My_string to the copy My_string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_init_copy_returns_copied_capacity\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hMy_string);
	my_string_destroy(&hCopy);
	return status;
}

Status test_sstanley_at_returns_same_last_element_value_as_copied(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	MY_STRING hCopy = NULL;
	Status status;

	hMy_string = my_string_init_c_string("test_string");
	if (hMy_string == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_same_last_element_value_as_copied\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	hCopy = my_string_init_copy(hMy_string);
	if (hCopy == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_same_last_element_value_as_copied\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hMy_string);
		return FAILURE;
	}

	if (*(my_string_at(hCopy, my_string_get_size(hCopy) - 1)) != *(my_string_at(hMy_string, my_string_get_size(hMy_string) - 1)))
	{
		printf("ERROR: expected my_string_at to return %c, but it returned %c\n", *(my_string_at(hMy_string, my_string_get_size(hMy_string) - 1)), *(my_string_at(hCopy, my_string_get_size(hCopy) - 1)));
		strncpy(buffer,
			"\ttest_sstanley_at_returns_same_last_element_value_as_copied\n"
			"\tcopy does not accurately copy the last element of the original string to the copy string\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_at_returns_same_last_element_value_as_copied\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hMy_string);
	my_string_destroy(&hCopy);
	return status;
}

Status test_sstanley_get_size_on_swap_returns_swapped_values(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	int left_size;
	int right_size;
	Status status;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_swap_returns_swapped_values\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	left_size = my_string_get_size(hLeft);
	hRight = my_string_init_c_string("string");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_swap_returns_swapped_values\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}
	right_size = my_string_get_size(hRight);
	
	my_string_swap(hLeft, hRight);

	if (my_string_get_size(hLeft) != right_size)
	{
		printf("ERROR: expected my_string_get_size to return %d, but it returned %d\n", right_size, my_string_get_size(hLeft));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_swap_returns_swapped_values\n"
			"\tswap does not correctly give the size of left the value of the size of right\n",
			length);
		status = FAILURE;
	}
	if (my_string_get_size(hRight) != left_size)
	{
		printf("ERROR: expected my_string_get_size to return %d, but it returned %d\n", left_size, my_string_get_size(hRight));
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_swap_returns_swapped_values\n"
			"\tswap does not correctly give the size of right the value of the size of left\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_size_on_swap_returns_swapped_values\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hRight);
	my_string_destroy(&hLeft);
	return status;
}

Status test_sstanley_get_capacity_on_swap_returns_swapped_values(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	int left_capacity;
	int right_capacity;
	Status status;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_swap_returns_swapped_values\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	left_capacity = my_string_get_capacity(hLeft);
	hRight = my_string_init_c_string("string");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_swap_returns_swapped_values\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}
	right_capacity = my_string_get_capacity(hRight);
	
	my_string_swap(hLeft, hRight);

	if (my_string_get_capacity(hLeft) != right_capacity)
	{
		printf("ERROR: expected my_string_get_capacity to return %d, but it returned %d\n", right_capacity, my_string_get_capacity(hLeft));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_swap_returns_swapped_values\n"
			"\tswap does not correctly give the capacity of left the value of the capacity of right\n",
			length);
		status = FAILURE;
	}
	if (my_string_get_capacity(hRight) != left_capacity)
	{
		printf("ERROR: expected my_string_get_capacity to return %d, but it returned %d\n", left_capacity, my_string_get_capacity(hRight));
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_swap_returns_swapped_values\n"
			"\tswap does not correctly give the capacity of right the value of the capacity of left\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_get_capacity_on_swap_returns_swapped_values\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hRight);
	my_string_destroy(&hLeft);
	return status;
}

Status test_sstanley_at_element_zero_returns_swapped_addresses(char* buffer, int length)
{
	MY_STRING hLeft = NULL;
	MY_STRING hRight = NULL;
	char* left_data = NULL;
	char* right_data = NULL;
	Status status;

	hLeft = my_string_init_c_string("test");
	if (hLeft == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_element_zero_returns_swapped_addresses\n"
			"\tfailed allocation of init_c_string\n",
			length);
		return FAILURE;
	}
	left_data = my_string_at(hLeft, 0);
	hRight = my_string_init_c_string("string");
	if (hRight == NULL)
	{
		strncpy(buffer,
			"\ttest_sstanley_at_element_zero_returns_swapped_addresses\n"
			"\tfailed allocation of init_c_string\n",
			length);
		my_string_destroy(&hLeft);
		return FAILURE;
	}
	right_data = my_string_at(hRight, 0);
	
	my_string_swap(hLeft, hRight);

	if (my_string_at(hLeft, 0) != right_data)
	{
		printf("ERROR: expected my_string_at to return %p, but it returned %p\n", right_data, my_string_at(hLeft, 0));
		strncpy(buffer,
			"\ttest_sstanley_at_element_zero_returns_swapped_addresses\n"
			"\tswap does not correctly give right's data pointer to left's data pointer\n",
			length);
		status = FAILURE;
	}
	if (my_string_at(hRight, 0) != left_data)
	{
		printf("ERROR: expected my_string_at to return %p, but it returned %p\n", left_data, my_string_at(hRight, 0));
		strncpy(buffer,
			"\ttest_sstanley_at_element_zero_returns_swapped_addresses\n"
			"\tswap does not correctly give left's data pointer to right's data pointer\n",
			length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer,
			"\ttest_sstanley_at_element_zero_returns_swapped_addresses\n",
			length);
		status = SUCCESS;
	}

	my_string_destroy(&hRight);
	my_string_destroy(&hLeft);
	return status;

}
