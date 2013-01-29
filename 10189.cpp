#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

static int lines;
static int columns;
static char chart[101][101];
static int result[102][102];

#define MINE '*'
#define MATRIX_OFFSET 1

void dumpChart()
{
	int i,j;
	for (i=0;i<lines;i++) {
		for(j=0;j<columns;j++)
			cout << chart[i][j];
		printf("\n");
	}

}

void dumpResults()
{
	int i,j;
	for (i=0;i<lines;i++) {
		for(j=0;j<columns;j++)
			printf("%d ",result[i][j]);
		printf("\n");
	}

}

void calculate_mines()
{
	for (int i=0;i<lines;i++)
		for(int j=0;j<columns;j++)
			if (chart[i][j] == MINE)
			{
				int l = i+1;
				int c = j+1;
				result[l][c] = INT_MIN;
				result[l-1][c] += 1;
				result[l+1][c] += 1;
				result[l][c-1] += 1;
				result[l][c+1] += 1;
				result[l-1][c-1] += 1;
				result[l-1][c+1] += 1;
				result[l+1][c-1] += 1;
				result[l+1][c+1] += 1;
			}
}

void show_results()
{
	for(int i=1;i < lines+1  ;i++) {
		for(int j=1; j < columns+1; j++)
		{
			if (result[i][j] < 0)
				printf("%c",'*');
			else
				printf("%d",result[i][j]);
		}
		printf("\n");
	}

}

void init_result()
{
	for(int i=0;i<102;i++)
		for(int j=0; j< 102; j++)
			result[i][j] = 0;
}

int main(int argc, char const *argv[])
{
	int i=0,j=0,field=0;
	while (scanf("%d %d",&lines,&columns) != EOF)
	{
		if (lines == 0 && columns == 0)
			return 0;
		else {
			if (field > 0) {
				printf("\n");
			}
		}
		init_result();
		field++;
		for (i=0;i<lines;i++)		
			for(j=0;j<columns;j++)
				cin>>chart[i][j];			
		calculate_mines();
		printf("Field #%d:\n",field);
		
		show_results();
		scanf("%d %d",&lines,&columns);
	}
	return 0;
}