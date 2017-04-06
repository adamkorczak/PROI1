#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include "header.hpp"
#include "test.hpp"


int main()
{
bool running = true;
char switchButton;
int value, elementValue;
srand(time(NULL));

intSet A,B;

	while(running)
	{	
	system("clear");
	std::cout << "Listy jednokierunkowe testy v1.0" << std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista A posiada: "  << A.checkSize() << " elementow"<< std::endl << A << std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista B posiada: "   << B.checkSize() << " elementow"<< std::endl << B << std::endl;
	std::cout << std::endl;
	std::cout << "Wybierz liste, ktora chcesz edytowac" <<std::endl;
	std::cout << "a.) Lista A" <<std::endl;
	std::cout << "b.) Lista B" <<std::endl;
	std::cout << "c.) Wyjscie" <<std::endl;

	std::cin >> switchButton;
		
		switch(switchButton)
		{	
			
			case 'a':
			test_A(A,B);
			break;

			case 'b':
			test_B(A,B);
			break;

			case 'c':
			running = false;
			break;
		}
	}

	return 0;
}
