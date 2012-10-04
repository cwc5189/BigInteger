#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <sstream>
#include <deque>

class BigInt {

public:
	BigInt();
	BigInt(const int other);
	BigInt::BigInt(std::string other);
	int at(int i);
	double length();
	bool operator!=(BigInt& other);
	BigInt operator=(const int other);
	BigInt operator+(BigInt other);
	BigInt operator+(int other);
	BigInt operator*(BigInt other);
	BigInt operator^(BigInt other);
	BigInt operator^(int pow);
	std::string toString() const;

private:
	std::string num;
	friend std::ostream & operator<<(std::ostream &os, const BigInt& i);

};

#endif //BIGINT_H