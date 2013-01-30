#include "stdio.h"
#include "vector"
#include "iostream"
#include <sstream>
#include "string"
#include "string.h"
#include "stdlib.h"

using namespace std;


class Card
{
public:
	Card(int _value, string _suit) : value(_value),suit(_suit) {};
	~Card() {};

	int value;
	string suit;

	inline string to_string()
	{
		stringstream out;
		out << this->value;
		string val = out.str();
		if (this->value == 11) val = "Jack";
		if (this->value == 12) val = "Queen";
		if (this->value == 13) val = "King";
		if (this->value == 14) val = "Ace";
		return val + " " + "of" + " " + this->suit;
	}

};


vector<Card> deck;

void init_deck()
{
	deck.clear();
	string suits[] = {"Clubs", "Diamonds","Hearts","Spades"};
	int values[] = {2,3,4,5,6,7,8,9,10,11,12,13,14};
	int count = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int k = 0; k < 13; k++)
		{
			Card atual(values[k],suits[i]);
			deck.push_back(atual);
			// printf("%s\n", deck.at(count).to_string().data());
			count++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int num_tests,num_shuffles;
	scanf("%d",&num_tests);
	// printf("Num tests %d\n", num_tests);
	for (int i = 0; i < num_tests; i++)
	{
		init_deck();
		scanf("%d", &num_shuffles);
		// printf("Num shuffles %d\n",num_shuffles);
		int shuffles[num_shuffles][52];
		for (int m = 0; m < num_shuffles; ++m)
		{
			for (int k = 0; k < 52; k++)
			{

				scanf("%d",&shuffles[m][k]);
				// printf("%d ",shuffles[i][k]);
			}
			// printf("\n\n");
		}
		getchar();
		char input[50];
		vector<Card> previous = deck;
		vector<Card> current;
		while ( gets (input) && strlen (input) )
		{
			vector<Card>::iterator it;
			int order = atoi(input);
			for (int j = 0; j < 52; j++)
			{
				int i = shuffles[order-1][j]-1;
				it = current.begin() + j;
				Card tmp = previous.at(i);
				current.insert(it,tmp);
			}
			previous = current;			
		}

		for (int n = 0; n < 52; n++)
		{
			printf("%s\n", current.at(n).to_string().data());
		}
		// printf("%s", current.at(51).to_string().data());

		if (i+1 != num_tests) printf("\n");
		
	}

	return 0;
}