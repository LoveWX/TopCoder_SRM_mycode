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

class Pricing {
public:
	int maxSales(vector <int>);
};

int Pricing::maxSales(vector <int> price)
{
	int i,j,k,h,maxp,num,ans;
	sort(price.begin(),price.end());
	num=1;
	for(i=1;i<price.size();i++)
	{
		if(price[i]!=price[i-1])
			num++;
	}
	if(num<=4)
	{
		ans=0;
		for(i=0;i<price.size();i++)
			ans+=price[i];
		return ans;
	}
	maxp=0;
	reverse(price.begin(),price.end());
	for(i=0;i<price.size();i++)
	{
		for(j=i+1;j<price.size();j++)
		{
			for(k=j+1;k<price.size();k++)
			{
				for(h=k+1;h<price.size();h++)
				{
					num=(i+1)*price[i]+(j-i)*price[j]+(k-j)*price[k]+(h-k)*price[h];
					if(num>maxp)
						maxp=num;
				}
			}
		}
	}
	return maxp;
}

double test0() {
	int t0[] = {9,1,5,5,5,5,4,8,80};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Pricing * obj = new Pricing();
	clock_t start = clock();
	int my_answer = obj->maxSales(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 120;
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
	int t0[] = {17,50,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Pricing * obj = new Pricing();
	clock_t start = clock();
	int my_answer = obj->maxSales(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 69;
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
	int t0[] = {130,110,90,13,6,5,4,3,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Pricing * obj = new Pricing();
	clock_t start = clock();
	int my_answer = obj->maxSales(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 346;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}

//Powered by [KawigiEdit] 2.0!
