#ifndef _STRING__H_
#define _STRING__H_

#include <cstring>
class String
{
public:

	String();
	String(char* string);
	String(const String &string_class);

	~String();

	//METHODS
	bool empty() const;
	int size() const;
	void clear();
	const char* pointer() const;

	//OPERATORS  // +,+=,==, =

	String operator+(const String &string_class);
	String operator+= (const String &string_class);
	String operator= (const String &string_class);
	String operator== (const String &string_class);


private:

	char* string; //Pointer to the array of chars
	int string_char_num; //Size of the string
};


#endif //