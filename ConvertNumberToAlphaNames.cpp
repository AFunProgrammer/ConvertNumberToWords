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

    if ( (DigitsPlace + 1) % 3 == 0 )
    {
        out = (Value == 0 ? "" : string("hundred"));
    }

    switch ( DigitsPlace )
    {
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
        case 21:
            out = string("sextillion");
            break;
        case 24:
            out = string("septillion");
            break;
        case 27:
            out = string("octillion");
            break;
        case 30:
            out = string("nonillion");
            break;
        case 33:
            out = string("decillion");
            break;
        case 36:
            out = string("undecillion");
            break;
        case 39:
            out = string("duodecillion");
            break;
        case 42:
            out = string("tredecillion");
            break;
        case 45:
            out = string("quattuordecillion");
            break;
        case 48:
            out = string("quindecillion");
            break;
        case 51:
            out = string("sexdecillion");
            break;
        case 54:
            out = string("septendecillion");
            break;
        case 57:
            out = string("octodecillion");
            break;
        case 60:
            out = string("novemdecillion");
            break;
    }
    
    /*
    Place
    1 	Ten 	Ten 	Ten 	da 	Deca-
    2 	Hundred 	Hundred 	Hundred 	h 	Hecto-
    3 	Thousand 	Thousand 	Thousand 	K 	Kilo-
    4 	Ten thousand 	Ten thousand 	Ten thousand 	my (Now obsolete) 	Myria- (Now obsolete)
    5 	Hundred thousand 	Hundred thousand 	Hundred thousand 		
    6 	Million 	Million 	Million 	M 	Mega-
    9 	Billion 	Milliard 	Thousand million 	G 	Giga-
    12 	Trillion 	Billion 	Billion 	T 	Tera-
    15 	Quadrillion 	Billiard 	Thousand billion 	P 	Peta- 
    18 	Quintillion 	Trillion 	Trillion 	E 	Exa-
    21 	Sextillion 	Trilliard 	Thousand trillion 	Z 	Zetta-
    24 	Septillion 	Quadrillion 	Quadrillion 	Y 	Yotta-
    27 	Octillion 	Quadrilliard 	Thousand quadrillion
    30 	Nonillion 	Quintilion 	Quintillion
    33 	Decillion 	Quintilliard 	Thousand quintillion
    36 	Undecillion 	Sextillion 	Sextillion
    39 	Duodecillion 	Sextilliard 	Thousand sextillion
    42 	Tredecillion 	Septillion 	Septillion
    45 	Quattuordecillion 	Septilliard 	Thousand septillion
    48 	Quindecillion 	Octillion 	Octillion
    51 	Sexdecillion 	Octilliard 	Thousand octillion
    54 	Septendecillion 	Nonillion 	Nonillion
    57 	Octodecillion 	Nonilliard 	Thousand nonillion
    60 	Novemdecillion 	Decillion 	Decillion
    */

    return out;
}

bool isTensDigit(int DigitsPlace)
{
    if ( (DigitsPlace + 2) % 3 == 0 )
        return true;

    return false;
}

string ConvertNumberToWords(string Value)
{
    string ConvertedToWords = "";
    int ilength = Value.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    
    for( int i = ilength; i >= 0; i-- )
    {
        cNumber = Value[ilength - i];
        iNumber = atoi(&cNumber);

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= ilength && isTensDigit(i+1) && iPrevNumber == 1 )
            word = getOddTensValues( iNumber );
        else
            word = getOnesString( iNumber, bTens );

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        word = getUnitsString(i,iNumber);
        
        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";
        
        word = "";
        iPrevNumber = iNumber; 
    }
    
    return ConvertedToWords;
}

int main()
{
    string sInput = string("");
    cout << "Input A Number To Convert To It's Word Value: ";
    cin >> sInput;

    cout << "The Number Received Was: " << sInput << endl;
    
    cout << ConvertNumberToWords(sInput);

    return 0;
}
