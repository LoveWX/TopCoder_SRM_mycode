#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class BrickByBrick {
public:
	int timeToClear(vector <string>);
	int x,y,themove,numofbrick;
	int ballmove();
	char grid[20][20];
};

int BrickByBrick::ballmove()
{
	switch(themove)
	{
	case 0:
		if(grid[x][y+1]=='.')
		{
			y++;
			themove=5;	
		}
		else if(grid[x][y+1]=='B')
		{
			grid[x][y+1]='.';
			themove=1;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=1;
		}
		break;
	case 1:
		if(grid[x+1][y]=='.')
		{
			x++;
			themove=4;	
		}
		else if(grid[x+1][y]=='B')
		{
			grid[x+1][y]='.';
			themove=2;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=2;
		}
		break;
	case 2:
		if(grid[x][y-1]=='.')
		{
			y--;
			themove=7;	
		}
		else if(grid[x][y-1]=='B')
		{
			grid[x][y-1]='.';
			themove=3;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=3;
		}
		break;
	case 3:
		if(grid[x-1][y]=='.')
		{
			x--;
			themove=6;	
		}
		else if(grid[x-1][y]=='B')
		{
			grid[x-1][y]='.';
			themove=0;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=0;
		}
		break;
	case 4:
		if(grid[x][y-1]=='.')
		{
			y--;
			themove=1;	
		}
		else if(grid[x][y-1]=='B')
		{
			grid[x][y-1]='.';
			themove=5;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=5;
		}
		break;
	case 5:
		if(grid[x+1][y]=='.')
		{
			x++;
			themove=0;	
		}
		else if(grid[x+1][y]=='B')
		{
			grid[x+1][y]='.';
			themove=6;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=6;
		}
		break;
	case 6:
		if(grid[x][y+1]=='.')
		{
			y++;
			themove=3;	
		}
		else if(grid[x][y+1]=='B')
		{
			grid[x][y+1]='.';
			themove=7;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=7;
		}
		break;
	case 7:
		if(grid[x-1][y]=='.')
		{
			x--;
			themove=2;	
		}
		else if(grid[x-1][y]=='B')
		{
			grid[x-1][y]='.';
			themove=4;
			numofbrick--;
			return 1;
		}
		else
		{
			themove=4;
		}
		break;
	}
	return 0;
}

int BrickByBrick::timeToClear(vector <string> map)
{
	int i,j,step,anstime;
	numofbrick=0;
	for(i=0;i<map.size();i++)
	{
		for(j=0;j<map[0].size();j++)
		{
			grid[i+1][j+1]=map[i][j];
			if(map[i][j]=='B')
				numofbrick++;
		}
	}
	for(i=0;i<=map.size()+1;i++)
	{
		grid[i][0]='#';
		grid[i][map[0].size()+1]='#';
	}
	for(j=0;j<=map[0].size()+1;j++)
	{
		grid[0][j]='#';
		grid[map.size()+1][j]='#';
	}
	anstime=0;	
	step=0;
	x=1;
	y=1;
	themove=0;
	while(numofbrick>0)
	{
		if(ballmove()==0)
		{
			step++;
			anstime++;
		}
		else
		{
			step=0;
			anstime++;
		}
		if(step>1000&&numofbrick>0)
		{
			return -1;
		}
	}
	return anstime;
}

/*
// themove means:
//  __________
// |    /\    |
// |   /  \   |
// |  3    0  |
// | /      \ |
// |/        \|
// |\        /|
// | \      / |
// |  2    1  |
// |   \  /   |
// |____\/____|
// clockwise
//  __________
// |    /\    |
// |   /  \   |
// |  4    7  |
// | /      \ |
// |/        \|
// |\        /|
// | \      / |
// |  5    6  |
// |   \  /   |
// |____\/____|
// anticlockwise
*/

double test0() {
	string t0[] = { ".B",
  "BB" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = { ".BB",
  "BBB",
  "BBB" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = { "......B",
  "###.###",
  "B.....B" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 35;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = { "..BBB...",
  ".#BB..#.",
  "B.#B.B..",
  "B.B.....",
  "##.B.B#.",
  "#BB.#.B.",
  "B..B.BB.",
  "#..BB..B",
  ".B....#." };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = { ".BB..BBB.B...",
  "B.B...B..BB..",
  "#B...B#B.....",
  "B#B.B##...##B",
  "BB.B#.B##B.B#",
  "B.B#.BBB.BB#B",
  "B#BBB##.#B#B.",
  "B#BB.BBB#BB.#" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3912;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = { ".BBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB",
  "B##############",
  "BBBBBBBBBBBBBBB",
  "##############B",
  "BBBBBBBBBBBBBBB" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BrickByBrick * obj = new BrickByBrick();
	clock_t start = clock();
	int my_answer = obj->timeToClear(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 31753;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}

//Powered by [KawigiEdit] 2.0!
