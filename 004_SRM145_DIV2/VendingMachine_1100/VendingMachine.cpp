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

class VendingMachine {
public:
	int motorUse(vector <string>, vector <string>);
	int col;
	int calstep(int from,int to);
};

int VendingMachine::calstep(int from,int to)
{
	int step1=(from-to+col)%col;
	int step2=(to-from+col)%col;
	if(step1<step2)
		return step1;
	return step2;
}

int VendingMachine::motorUse(vector <string> prices, vector <string> purchases)
{
	int i,j,mostexpensive,ans,pos,lastmin,currentmin,maxpos,x,y;
	int grid[50][50],sum[50];
	char buffer[100];
	int start;
	
	for(i=0,col=1;i<prices[0].size();i++)
		if(prices[0][i]==' ')
			col++;
	for(i=0;i<prices.size();i++)
	{
		strcpy(buffer,prices[i].c_str());
		start=0;
		for(j=0;j<col;j++)
		{
			sscanf(buffer+start,"%d",&grid[i][j]);
			for(start++;buffer[start]!='\0'&&buffer[start]!=' ';start++);
			start++;
		}
	}

	mostexpensive=0;
	pos=0;
	for(i=0;i<col;i++)
	{
		sum[i]=0;
		for(j=0;j<prices.size();j++)
			sum[i]+=grid[j][i];
		if(sum[i]>mostexpensive)
		{
			mostexpensive=sum[i];
			pos=i;
		}
	}
	ans=calstep(0,pos);
	lastmin=0;

	for(i=0;i<purchases.size();i++)
	{
		strcpy(buffer,purchases[i].c_str());
		sscanf(buffer,"%d,%d:%d",&x,&y,&currentmin);
		if(currentmin>=lastmin+5)
		{
			mostexpensive=sum[0];
			maxpos=0;
			for(j=1;j<col;j++)
			{
				if(sum[j]>mostexpensive)
				{
					mostexpensive=sum[j];
					maxpos=j;
				}
			}
			ans+=calstep(pos,maxpos);
			pos=maxpos;
		}
		if(grid[x][y]==-1)
			return -1;
		ans+=calstep(pos,y);
		sum[y]-=grid[x][y];
		grid[x][y]=-1;
		pos=y;
		lastmin=currentmin;
	}
	mostexpensive=sum[0];
	maxpos=0;
	for(i=1;i<col;i++)
	{
		if(sum[i]>mostexpensive)
		{
			mostexpensive=sum[i];
			maxpos=i;	
		}
	}
	ans+=calstep(maxpos,pos);
	return ans;
}


double test0() {
	string t0[] = {"100 100 100"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0,0:0", "0,2:5", "0,1:10"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	VendingMachine * obj = new VendingMachine();
	clock_t start = clock();
	int my_answer = obj->motorUse(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"100 200 300 400 500 600"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	VendingMachine * obj = new VendingMachine();
	clock_t start = clock();
	int my_answer = obj->motorUse(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 17;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"100 200 300 400 500 600"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	VendingMachine * obj = new VendingMachine();
	clock_t start = clock();
	int my_answer = obj->motorUse(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 11;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"100 100 100"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0,0:10", "0,0:11"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	VendingMachine * obj = new VendingMachine();
	clock_t start = clock();
	int my_answer = obj->motorUse(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"100 200 300",
 "600 500 400"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0,0:0", "1,1:10", "1,2:20",
 "0,1:21", "1,0:22", "0,2:35"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	VendingMachine * obj = new VendingMachine();
	clock_t start = clock();
	int my_answer = obj->motorUse(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
