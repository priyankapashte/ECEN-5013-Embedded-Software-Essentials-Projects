#ifndef _PROJECT_1_H
#define _PROJECT_1_H

/***************************************************************************************
* project1_report
* set_1 : Create an array of 32 bytes (unsigned). Initialize this array to increasing
*         hex numbers like: 0x0123456789ABCDEF0123456789ABCDEF
* set_2 : Create another array of 32 bytes (unsigned). Initialize this array to an
*         increasing integer count of 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, …., 31.
* set_3 : Create another array of 32 bytes (unsigned). Initialize this array to an
*         increasing integer count of “abcdefghijklmnopqrstuvwxyzABCDEF”
****************************************************************************************/
void project_1_report();

/***************************************************************************************
* test_data1
* Test the data functions work by calling the following functions in the given order
* with the first array, set_1 :
* 1. print_memory()
* 2. big_to_little32()
* 3. print_memory()
* 4. little_to_big32()
* 5. print_memory()
***************************************************************************************/
void test_data1();

/**************************************************************************************
* test_data2
* Test the data functions work by calling the following functions in the given order
* with the second array, set_2 : my_itoa() & then print_memory()
***************************************************************************************/
void test_data2();

/**************************************************************************************
* test_data3
* Test the data functions work by calling the following functions in the given order
* with the second array, set_3 : my_atoi() & then print_memory()
***************************************************************************************/
void test_data3();

/**************************************************************************************
* test_memory
* Performs the following operations on a point to the set_2 data block.
* 1. print_memory(); all 32 bytes
* 2. my_reverse(); On the first 12 bytes
* 3. my_memset(); Set 0xEE on the 17th to the 20th bytes ([16]-[19])
* 4. my_memmove(); Move the 6 bytes starting at the 26th byte([25]),
* to the 20th position ([19])
* 5. memzero(); Bytes 12 - 16 ([11] - [15])
* 6. my_memmove(); Move the 8 bytes starting at the 1st byte ([0]),
* to the 9th position ([8])
* 7. print_memory(); all 32 bytes
***************************************************************************************/
void test_memory();

#endif
