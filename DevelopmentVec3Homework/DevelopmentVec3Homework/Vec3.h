#ifndef _VEC3_H_
#define _VEC3_H_

#include <cmath>

template <class T>

class vec3
{
public:
	
	vec3() {}
	~vec3() {}

	//OPERATORS (+,-,+=,-=,=,==)
	vec3 operator+  (const vec3 v2) 
	{ 
		vec3 vecret;
		vecret.x = x + v2.x;
		vecret.y = y + v2.y;
		vecret.z = z + v2.z;
		return vecret;
	}
	vec3 operator-  (const vec3 v2) 
	{
		vec3 vecret;
		vecret.x = x - v2.x;
		vecret.y = y - v2.y;
		vecret.z = z - v2.z;
		return vecret;
	}
	void operator+= (const vec3 v2) 
	{
		x += v2.x;
		y += v2.y;
		z += v2.z;
	}
	void operator-= (const vec3 v2) 
	{
		x += v2.x;
		y += v2.y;
		z += v2.z;
	}
	void operator=  (const vec3 v2) {/*X*/x = v2.x;/*Y*/ y = v2.y;/*Z*/ z = v2.z;}
	
	bool operator== (const vec3 v2) { return (x == v2.x && y == v2.y && z == v2.z);}
	
		
	//METHODS
	void normalize() 
	{
		T mod = sqrt(x*x+y*y+z*z);
		x = x / mod;
		y = y / mod;
		z = z / mod;
	
	}
	void zero() { x = 0; y = 0; z = 0;}
	bool const is_zero() { return (x==0 && x==y && z==0); }
	void distance_to() {}


private:
	T x, y, z;

};



#endif // _VEC3_H_
