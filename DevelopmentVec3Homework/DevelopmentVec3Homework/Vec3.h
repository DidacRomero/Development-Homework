#ifndef _VEC3_H_
#define _VEC3_H_

template <class T>

class vec3
{
public:
	
	vec3() {}
	~vec3() {}

	//OPERATORS (+,-,+=,-=,=,==)
	void operator+  (const vec3 v2) {}
	void operator-  (const vec3 v2) {}
	void operator+= (const vec3 v2) {}
	void operator-= (const vec3 v2) {}
	void operator=  (const vec3 v2) {}
	void operator== (const vec3 v2) {}
		
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
