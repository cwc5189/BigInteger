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
		std::deque<char> temp;
		std::string da = "";
		int remainder = 0, sum = 0, i = 0, additive = 0;

		BigInt max = other.length() < length() ? *this : other;
		BigInt min = other.length() < length() ? other : *this;
		int least = min.length(), most = max.length();

		for(; i < most; i++){
			if(i < least)
				additive = min.num[least-1-i] -'0';
			else
				additive = 0;

			sum = ((max.num[most-1-i]-'0') + additive) + remainder;
			remainder = sum /10;

			if(sum/10)
				sum %= 10;

			max.num[most-i-1] = (char)(sum + '0');
		}

		if(remainder)
			max.num = '1' + max.num;

		return max;

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

	BigInt BigInt::operator^(BigInt other){
		BigInt temp(1);
		for(BigInt i(0); i != other; i = i + 1){
			temp = temp * *this;
		}

		return temp;
	}

	BigInt BigInt::operator^(int pow){
		BigInt p(pow);

		return *this ^ p;
	}


	std::string BigInt::toString() const{
		return num;
	}

	std::ostream & operator<<(std::ostream &os, const BigInt& o){
		return os << o.num;
	}

