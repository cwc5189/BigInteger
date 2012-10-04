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
		int remainder = 0, sum = 0, i = 0;
		int least = other.length() < length() ? other.length() : length();

		for(; i < least; i++){
			sum = (other.at(i) + at(i)) + remainder;
			remainder = sum /10;

			if(sum/10)
				sum %= 10;

			temp =  (char)(sum + '0') + temp;
		}

		std::string temp2 = (*this).num.substr(0, other.length() - least + 1);

		temp = other.length() > num.length() ? other.toString().substr(0, other.length() - least) + temp : num.substr(0, num.length() - least) + temp;
		
		if(remainder){
			if( i = temp.length() )
				if( temp.at(0) == '9' ){
					temp[0] = 0;
					temp = '1' + temp;
				}
				else
					temp[0] += remainder;
			else
				temp.at(temp.length() - least - 1) += 1;
		}
			

		BigInt result(temp);

		return result;

	}


	BigInt BigInt::operator*(BigInt other){
		BigInt temp = 0;
		for(BigInt i(0); i != other; i = i + 1){
			temp = temp + *this;
		}

		return temp;
	}

	BigInt BigInt::operator^(int pow){
		BigInt temp(0);
		for(int i = 0; i <= pow; i++){
			temp = temp + ( *this * *this );
		}

		return temp;
	}


	std::string BigInt::toString(){
		return num;
	}

	std::ostream & operator<<(std::ostream &os, const BigInt& o){
		return os << o.num;
	}

