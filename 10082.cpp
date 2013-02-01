#include "stdio.h"
#include "iostream"

using namespace std;


int main(int argc, char const *argv[])
{
	char dic[128];
	dic['1'] = '`';
	dic['2'] = '1';
	dic['3'] = '2';
	dic['4'] = '3';
	dic['5'] = '4';
	dic['6'] = '5';
	dic['7'] = '6';
	dic['8'] = '7';
	dic['9'] = '8';
	dic['0'] = '9';
	dic['-'] = '0';
	dic['='] = '-';

	dic['W'] = 'Q';
	dic['E'] = 'W';
	dic['R'] = 'E';
	dic['T'] = 'R';
	dic['Y'] = 'T';
	dic['U'] = 'Y';
	dic['I'] = 'U';
	dic['O'] = 'I';
	dic['P'] = 'O';
	dic['['] = 'P';
	dic[']'] = '[';
	dic['\\'] = ']';

	dic['S'] = 'A';
	dic['D'] = 'S';
	dic['F'] = 'D';
	dic['G'] = 'F';
	dic['H'] = 'G';
	dic['J'] = 'H';
	dic['K'] = 'J';
	dic['L'] = 'K';
	dic[';'] = 'L';
	dic['\''] = ';';

	dic['X'] = 'Z';
	dic['C'] = 'X';
	dic['V'] = 'C';
	dic['B'] = 'V';
	dic['N'] = 'B';
	dic['M'] = 'N';
	dic[','] = 'M';
	dic['.'] = ',';
	dic['/'] = '.';

	dic[' '] = ' '; 
	dic['\n'] = '\n';

	char c = ' ';
	while((c = getchar()) != EOF)
		putchar(dic[c]);

	return 0;
}