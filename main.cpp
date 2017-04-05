#include <iostream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>

class intSet
{
	struct node
	{
		int a;
		struct node *nextPointer;
	};
	int size;

public:
	
	node *lastPointer;

	intSet() { lastPointer = NULL; size = 0; }
	intSet(const intSet &t);

	void addNodeAtTheEnd(int aInput);
	void addNodeAtTheBegining(int aInput);
	void addNodeAfterValue(int aInput, int valueInput);
	void addNodeAfterIndex(int aInput, int index);
	void deleteNodeAtTheIndex(int index);
	void deleteNodeWithValue(int value);
	void deleteNodeWithValueInRange(int low, int high);
	void display();
	int checkSize();
	void deleteTheSameValue();
	int getValue(int index);
	void setValueInElement(int aInput, int index);

	intSet operator+(const intSet &t) const;
	intSet operator-(const intSet &t) const;
	intSet &operator=(const intSet &t);


	friend bool operator>(const intSet &t1, const intSet &t2);
	friend bool operator<(const intSet &t1, const intSet &t2);
	friend bool operator>=(const intSet &t1, const intSet &t2);
	friend bool operator<=(const intSet &t1, const intSet &t2);
	friend std::ostream& operator<<(std::ostream &out, const intSet &t);
	friend std::istream& operator>>(std::istream &in, const intSet &t);
		
};


std::istream& operator>>(std::istream &in,intSet &t)
{
int index, value;
	
	in >> index;
	in >> value;
	t.setValueInElement(value, index);	

	return in;
}

std::ostream& operator<<(std::ostream& out, const intSet& t)
{
	intSet::node *s = t.lastPointer;
	if(s == NULL)
	{
		out << "List is empty" ;
		return out;
	}
	
	s = t.lastPointer ->nextPointer;
	out << "List" << std::endl;
	
	while(s != t.lastPointer)
	{
		out << s->a << "->";
		s = s->nextPointer;
	}
	out << s->a ;

return out;
	
}


void intSet::setValueInElement(int aInput, int index)
{
		if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}

	int i = 1;
	struct node *buffor;
		buffor = lastPointer ->nextPointer;
	
		while(i++ != index)
		{	
			buffor = buffor ->nextPointer;
			//std::cout << buffor ->a << " i = " << i << std::endl;
			if(buffor == lastPointer->nextPointer)
			{
			std::cout << "The list is too short" << std::endl;
			return;
			}
		}

	buffor ->a = aInput;

	return;
}

int intSet::getValue(int index)
{
	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return -1;
	}

	int i = 1;
	struct node *buffor;
		buffor = lastPointer ->nextPointer;
	
		while(i++ != index)
		{	
			buffor = buffor ->nextPointer;
			//std::cout << buffor ->a << " i = " << i << std::endl;
			if(buffor == lastPointer->nextPointer)
			{
			std::cout << "The list is too short" << std::endl;
			return -1;
			}
		}

	return buffor->a;
}


bool operator>(const intSet &t1, const intSet &t2)
{
	return t1.size >  t2.size;
}

bool operator<(const intSet &t1, const intSet &t2)
{
	return t1.size < t2.size;
}

bool operator>=(const intSet &t1, const intSet &t2)
{
	return t1.size >= t2.size;
}

bool operator<=(const intSet &t1, const intSet &t2)
{
	return t1.size <= t2.size;
}


void intSet::deleteTheSameValue()
{
	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}
	if(lastPointer ->nextPointer ==lastPointer)
	{
		std::cout << "There is only one node, create at least two nodes to use this function " <<std::endl;
		return;
	}
	
	struct node *buff = lastPointer ->nextPointer;
	struct node *iter;

	while(buff != lastPointer)
	{	
		iter = buff ->nextPointer;
		while(iter != lastPointer ->nextPointer)
		{
			if(buff ->a == iter ->a)
			this->deleteNodeWithValue(buff ->a);

			iter = iter ->nextPointer;
		}
		buff = buff ->nextPointer;
	}

	return;
}


int intSet::checkSize()
{	size = 0;
	
	if(lastPointer == NULL)
	{
		size = 0;
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return size;
	}
	struct node *buff = lastPointer ->nextPointer;
	
	if(lastPointer ->nextPointer == lastPointer)
	{
		size = 1;
		return size;
	}

	while(buff != lastPointer)
	{
		size++;
		buff = buff ->nextPointer;
		if(buff == lastPointer)
		{
			size++;
		}	
	}

return size;
}


