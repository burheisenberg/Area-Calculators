#include <iostream>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535897932384626
using namespace std;

float heron_formula(float x, float y, float z);

int main() {
	first:
	float x, y,z;
	float value;
	cout << endl <<"Please, put lengths: ";
	cin >> x >> y >> z;
	value=heron_formula(x,y,z);
	cout << "Area of triangle: " << value << endl;
	goto first;
}

float heron_formula(float x, float y, float z) {
	float u, temporary, value;
	u=(x+y+z)/2;
	temporary=(u-x)*(u-y)*(u-z)*u;
	value=pow(temporary, 0.5);
	return value;
}
