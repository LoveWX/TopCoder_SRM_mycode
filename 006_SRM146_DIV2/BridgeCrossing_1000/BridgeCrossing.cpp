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

class BridgeCrossing
{
public:
	int minTime(vector <int>);
	int findmintime(vector <int> times,int len);
};

int BridgeCrossing::minTime(vector <int> times)
{
	sort(times.begin(),times.end());
	return findmintime(times,times.size());
}

int BridgeCrossing::findmintime(vector <int> times,int len)
{
	if(len==1)
		return times[0];
	if(len==2)
		return times[1];
	if(len==3)
		return times[0]+times[1]+times[2];
	int t1=times[0]+times[0]+times[len-2]+times[len-1];
	int t2=times[0]+times[1]+times[1]+times[len-1];
	if(t1>t2)
		t1=t2;
	return t1+findmintime(times,len-2);
}

double test2() {
	int t0[] = { 1, 2, 5, 10 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BridgeCrossing * obj = new BridgeCrossing();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 17;
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
	int t0[] = { 1, 2, 3, 4, 5 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BridgeCrossing * obj = new BridgeCrossing();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
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
double test0() {
	int t0[] = { 100 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BridgeCrossing * obj = new BridgeCrossing();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 100;
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
	int t0[] = { 1, 2, 3, 50, 99, 100 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BridgeCrossing * obj = new BridgeCrossing();
	clock_t start = clock();
	int my_answer = obj->minTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 162;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}

//Powered by [KawigiEdit] 2.0!