intSet &intSet::operator=(const intSet &t)
{
	struct node *buff;
	if(lastPointer != NULL)
	{
		buff = lastPointer ->nextPointer;
		while(buff != lastPointer)
		{
			this->deleteNodeAtTheIndex(1);
			buff = lastPointer ->nextPointer;		
		}
		if(buff == lastPointer)
		{
			this->deleteNodeAtTheIndex(1);		
		}
		
	}	

	buff = t.lastPointer ->nextPointer;

		while(buff != t.lastPointer)
		{
			this->addNodeAtTheEnd(buff ->a);
			buff = buff ->nextPointer;
		}
		if(buff == t.lastPointer)
		{
			this->addNodeAtTheEnd(buff ->a);
		}

	return *this ;

}


intSet intSet::operator-(const intSet &t) const
{
	intSet *buffor = new intSet(*this);
	struct node *tempS, *temp;
	tempS = buffor->lastPointer ->nextPointer;
	temp = t.lastPointer ->nextPointer;

	while(tempS != buffor->lastPointer)
	{	
		temp = t.lastPointer ->nextPointer;
		while(temp != t.lastPointer)
		{
			if(temp ->a == tempS ->a)
			{
				buffor->deleteNodeWithValue(temp ->a);
			}
			temp = temp ->nextPointer;
			if((temp == t.lastPointer) && (temp ->a == tempS ->a))
			{
				buffor->deleteNodeWithValue(temp ->a);
			}
			
		}
		tempS = tempS ->nextPointer;
		if(tempS == buffor->lastPointer)
		{
			while(temp != t.lastPointer)
			{
				if(temp ->a == tempS ->a)
				{
					buffor->deleteNodeWithValue(temp ->a);
				}
				temp = temp ->nextPointer;
				if((temp == t.lastPointer) && (temp ->a == tempS ->a))
				{
					buffor->deleteNodeWithValue(temp ->a);
				}
			
			}

		}
		
	}
	return *buffor;

}

intSet intSet::operator+(const intSet &t) const
{
	intSet *buffor = new intSet(*this);
	struct node *temp;
	temp = t.lastPointer ->nextPointer;
	
	while(temp != t.lastPointer)
	{
		buffor->addNodeAtTheEnd(temp ->a);
		temp = temp ->nextPointer;
	}
	if(temp == t.lastPointer)
	{
		buffor->addNodeAtTheEnd(temp ->a);
	}	

	return *buffor;	
	
}

intSet::intSet(const intSet &t)
{	
	size = 0;
	lastPointer = NULL;	
	struct node *buffor;
	buffor = t.lastPointer ->nextPointer;

		while(buffor != t.lastPointer)
		{
			this->addNodeAtTheEnd(buffor ->a);
			buffor = buffor ->nextPointer;
		}
		if(buffor == t.lastPointer)
		{
			this->addNodeAtTheEnd(buffor ->a);
		}
	
}

void intSet::deleteNodeWithValueInRange(int low, int high)
{
	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}

int setRange;
int counter = 0;

	if(low > high)
	{
		setRange = low;
		low = high;
		high = setRange;
	}
	else if(low == high)
	{
		setRange = low;
		std::cout << "Integer Set has one element, so use function to deleting one value" << std::endl;
		return;
	}

	struct node *buffor1, *buffor2, *bufforFirst;
	buffor1 = lastPointer -> nextPointer;

	while(buffor1->nextPointer != lastPointer)
	{
		bufforFirst = lastPointer -> nextPointer;
		if((bufforFirst ->a >= low && bufforFirst ->a <= high)&&(lastPointer  ->nextPointer != lastPointer))
		{
			lastPointer ->nextPointer = bufforFirst ->nextPointer;
			buffor2 = bufforFirst;
			std::cout << "usunieto[F]" << buffor2 ->a << std::endl;
			delete buffor2;
			counter++;
			continue;
			
		}

				
		else if(buffor1 ->nextPointer->a >= low && buffor1 ->nextPointer->a <= high)
		{

					buffor2 = buffor1 ->nextPointer;
					buffor1 ->nextPointer = buffor2 ->nextPointer;
					std::cout << "usunieto" << buffor2 ->a << std::endl;
					delete buffor2;
					counter++;
					continue;
		}
		buffor1 = buffor1 ->nextPointer;
	}

	if((buffor1->nextPointer ->a >= low && buffor1 ->nextPointer->a <= high)&&(lastPointer  ->nextPointer != lastPointer))
	{
					buffor2 = buffor1 ->nextPointer;
					buffor1 ->nextPointer = lastPointer ->nextPointer;
					std::cout << "usunieto[L]" << buffor2 ->a << std::endl;
					delete buffor2;
					counter++;
					lastPointer = buffor1;

	}

	else if((buffor1->nextPointer ->a >= low && buffor1 ->nextPointer->a <= high)&&(lastPointer  ->nextPointer == lastPointer))
	{
		buffor2 = lastPointer;
		lastPointer = NULL;
		std::cout << "usunieto[LL]" << buffor2 ->a << std::endl;
		delete buffor2;
		counter++;

	}
	
	if(counter < 1)
	{
		std::cout << "There are no values in list that include in Range" << std::endl;
		return;
	}
	else	
	std::cout << counter << " have been deleted" << std::endl;

}


