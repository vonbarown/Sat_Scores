#include <iostream>

/// creating a program that reads data into arrays
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int readSATscores(int[], int[], int[], int[],int);
void printArray(const int[], int);
int sumscores (int[], int[], int[], int ,int[]);
int findmax(int[], int);
int tallyarea(int[], int, int);
const int SIZE=50;

ofstream outfile("Score Sheet.txt");

int main()
{

    int idnum[SIZE], readingscores[SIZE], mathscores[SIZE], writingscores [SIZE];
    int totalscores[SIZE];
    int numofelts=17, index, threshold=650;
    int n, numthresh,print_k_value=6;
// calling the scores
    n=readSATscores(idnum,readingscores,mathscores,writingscores,numofelts);
    cout << "There were: " << n << " students in attendance for the exam."<< endl;
    cout<< endl;
//printing the values in the array to the data file
      outfile<< setw(45)<<"Snapshot of data taken from 2015 SAT."<<endl;
      outfile<< setw(42)<<"________________________________"<<endl;
      outfile << "ID numbers of students present for the test. "<< endl;
         printArray(idnum,print_k_value);
      outfile << "The reading scores collected are."<<endl;
         printArray(readingscores,print_k_value);
      outfile << "The math scores collected are."<<endl;
         printArray(mathscores,print_k_value);
      outfile << "The writing scores collected are."<<endl;
         printArray(writingscores,print_k_value);
//calling the sum of three arrays into new array totalscores.
    sumscores(readingscores,mathscores,writingscores,n,totalscores);
//printing totalscores array
       outfile<< "The cumulated SAT scores are:"<<endl;
    printArray(totalscores,print_k_value);
       outfile<<endl;
//calling the function to find the max score of the cumulated test
      outfile<< setw(35)<<"2015 SAT statistics."<<endl;
      outfile<< setw(37)<<"____________________________"<<endl;
    index=findmax(totalscores,numofelts);
       outfile << "The student with the highest score is: "<< idnum[index]<< endl;
//calling the function that determines the amount of students above threshold
    numthresh=tallyarea(writingscores,numofelts,threshold);
       outfile<< "The amount of students above the threshold in writing is: "<< numthresh <<endl;
    outfile.close();
    return 0;
}
/***
Input: integer array idnum, readingscores, mathscores and writingscores containing n elements
Process: read in from from data file n elements into idnum, readingscores, mathscores and writingscores
Output: idnum, readingscores, mathscores and writingscores are filled with n values.
***/
int readSATscores(int idnum[],int reading[],int math[], int writing[],int n)
{
//opening read in data file
    fstream myinfile;
    myinfile.open("student info.txt");
    if (!myinfile) {
        cout << "file student info.txt does not exist! Program will exit.";
        exit(1);
    }
//reading data file to arrays with while loop
      int students=0;
    while ( students <n && !myinfile.eof()){
        myinfile >> idnum[students]>> reading[students] >> math[students] >> writing[students];
        students++;
    }
//printing the arrays to the screen
    for ( int i=0; i<n; i++){
        cout << "Student: " << idnum[i] << " Received: "<< reading[i] << " in reading " << math[i] << " in math and " << writing[i] << " in writing."<< endl;
     }
     myinfile.close();
    return students;
}
/**
Input: integer array arr[] receives the values from other arrays
Process: the for loop reads the numbers in the array
Output: the numbers in the four arrays are printed to file
**/
void printArray(const int arr[], int k)
{
    for (int i=0; i<k; i++)
        outfile <<  arr[i] << ' ';
        outfile <<endl;
}
/**
Input: values from the three arrays reading[],math[],writing[] containing the test scores
Process:the loop adds the values that are in the same index position together
Output: the sum of the values are placed in the new array totalscores[]
**/
int sumscores(int reading[], int math[], int writing[], int k, int totalscores[])
{
   for (int i=0; i<k-1; i++){
    totalscores[i]=reading[i]+math[i]+writing[i];  }
return 0;
}
/**Input:integer array arr[] receives values from the other arrays with scores
Process:goes through array evaluating numbers
Output: prints out the maximum grade on exam part
**/
int findmax (int arr[], int k)
{
    int maxgrade=arr[0];
    for (int i=0; i<k; i++){
    if (arr[i]> maxgrade)
        maxgrade=arr[i];
    }
    for (int i=0;i<k;i++){
        if (arr[i]==maxgrade)
            return i;
    }
    return -1;
}
/**Input: integer array[] receives values from the test score arrays
Process:the values are compared to a set threshold number
Output: the amount of test scores in arrays that are above the threshold**/
int tallyarea(int arr[], int n, int threshold)
{
    int numstud=0;
    for(int i=0; i<n; i++){
        if (arr[i]>=threshold)
            numstud++;
    }
    return numstud;
}
