#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "stdlib.h"
#include "set"
#include "stack"

#define MAX_LETTER 16

using namespace std;


vector<string> dicio[MAX_LETTER][MAX_LETTER];
vector<string> answer;
map<char,char> trans;


bool reverse_translate(char c)
{
	map<char,char>::iterator it = trans.begin();
	while(it != trans.end())
	{
		if (it->second == c)
			return true;
		it++;
	}
	return false;
}

int repeated_letters(string str)
{
    int i;
    set<char> cnt;
    int size = (int)str.length();

    for(i=0; i<size; i++)
    	cnt.insert(str[i]);

    return (int) (size-cnt.size());
}

bool impossible(char *str)
{
    char *p;
    int n;
    char word[80];
    bool imp = true;

    for(p=str; sscanf(p, "%s%n", word, &n)>0 && imp; p+=n) 
        imp = dicio[string(word).length()][repeated_letters(word)].empty();

    return imp;
}

bool backtrack(char *line, int deep)
{
	// volta
    if(*line == '\0')
        return true;

	int n;
	char word[MAX_LETTER];
	string coded;
	sscanf(line, "%s%n", word,&n);
	coded = word;
	int size = coded.length();
	int repeat = repeated_letters(coded);
	for (int i = 0; i < dicio[size][repeat].size(); ++i)
	{
		string candidate = dicio[size][repeat].at(i);
		string decoded;
		stack<char> chars_decoded;
		for(int k = 0; k< size;k++)
		{
			/* Dont have translation yet */
			if (trans.count(coded[k]) == 0) {
				/* Nothing reverse translates */
				if (!reverse_translate(candidate[k])) {
					trans[coded[k]] = candidate[k];
					chars_decoded.push(coded[k]);
				} else {
					break;
				}
			}
			decoded += trans[coded[k]];
		}

		if (decoded.length() == size && decoded == candidate) 
		{
			answer.push_back(decoded);
			if (backtrack(line+n,deep+1))
				return true;
			answer.pop_back();
		}
		while(!chars_decoded.empty())
		{
			trans.erase(chars_decoded.top());
			chars_decoded.pop();
		}
	}
	return false;

}

int main(int argc, char const *argv[])
{
	int num_words,size,repeat;;
	string current;
	getline(cin,current);
	sscanf(current.c_str(), "%d", &num_words);
	while(num_words--)
	{
		getline(cin,current);
		size = current.length();
		repeat = repeated_letters(current);
		dicio[size][repeat].push_back(current); 
	}
	while (getline(cin,current))
	{
		trans.clear();
		answer.clear();
		bool possible = true;
		if (impossible((char*)current.data())) 
		{
			possible = false;
		}
		else if (backtrack((char*)current.data(), 0)) 
		{
			possible = true;
		} else {
			possible = false;
		}
			
		if (!possible) {
			for (int i = 0; i < current.length(); i++)
				printf("%c", (current[i] >= 'a' && current[i] <= 'z') ? '*' : ' ');
		} else {
			printf("%s", answer[0].c_str());
            for(int i=1; i<(int)answer.size(); i++)
                printf(" %s", answer[i].c_str());
		}
		printf("\n");
	}
	return 0;
}