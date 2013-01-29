#include <stdio.h>
#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;




int main(int argc, char const *argv[])
{
	int num;
	while(scanf("%d",&num) != EOF)
	{
		if(num==1) 
		{
			int tmp;
			scanf("%d",&tmp);
			printf("Jolly\n");
			continue;
		}
		map<int,bool> hit;
		hit.clear();
		int previous,current;
		for(int i=0;i<num;i++)
		{
			scanf("%d",&current);
			if (i!=0) 
			{
				hit[abs(current-previous)] = true;	
			} 
			previous = current;
		}
		bool jolly = true;
		for(int i =1;i<num;i++)
		{
			if (hit.count(i) == 0)
			{
				jolly = false;
				break;
			}
		}
		if(jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	

	return 0;
}