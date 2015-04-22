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

class PrefixCode {
public:
	string isOne(vector <string>);
};

string PrefixCode::isOne(vector <string> words)
{
	int i,j,l1;
	bool isprefix;
	char s1[51],s2[51];
	for(i=0;i<words.size();i++)
	{
		isprefix=false;
		strcpy(s1,words[i].c_str());
		l1=words[i].size();
		for(j=0;j<words.size();j++)
		{
			if(i==j)
				continue;
			strcpy(s2,words[j].c_str());
			s2[l1]='\0';
			if(strcmp(s1,s2)==0)
			{
				isprefix=true;
				break;
			}
		}
		if(isprefix)
		{
			sprintf(s1,"%d",i);
			string ans="No, "+(string)(s1);
			return ans;
		}
	}
	return (string)("Yes");
}


double test0() {
	string t0[] = {"trivial"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"10001", "011", "100", "001", "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "No, 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"no", "nosy", "neighbors", "needed"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "No, 0";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"1010", "11", "100", "0", "1011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"No", "not"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrefixCode * obj = new PrefixCode();
	clock_t start = clock();
	string my_answer = obj->isOne(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
