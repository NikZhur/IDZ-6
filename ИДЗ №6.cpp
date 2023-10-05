#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");
	cout << "int: " << sizeof(int) << "  short int: " << sizeof(short int) << "  float: " << sizeof(float) << "  double: " << sizeof(double) << "  long double: " << sizeof(long double) << "  char: " << sizeof(char) << "  bool: " << sizeof(bool);
	cout << "\n";
	cout << "Enter the integer whose binary representation you want to get: ";
	int a;
	cin >> a;
	cout << "\n";
	int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	cout << "a:" << " " << a << " " << "place in memory" << " " << '-' << " " << &a << " " << "mask:" << " " << mask << " " << "\n";
	int I[sizeof(int) * 8];
	int onebit;
	for (int i = 0; i < order; i++)
	{
		onebit = a & mask ? 1 : 0;
		cout << onebit;
		I[i] = onebit;
		mask >>= 1;
	}
	int starbit;
	cout << '\n';
	cout << "enter the bit where you want to start mirroring. Otherwise, enter a number less than one or more than the memory allocated for the data type integer: ";
	cin >> starbit;
	if (starbit >= 1 && starbit <= order) {
		for (int i = size(I) - starbit; i >= 0; i--) {
			cout << I[i];
		}
		for (int i = size(I) - starbit + 1; i < size(I); i++) {
			cout << I[i];
		}
	}
	else {
		for (int i = 0; i < size(I); i++) {
			cout << I[i];
		}
	}
	union {
		int integerA;
		float floatB;
	};
	cout << "\n";
	cout << "Enter the float type number whose binary representation you want to get: ";
	cin >> floatB;
	mask = 1 << order - 1;
	cout << "\n";
	cout << "integerA:" << " " << integerA << " " << "place in memory" << " " << '-' << " " << &integerA << " " << "floatB:" << " " << floatB << " " << "place in memory" << " " << '-' << " " << &floatB << "\n";
	int F[sizeof(float) * 8];
	for (int i = 0; i < order; i++)
	{
		onebit = integerA & mask ? 1 : 0;
		cout << onebit;
		F[i] = onebit;
		mask >>= 1;
	}
	int starbit2;
	cout << '\n';
	cout << "enter the bit where you want to start mirroring. Otherwise, enter a number less than one or more than the memory allocated for the data type float: ";
	cin >> starbit2;
	if (starbit2 >= 1 && starbit2 <= order) {
		for (int i = size(F) - starbit2; i >= 0; i--) {
			cout << F[i];
		}
		for (int i = size(F) - starbit2 + 1; i < size(F); i++) {
			cout << F[i];
		}
	}
	else {
		for (int i = 0; i < size(F); i++) {
			cout << F[i];
		}
	}
	union {
		int A[2];
		double doubleC;
	};
	cout << "\n";
	cout << "Enter a number of type double whose binary representation you want to get: ";
	cin >> doubleC;
	cout << "\n";
	cout << "A:" << " " << "{" << A[0] << "," << A[1] << "}" << " " << "place in memory" << " " << "-" << " " << &A << " " << "doubleC:" << " " << doubleC << " " << "place in memory" << " " << "-" << " " << &doubleC << "\n";
	int order2 = sizeof(double) * 8;
	int D[sizeof(double) * 8];
	for (int j = 1; j >= 0; j--)
	{
		mask = 1 << order - 1;
		for (int i = 0; i < order2 / 2; i++) {
			onebit = A[j] & mask ? 1 : 0;
			cout << onebit;
			if (j == 1) {
				D[i] = onebit;
			}
			else {
				D[i + 32] = onebit;
			}
			mask >>= 1;
			
		}
	}
	int starbit3;
	cout << '\n';
	cout << "enter the bit where you want to start mirroring. Otherwise, enter a number less than one or more than the memory allocated for the data type double: ";
	cin >> starbit3;
	if (starbit3 >= 1 && starbit3 <= order2) {
		for (int i = size(D) - starbit3; i >= 0; i--) {
			cout << D[i];
		}
		for (int i = size(D) - starbit3 + 1; i < size(D); i++) {
			cout << D[i];
		}
	}
	else {
		for (int i = 0; i < size(D); i++) {
			cout << D[i];
		}
	}
}