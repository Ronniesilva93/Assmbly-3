//determine if users number is prime
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
	//declarations
	int myPrimeNum;
	int halfOf;
	int divisor=2;
	int result;//if result = 0 means false or the number is NOT prime
			   //if result = 1 means true  or the number is prime

	cout << "Enter an integer to determine if it is prime: ";
	cin >> myPrimeNum;


	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	_asm {
		xor edx, edx; clear edx
		mov eax, myPrimeNum;
		mov ebx, 2
		idiv ebx; what is half of myPrimeNum
		mov halfOf, eax

		L1:
		xor edx, edx; clear edx
		mov eax, myPrimeNum
		mov ebx, divisor
		idiv ebx/* quotient in eax remainder in edx*/
		cmp edx, 0
		je notPrimeLabel

		inc divisor
		mov eax, divisor
		mov ebx, halfOf
		cmp eax, ebx; is the divisor still less than half the potential prime number
		je isPrimeLabel; since we have passed the halfway point, potential number is in fact prime

		jbe L1

		isPrimeLabel:
		mov result, 1
		jmp quit

		notPrimeLabel:
		mov result, 0
		jmp quit

		quit:

	}

	if (result == 0)
		cout << myPrimeNum << " is not prime." << endl;
	else if (result == 1)
		cout << myPrimeNum << " is prime." << endl;

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	
	cout << " This process was completed in " << duration << " microseconds" << endl << endl;



	system("pause");
	return 0;
}

