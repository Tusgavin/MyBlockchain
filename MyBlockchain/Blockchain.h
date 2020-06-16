#pragma once

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <memory>
#include <ctime>
#include "utils.h"
#include "Block.h"

class Blockchain
{
private:
	std::vector<std::unique_ptr<Block>> chain;

public:

	Blockchain();
	~Blockchain();

	void addBlock(std::unique_ptr<Block> new_block);

	std::string get_last_block_hash();
	int get_last_block_difficulty();
	std::time_t get_last_block_timestamp();
};

#endif  //BLOCKCHAIN_H