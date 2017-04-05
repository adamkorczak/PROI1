#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include "header.hpp"

void test_A(intSet& A, intSet& B)
{
bool running_A = true;
char switchButtonA;
int valueA, elementValueA;

	while(running_A)
	{
	system("clear");
	std::cout << "Modyfikowanie A oraz interakcja A z B" << std::endl;
	std::cout << "Wybierz czynność" <<std::endl;
	std::cout << "a.) Uzupełnij listę A losowymi liczbami calk." <<std::endl;
	std::cout << "b.) Uzupełnij listę B losowymi liczbami calk." <<std::endl;
	std::cout << "c.) Dodaj liczbe calk. na koncu listy A" <<std::endl;
	std::cout << "d.)  Dodaj liczbe calk. na poczatku listy A" <<std::endl;
	std::cout << "e.)  Dodaj liczbe calk. o indexie do listy A" <<std::endl;
	std::cout << "f.)  Usun liczbe calk. o indexie z listy A" <<std::endl;
	std::cout << "g.)  Usun liczbe calk. o wartosci z listy A" <<std::endl;
	std::cout << "h.)  Usun liczby calk. z przedzialu wartosci z listy A" <<std::endl;
	std::cout << "i.)  Sprawdz wielkosc listy A" <<std::endl;
	std::cout << "j.)  Dodaj B do A" <<std::endl;
	std::cout << "k.)  Odejmij B od A" <<std::endl;
	std::cout << "l.)  Skopiuj A do B" <<std::endl;
	std::cout << "m.)  Zmodyfikuj element listy A z klawiatury" <<std::endl;
	std::cout << "n.)  Powrot do menu glownego" <<std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista A posiada: "  << A.checkSize() << " elementow"<< std::endl << A << std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista B posiada: "   << B.checkSize() << " elementow"<< std::endl << B << std::endl;

	std::cin >> switchButtonA;
		switch(switchButtonA)
		{
			case 'a':
			std::cout << "Podaj ilosc elementow do automatycznego dodania do listy A:";
			std::cin >> valueA;
			while(valueA--)
			{
			A.addNodeAtTheEnd(std::rand()%100);
			}						
			break;

			case 'b':
			std::cout << "Podaj  ilosc elementow do automatycznego dodania do listy B:";
			std::cin >> valueA;
			while(valueA--)
			{
			B.addNodeAtTheEnd(std::rand()%100);
			}						
			break;
			
			case 'c':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueA;
			A.addNodeAtTheEnd(valueA);			
			break;

			case 'd':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueA;
			A.addNodeAtTheBegining(valueA);			
			break;

			case 'e':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueA;
			std::cout << "Podajindex na ktorym go dodac:";
			std::cin >> elementValueA;
			A.addNodeAfterIndex(valueA,elementValueA);			
			break;

			case 'f':
			std::cout << "Podaj index elementu do usuniecia:";
			std::cin >> valueA;
			A.deleteNodeAtTheIndex(valueA);			
			break;

			case 'g':
			std::cout << "Podaj wartosc elementu do usuniecia:";
			std::cin >> valueA;
			A.deleteNodeWithValue(valueA);			
			break;

			case 'h':
			std::cout << "Podaj dolna granice przedzialu:";
			std::cin >> elementValueA;
			std::cout << "Podaj gorna granice przedzialu:";
			std::cin >> valueA;
			A.deleteNodeWithValueInRange(elementValueA, valueA);
			break;
			
			case 'i':
			std::cout << "Wielkosc listy wynosi: " << A.checkSize() <<std::endl;
			break;

			case 'j':
			A = A + B;
			break;

			case 'k':
			A= A - B;
			break;

			case 'l':
			B = A;
			break;

			case 'm':
			std::cout << "Podaj indeks modyfikowanego elementu oraz wartosc elementu oddzielajac obie wielkosci spacja:";
			std::cin >> A;
			break;

			case 'n':
			running_A =false;
		}


		
	}


}

