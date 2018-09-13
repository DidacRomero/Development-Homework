#ifndef _VEC3_H_
#define _VEC3_H_

#include <cmath>

template <class T>

class vec3
{
public:
	
	//Default Constructor sets the vec3 to 0 value
	vec3() { x = y = z = 0; }
	vec3(T newX, T newY, T newZ) { x = newX; y = newY; z = newZ; }
	vec3(vec3 &vecToCopy) { x = vecToCopy->getX(); y = vecToCopy->getY(); z = vecToCopy->getZ(); }
	~vec3() {}

	//OPERATORS (+,-,+=,-=,=,==)
	vec3 operator+  (const vec3 &v2) 
	{ 
		vec3 vecret;
		vecret.x = x + v2->getX;
		vecret.y = y + v2->getY;
		vecret.z = z + v2->getZ;
		return vecret;
	}
	vec3 operator-  (const vec3 &v2) 
	{
		vec3 vecret;
		vecret.x = x - v2->getX;
		vecret.y = y - v2->getY;
		vecret.z = z - v2->getZ;
		return vecret;
	}
	void operator+= (const vec3 &v2) 
	{
		x += v2->getX;
		y += v2->getY;
		z += v2->getZ;
	}
	void operator-= (const vec3 &v2) 
	{
		x += v2->getX;
		y += v2->getY;
		z += v2->getZ;
	}
	void operator=  (const vec3 &v2) {/*X*/x = v2->getX;/*Y*/ y = v2->getY;/*Z*/ z = v2->getZ;}
	
	bool operator== (const vec3 &v2) { return (x == v2->getX() && y == v2->getY && z == v2->getZ);}
	
		
	// HOMEWORK METHODS
	void normalize() 
	{
		T mod = sqrt(x*x+y*y+z*z);
		x = x / mod;
		y = y / mod;
		z = z / mod;
	
	}
	void zero() { x = 0; y = 0; z = 0;}
	bool const is_zero() { return (x==0 && y==0 && z==0); }
	void distance_to() {}

	//Basic GETTER Methods
	T const getX() { return x; }
	T const getY() { return y; }
	T const getZ() { return z; }

	//Printing Methods
	void const printVec()
	{
		cout<< "	" << "x: " << x << "	" << "y: " << y << "	" << "z: " << z <<endl;
	}
private:
	T x, y, z;

};



#endif // _VEC3_H_
