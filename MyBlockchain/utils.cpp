#ifndef UTILS_CPP
#define UTILS_CPP

#include "utils.h"

const char* hex_char2bin(char c) {
	switch (toupper(c))
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	default: 
		std::cout << "Not Hex char" << std::endl;
		exit(1);
	}
}

std::string sha256(const std::string str) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
	std::stringstream ss;
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
	}
	return ss.str();
}

std::string hex2binary(const std::string str) {
	std::string bin;
	for (unsigned i = 0; i != str.length(); ++i)
		bin += hex_char2bin(str[i]);
	return bin;
}

bool checking4proof(const std::string str, const unsigned int difficulty) {
	for (unsigned i = 0; i != difficulty; ++i) {
		if (str[i] != '0') {
			return true;
		}
	}
	return false;
}

#endif  //UTILS_CPP