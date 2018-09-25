#include "String.h"

//CONSTRUCTORS
String::String() : string(nullptr), string_char_num(0) {}//Size of the string(0){}

String::String(char* string): string(string), string_char_num(0)
{
}

String::String(const String &string_class): string(string_class.string), string_char_num(string_class.string_char_num) {}

//DESTRUCTOR
String::~String() {}

//METHODS
bool String::empty() const { return (string_char_num==0); }
int String::size() const { return string_char_num; }
void String::clear() {}
const char* String::pointer() const { return string; }

//OPERATORS
String String::operator+(const String &string_class) 
{}
String String::operator+=(const String &string_class) 
{}
String String::operator=(const String &string_class) 
{}
String String::operator==(const String &string_class) 
{}