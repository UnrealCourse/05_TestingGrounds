// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

template<class T>
std::string PrettyString(T objectToPrettify)
{
	return "int: " + std::to_string(objectToPrettify);
}

template<>
std::string PrettyString(double objectToPrettify)
{
	return "double: " + std::to_string(objectToPrettify);
}

template<class T>
T GetMax(T a, T b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

template<>
std::string GetMax(std::string a, std::string b)
{
	if (a.length() > b.length()) {
		return a;
	}
	else {
		return b;
	}
}

template<class T>
T AddThree(T a, T b, T c) {
	return a + b + c;
}

int main()
{
	std::cout << GetMax(1.3, 2.5) << std::endl;
	std::cout << GetMax(1, 2) << std::endl;
	std::cout << GetMax(std::string("hello"), std::string("world1234")) << std::endl;
	std::cout << GetMax((float) 1.3, (float) 2.5) << std::endl;
	std::cout << PrettyString(3) << std::endl;
	std::cout << PrettyString(3.5) << std::endl;
}