void intSet::deleteNodeWithValue(int value)
{

	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}

	struct node *buffor1, *buffor2;
	buffor1 = lastPointer -> nextPointer;

	if(buffor1 ->a == value)
	{
		buffor2 = buffor1;
		lastPointer ->nextPointer = buffor1 ->nextPointer;
		delete buffor2;
		return;
	}

	while(buffor1 ->nextPointer != lastPointer)
	{
		if(buffor1 ->nextPointer ->a == value)
		{
			buffor2 = buffor1 ->nextPointer;
			buffor1 ->nextPointer = buffor2 ->nextPointer;
			delete buffor2;
			return;
		}
		buffor1 = buffor1 -> nextPointer;
	}

	if(buffor1 ->nextPointer ->a == value)
	{
		buffor2 = buffor1 ->nextPointer;
		buffor1 ->nextPointer = lastPointer ->nextPointer;
		delete buffor2;
		lastPointer = buffor1;
		return;
	}

	std::cout << "Element" << value << "not found in the list" << std::endl;	
	
}


void intSet::deleteNodeAtTheIndex(int index)
{
	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}

int i = 1;
struct node *buffor1, *buffor2;

	buffor1 = lastPointer ->nextPointer;

	if(buffor1 == lastPointer)
	{
		buffor2 = lastPointer;
		lastPointer = NULL;
		delete buffor2;
		return;
	}

	if(index == 1)
	{
		lastPointer ->nextPointer = buffor1 ->nextPointer;
		buffor2 = buffor1;
		delete buffor2;
		return;
	}
	
		while(i++ < (index - 1 ))
		{	
			buffor2 = buffor1;
			buffor1 = buffor1 ->nextPointer;
			//std::cout << buffor1 ->a << " i = " << i << std::endl;
			if(buffor1 == lastPointer->nextPointer)
			{
			std::cout << "The list is too short" << std::endl;
			return;
			}
			else if(buffor1 ->nextPointer == lastPointer)
			{ 
				buffor2 = buffor1 ->nextPointer;
				buffor1 ->nextPointer = lastPointer ->nextPointer;
				delete buffor2;
				lastPointer = buffor1;
				return;	
			}	
		}
		
		buffor2 = buffor1 ->nextPointer;
		buffor1 ->nextPointer = buffor2 ->nextPointer;
		delete buffor2;
		
}


void intSet::addNodeAfterIndex(int aInput, int index)
{
int i = 1;
struct node *temp = new(struct node);
temp -> a = aInput;

	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}	

	if(index == 1)
	{
		temp -> nextPointer = lastPointer -> nextPointer;
		lastPointer -> nextPointer = temp;
	}
	else
	{

		struct node *buffor;
		buffor = lastPointer ->nextPointer;
	
		while(i++ < (index - 1 ))
		{	
			buffor = buffor ->nextPointer;
			//std::cout << buffor ->a << " i = " << i << std::endl;
			if(buffor == lastPointer->nextPointer)
			{
			std::cout << "The list is too short" << std::endl;
			return;
			}
		}

		temp ->nextPointer = buffor ->nextPointer;
		buffor ->nextPointer = temp;

		if(buffor == lastPointer)
		{
			lastPointer = temp;
		}
	}
}

void intSet::addNodeAfterValue(int aInput, int valueInput)
{

	if(lastPointer == NULL)
	{
		std::cout << "There is no list, firstly add any node" <<std::endl;
		return;
	}
	
	struct node *buffor;
	buffor = lastPointer -> nextPointer;
	
	while(buffor != lastPointer)
	{
		if(buffor -> a == valueInput)
		{
		break;
		}
		buffor = buffor -> nextPointer;
	}
	struct node *temp = new(struct node);
	temp ->a = aInput;

	if(buffor == lastPointer && buffor ->a == valueInput)
	{
		temp ->nextPointer = lastPointer ->nextPointer;
		lastPointer ->nextPointer = temp;
		lastPointer = temp;
	}
	else if(buffor == lastPointer && buffor ->a != valueInput)
	{
		std::cout << "There is no such a value" << std::endl;
		return;
	}
	else
	{
		temp ->nextPointer = buffor ->nextPointer;
		buffor ->nextPointer = temp;
	}
}

