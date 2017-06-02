// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

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

template<class T>
T AddThree(T a, T b, T c) {
	return a + b + c;
}

int main()
{
	std::cout << GetMax(1.3, 2.5) << std::endl;
	std::cout << GetMax(1, 2) << std::endl;
	std::cout << GetMax("hello", "world") << std::endl;
	std::cout << GetMax((float) 1.3, (float) 2.5) << std::endl;
	std::cout << AddThree(1, 2, 3) << std::endl;
	std::cout << AddThree(1.4, 2.32, 3.7) << std::endl;
}

