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

class ProblemWriting {
public:
	string myCheckData(string);
};

string ProblemWriting::myCheckData(string dotForm)
{
	string ans="";
	int current,i;
	if(dotForm.size()>25)
	{
		ans="dotForm must contain between 1 and 25 characters, inclusive.";
		return ans;
	}
	char str[90];
	if(dotForm[0]<'0'||dotForm[0]>'9')
	{
		ans="dotForm is not in dot notation, check character 0.";
		return ans;
	}
	current=1;
	while(current<dotForm.size())
	{
		for(i=current;i<dotForm.size()&&dotForm[i]=='.';i++);
		if(i>=dotForm.size())
		{
			sprintf(str,"dotForm is not in dot notation, check character %d.",i);
			ans=(string)str;
			return ans;
		}
		if(dotForm[i]!='+'&&dotForm[i]!='-'&&dotForm[i]!='*'&&dotForm[i]!='/')
		{
			sprintf(str,"dotForm is not in dot notation, check character %d.",i);
			ans=(string)str;
			return ans;
		}
		current=i+1;
		if(current>=dotForm.size())
		{
			sprintf(str,"dotForm is not in dot notation, check character %d.",i+1);
			ans=(string)str;
			return ans;
		}
		for(i=current;i<dotForm.size()&&dotForm[i]=='.';i++);
		if(i>=dotForm.size())
		{
			sprintf(str,"dotForm is not in dot notation, check character %d.",i);
			ans=(string)str;
			return ans;
		}
		if(dotForm[i]<'0'||dotForm[i]>'9')
		{
			sprintf(str,"dotForm is not in dot notation, check character %d.",i);
			ans=(string)str;
			return ans;
		}
		current=i+1;
	}
	ans="";
	return ans;
}


double test0() {
	string p0 = "3+5";
	ProblemWriting * obj = new ProblemWriting();
	clock_t start = clock();
	string my_answer = obj->myCheckData(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
	string p0 = "9..+.5...*....3";
	ProblemWriting * obj = new ProblemWriting();
	clock_t start = clock();
	string my_answer = obj->myCheckData(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
	string p0 = "5.3+4";
	ProblemWriting * obj = new ProblemWriting();
	clock_t start = clock();
	string my_answer = obj->myCheckData(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "dotForm is not in dot notation, check character 2.";
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
	string p0 = "9*9*9*9*9*9*9*9*9*9*9*9*9*9";
	ProblemWriting * obj = new ProblemWriting();
	clock_t start = clock();
	string my_answer = obj->myCheckData(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "dotForm must contain between 1 and 25 characters, inclusive.";
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
	string p0 = "3.........../...........4";
	ProblemWriting * obj = new ProblemWriting();
	clock_t start = clock();
	string my_answer = obj->myCheckData(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "";
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
