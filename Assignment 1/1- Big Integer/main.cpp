#include <iostream>
#include <algorithm>
#include <cstring>
#include <assert.h>
using namespace std;

class BigInt{
private:
    string num = "";
public:
    BigInt(){}
    BigInt (string decStr); // Initialize from string and rejects bad input
    BigInt (int decInt); // Initialize from integer
    BigInt operator+ (BigInt anotherDec);
    BigInt operator= (BigInt anotherDec);
    string subtract(string num1, string num2);
    string add(string num1, string num2);
    int size();
    bool isNumber(const string &);
    bool isSmaller(string, string);
    friend ostream& operator << (ostream& out, BigInt b);

};

bool BigInt::isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

BigInt::BigInt(string decStr){
    string check = decStr;
    if(decStr[0] == '-')    {check = decStr.substr(1);}
    assert(isNumber(check));
    this->num = decStr;
}


BigInt::BigInt(int decInt){
    this->num = to_string(decInt);
}

int BigInt::size(){
    return (this->num).length();
}

// Returns true if number 1 is smaller than number 2, false otherwise
bool BigInt::isSmaller(string num1, string num2){
	int n1 = num1.length(), n2 = num2.length();
	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;
	for (int i = 0; i < n1; i++)
		if (num1[i] < num2[i])
			return true;
		else if (num1[i] > num2[i])
			return false;

	return false;
}

string BigInt::subtract(string num1, string num2){
	if (isSmaller(num1, num2))
		swap(num1, num2);
	string str = "";
	int n1 = num1.length(), n2 = num2.length();

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int borrow = 0;
	for (int i = 0; i < n2; i++) {
		int sub = (num1[i] - '0') - (num2[i] - '0') - borrow;
		if (sub < 0) {
			sub = sub + 10;
			borrow = 1;
		}
		else
			borrow = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (int i = n2; i < n1; i++) {
		int sub = ((num1[i] - '0') - borrow);
		if (sub < 0) {
			sub = sub + 10;
			borrow = 1;
		}
		else
			borrow = 0;

		str.push_back(sub + '0');
	}
	return str;
}

string BigInt::add(string num1, string num2){
    if (isSmaller(num1, num2))
		swap(num1, num2);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int len1 = num1.length(); int len2 = num2.length();
    int add;
    int carry = 0;
    string sum = "";

    for(int i = 0; i < len2; i++){
        add = (num1[i] - '0') + (num2[i] - '0') + carry;
        if(add >= 10){
            carry = 1;
            add = add - 10;
        }
        else{
            carry = 0;
        }
        sum += to_string(add);
    }
    // subtract remaining digits of larger number
	for (int i = len2; i < len1; i++) {
		add = ((num1[i] - '0') + carry);
		add = add % 10;
        carry = add / 10;
		sum.push_back(add + '0');
	}
	if(carry){
        sum.push_back(carry + '0');
	}
    return sum;
}

BigInt BigInt::operator+ (BigInt anotherDec){
    BigInt sum;
    string num1 = this->num;
    string num2 = anotherDec.num;

    if(num2[0] == '-' && num1[0] == '-'){
        num1 = num1.substr(1);
        num2 = num2.substr(1);
        sum.num = add(num1, num2);
        sum.num += '-';
    }

    else if(num2[0] == '-' && num1[0] != '-'){
        num2 = num2.substr(1);
        if(isSmaller(num1, num2)){
            sum.num = subtract(num2, num1);
            if(anotherDec.num[0] == '-'){
                sum.num += '-';
            }
        }

        else if(isSmaller(num2, num1)){
            sum.num = subtract(num1, num2);
        }
    }
    else if(num2[0] != '-' && num1[0] == '-'){
        num1 = num1.substr(1);
        if(isSmaller(num2, num1)){
            sum.num = subtract(num1, num2);
            if(this->num[0] == '-'){
                sum.num += '-';
            }
        }

        else if(isSmaller(num1, num2)){
            sum.num = subtract(num1, num2);
        }
    }
    else{
        sum.num = add(num1, num2);
    }
    reverse((sum.num).begin(), (sum.num).end());
    return sum;
}


ostream& operator << (ostream& out, BigInt b){
    out << b.num;
    return out;
}
int main()
{
    // TEST CASE 1
    cout << "Test case 1.\n";
    BigInt num1("923456789012345678901234567890");
    BigInt num2("113456789011345678901134567890");
    BigInt num3 = num1 + num2;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num3 << endl << endl;

    // TEST CASE 2
    cout << "Test case 2.\n";
    BigInt num4("-123456789012345678901234567890");
    BigInt num5("113456789011345678901134567890");
    BigInt num6 = num4 + num5;
    cout << "num4 = " << num4 << endl;
    cout << "num5 = " << num5 << endl;
    cout << "num4 + num5 = " << num6 << endl << endl;

    // TEST CASE 3
    cout << "Test case 3.\n";
    BigInt num7("1234567890");
    BigInt num8("21");
    BigInt num9 = num7 + num8;
    cout << "num7 = " << num7 << endl;
    cout << "num8 = " << num8 << endl;
    cout << "num7 + num8 = " << num9 << endl << endl;

    // TEST CASE 4
    cout << "Test case 4.\n";
    BigInt num10(1234567890);
    BigInt num11(-21);
    BigInt num12 = num10 + num11;
    cout << "num10 = " << num10 << endl;
    cout << "num11 = " << num11 << endl;
    cout << "num10 + num11 = " << num12 << endl << endl;

    // TEST CASE 5
    cout << "Test case 5.\n";
    BigInt num13("-1234567890");
    BigInt num14("21");
    BigInt num15 = num13 + num14;
    cout << "num13 = " << num13 << endl;
    cout << "num14 = " << num14 << endl;
    cout << "num13 + num14 = " << num15 << endl << endl;

    BigInt inty = num10;
    cout << inty << endl;
    return 0;
}
