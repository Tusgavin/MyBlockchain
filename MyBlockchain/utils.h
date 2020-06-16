#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include "Block.h"
#include "openssl/sha.h"

template<typename T>
std::string to_string(T arg) {
	return boost::lexical_cast<std::string>(arg);
};

const char* hex_char2bin(char c);
std::string sha256(const std::string str);
std::string hex2binary(const std::string str);

bool checking4proof(const std::string str, const unsigned int difficulty);

#endif  //UTILS_H