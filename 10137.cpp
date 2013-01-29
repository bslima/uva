#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	int num;

	while(scanf("%d",&num) != EOF)
	{
		if (num == 0) return 0;
		double value[num];
		double total = 0.0;
		for (int i=0;i<num;i++)
		{
			scanf("%lf",&value[i]);
			total = total + value[i];
			value[i] = value[i];
		}
		double avg = total/num;
		double exchange_positive = 0.0;
		double exchange_negative = 0.0;
		for (int i=0;i<num;i++)
		{
			double diff = (double) (long) ((value[i] - avg) * 100.0) / 100.0;
			if (diff > 0){
				exchange_positive = exchange_positive + diff; 
			}else {
				exchange_negative = exchange_negative + diff;
			}
		}

		printf("$%.2lf\n",
			(-exchange_negative > exchange_positive) ? -exchange_negative : exchange_positive);


	}
	return 0;
}
