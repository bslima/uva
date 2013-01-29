#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <map>


using namespace std;

static map<int,int> result;

int cycle_length(register int n)
{
	int count = 0;
	while (true)
	{
		if (result.count(n) != 0 ) {
			
			count += result[n];
			break;
		}
		else count++;
		if (n == 1) break;
		if (n%2) n = (3*n) + 1;
		else n >>= 1; 
	}
	return count;

}

int main(int argc, char const *argv[])
{
	int n,m,cycle,first,second;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		if (n < m) { first=n; second=m; } else { first=m; second=n; }
		int max = 0;
		printf("%d %d ",n,m);
		for (int i = first; i <= second;i++)
		{
			cycle = cycle_length(i);
			result[i] = cycle;
			if (cycle > max)	max = cycle;
		}
		printf("%d\n",max);
	}
	return 0;
}