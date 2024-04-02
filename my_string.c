#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "status.h"
#include "boolean.h"

struct my_string
{
	//The amount of characters the string currently holds. Strings do not have null terminators, so size is exactly the amount of useful characters.
	//When applicable, set size with the iterator i, just for consistancy.
	int size;

	//The amount of characters the string can hold
	int capacity;

	//The string itself
	char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string == NULL)
	{
		return NULL;
	}

	pMy_string->size = 0;

	pMy_string->capacity = 7;

	pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
	if (pMy_string->data == NULL)
	{
		return NULL;
	}

	return (MY_STRING)pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	int i;
	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string == NULL)
	{
		return NULL;
	}

	pMy_string->size = 0;

	pMy_string->capacity = 0;
	while (c_string[pMy_string->capacity] != '\0')
	{
		pMy_string->capacity++;
	}
	pMy_string->size = pMy_string->capacity;
	pMy_string->capacity++;

	pMy_string->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
	if (pMy_string->data == NULL)
	{
		return NULL;
	}

	i = 0;
	while (i < pMy_string->size)
	{
		(pMy_string->data)[i]= c_string[i];
		i++;
	}

	return (MY_STRING)pMy_string;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;

	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;

	return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	int i;
	int compare_number;
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;
	
	//If size is 0 in either string
	if (pLeft_string->size <= 0 && pRight_string->size <= 0)
	{
		return 0;
	}
	else if (pLeft_string->size == 0)
	{
		return -1;
	}
	else if (pRight_string->size == 0)
	{
		return 1;
	}

	//Neither string has a size of 0
	i = 0;
	compare_number = ((pLeft_string->data)[i] - (pRight_string->data)[i]);

	while (compare_number == 0)
	{
		if (pLeft_string->size - 1 <= i && pRight_string->size - 1 <= i)
		{
			return compare_number;
		}
		else if (pLeft_string->size - 1 <= i)
		{
			return -1;
		}
		else if (pRight_string->size - 1 <= i)
		{
			return 1;
		}
		i++;
		compare_number = ((pLeft_string->data)[i] - (pRight_string->data)[i]);
	}

	return compare_number;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*)hMy_string;
	int c;
	char* temp = NULL;
	int i;
	int j;

	c = fgetc(fp);
	while (isspace(c))
	{
		c = fgetc(fp);
	}
	
	i = 0;
	while (c != EOF && !isspace(c))
	{
		if (pMy_string->capacity - 1 <= i)
		{
			temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
			if (temp == NULL)
			{
				return FAILURE;
			}
			j = 0;
			while (j < i)
			{
				temp[j] = (pMy_string->data)[j];
				j++;
			}
			free(pMy_string->data);
			pMy_string->data = temp;
			pMy_string->capacity *= 2;
		}
		(pMy_string->data)[i] = (char)c;
		c = fgetc(fp);
		i++;
	}

	if (i <= 0)
	{
		return FAILURE;
	}
	ungetc(c, fp);
	pMy_string->size = i;
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pMy_string = (My_string*)hMy_string;
	int i = 0;
	while (i < pMy_string->size)
	{
		if (fputc((pMy_string->data)[i], fp) == EOF)
		{
			return FAILURE;
		}
		i++;
	}
	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	int i;
	char* temp;
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size >= pMy_string->capacity)
	{
		temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pMy_string->size; i++)
		{
			temp[i] = (pMy_string->data)[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity *= 2;
	}
	(pMy_string->data)[pMy_string->size] = item;
	pMy_string->size++;
	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size <= 0)
	{
		return FAILURE;
	}
	(pMy_string->size)--;
	return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (index >= pMy_string->size || index < 0)
	{
		return NULL;
	}
	return pMy_string->data + index;
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	char* temp;
	int i;
	//If there is insufficient capacity to add the null terminator to the end of the string
	if (pMy_string->size >= pMy_string->capacity)
	{
		temp = (char*)malloc(sizeof(char) * (pMy_string->capacity + 1));
		if (temp == NULL)
		{
			return NULL;
		}
		for (i = 0; i < pMy_string->size; i++)
		{
			temp[i] = (pMy_string->data)[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity++;
	}
	(pMy_string->data)[pMy_string->size] = '\0';
	return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	My_string* pResult = (My_string*)hResult;
	My_string* pAppend = (My_string*)hAppend;
	char* temp;
	int i;
	//If there is insufficient capacity to append pAppend to hResult
	if (pResult->size + pAppend->size >= pResult->capacity)
	{
		temp = (char*)malloc(sizeof(char) * (pResult->capacity + pAppend->capacity));
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pResult->size; i++)
		{
			temp[i] = (pResult->data)[i];
		}
		free(pResult->data);
		pResult->data = temp;
		pResult->capacity += pAppend->capacity;
	}
	for (i = 0; i < pAppend->size; i++)
	{
		(pResult->data)[i + pResult->size] = (pAppend->data)[i];
	}
	pResult->size += pAppend->size;
	return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size > 0)
	{
		return FALSE;
	}
	return TRUE;
}

Status my_string_assignment(MY_STRING hLeft, MY_STRING hRight)
{
	My_string* pLeft = (My_string*)hLeft;
	My_string* pRight = (My_string*)hRight;
	char* temp;
	int i;

	if (pLeft->capacity < pRight->capacity)
	{
		temp = (char*)malloc(sizeof(char) * pRight->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		free(pLeft->data);
		pLeft->data = temp;
		pLeft->capacity = pRight->capacity;
	}
	for (i = 0; i < pRight->size; i++)
	{
		pLeft->data[i] = pRight->data[i];
	}
	pLeft->size = pRight->size;
	return SUCCESS;
}

MY_STRING my_string_init_copy(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	int i;
	My_string* pCopy = (My_string*)malloc(sizeof(My_string));
	if (pCopy != NULL)
	{
		pCopy->data = (char*)malloc(sizeof(char) * pMy_string->capacity);
		if (pCopy->data == NULL)
		{
			free(pCopy); pCopy = NULL;
			return NULL;
		}
		pCopy->capacity = pMy_string->capacity;
		for (i = 0; i < pMy_string->size; i++)
		{
			pCopy->data[i] = pMy_string->data[i];
		}
		pCopy->size = pMy_string->size;
	}
	return pCopy;
}

void my_string_swap(MY_STRING hLeft, MY_STRING hRight)
{
	My_string* pLeft = (My_string*)hLeft;
	My_string* pRight = (My_string*)hRight;
	int temp_size;
	int temp_capacity;
	char* temp_data;

	//temp = left
	temp_size = pLeft->size;
	temp_capacity = pLeft->capacity;
	temp_data = pLeft->data;
	//left = right
	pLeft->size = pRight->size;
	pLeft->capacity = pRight->capacity;
	pLeft->data = pRight->data;
	//right = temp
	pRight->size = temp_size;
	pRight->capacity = temp_capacity;
	pRight->data = temp_data;
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
	My_string* pNew_key = (My_string*)new_key;
	My_string* pWord = (My_string*)word;
	int i;

	if (my_string_assignment(new_key, current_word_family) == FAILURE)
	{
		return FAILURE;
	}

	for (i = 0; i < pWord->size; i++)
	{
		if (tolower(pWord->data[i]) == tolower(guess))
		{
			pNew_key->data[i] = tolower(guess);
		}
	}
	return SUCCESS;
}

void my_string_destroy(MY_STRING* phMy_string)
{
	My_string* pMy_string = (My_string*)*phMy_string;
	free(pMy_string->data); pMy_string->data = NULL;
	free(pMy_string); *phMy_string = NULL;
}
