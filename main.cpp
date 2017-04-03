#include <iostream>
#include <stdio.h>
#include <string.h>

class intSet
{
	struct node
	{
		int a;
		struct node *nextPointer;
	};
	
public:
	
	//node *pointer;
	node *lastPointer;

	intSet() { /*pointer = */lastPointer = NULL; }
	void addNodeAtTheEnd(int aInput);
	void display();
	
};

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
	while(s != lastPointer)
	{
		std::cout << s->a << "->";
		s = s->nextPointer;
	}
	std::cout << s->a << std::endl;
	
}

void intSet::addNodeAtTheEnd(int aInput)
{
	struct node *temp = new (struct node);
	temp -> a = aInput;

	if(lastPointer == NULL)
	{	
		lastPointer = temp;
		//pointer = temp;
		temp -> nextPointer = lastPointer;
	}
	else
	{
		temp -> nextPointer = lastPointer -> nextPointer;
		lastPointer -> nextPointer = temp;
		lastPointer = temp;
	}
}


int main()
{
bool running = true;
char switchButton;
int value;

intSet A;

	while(running)
	{	std::cin >> switchButton;
		
		switch(switchButton)
		{
			case 'a':
			std::cout << "Podaj element do dodania:";
			std::cin >> value;
			A.addNodeAtTheEnd(value);			
			break;	

			case 'd':
			A.display();
			break;
		
			case 'p':
			running = false;
			break;
						
		}

	}



	return 0;
}

