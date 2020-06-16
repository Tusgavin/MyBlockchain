#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>
#include <vector>
#include <memory>
#include <boost/lexical_cast.hpp>

#include "utils.h"
#include "Transaction.h"


#define MINE_RATE 100
#define INITIAL_DIF 3

class Block
{
private:
	std::time_t timestamp;
	std::string last_hash;
	int nonce;
	int difficulty;
	std::string current_hash;

	std::string hash_data;

public:
	Block(std::time_t _timestamp, std::string _last_hash, int _nonce, int _difficulty, std::string _current_hash, std::string _hash_data);
	~Block();

	std::string get_current_hash();
	int get_difficulty();
	std::time_t get_timestamp();
	int get_nonce();
	std::string get_hash_data();
	std::string get_last_hash();

	std::string block2string();

	static std::unique_ptr<Block> Genesis();
	static std::unique_ptr<Block> mineBlock(std::time_t last_block_timestamp, int last_block_difficulty, std::string last_block_hash, std::string _hash_data);
	static int adjustDifficulty(std::time_t original_timestamp, int original_difficulty, std::time_t new_timestamp);
};

#endif  //BLOCK_H