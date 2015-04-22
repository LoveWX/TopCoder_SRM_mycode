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

struct Date 
{
	int m,d;
};

Date thedate[50];

bool smaller(const Date &a,const Date &b)
{
	if(a.m==b.m)
		return a.d<b.d;
	return a.m<b.m;
}

class Birthday {
public:
	string getNext(string, vector <string>);
};

string Birthday::getNext(string date, vector <string> birthdays)
{
	int i;
	Date today;
	today.m=(date[0]-'0')*10+date[1]-'0';
	today.d=(date[3]-'0')*10+date[4]-'0';
	for(i=0;i<birthdays.size();i++)
	{
		thedate[i].m=(birthdays[i][0]-'0')*10+birthdays[i][1]-'0';
		thedate[i].d=(birthdays[i][3]-'0')*10+birthdays[i][4]-'0';
		if(smaller(thedate[i],today))
		{
			thedate[i].m+=12;
		}
	}
	sort(&thedate[0],&thedate[birthdays.size()],smaller);
	if(thedate[0].m>12)
		thedate[0].m-=12;
	char t[51];
	t[0]=thedate[0].m/10+'0';
	t[1]=thedate[0].m%10+'0';
	t[2]='/';
	t[3]=thedate[0].d/10+'0';
	t[4]=thedate[0].d%10+'0';
	t[5]='\0';
	return (string)t;
}


double test0() {
	string p0 = "06/17";
	string t1[] = {"02/17 Wernie", "10/12 Stefan"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Birthday * obj = new Birthday();
	clock_t start = clock();
	string my_answer = obj->getNext(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "10/12";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "06/17";
	string t1[] = {"10/12 Stefan"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Birthday * obj = new Birthday();
	clock_t start = clock();
	string my_answer = obj->getNext(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "10/12";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "02/17";
	string t1[] = {"02/17 Wernie", "10/12 Stefan"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Birthday * obj = new Birthday();
	clock_t start = clock();
	string my_answer = obj->getNext(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "02/17";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "12/24";
	string t1[] = {"10/12 Stefan"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Birthday * obj = new Birthday();
	clock_t start = clock();
	string my_answer = obj->getNext(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "10/12";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "01/02";
	string t1[] = {"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	Birthday * obj = new Birthday();
	clock_t start = clock();
	string my_answer = obj->getNext(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "02/17";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
