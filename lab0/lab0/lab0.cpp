// lab0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;
int main()
{
	const int MAX = 100;
	double A[MAX], B[MAX], C[MAX];
	int nA, nB, nC, i, m;
	do {
		cout << " Input number N < " << MAX << endl;
		cin >> nA;
	} while (nA<0 || nA>MAX);
	nB = nC = 0;
	for (i = 0; i < nA; i++)
	{
		cout << "A[" << i << "] = "; cin >> A[i];
	}
	do {
		cout << " Input index m(0 <= m <= " << nA - 1 << ") " << endl;
		cin >> m;
	} while (m < 0 || m >= nA);
	for (i = 0; i < nA; i++)
		if (A[i] > A[m]) B[nB++] = A[i];
		else C[nC++] = A[i];
	cout << " Rezult " << endl;
	cout << " B : " << endl;
	for (i = 0; i < nB; i++)
		cout << B[i] << "\t";
	cout << "C " << endl;
	for (i = 0; i < nC; i++)
		cout << C[i] << "\t";
	cin >> i;
	cout << "Exit\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
