#include "stdio.h"
#include "iostream"
#include "vector"
#include "string"
#include "string.h"
#include "stdlib.h"
#include "utility"
#include "algorithm"
#include "map"

using namespace std;

#define TEAMS 101
#define PROBLEMS 11

class Result
{
	public:
		Result(int tempo_, bool submited_, bool solved_) : 
			tempo(tempo_), submited(submited_), solved(solved_) {};
		Result() {};
		~Result() {};
	
		int tempo;
		bool submited;
		bool solved;
};

class Team
{
	public:
		Team(int id_, int tempo_, int solved_) :
			id(id_),tempo(tempo_),solved(solved_) {};

		Team (int id_) : id(id_) {};
		Team() {};
		~Team() {};

		int id;
		int tempo;
		int solved;
};

bool operator== ( const Team &A, const Team &B) 
{
        return A.id == B.id;
}

struct IntCmp {
    bool operator()(const Team &A, const Team &B) {
        if (A.solved > B.solved) return true;
        if (A.solved < B.solved) return false;
        if (A.solved == B.solved)
        {
        	if (A.tempo > B.tempo) return false;
        	if (A.tempo < B.tempo) return true;
        	if (A.tempo == B.tempo) {
        		if (A.id >= B.id) return false;
        		else return true;
        	}
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	int num_cases,team,problem,tempo;
	char judge = ' ';
	Result contest[TEAMS][PROBLEMS];
	Result tmp;
	vector<Team> resultados;
	map<int,Team> teams;
	vector<Team>::iterator it;

	char line[TEAMS];
	scanf("%d", &num_cases);
	scanf("\n");
	while(num_cases--)
	{
		for (int i = 0; i < TEAMS; ++i)
		{
			for (int k = 0; k < PROBLEMS; ++k)
			{
				contest[i][k] = Result(0,false,false);
			}
		}		
		teams.clear();
		resultados.clear();

		while ( fgets (line,sizeof(line),stdin) && line[0] != '\n' )
		{
			// printf("%s\n", line);
			sscanf(line, "%d %d %d %c", &team,&problem,&tempo,&judge);
			tmp = contest[team][problem];
			tmp.submited = true;
			if (!tmp.solved)
			{
				if (judge == 'I') {
					tmp.tempo += 20;	
				}
				if (judge == 'C') {
					tmp.solved = true;
					tmp.tempo += tempo;
				}
			}
			contest[team][problem] = tmp;
		} 

		for (int i = 0; i < TEAMS; ++i)
		{
			for (int k = 0; k < PROBLEMS; ++k)
			{
				tmp = contest[i][k];
				if (tmp.submited) 
				{
					if (teams.count(i) != 0)
					{
						Team t = teams[i];
						if (tmp.solved)
						{
							t.solved++;
							t.tempo += tmp.tempo;
							teams[i] = t;
						}
					} else { /* not found */
						if (tmp.solved)
						{
							Team t(i,tmp.tempo,1);	
							teams[i] = t;
						} else { /* not found not solved */
							Team t(i,0,0);	
							teams[i] = t;
						} 
						
					}
				}
			}
		}
		map<int,Team>::iterator it = teams.begin();
		while(it!=teams.end()) {
			resultados.push_back(it->second);
			it++;
		}
			
		sort(resultados.begin(), resultados.end(), IntCmp());

		vector<Team>::iterator iter = resultados.begin();
		while(iter!=resultados.end()) {
			printf("%d %d %d\n", (*iter).id,(*iter).solved,(*iter).tempo);
			iter++;
		}

		if (num_cases) printf("\n");
			

	}
	return 0;
}