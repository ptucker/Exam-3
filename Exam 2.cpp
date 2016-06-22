//
//  Exam 2.cpp
//  Exam 2
//
//  Created by Grant Bingham on 6/21/16.
//  Copyright (c) 2016 gbingham18. All rights reserved.
//
//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Runner
{
public:
    
    Runner(string setfirst, string setlast, int setpace)
    {
        firstname = setfirst;
        lastname = setlast;
        pace = setpace;
    }
    string getfirstname()
    {
        return firstname;
    }
    
    string getlastname()
    {
        return lastname;
    }
    
private:
    string firstname;
    string lastname;
    int pace;
};

int main()
{
    vector<string> firstnames;
    vector<string> lastnames;
    vector<int> racepace;
    int numberOfCompetitors = 0;
    
    //Input runner info from file
    ifstream input;
    
    input.open("registrants.txt");
    
    if(input.fail())
    {
        cout << "File does not exist, exit program." << endl;
    }
    
    while(!input.eof())
    {
        input >> firstnames >> lastnames >> racepace;
        numberOfCompetitors++;
    }
    
    input.close();
    
    //Sort runners based on mile-pace
    bool sorted;
    do
    {
        sorted = false;
        for(int n = 0; n < numberOfCompetitors; n++)
        {
            if(racepace[n] > racepace[n+1])
            {
                int temp = racepace[n];
                racepace[n] = racepace[n+1];
                racepace[n+1] = temp;
                
                //Keep runners' first/last names in order with their pace
                string temp1 = firstnames[n];
                firstnames[n] = firstnames[n+1];
                firstnames[n+1] = temp1;
                
                string temp2 = lastnames[n];
                lastnames[n] = lastnames[n+1];
                lastnames[n+1] = temp2;
                sorted = true;
            }
        }
    }while(sorted == true);
    
    // Assign runners to their groups based on pace
    for(int n = 0; n < numberOfCompetitors; n++)
    {
        if(racepace[n] > 0 && racepace[n] <= 360)
        {
            ofstream output;
            output.open("white.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();
        }
        else if(racepace[n] > 360 && racepace[n] <= 420)
        {
            ofstream output;
            output.open("yellow.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();            }
        else if(racepace[n] > 420 && racepace[n] <= 480)
        {
            ofstream output;
            output.open("green.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();
        }
        else if(racepace[n] > 480 && racepace[n] <= 540)
        {
            ofstream output;
            output.open("orange.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();            }
        else if(racepace[n] > 540 && racepace[n] <= 600)
        {
            ofstream output;
            output.open("blue.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();            }
        else if(racepace[n] > 600 && racepace[n] <= 720)
        {
            ofstream output;
            output.open("lilac.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();            }
        else if(racepace[n] > 720 && racepace[n] <= 1200)
        {
            ofstream output;
            output.open("red.txt");
            if(output.fail())
            {
                cout << "File does not exist, exit program." << endl;
            }
            output << firstnames[n] << " " << lastnames[n] << " " << racepace[n] << endl;
            output.close();
        }
    }
    
    //Create vector of Runner objects that takes vectors firstnames, lastnames, and racepace as arguments
    
    const int SIZE = numberOfCompetitors;
    vector<Runner> r1(SIZE);
    
    for(int i = 0; i < numberOfCompetitors; i++)
    {
        r1[i](firstnames[i], lastnames[i], racepace[i]);
    }
    
    return 0;
}


