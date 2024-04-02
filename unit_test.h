#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"
#include "status.h"

//When new test functions are made, they must be added to the list below.
Status test_init_default_returns_nonNULL(char* buffer, int length);

Status test_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_sstanley_get_capacity_on_init_default_returns_7(char* buffer, int length);

Status test_sstanley_init_c_string_returns_nonNULL(char* buffer, int length);

Status test_sstanley_get_size_on_init_c_string_returns_0_for_empty_string(char* buffer, int length);

Status test_sstanley_get_capacity_on_init_c_string_returns_1_for_empty_string(char* buffer, int length);

Status test_sstanley_get_size_on_init_c_string_returns_3_for_string_the(char* buffer, int length);

Status test_sstanley_get_capacity_on_init_c_string_returns_4_for_string_the(char* buffer, int length);

Status test_sstanley_push_back_returns_SUCCESS_on_string_with_size_less_than_capacity(char* buffer, int length);

Status test_sstanley_get_size_on_push_back_returns_1_more_than_previous(char* buffer, int length);

Status test_sstanley_get_capacity_on_push_back_returns_same_on_string_with_size_less_than_capacity(char* buffer, int length);

Status test_sstanley_push_back_returns_SUCCESS_on_string_with_size_equals_capacity(char* buffer, int length);

Status test_sstanley_get_capacity_on_push_back_returns_double_on_string_with_size_equals_capacity(char* buffer, int length);

Status test_sstanley_get_size_on_concat_returns_result_size_plus_append_size(char* buffer, int length);

Status test_sstanley_c_str_returns_address_of_correct_c_string(char* buffer, int length);

Status test_sstanley_get_size_on_pop_back_returns_1_less_than_previous(char* buffer, int length);

Status test_sstanley_compare_returns_negative_on_left_smaller_than_right(char* buffer, int length);

Status test_sstanley_compare_returns_positive_on_left_bigger_than_right(char* buffer, int length);

Status test_sstanley_compare_returns_0_on_left_equals_right(char* buffer, int length);

Status test_sstanley_compare_returns_negative_on_left_prefix_of_right(char* buffer, int length);

Status test_sstanley_at_returns_correct_address_for_index_in_bounds(char* buffer, int length);

Status test_sstanley_empty_returns_TRUE_if_string_empty(char* buffer, int length);

//Requires a file called "test_input_sentence.txt" to be in the same directory as the code files with a sentence "The quick brown fox jumped over the lazy dogs."
Status test_sstanley_extraction_writes_word_from_file_with_sentence_to_string(char* buffer, int length);

//Requires a file called "test_output.txt" to be in the same directory as the code files.
Status test_sstanley_insertion_writes_non_empty_string_to_file(char* buffer, int length);

Status test_sstanley_string_is_NULL_after_destroy(char* buffer, int length);

Status test_sstanley_get_size_on_assignment_returns_right_size(char* buffer, int length);

Status test_sstanley_get_capacity_on_assignment_returns_same_without_resize(char* buffer, int length);

Status test_sstanley_get_capacity_on_assignment_returns_right_with_resize(char* buffer, int length);

Status test_sstanley_get_size_on_init_copy_returns_copied_size(char* buffer, int length);

Status test_sstanley_get_capacity_on_init_copy_returns_copied_capacity(char* buffer, int length);

Status test_sstanley_at_returns_same_last_element_value_as_copied(char* buffer, int length);

Status test_sstanley_get_size_on_swap_returns_swapped_values(char* buffer, int length);

Status test_sstanley_get_capacity_on_swap_returns_swapped_values(char* buffer, int length);

Status test_sstanley_at_element_zero_returns_swapped_addresses(char* buffer, int length);

#endif
