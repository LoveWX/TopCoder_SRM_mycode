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

class MNS {
public:
	int combos(vector <int>);
	bool ismns(vector<int> &comb);
};

bool cmp(const int &a,const int &b)
{
	return a>b;
}

bool MNS::ismns(vector<int> &comb)
{
	int r0,r1,r2,c0,c1,c2;
	r0=comb[0]+comb[1]+comb[2];
	r1=comb[3]+comb[4]+comb[5];
	if(r0!=r1)
		return false;
	r2=comb[6]+comb[7]+comb[8];
	if(r0!=r2)
		return false;
	c0=comb[0]+comb[3]+comb[6];
	if(r0!=c0)
		return false;
	c1=comb[1]+comb[4]+comb[7];
	if(r0!=c1)
		return false;
	c2=comb[2]+comb[5]+comb[8];
	if(r0!=c2)
		return false;
	return true;
}

int MNS::combos(vector <int> numbers)
{
	sort(numbers.begin(),numbers.end());
	int ans=0;
	do 
	{
		if(ismns(numbers))
			ans++;
	} while(next_permutation(numbers.begin(),numbers.end()));
	return ans;
}


double test0() {
	int t0[] = {1,2,3,3,2,1,2,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MNS * obj = new MNS();
	clock_t start = clock();
	int my_answer = obj->combos(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 18;
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
	int t0[] = {4,4,4,4,4,4,4,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MNS * obj = new MNS();
	clock_t start = clock();
	int my_answer = obj->combos(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {1,5,1,2,5,6,2,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MNS * obj = new MNS();
	clock_t start = clock();
	int my_answer = obj->combos(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 36;
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
	int t0[] = {1,2,6,6,6,4,2,6,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MNS * obj = new MNS();
	clock_t start = clock();
	int my_answer = obj->combos(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
