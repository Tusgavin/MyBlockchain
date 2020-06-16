#ifndef BLOCK_CPP
#define BLOCK_CPP

#include "Block.h"


Block::Block(std::time_t _timestamp, std::string _last_hash, int _nonce, int _difficulty, std::string _current_hash, std::string _hash_data) {
	this->timestamp = _timestamp;
	this->last_hash = _last_hash;
	this->nonce = _nonce;
	this->difficulty = _difficulty;
	this->current_hash = _current_hash;
	this->hash_data = _hash_data;
}

Block::~Block() {

}

std::string Block::get_current_hash() {
	return this->current_hash;
}

int Block::get_difficulty() {
	return this->difficulty;
}

std::time_t Block::get_timestamp() {
	return this->timestamp;
}

int Block::get_nonce() {
	return this->nonce;
}

std::string Block::get_hash_data() {
	return this->hash_data;
}

std::string Block::get_last_hash() {
	return this->last_hash;
}

std::string Block::block2string() {
	std::string block_string;

	std::string string_timestamp = to_string(this->get_timestamp());
	std::string string_nonce = to_string(this->get_nonce());
	std::string string_difficulty = to_string(this->get_difficulty());
	
	block_string = string_timestamp + this->last_hash + string_nonce + string_difficulty + this->get_current_hash() + this->get_hash_data();

	return block_string;
} 

std::unique_ptr<Block> Block::Genesis() {
	std::string genesis_hash_data = "GENESIS_HASH_DATA";

	std::unique_ptr<Block> Genesis = std::make_unique<Block>(1, "-", 0, INITIAL_DIF, "GENESIS_HASH", genesis_hash_data);

	return Genesis;
}

std::unique_ptr<Block> Block::mineBlock(std::time_t last_block_timestamp, int last_block_difficulty, std::string last_block_hash, std::string _hash_data) {
	std::time_t _timestamp;
	int _difficulty;
	std::string mine_block_hash;
	std::string mine_block_binary;
	int _nonce = 0;

	do {
		_nonce++;

		_timestamp = std::time(0);
		_difficulty = Block::adjustDifficulty(last_block_timestamp, last_block_difficulty, _timestamp);

		std::string string_timestamp = to_string(_timestamp);
		std::string string_nonce = to_string(_nonce);
		std::string string_difficulty = to_string(_difficulty);

		std::string mine_block_string = last_block_hash + string_timestamp + string_nonce + string_difficulty + _hash_data;

		std::string mine_block_hash = sha256(mine_block_string);
		std::string mine_block_binary = hex2binary(mine_block_hash);

	} while (checking4proof(mine_block_binary, _difficulty));

	std::unique_ptr<Block> new_block = std::make_unique<Block>(_timestamp, last_block_hash, _nonce, _difficulty, mine_block_hash, _hash_data);

	return new_block;
}

int Block::adjustDifficulty(std::time_t last_block_timestamp, int last_block_difficulty, time_t new_timestamp) {
	if (last_block_difficulty < 1) {
		return 1;
	}

	if ((new_timestamp - last_block_timestamp) > MINE_RATE) {
		return last_block_difficulty - 1;
	}

	return last_block_difficulty + 1;
}


#endif  //BLOCK_CPP