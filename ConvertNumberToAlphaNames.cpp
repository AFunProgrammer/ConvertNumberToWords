/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string>
#include <deque>
#include <iostream>
#include <stdlib.h>

using namespace std;

string getOddTensValues(int Value)
{
    string out = "";
    
    switch(Value)
    {
        case 0:
            out = string("ten");
            break;
        case 1:
            out = string("eleven");
            break;
        case 2:
            out = string("twelve");
            break;
        case 3:
            out = string("thirteen");
            break;
        case 4:
            out = string("fourteen");
            break;
        case 5:
            out = string("fifteen");
            break;
        case 6:
            out = string("sixteen");
            break;
        case 7:
            out = string("seventeen");
            break;
        case 8:
            out = string("eighteen");
            break;
        case 9:
            out = string("nineteen");
            break;
    }
    
    return out;   
}

string getOnesString(int Value, bool Tens)
{
    string out = "";

    switch(Value)
    {
        case 0:
            //cout << (idigit == 2 ? "ten" : "zero" );
            break;
        case 1:
            out = string(Tens ? "" : "one");
            break;
        case 2:
            out = string(Tens ? "twenty" : "two" );
            break;
        case 3:
            out = string(Tens ? "thirty" : "three" );
            break;
        case 4:
            out = string(Tens ? "fourty" : "four" );
            break;
        case 5:
            out = string(Tens ? "fifty" : "five" );
            break;
        case 6:
            out = string(Tens ? "sixty" : "six" );
            break;
        case 7:
            out = string(Tens ? "seventy" : "seven" );
            break;
        case 8:
            out = string(Tens ? "eighty" : "eight" );
            break;
        case 9:
            out = string(Tens ? "ninety" : "nine" );
            break;
    }
    
    return out;
}

string getUnitsString(int DigitsPlace, int Value)
{
    string out = "";

    switch ( DigitsPlace )
    {
        case 2:
        case 5:
        case 8:
        case 11:
        case 14:
        case 17:
        case 20:
            out = (Value == 0 ? "" : string("hundred"));
            break;
        case 3:
            out = string("thousand");
            break;
        case 6:
            out = string("million");
            break;
        case 9:
            out = string("billion");
            break;
        case 12:
            out = string("trillion");
            break;
        case 15:
            out = string("quadrillion");
            break;
        case 18:
            out = string("quintillion");
            break;
        default:
            out = string("");
            break;
    }
    
    return out;
}

bool isTensDigit(int DigitsPlace)
{
    switch ( DigitsPlace )
    {
        case 1:
        case 4:
        case 7:
        case 10:
        case 13:
        case 16:
        case 19:
            return true;
        default:
            return false;
    }
        
    return false;
}

int main()
{
    long int iInput = 0;
    cout << "Input A Number To Convert To It's Word Value: ";
    cin >> iInput;

    cout << "The Number Received Was: " << iInput << endl;
    
    string strValue = to_string(iInput);
    int ilength = strValue.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string stdout = "";
    
    for( int i = ilength; i >= 0; i-- )
    {
        cNumber = strValue[ilength - i];
        iNumber = atoi(&cNumber);

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= ilength && isTensDigit(i+1) && iPrevNumber == 1 )
            stdout = getOddTensValues( iNumber );
        else
            stdout = getOnesString( iNumber, bTens );

        cout << stdout;
        
        if ( stdout.length() != 0 )
            cout << " ";

        stdout = getUnitsString(i,iNumber);
        
        cout << stdout;
        
        if ( stdout.length() != 0 )
            cout << " ";
        
        stdout = "";
        iPrevNumber = iNumber; 
    }


    return 0;
}
