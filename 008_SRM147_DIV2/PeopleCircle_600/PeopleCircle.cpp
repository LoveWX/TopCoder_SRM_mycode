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

class PeopleCircle {
public:
	string order(int, int, int);
};

string PeopleCircle::order(int numMales, int numFemales, int K)
{
	int i,j,inposition=numMales,newposition,len=numMales+numFemales;
	if(numMales==0)
	{
		char tempans[51];
		for(i=0;i<numFemales;i++)
			tempans[i]='F';
		tempans[i]='\0';
		string ans1=tempans;
		return ans1;
	}
	if(numFemales==0)
	{
		char tempans[51];
		for(i=0;i<numMales;i++)
			tempans[i]='M';
		tempans[i]='\0';
		string ans2=tempans;
		return ans2;
	}
	char* mycircle=new char[len+1];
	char* tempcircle=new char[len+1];
	char* temppoint;
	for(i=0;i<numMales;i++)
	{
		mycircle[i]='M';
	}
	mycircle[numMales]='F';
	numFemales--;
	while (numFemales>0)
	{
		newposition=inposition-(K%(inposition+1)-1);
		if(newposition>inposition)
			newposition=0;
		for(i=inposition+1;i>newposition;i--)
			mycircle[i]=mycircle[i-1];
		mycircle[newposition]='F';
		for(i=newposition+1,j=0;i<=inposition;i++,j++)
			tempcircle[j]=mycircle[i];
		tempcircle[j++]='F';
		for(i=0;i<=newposition;i++,j++)
			tempcircle[j]=mycircle[i];
		temppoint=mycircle;
		mycircle=tempcircle;
		tempcircle=temppoint;
		numFemales--;
		inposition++;
	}
	inposition=len-K%len;
	for(i=inposition,j=0;i<len;i++,j++)
		tempcircle[j]=mycircle[i];
	for(i=0;i<inposition;i++,j++)
		tempcircle[j]=mycircle[i];
	tempcircle[len]='\0';
	string ans=tempcircle;
	//delete[] mycircle;
	//delete[] tempcircle;
	return ans;
}


double test0() {
	int p0 = 5;
	int p1 = 3;
	int p2 = 2;
	PeopleCircle * obj = new PeopleCircle();
	clock_t start = clock();
	string my_answer = obj->order(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "MFMFMFMM";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 7;
	int p1 = 3;
	int p2 = 1;
	PeopleCircle * obj = new PeopleCircle();
	clock_t start = clock();
	string my_answer = obj->order(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "FFFMMMMMMM";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 25;
	int p1 = 25;
	int p2 = 1000;
	PeopleCircle * obj = new PeopleCircle();
	clock_t start = clock();
	string my_answer = obj->order(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int p1 = 5;
	int p2 = 3;
	PeopleCircle * obj = new PeopleCircle();
	clock_t start = clock();
	string my_answer = obj->order(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "MFFMMFFMFM";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1;
	int p1 = 0;
	int p2 = 245;
	PeopleCircle * obj = new PeopleCircle();
	clock_t start = clock();
	string my_answer = obj->order(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "M";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
