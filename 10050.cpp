#include "stdio.h"
#include "iostream"
#include "set"

using namespace std;

int main(int argc, char const *argv[])
{
	int num_tests,num_days,num_parties;
	scanf("%d",&num_tests);
	set<int> lost_days;
	for (int j = 0;j<num_tests;j++)
	{
		lost_days.clear();
		scanf("%d",&num_days);
		scanf("%d",&num_parties);
		// printf("%d %d\n", num_days,num_parties);
		int strikes[num_parties];
		for (int i = 0;i<num_parties;i++){
			scanf("%d",&strikes[i]);
			// printf("%d ", strikes[i]);
		}
		// printf("\n");
		for (int i = 1; i <= num_days; i++)
		{
			for (int k = 0; k < num_parties; k++)
			{
				int strike_day = strikes[k];
				if (i%strike_day == 0)
				{
					if (i%7 != 0 && i%7 !=6)
					{
						// printf("%d %d ",i,strike_day);
						lost_days.insert(i);
					}
				}
			}
		}
		// printf("\n");
		printf("%d\n",(int)lost_days.size());
	}
	return 0;
}