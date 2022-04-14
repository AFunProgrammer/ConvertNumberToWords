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

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
    {
        return false;
    }
    
    return true;
}

//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation)
{
    string converted = "";
    string eNotation = "";
    int nDecimalPos = -1;
    int nENotationPos = -1;
    int nPower = 0;
    int nAddPower = 0;
    
    nDecimalPos = ScientificNotation.find(".");

    nENotationPos = ScientificNotation.find("e");
    if ( string::npos == nENotationPos)
    {
        nENotationPos = ScientificNotation.find("e");
        if ( string::npos == nENotationPos)
            return string("error");
    }
    
    //negative ScientificNotation
    if ( ScientificNotation[nENotationPos+1] == '-' )
    {
        return string("0");
    }
    
    if ( ScientificNotation[nENotationPos+1] == '+' )
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+2));
    else
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+1));
    
    converted = ScientificNotation.substr(0,nENotationPos);
    
    //Add in number of digits past places already in the string
    if ( string::npos == nDecimalPos )
        nPower = 0;
    else
        nPower = converted.substr(nDecimalPos+1).length();
    
    for( int iAddPower = nPower; iAddPower < nAddPower; iAddPower++ )
    {
        converted += "0";
    }
    
    if ( string::npos != nDecimalPos)
        converted.erase(nDecimalPos,1);
    
    return converted;
}

//TODO
string convertToScientificNotation(const string Value)
{
    string converted = "";
    return converted;
}

