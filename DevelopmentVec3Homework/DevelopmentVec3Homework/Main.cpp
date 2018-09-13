#include <cstdio>
#include <iostream>
#include "Vec3.h"

using namespace std;

int main ()
{
	cout << "DEVELOPMENT HOMEWORK   vec3" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;

	vec3<float> vec1toTest (2,4,8);
	vec3<float> vec2toTest;
	// Start Printing the vectors/Results
	cout << "Vector1: " << endl;
	vec1toTest.printVec();
	cout << "Vector2: " << endl;
	vec2toTest.printVec();

	bool vec1isZero = vec1toTest.is_zero();
	bool vec2isZero = vec2toTest.is_zero();
	
	cout << "Vec 1 Is zero: " << vec1isZero << endl;
	cout << "Vec 2 Is zero: " << vec2isZero << endl;


	system("pause");
	return 0;
}