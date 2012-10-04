#include "BigInt.h"

	// Default constructor
	BigInt::BigInt(): num("0") {
		
	}

	// Integer constructor
	BigInt::BigInt(const int other){
		std::stringstream convert;

		convert << other;

		num = convert.str();
	}

	// String constructor
	BigInt::BigInt(std::string other) : num(other) {}

	// Integer assignment
	BigInt BigInt::operator=(const int other){
		*this = BigInt(other);
		return *this;
	}

	// Get value at place i
	int BigInt::at(int i){
		return (num.at(length() - 1 - i) - '0');
	}
	
	// Return number of digits
	double BigInt::length(){
		return num.length();
	}

	bool BigInt::operator!=(BigInt& other){
		bool equal = num == other.num;
		return !equal;
	}

	BigInt BigInt::operator+(BigInt other){
		std::string temp = "";
		int remainder = 0, sum = 0, i = 0, additive = 0;
		int least = other.length() < length() ? other.length() : length();
		BigInt max = other.length() < length() ? *this : other;
		BigInt min = other.length() < length() ? other : *this;

		for(; i < max.length(); i++){
			if(i < least)
				additive = min.at(i);
			else
				additive = 0;

			sum = (max.at(i) + additive) + remainder;
			remainder = sum /10;

			if(sum/10)
				sum %= 10;

			temp =  (char)(sum + '0') + temp;
		}

		if(remainder)
			temp = '1' + temp;
			
		BigInt result(temp);

		return result;

	}

	BigInt BigInt::operator+(int other){
		std::stringstream ss;
		ss << other;
		BigInt temp(ss.str());
		return *this + temp;
	}

	BigInt BigInt::operator*(BigInt other){
		BigInt temp = 0;
		for(BigInt i(0); i != other; i = i + 1){
			temp = temp + *this;
		}

		return temp;
	}

	BigInt BigInt::operator^(int pow){
		BigInt temp(1);
		for(int i = 0; i < pow; i++){
			temp =  temp * *this;
		}

		return temp;
	}


	std::string BigInt::toString(){
		return num;
	}

	std::ostream & operator<<(std::ostream &os, const BigInt& o){
		return os << o.num;
	}

