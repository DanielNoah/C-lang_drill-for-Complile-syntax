#include <stdio.h>

int main()
{
	struct profile
	{
		int num;
		char name[20];
		char *skill;
	};

	struct sports
	{
		char *event;
		struct profile player;		
	};
	
	struct sports a;

	


	return 0;

}

