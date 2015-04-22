#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

class MergeSort {
public:
	int howManyComparisons(vector <int>);
	int ans;
	queue<int> mergesort(queue<int> a);
	queue<int> merge(queue<int> b,queue<int> c);
};

queue<int> MergeSort::mergesort(queue<int> a)
{
	int i,t;
	if(a.size()<=1)
	{
		return a;
	}
	queue<int> b;
	t=a.size()/2;
	for(i=0;i<t;i++)
	{
		b.push(a.front());
		a.pop();
	}
	queue<int> c(a);
	queue<int> sb=mergesort(b);
	queue<int> sc=mergesort(c);
	return merge(sb,sc);
}

queue<int> MergeSort::merge(queue<int> b,queue<int> c)
{
	int bb,cc;
	queue<int> a;
	while((!b.empty())&&(!c.empty()))
	{
		bb=b.front();
		cc=c.front();
		ans++;
		if(bb<cc)
		{
			a.push(b.front());
			b.pop();
		}
		else if(bb>cc)
		{
			a.push(c.front());
			c.pop();
		}
		else
		{
			a.push(b.front());
			b.pop();
			a.push(c.front());
			c.pop();
		}
	}
	while (!b.empty())
	{
		a.push(b.front());
		b.pop();
	}
	while (!c.empty())
	{
		a.push(c.front());
		c.pop();
	}
	return a;
}

int MergeSort::howManyComparisons(vector <int> numbers)
{
	int i;
	ans=0;
	queue<int> num;
	for(i=0;i<numbers.size();i++)
	{
		num.push(numbers[i]);
	}
	mergesort(num);
	return ans;
}


double test0() {
	int t0[] = {1, 2, 3, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MergeSort * obj = new MergeSort();
	clock_t start = clock();
	int my_answer = obj->howManyComparisons(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	int t0[] = {2, 3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MergeSort * obj = new MergeSort();
	clock_t start = clock();
	int my_answer = obj->howManyComparisons(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = {-17};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MergeSort * obj = new MergeSort();
	clock_t start = clock();
	int my_answer = obj->howManyComparisons(p0);
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
double test3() {
	vector <int> p0;
	MergeSort * obj = new MergeSort();
	clock_t start = clock();
	int my_answer = obj->howManyComparisons(p0);
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
double test4() {
	int t0[] = {-2000000000,2000000000,0,0,0,-2000000000,2000000000,0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MergeSort * obj = new MergeSort();
	clock_t start = clock();
	int my_answer = obj->howManyComparisons(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 19;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}

//Powered by [KawigiEdit] 2.0!
