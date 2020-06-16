#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction
{
private:
	std::string sender_wallet;
	std::string receiver_wallet;
	float amount;
};


#endif  //TRANSACTION_H