void test_B(intSet& A, intSet& B)
{
bool running_B = true;
char switchButtonB;
int valueB, elementValueB;

	while(running_B)
	{
	system("clear");
	std::cout << "Modyfikowanie B oraz interakcja B z A" << std::endl;
	std::cout << "Wybierz czynność" <<std::endl;
	std::cout << "a.) Uzupełnij listę B losowymi liczbami calk." <<std::endl;
	std::cout << "b.) Uzupełnij listę A losowymi liczbami calk." <<std::endl;
	std::cout << "c.) Dodaj liczbe calk. na koncu listy B" <<std::endl;
	std::cout << "d.)  Dodaj liczbe calk. na poczatku listy B" <<std::endl;
	std::cout << "e.)  Dodaj liczbe calk. o indexie do listy B" <<std::endl;
	std::cout << "f.)  Usun liczbe calk. o indexie z listy B" <<std::endl;
	std::cout << "g.)  Usun liczbe calk. o wartosci z listy B" <<std::endl;
	std::cout << "h.)  Usun liczby calk. z przedzialu wartosci z listy B" <<std::endl;
	std::cout << "i.)  Sprawdz wielkosc listy B" <<std::endl;
	std::cout << "j.)  Dodaj A do B" <<std::endl;
	std::cout << "k.)  Odejmij A od B" <<std::endl;
	std::cout << "l.)  Skopiuj B do A" <<std::endl;
	std::cout << "m.)  Zmodyfikuj element listy B z klawiatury" <<std::endl;
	std::cout << "n.)  Powrot do menu glownego" <<std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista A posiada: "  << A.checkSize() << " elementow"<< std::endl << A << std::endl;
	std::cout << std::endl;
	std::cout << "Obecna lista B posiada: "   << B.checkSize() << " elementow"<< std::endl << B << std::endl;

	std::cin >> switchButtonB;
		switch(switchButtonB)
		{
			case 'a':
			std::cout << "Podaj ilosc elementow do automatycznego dodania do listy B:";
			std::cin >> valueB;
			while(valueB--)
			{
			B.addNodeAtTheEnd(std::rand()%100);
			}						
			break;

			case 'b':
			std::cout << "Podaj  ilosc elementow do automatycznego dodania do listy A:";
			std::cin >> valueB;
			while(valueB--)
			{
			A.addNodeAtTheEnd(std::rand()%100);
			}						
			break;
			
			case 'c':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueB;
			B.addNodeAtTheEnd(valueB);			
			break;

			case 'd':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueB;
			B.addNodeAtTheBegining(valueB);			
			break;

			case 'e':
			std::cout << "Podaj element do dodania:";
			std::cin >> valueB;
			std::cout << "Podajindex na ktorym go dodac:";
			std::cin >> elementValueB;
			B.addNodeAfterIndex(valueB,elementValueB);			
			break;

			case 'f':
			std::cout << "Podaj index elementu do usuniecia:";
			std::cin >> valueB;
			B.deleteNodeAtTheIndex(valueB);			
			break;

			case 'g':
			std::cout << "Podaj wartosc elementu do usuniecia:";
			std::cin >> valueB;
			B.deleteNodeWithValue(valueB);			
			break;

			case 'h':
			std::cout << "Podaj dolna granice przedzialu:";
			std::cin >> elementValueB;
			std::cout << "Podaj gorna granice przedzialu:";
			std::cin >> valueB;
			B.deleteNodeWithValueInRange(elementValueB, valueB);
			break;
			
			case 'i':
			std::cout << "Wielkosc listy wynosi: " << B.checkSize() <<std::endl;
			break;

			case 'j':
			B = B + A;
			break;

			case 'k':
			B= B - A;
			break;

			case 'l':
			A = B;
			break;

			case 'm':
			std::cout << "Podaj indeks modyfikowanego elementu oraz wartosc elementu oddzielajac obie wielkosci spacja:";
			std::cin >> B;
			break;

			case 'n':
			running_B =false;
		}


		
	}
}

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
