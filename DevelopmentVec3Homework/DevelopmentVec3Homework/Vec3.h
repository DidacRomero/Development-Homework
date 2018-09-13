#ifndef _VEC3_H_
#define _VEC3_H_

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
	void normalize() {}
	void zero() {}
	void const is_zero() {}
	void distance_to() {}

protected:

private:
	T x, y, z;

};



#endif // _VEC3_H_
