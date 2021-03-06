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

class CeyKaps {
public:
	string decipher(string, vector <string>);
};

string CeyKaps::decipher(string typed, vector <string> switches)
{
	int i;
	char word[26],cha,chb,tempch,s[26];
	for(i=0;i<26;i++)
		word[i]=i+'A';
	for(i=0;i<switches.size();i++)
	{
		cha=switches[i][0];
		chb=switches[i][2];
		tempch=word[cha-'A'];
		word[cha-'A']=word[chb-'A'];
		word[chb-'A']=tempch;
	}
	for(i=0;i<26;i++)
	{
		s[word[i]-'A']=i+'A';
	}
	for(i=0;i<typed.size();i++)
		typed[i]=s[typed[i]-'A'];
	return typed;
}


double test0() {
	string p0 = "AAAAA";
	string t1[] = {"A:B","B:C","A:D"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CeyKaps * obj = new CeyKaps();
	clock_t start = clock();
	string my_answer = obj->decipher(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "CCCCC";
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
	string p0 = "ABCDE";
	string t1[] = {"A:B","B:C","C:D","D:E","E:A"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CeyKaps * obj = new CeyKaps();
	clock_t start = clock();
	string my_answer = obj->decipher(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "AEBCD";
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
	string p0 = "IHWSIOTCHEDMYKEYCAPSARWUND";
	string t1[] = {"W:O","W:I"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CeyKaps * obj = new CeyKaps();
	clock_t start = clock();
	string my_answer = obj->decipher(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "WHOSWITCHEDMYKEYCAPSAROUND";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
	return 0;
}
