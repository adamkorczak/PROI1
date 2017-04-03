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
	void addEleAtTheEnd(int aInput);
	
};


void intSet::addEleAtTheEnd(int aInput)
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
		
		temp -> nextPointer = lastPointer;
		lastPointer -> nextPointer = temp;
		lastPointer = temp;
	}
		

	
}


int main()
{
bool running = true;
char switchButton;

intSet A;

	while(running)
	{	std::cin >> switchButton;
		
		switch(switchButton)
		{
			case 'a':
			
			
		}

	}



	return 0;
}

