#include "MyList.h"
#include <iostream>

int main()
{
	List l;
	l.push_back(3);
	l.push_back(54);
	l.erase(1);

	return 0;
}