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

class RectangularGrid
{
public:
	long long countRectangles(int, int);
};

long long RectangularGrid::countRectangles(int width, int height)
{
	long long sum=(long long)width*(width+1)/2*(long long)height*(height+1)/2;
	while (width>0&&height>0)
	{
		sum-=width*height;
		width--;
		height--;
	}
	return sum;
}


double test0() {
	int p0 = 3;
	int p1 = 3;
	RectangularGrid * obj = new RectangularGrid();
	clock_t start = clock();
	long long my_answer = obj->countRectangles(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 22;
	cout <<"Desired answer: " <<endl;
	//cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	//cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 5;
	int p1 = 2;
	RectangularGrid * obj = new RectangularGrid();
	clock_t start = clock();
	long long my_answer = obj->countRectangles(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 31;
	cout <<"Desired answer: " <<endl;
	//cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	//cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 10;
	int p1 = 10;
	RectangularGrid * obj = new RectangularGrid();
	clock_t start = clock();
	long long my_answer = obj->countRectangles(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 2640;
	cout <<"Desired answer: " <<endl;
	//cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	//cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 1;
	int p1 = 1;
	RectangularGrid * obj = new RectangularGrid();
	clock_t start = clock();
	long long my_answer = obj->countRectangles(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0;
	cout <<"Desired answer: " <<endl;
	//cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	//cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 592;
	int p1 = 964;
	RectangularGrid * obj = new RectangularGrid();
	clock_t start = clock();
	long long my_answer = obj->countRectangles(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 81508708664;
	cout <<"Desired answer: " <<endl;
	//cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	//cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}

//Powered by [KawigiEdit] 2.0!