void intSet::addNodeAtTheBegining(int aInput)
{
	struct node *temp = new (struct node);
	temp -> a = aInput;

	if(lastPointer == NULL)
	{
		lastPointer = temp;
		temp -> nextPointer = lastPointer;
	}
	else
	{
		temp -> nextPointer = lastPointer -> nextPointer;
		lastPointer -> nextPointer = temp;
	}
	
}

void intSet::addNodeAtTheEnd(int aInput)
{
	struct node *temp = new (struct node);
	temp -> a = aInput;

	if(lastPointer == NULL)
	{	
		lastPointer = temp;
		temp -> nextPointer = lastPointer;
	}
	else
	{
		temp -> nextPointer = lastPointer -> nextPointer;
		lastPointer -> nextPointer = temp;
		lastPointer = temp;
	}
}

void intSet::display()
{
	struct node *s;
	if(lastPointer == NULL)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	
	s = lastPointer ->nextPointer;
	std::cout << "List" <<std::endl;
	//std::cout << s->a <<std::endl;
	while(s != lastPointer)
	{
		std::cout << s->a << "->";
		s = s->nextPointer;
	}
	std::cout << s->a << std::endl;
	
}


int main()
{
bool running = true;
char switchButton;
int value, elementValue;
srand(time(NULL));

intSet A,B,C;

	while(running)
	{	std::cin >> switchButton;
		
		switch(switchButton)
		{	
			case 'k':
			std::cout << "Podaj  ilosc elementow do automatycznego dodania:";
			std::cin >> value;
			while(value--)
			{
			A.addNodeAtTheEnd(std::rand()%100);
			B.addNodeAtTheEnd(std::rand()%100);
			}			
			break;

			case 'h':
			C = intSet(A);
			//C.display();		
			break;

			case 'a':
			std::cout << "Podaj element do dodania:";
			std::cin >> value;
			A.addNodeAtTheEnd(value);			
			break;	

			case 'b':
			std::cout << "Podaj element do dodania na przodzie:";
			std::cin >> value;
			A.addNodeAtTheBegining(value);			
			break;

			case 'i':
			std::cout << "Podaj element za ktorym dodac:";
			std::cin >> elementValue;
			std::cout << "Podaj element:";
			std::cin >> value;
			A.addNodeAfterValue(value, elementValue);			
			break;

			case 'r':
			std::cout << "Podaj indeks elementu do usuniecia:";
			std::cin >> elementValue;
			A.deleteNodeAtTheIndex(elementValue);			
			break;

			case 'v':
			std::cout << "Podaj element do usuniecia:";
			std::cin >> elementValue;
			A.deleteNodeWithValue(elementValue);			
			break;

			case 'q':
			std::cout << "Podaj indeks elementu oraz wartosc elementu oddzielajac obie wielkosci spacja:";
			std::cin >> A;
			std::cout <<A << std::endl;			
			break;

			case 'f':
			std::cout << "Podaj indeks elementu:";
			std::cin >> elementValue;
			std::cout << A.getValue(elementValue) <<std::endl;			
			break;

			case 't':
			std::cout << "Podaj dolna granice przedzialu:";
			std::cin >> elementValue;
			std::cout << "Podaj gorna granice przedzialu:";
			std::cin >> value;
			C.deleteNodeWithValueInRange(elementValue, value);
			C.display();			
			break;

			case 's':
			A.checkSize();
			B.checkSize();
			if(A >= B)
			std::cout <<"dziala11"<<std::endl;
			if(A<B)
			std::cout <<"dziala2" << std::endl;			
			break;

			case 'd':
			std::cout << A << std::endl;
			std::cout << B << std::endl;
			//C = A+B;
			//A.display();
			//B.display();
			//C.display();
			std::cout << A.checkSize() << std::endl;
			break;
		
			case 'e':
			A.display();
			B.display();
			C = A;
			B = A;
			C.display();
			A.display();
			B.display();
			break;

			case 'p':
			running = false;
			break;
						
		}

	}



	return 0;
}