string removeNonNumberCharacters(const string RemoveNonNumbers)
{
    string keepOnlyNumbers = RemoveNonNumbers;
    
    int iChar = 0;
    int iNumber = 0;
    
    while ( iChar < keepOnlyNumbers.length() )
    {
        //special characters
        if ( keepOnlyNumbers[iChar] == 'e' || keepOnlyNumbers[iChar] == 'E' || keepOnlyNumbers[iChar] == '+' || keepOnlyNumbers[iChar] == '.' )
        {
            iChar++;
            continue;
        }
            
        iNumber = keepOnlyNumbers[iChar] - (char)'0';
        
        if ( iNumber >= 0 && iNumber <= 9 )
            iChar++;
        else
            keepOnlyNumbers.erase(iChar, 1); 
    }

    return keepOnlyNumbers;
}


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
            break;/******************************************************************************
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

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
    {
        return false;
    }
    
    return true;
}

//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation)
{
    string converted = "";
    string eNotation = "";
    int nDecimalPos = -1;
    int nENotationPos = -1;
    int nPower = 0;
    int nAddPower = 0;
    
    nDecimalPos = ScientificNotation.find(".");

    nENotationPos = ScientificNotation.find("e");
    if ( string::npos == nENotationPos)
    {
        nENotationPos = ScientificNotation.find("e");
        if ( string::npos == nENotationPos)
            return string("error");
    }
    
    //negative ScientificNotation
    if ( ScientificNotation[nENotationPos+1] == '-' )
    {
        return string("0");
    }
    
    if ( ScientificNotation[nENotationPos+1] == '+' )
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+2));
    else
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+1));
    
    converted = ScientificNotation.substr(0,nENotationPos);
    
    //Add in number of digits past places already in the string
    if ( string::npos == nDecimalPos )
        nPower = 0;
    else
        nPower = converted.substr(nDecimalPos+1).length();
    
    for( int iAddPower = nPower; iAddPower < nAddPower; iAddPower++ )
    {
        converted += "0";
    }
    
    if ( string::npos != nDecimalPos)
        converted.erase(nDecimalPos,1);
    
    return converted;
}

//TODO
string convertToScientificNotation(const string Value)
{
    string converted = "";
    return converted;
}

string removeNonNumberCharacters(const string RemoveNonNumbers)
{
    string keepOnlyNumbers = RemoveNonNumbers;
    
    int iChar = 0;
    int iNumber = 0;
    
    while ( iChar < keepOnlyNumbers.length() )
    {
        //special characters
        if ( keepOnlyNumbers[iChar] == 'e' || keepOnlyNumbers[iChar] == 'E' || keepOnlyNumbers[iChar] == '+' || keepOnlyNumbers[iChar] == '.' )
        {
            iChar++;
            continue;
        }
            
        iNumber = keepOnlyNumbers[iChar] - (char)'0';
        
        if ( iNumber >= 0 && iNumber <= 9 )
            iChar++;
        else
            keepOnlyNumbers.erase(iChar, 1); 
    }

    return keepOnlyNumbers;
}


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
        case 63:
            out = string("vigintillion");
            break;
        case 66:
            out = string("unvigintillion");
            break;
        case 69:
            out = string("duovigintillion");
            break;
        case 72:
            out = string("trevigintillion");
            break;
        case 75:
            out = string("quattuorvigintillion");
            break;
        case 78:
            out = string("quinvigintillion");
            break;
        case 81:
            out = string("sexvigintillion");
            break;    
        case 84:
            out = string("septenvigintillion");
            break;
        case 87:
            out = string("octovigintillion");
            break;
        case 90:
            out = string("novemvigintillion");
            break;
        case 93:
            out = string("trigintillion");
            break;
        case 96:
            out = string("untrigintillion");
            break;
        case 99:
            out = string("duotrigintillion");
            break;
        case 100:
            out = string("googol");
            break;
    }

    /* https://simple.wikipedia.org/wiki/Names_for_large_numbers 
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
    63	Vigintillion	Decilliard	Thousand decillion
    66	Unvigintillion	Undecillion	Undecillion
    69	Duovigintillion	Undecilliard	Thousand undecillion
    72	Trevigintillion	Duodecillion	Duodecillion
    75	Quattuorvigintillion	Duodecilliard	Thousand duodecillion
    78	Quinvigintillion	Tredecillion	Tredecillion
    81	Sexvigintillion	Tredecilliard	Thousand tredecillion
    84	Septenvigintillion	Quattuordecillion	Quattuordecillion
    87	Octovigintillion	Quattuordecilliard	Thousand quattuordecillion
    90	Novemvigintillion	Quindecillion	Quindecillion
    93	Trigintillion	Quindecilliard	Thousand quindecillion
    96	Untrigintillion	Sexdecillion	Sexdecillion
    99	Duotrigintillion	Sexdecilliard	Thousand sexdecillion
    100	Googol	Googol	Googol    
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
    int iDigit = Value.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    bool bNumberInGroup = false;
    
    for( int i = iDigit; i >= 0; i-- )
    {
        cNumber = Value[iDigit - i];
        iNumber = atoi(&cNumber);
        
        if ( (i + 1) % 3 == 0 )
            bNumberInGroup = false;
            
        if ( iNumber > 0 )
            bNumberInGroup = true;

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= iDigit && isTensDigit(i+1) && iPrevNumber == 1 )
            word = getOddTensValues( iNumber );
        else
            word = getOnesString( iNumber, bTens );

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = getUnitsString(i,iNumber);
        
            ConvertedToWords += word;
        
            if ( word.length() != 0 )
                ConvertedToWords += " ";
        }
        
        word = "";
        iPrevNumber = iNumber; 
    }
    
    return ConvertedToWords;/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;
32
    int nPower = 0;
33
    int nAddPower = 0;
34/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;
32
    int nPower = 0;
33
    int nAddPower = 0;
34
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
32
    int nPower = 0;
33
    int nAddPower = 0;
34
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
}

int main()
{
    string sCleaned = string("");
    string sInput = string("");
    cout << "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input): ";
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
        case 63:
            out = string("vigintillion");
            break;
        case 66:
            out = string("unvigintillion");
            break;
        case 69:
            out = string("duovigintillion");
            break;
        case 72:
            out = string("trevigintillion");
            break;
        case 75:
            out = string("quattuorvigintillion");
            break;
        case 78:
            out = string("quinvigintillion");
            break;
        case 81:
            out = string("sexvigintillion");
            break;    
        case 84:
            out = string("septenvigintillion");
            break;
        case 87:
            out = string("octovigintillion");
            break;
        case 90:
            out = string("novemvigintillion");
            break;
        case 93:
            out = string("trigintillion");
            break;
        case 96:
            out = string("untrigintillion");
            break;
        case 99:
            out = string("duotrigintillion");
            break;
        case 100:
            out = string("googol");
            break;
    }

    /* https://simple.wikipedia.org/wiki/Names_for_large_numbers 
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
    63	Vigintillion	Decilliard	Thousand decillion
    66	Unvigintillion	Undecillion	Undecillion
    69	Duovigintillion	Undecilliard	Thousand undecillion
    72	Trevigintillion	Duodecillion	Duodecillion
    75	Quattuorvigintillion	Duodecilliard	Thousand duodecillion
    78	Quinvigintillion	Tredecillion	Tredecillion
    81	Sexvigintillion	Tredecilliard	Thousand tredecillion
    84	Septenvigintillion	Quattuordecillion	Quattuordecillion
    87	Octovigintillion	Quattuordecilliard	Thousand quattuordecillion
    90	Novemvigintillion	Quindecillion	Quindecillion
    93	Trigintillion	Quindecilliard	Thousand quindecillion
    96	Untrigintillion	Sexdecillion	Sexdecillion
    99	Duotrigintillion	Sexdecilliard	Thousand sexdecillion
    100	Googol	Googol	Googol    
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
    int iDigit = Value.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    bool bNumberInGroup = false;
    
    for( int i = iDigit; i >= 0; i-- )
    {
        cNumber = Value[iDigit - i];
        iNumber = atoi(&cNumber);
        
        if ( (i + 1) % 3 == 0 )
            bNumberInGroup = false;
            
        if ( iNumber > 0 )
            bNumberInGroup = true;

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= iDigit && isTensDigit(i+1) && iPrevNumber == 1 )
            word = getOddTensValues( iNumber );
        else
            word = getOnesString( iNumber, bTens );

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = getUnitsString(i,iNumber);
        
            ConvertedToWords += word;
        
            if ( word.length() != 0 )
                ConvertedToWords += " ";
        }
        
        word = "";
        iPrevNumber = iNumber; 
    }
    
    return ConvertedToWords;/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;
32
    int nPower = 0;
33
    int nAddPower = 0;
34/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​
15
bool isInScientificNotation(const string CheckForScientificNotation)
16
{
17
    if( string::npos == CheckForScientificNotation.find("E") || string::npos == CheckForScientificNotation.find("e") )
18
    {
19
        return true;
20
    }
21
    
22
    return false;
23
}
24
​
25
//TODO: Bugcheck extensively
26
string convertFromScientificNotation(const string ScientificNotation)
27
{
28
    string converted = "";
29
    string eNotation = "";
30
    int nDecimalPos = -1;
31
    int nENotationPos = -1;
32
    int nPower = 0;
33
    int nAddPower = 0;
34
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
32
    int nPower = 0;
33
    int nAddPower = 0;
34
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
    
35
    nDecimalPos = ScientificNotation.find(".");
36
​
37
    nENotationPos = ScientificNotation.find("e");
38
    if ( string::npos == nENotationPos)
39
    {
40
        nENotationPos = ScientificNotation.find("e");
41
        if ( string::npos == nENotationPos)
42
            return string("error");
43
    }
44
    
45
    //negative ScientificNotation
}

int main()
{
    string sCleaned = string("");
    string sInput = string("");/******************************************************************************
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

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
    {
        return false;
    }
    
    return true;
}

//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation)
{
    string converted = "";
    string eNotation = "";
    int nDecimalPos = -1;
    int nENotationPos = -1;
    int nPower = 0;
    int nAddPower = 0;
    
    nDecimalPos = ScientificNotation.find(".");

    nENotationPos = ScientificNotation.find("e");
    if ( string::npos == nENotationPos)
    {
        nENotationPos = ScientificNotation.find("e");
        if ( string::npos == nENotationPos)
            return string("error");
    }
    
    //negative ScientificNotation
    if ( ScientificNotation[nENotationPos+1] == '-' )
    {
        return string("0");
    }
    
    if ( ScientificNotation[nENotationPos+1] == '+' )
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+2));
    else
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+1));
    
    converted = ScientificNotation.substr(0,nENotationPos);
    
    //Add in number of digits past places already in the string
    if ( string::npos == nDecimalPos )
        nPower = 0;
    else
        nPower = converted.substr(nDecimalPos+1).length();
    
    for( int iAddPower = nPower; iAddPower < nAddPower; iAddPower++ )
    {
        converted += "0";
    }
    
    if ( string::npos != nDecimalPos)
        converted.erase(nDecimalPos,1);
    
    return converted;
}

//TODO
string convertToScientificNotation(const string Value)
{
    string converted = "";
    return converted;
}

string removeNonNumberCharacters(const string RemoveNonNumbers)
{
    string keepOnlyNumbers = RemoveNonNumbers;
    
    int iChar = 0;
    int iNumber = 0;
    
    while ( iChar < keepOnlyNumbers.length() )
    {
        //special characters
        if ( keepOnlyNumbers[iChar] == 'e' || keepOnlyNumbers[iChar] == 'E' || keepOnlyNumbers[iChar] == '+' || keepOnlyNumbers[iChar] == '.' )
        {
            iChar++;
            continue;
        }
            
        iNumber = keepOnlyNumbers[iChar] - (char)'0';
        
        if ( iNumber >= 0 && iNumber <= 9 )
            iChar++;
        else
            keepOnlyNumbers.erase(iChar, 1); 
    }

    return keepOnlyNumbers;
}


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
        case 63:
            out = string("vigintillion");
            break;
        case 66:
            out = string("unvigintillion");
            break;
        case 69:
            out = string("duovigintillion");
            break;
        case 72:
            out = string("trevigintillion");
            break;
        case 75:
            out = string("quattuorvigintillion");
            break;
        case 78:
            out = string("quinvigintillion");
            break;
        case 81:
            out = string("sexvigintillion");
            break;    
        case 84:
            out = string("septenvigintillion");
            break;
        case 87:
            out = string("octovigintillion");
            break;
        case 90:
            out = string("novemvigintillion");
            break;
        case 93:
            out = string("trigintillion");
            break;
        case 96:
            out = string("untrigintillion");
            break;
        case 99:
            out = string("duotrigintillion");
            break;
        case 100:
            out = string("googol");
            break;
    }

    /* https://simple.wikipedia.org/wiki/Names_for_large_numbers 
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
    63	Vigintillion	Decilliard	Thousand decillion
    66	Unvigintillion	Undecillion	Undecillion
    69	Duovigintillion	Undecilliard	Thousand undecillion
    72	Trevigintillion	Duodecillion	Duodecillion
    75	Quattuorvigintillion	Duodecilliard	Thousand duodecillion
    78	Quinvigintillion	Tredecillion	Tredecillion
    81	Sexvigintillion	Tredecilliard	Thousand tredecillion
    84	Septenvigintillion	Quattuordecillion	Quattuordecillion
    87	Octovigintillion	Quattuordecilliard	Thousand quattuordecillion
    90	Novemvigintillion	Quindecillion	Quindecillion
    93	Trigintillion	Quindecilliard	Thousand quindecillion
    96	Untrigintillion	Sexdecillion	Sexdecillion
    99	Duotrigintillion	Sexdecilliard	Thousand sexdecillion
    100	Googol	Googol	Googol    
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
    int iDigit = Value.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    bool bNumberInGroup = false;
    
    for( int i = iDigit; i >= 0; i-- )
    {
        cNumber = Value[iDigit - i];
        iNumber = atoi(&cNumber);
        
        if ( (i + 1) % 3 == 0 )
            bNumberInGroup = false;
            
        if ( iNumber > 0 )
            bNumberInGroup = true;

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= iDigit && isTensDigit(i+1) && iPrevNumber == 1 )
            word = getOddTensValues( iNumber );
        else
            word = getOnesString( iNumber, bTens );

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = getUnitsString(i,iNumber);
        
            ConvertedToWords += word;
        
            if ( word.length() != 0 )
                ConvertedToWords += " ";
        }
        
        word = "";
        iPrevNumber = iNumber; 
    }
    
    return ConvertedToWords;/******************************************************************************
2
Welcome to GDB Online.
3
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
4
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
5
Code, Compile, Run and Debug online from anywhere in world.
6
*******************************************************************************/
7
#include <stdio.h>
8
#include <string>
9
#include <deque>
10
#include <iostream>
11
#include <stdlib.h>
12
​
13
using namespace std;
14
​/******************************************************************************
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

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
    {
        return false;
    }
    
    return true;
}

//TODO: Bugcheck extensively
string convertFromScientificNotation(const string ScientificNotation)
{
    string converted = "";
    string eNotation = "";
    int nDecimalPos = -1;
    int nENotationPos = -1;
    int nPower = 0;
    int nAddPower = 0;
    
    nDecimalPos = ScientificNotation.find(".");

    nENotationPos = ScientificNotation.find("e");
    if ( string::npos == nENotationPos)
    {
        nENotationPos = ScientificNotation.find("e");
        if ( string::npos == nENotationPos)
            return string("error");
    }
    
    //negative ScientificNotation
    if ( ScientificNotation[nENotationPos+1] == '-' )
    {
        return string("0");
    }
    
    if ( ScientificNotation[nENotationPos+1] == '+' )
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+2));
    else
        nAddPower = stoi(ScientificNotation.substr(nENotationPos+1));
    
    converted = ScientificNotation.substr(0,nENotationPos);
    
    //Add in number of digits past places already in the string
    if ( string::npos == nDecimalPos )
        nPower = 0;
    else
        nPower = converted.substr(nDecimalPos+1).length();
    
    for( int iAddPower = nPower; iAddPower < nAddPower; iAddPower++ )
    {
        converted += "0";
    }
    
    if ( string::npos != nDecimalPos)
        converted.erase(nDecimalPos,1);
    
    return converted;
}

//TODO
string convertToScientificNotation(const string Value)
{
    string converted = "";
    return converted;
}

string removeNonNumberCharacters(const string RemoveNonNumbers)
{
    string keepOnlyNumbers = RemoveNonNumbers;
    
    int iChar = 0;
    int iNumber = 0;
    
    while ( iChar < keepOnlyNumbers.length() )
    {
        //special characters
        if ( keepOnlyNumbers[iChar] == 'e' || keepOnlyNumbers[iChar] == 'E' || keepOnlyNumbers[iChar] == '+' || keepOnlyNumbers[iChar] == '.' )
        {
            iChar++;
            continue;
        }
            
        iNumber = keepOnlyNumbers[iChar] - (char)'0';
        
        if ( iNumber >= 0 && iNumber <= 9 )
            iChar++;
        else
            keepOnlyNumbers.erase(iChar, 1); 
    }

    return keepOnlyNumbers;
}


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
        case 63:
            out = string("vigintillion");
            break;
        case 66:
            out = string("unvigintillion");
            break;
        case 69:
            out = string("duovigintillion");
            break;
        case 72:
            out = string("trevigintillion");
            break;
        case 75:
            out = string("quattuorvigintillion");
            break;
        case 78:
            out = string("quinvigintillion");
            break;
        case 81:
            out = string("sexvigintillion");
            break;    
        case 84:
            out = string("septenvigintillion");
            break;
        case 87:
            out = string("octovigintillion");
            break;
        case 90:
            out = string("novemvigintillion");
            break;
        case 93:
            out = string("trigintillion");
            break;
        case 96:
            out = string("untrigintillion");
            break;
        case 99:
            out = string("duotrigintillion");
            break;
        case 100:
            out = string("googol");
            break;
    }

    /* https://simple.wikipedia.org/wiki/Names_for_large_numbers 
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
    63	Vigintillion	Decilliard	Thousand decillion
    66	Unvigintillion	Undecillion	Undecillion
    69	Duovigintillion	Undecilliard	Thousand undecillion
    72	Trevigintillion	Duodecillion	Duodecillion
    75	Quattuorvigintillion	Duodecilliard	Thousand duodecillion
    78	Quinvigintillion	Tredecillion	Tredecillion
    81	Sexvigintillion	Tredecilliard	Thousand tredecillion
    84	Septenvigintillion	Quattuordecillion	Quattuordecillion
    87	Octovigintillion	Quattuordecilliard	Thousand quattuordecillion
    90	Novemvigintillion	Quindecillion	Quindecillion
    93	Trigintillion	Quindecilliard	Thousand quindecillion
    96	Untrigintillion	Sexdecillion	Sexdecillion
    99	Duotrigintillion	Sexdecilliard	Thousand sexdecillion
    100	Googol	Googol	Googol    
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
    int iDigit = Value.length() - 1;
    
    char cNumber = ' ';
    int iNumber = 0;
    int iPrevNumber = 0;
    string word = "";
    bool bNumberInGroup = false;
    
    for( int i = iDigit; i >= 0; i-- )
    {
        cNumber = Value[iDigit - i];
        iNumber = atoi(&cNumber);
        
        if ( (i + 1) % 3 == 0 )
            bNumberInGroup = false;
            
        if ( iNumber > 0 )
            bNumberInGroup = true;

        bool bTens = isTensDigit(i);
        
        if ( i+1 <= iDigit && isTensDigit(i+1) && iPrevNumber == 1 )
            word = getOddTensValues( iNumber );
        else
            word = getOnesString( iNumber, bTens );

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = getUnitsString(i,iNumber);
        
            ConvertedToWords += word;
        
            if ( word.length() != 0 )
                ConvertedToWords += " ";
        }
        
        word = "";
        iPrevNumber = iNumber; 
    }
    
    return ConvertedToWords;
}

int main()
{
    string sCleaned = string("");
    string sInput = string("");
    cout << "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input): ";
    cout << "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input): ";
    cin >> sInput;
    cout << "I Received: " << sInput << endl;
    sCleaned = removeNonNumberCharacters(sInput);
    
    if( sCleaned.length() != sInput.length() )
    {
        cout << "The Number after removing extraneous characters: " << sCleaned << endl;
        sInput = sCleaned;
    }
    
    if ( isInScientificNotation(sInput) )
    {
        sInput = convertFromScientificNotation(sInput);
    }

    cout << "In Decimal Format: " << sInput << endl;
    cout << "The Number Is Read As: " << endl;
    
    cout << ConvertNumberToWords(sInput);

    return 0;
}
