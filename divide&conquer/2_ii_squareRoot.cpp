#include <iostream>
#include <cmath>
using namespace std;

int findSquareRoot(int x) {
	double result = exp(log(x) / 2);
	int floorResult = floor(result);
	if (floorResult * floorResult == x) return floorResult;
	else return floorResult;
}

int main() {
	int x = 11;
	int squareRoot = findSquareRoot(x);
	cout << squareRoot << endl; 
	return 0;
}