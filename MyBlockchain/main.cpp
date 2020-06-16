#include <iostream>
#include <string>

#include "test.h"



#define TEST_UTILS 1

int main(int argc, char *argv[]) {

#if TEST_UTILS
	test_sha256();
	test_hex2binary();
	test_to_string();
	test_checking4proof();
#endif



	return 0;
}