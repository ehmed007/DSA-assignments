#include "iostream"
using namespace std;

int f (int n) {
	if (n == 0) {
		return 0;
	}
	return f(n-1)+2*n;
}

int main() { 
	cout << f(4);
	return 0;
}