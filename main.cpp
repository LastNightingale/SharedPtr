#include <iostream>
#include "SharedPtr.h"

int main()
{
	int i = 1;
	SharedPtr<int> ptr(i);
	std::cout << *ptr << std::endl;
	{
		SharedPtr<int> ptrx = ptr;
		std::cout << *ptrx << std::endl;
	}
}