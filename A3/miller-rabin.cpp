#include <bits/stdc++.h> 
using namespace std; 

// Utility function to do modular exponentiation. 
// It returns (x^y) % p 
int power(int x, unsigned int y, int p) { 
	int res = 1; 
	x = x % p; 
	while (y > 0) { 
		if (y & 1) 
			res = (res * x) % p; 
		y = y >> 1; 
		x = (x * x) % p; 
	} 
	return res; 
} 

// This function is called for all k trials. It returns 
// false if n is composite and returns false if n is 
// probably prime 
bool miillerTest(int d, int n) { 
	int a = 2 + rand() % (n - 4); 
	int x = power(a, d, n); 
	if (x == 1 || x == n - 1) 
		return true; 

	while (d != n - 1) { 
		x = (x * x) % n; 
		d *= 2; 
		if (x == 1) 
			return false; 
		if (x == n - 1) 
			return true; 
	} 
	return false; 
} 

// It returns false if n is composite and returns true if n 
// is probably prime. k is an input parameter that determines 
// accuracy level. Higher value of k indicates more accuracy. 
bool isPrime(int n, int k) { 
	// Corner cases 
	if (n <= 1 || n == 4) 
		return false; 
	if (n <= 3) 
		return true; 

	// Find r such that n = 2^d * r + 1 for some r >= 1 
	int d = n - 1; 
	while (d % 2 == 0) 
		d /= 2; 

	// Iterate given nber of 'k' times 
	for (int i = 0; i < k; i++) 
		if (miillerTest(d, n) == false) 
			return false; 

	return true; 
} 

int main() { 
	int k = 4;
	int n;
	cout << "Enter number: ";
	cin >> n;
	
	if (isPrime(n, k)) cout << n << " is prime\n"; 
	else cout << n << " is composite\n"; 

	return 0; 
} 

