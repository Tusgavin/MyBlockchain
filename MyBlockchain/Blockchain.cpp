#ifndef BLOCKCHAIN_CPP
#define BLOCKCHAIN_CPP

#include "Blockchain.h"

Blockchain::Blockchain() {
	this->addBlock(Block::Genesis());
}

Blockchain::~Blockchain() {

}

void Blockchain::addBlock(std::unique_ptr<Block> new_block) {
	this->chain.push_back(std::move(new_block));
}

std::string Blockchain::get_last_block_hash() {
	return this->chain.at(this->chain.size() - 1)->get_current_hash();
}

int Blockchain::get_last_block_difficulty() {
	return this->chain.at(this->chain.size() - 1)->get_difficulty();
}

std::time_t Blockchain::get_last_block_timestamp() {
	return this->chain.at(this->chain.size() - 1)->get_timestamp();
}


#endif  //BLOCKCHAIN_CPP