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
#include <queue>

using namespace std;

class PowerOutage {
public:
	int estimateTimeOut(vector <int>, vector <int>, vector <int>);
};

int PowerOutage::estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)
{
	int grid[60][60],dis[60];
	int ans=0,temp=0,i,j,from,n=0;
	for(i=0;i<fromJunction.size();i++)
	{
		if(n<toJunction[i])
			n=toJunction[i];
	}
	n++;
	for(i=0;i<n;i++)
	{
		dis[i]=0;
		for(j=0;j<n;j++)
			grid[i][j]=0;
	}
	for(i=0;i<fromJunction.size();i++)
	{
		grid[fromJunction[i]][toJunction[i]]=ductLength[i];
		ans+=ductLength[i];
	}
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		from=q.front();
		q.pop();
		for(i=0;i<n;i++)
		{
			if(grid[from][i]!=0)
			{
				dis[i]=dis[from]+grid[from][i];
				grid[from][i]=0;
				q.push(i);
			}
		}
	}
	for(i=0;i<n;i++)
		if(dis[i]>temp)
			temp=dis[i];
	return ans+ans-temp;
}


double test0() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	PowerOutage * obj = new PowerOutage();
	clock_t start = clock();
	int my_answer = obj->estimateTimeOut(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10,10,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	PowerOutage * obj = new PowerOutage();
	clock_t start = clock();
	int my_answer = obj->estimateTimeOut(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 40;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0,0,0,1,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,3,4,2,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10,10,100,10,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	PowerOutage * obj = new PowerOutage();
	clock_t start = clock();
	int my_answer = obj->estimateTimeOut(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 165;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0,0,0,1,4,4,6,7,7,7,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,3,4,2,5,6,7,20,9,10,31};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10,10,100,10,5,1,1,100,1,1,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	PowerOutage * obj = new PowerOutage();
	clock_t start = clock();
	int my_answer = obj->estimateTimeOut(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 281;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0,0,0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100,200,300,400,500};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	PowerOutage * obj = new PowerOutage();
	clock_t start = clock();
	int my_answer = obj->estimateTimeOut(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2500;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
