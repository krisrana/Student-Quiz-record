/*
     Name:      Krishna rana 
     Course:    CIS 160 ME1
     Date:      10/26/2016
     Program:   Student Quiz record
     Description:  This program keeps records and prints statistical analysis for a class
    			of students. who have three quizzes. The program reads input data from file
				and outputs the student ID, Quizzes score, total average of student,average
				of all the quiz, highest and lowest score for a Quiz to an output file.    				
*/
#include <iostream>//Standard Input/output streams libary
#include <iomanip>//Header providing parametric manipulators
#include <fstream>//Header providing file stream classes
using namespace std;
//declaring Array size
const int SIZE = 40;
//typedef to create an alias name for another data type.
typedef int intarray[SIZE];
typedef float farray[SIZE];
//Function prototype
int getdata(intarray, intarray, intarray, intarray, ifstream&);
void findstavg(farray, intarray, intarray, intarray, int);
int findhigh(int, intarray);
int findlow(int, intarray);
float findqzavg(int, intarray);
void printall(int, const intarray, const intarray, const intarray, const intarray,
			farray, int, int, int, int, int, int, float, float, float, ofstream&);
//Main() Function Defination
//This function runs the whole program with step by step intruction written below.
//main() has calls and parameters of other function in the program.
int main()
{
	//Local Definations/ Declarlations
	intarray StudId, Quiz1, Quiz2, Quiz3;
	farray StudAvg;
	int hi1, hi2, hi3, lo1, lo2, lo3, count;
	float qzavg1, qzavg2, qzavg3;
	//This are type associated with fstream,
	//ifstream get file info and ofstrem give info to file.
	ifstream infile("pr2data.txt");
	ofstream outfile;
	//opens the files to write data.
	outfile.open("OUTPUT.out");
	//file error check, checks if the file exist or not.	
	if(!infile)
	//if the file does not exist. prints the message.
	cout<<"file Error: file not present"<<endl;
	else
	{	//if file exist, follows this steps
		//function calls
		//count is the counter to count the number of times the array is used.
		count = getdata(StudId, Quiz1, Quiz2, Quiz3, infile);
		findstavg(StudAvg,Quiz1, Quiz2, Quiz3,count);
		hi1 = findhigh(count, Quiz1);
		hi2 = findhigh(count, Quiz2);
		hi3 = findhigh(count, Quiz3);
		lo1 = findlow(count, Quiz1);
		lo2 = findlow(count, Quiz2);
		lo3 = findlow(count, Quiz3);
		qzavg1 = findqzavg(count, Quiz1);
		qzavg2 = findqzavg(count, Quiz2);
		qzavg3 = findqzavg(count, Quiz3);
		printall(count, StudId, Quiz1, Quiz2, Quiz3, StudAvg, hi1, hi2, hi3, lo1, lo2, lo3,
				 qzavg1, qzavg2, qzavg3, outfile);
	}
	//close all file after data is updated
	infile.close();
	outfile.close();

	return 0;
}
//getdata() Function Defination
//This function is used to get input from the file.
//The input from file consist of student Id number, three Quiz scores.
//It's return type is int and acts as the counter of array as many time the getdata() is called
int getdata(intarray StudId, intarray Quiz1, intarray Quiz2, intarray Quiz3, ifstream& fin)
{
	//initializing i to 0
	int i = 0;
	fin>>StudId[i];
	//loop to read data until the trailing value 0 for student ID is encountered.
	while(StudId[i] != 0)
	{
		fin>>Quiz1[i];
		fin>>Quiz2[i];
		fin>>Quiz3[i];
		i++;
		fin>>StudId[i];
	}
	//returns the i, here i is used for counting purpose for the number of time loop is executed
	return i;
}
//findstavg Function Defination
//This Function is used to calculate average of three quizzes of a student.
//This function gets the data from main(), and main() gets it from getdata().
//It's return type is void(null)
void findstavg(farray StudAvg,intarray Quiz1, intarray Quiz2, intarray Quiz3,int count)
{
	//Local Definations/ Declarlations
	//counter for the sum of student quiz total 
	float Stavg;
	//loop to add three quiz score for every student Id encounterd.
	for(int i = 0; i < count; i++)
	{
		Stavg = Quiz1[i]+Quiz2[i]+Quiz3[i];
		StudAvg[i] = Stavg / 3;
	}
}
//findhigh Function Defination
//This is a general purpose function.
//This Function is used to find the highest quiz score of a student in each quiz.
//This function gets the data from main(), and main() gets it from getdata().
//It's return type is int, it returns the highest quiz score everytime the function is called
int findhigh(int count, intarray Quiz)
{
	//Local Definations/ Declarlations
	int highest = Quiz[0];
	//loop to find highest score in a quiz	
	for(int i = 0; i < count; i++)
		{
	   		if (highest <= Quiz[i])
				highest = Quiz[i];	
		}
	return highest;
}
//findlow Function Defination
//This is a general purpose function.
//This Function is used to find the lowest quiz score of a student in each quiz.
//This function gets the data from main(), and main() gets it from getdata().
//It's return type is int, it returns the lowest quiz score everytime the function is called
int findlow(int count, intarray Quiz)
{
	//Local Definations/ Declarlations
	int lowest = Quiz[0];
	//loop to find lowest score in a quiz	
	for(int i = 0; i < count; i++)
		{
			if (lowest >= Quiz[i])
				lowest = Quiz[i];
		}
	return lowest;
}
//findqzavg Function Defination
//This is a general purpose function.
//This Function is used to find the average of all quiz score of a student in each quiz.
//This function gets the data from main(), and main() gets it from getdata().
//It's return type is float, it returns the total quiz average for a quiz everytime the function is called
float findqzavg(int count, intarray Quiz)
{
	//Local Definations/ Declarlations
	float total = 0;
	//loop to find total quiz average
	for(int i = 0; i < count; i++)
	{
		total= total + Quiz[i];
	}
	return total/count;
}
//printall Function Defination
//This Function is the output function, it write's the data in an output file.
//It's return type is void(null)
void printall(int count, const intarray StudId, const intarray Quiz1, const intarray Quiz2,
			  const intarray Quiz3, farray StudAvg, int hi1, int hi2, int hi3, int lo1, int lo2, 
			  int lo3, float qzavg1, float qzavg2, float qzavg3, ofstream& fout)
{
	fout<<setw(41)<<"CIS Department - FALL 2016"<<endl;
	fout<<setw(40)<<"CIS 161 Class Statistics"<<endl;
	fout<<"***********************************************************************"<<endl;
	fout<<"Student"<<setw(15)<<"Quiz 1"<<setw(15)<<"Quiz 2"<<setw(15)<<"Quiz 3"<<setw(15)<<"Average"<<endl;
	fout<<"-----------------------------------------------------------------------"<<endl;
	fout<<fixed<<showpoint<<setprecision(2);
	for (int i = 0; i < count; i++)
	{
		fout<<StudId[i]<<setw(15)<<Quiz1[i]<<setw(15)<<Quiz2[i]<<setw(15)<<Quiz3[i]<<setw(15)<<StudAvg[i]<<endl;	
	}
	fout<<"-----------------------------------------------------------------------"<<endl;
	fout<<"High Score"<<setw(9)<<hi1<<setw(15)<<hi2<<setw(15)<<hi3<<endl<<endl;
	fout<<"Low  Score"<<setw(9)<<lo1<<setw(15)<<lo2<<setw(15)<<lo3<<endl<<endl;
	fout<<"Quiz Average"<<setw(10)<<qzavg1<<setw(15)<<qzavg2<<setw(15)<<qzavg3<<endl;
}
