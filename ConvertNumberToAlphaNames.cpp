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
#include <map>
using namespace std;

string removeNonNumberCharacters(const string RemoveNonNumbers);
bool isInScientificNotation(const string CheckForScientificNotation);
string convertFromScientificNotation(const string ScientificNotation);
string convertToScientificNotation(const string Value);
bool isTensDigit(int DigitsPlace);
string ConvertNumberToWords(string Value);

class CGetNumber
{
    private:
/* https://simple.wikipedia.org/wiki/Names_for_large_numbers 
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
    102 Tretrigintillion 	Septendecillion 	Septendecillion
    105 Quattuortrigintillion 	Septendecilliard 	Thousand septedecillion
    108 Quintrigintillion 	Octodecillion 	Octodecillion
    111 Sextrigintillion 	Octodecilliard 	Thousand octodecillion
    114 Septentrigintillion 	Novemdecillion 	Novemdecillion
    117 Octotrigintillion 	Novemdecilliard 	Thousand novemdecillion
    120 Novemtrigintillion 	Vigintillion 	Vigintillion     
    //https://en.wikipedia.org/wiki/Names_of_large_numbers
    123	Quadragintillion	Thousand vigintillion	Vigintilliard
*/    
    //map<10^x,name>
    static map<int,string> m_NumberGroups;
    static map<int, tuple<string,string,string>> m_DigitNames;
    
    public:
    
    CGetNumber(){}
    
    static string getUnitsString(int Place, int Value)
    {
        string unit = "";
    
        if ( (Place + 1) % 3 == 0 )
        {
            unit = (Value == 0 ? "" : string("hundred"));
        }
        else
        {
            unit = m_NumberGroups[Place];
        }
    
        return unit;
    }

    static string getOnesValue(int Value)
    {
        return get<0>(m_DigitNames[Value]);
    }
    
    static string getTeensValue(int Value)
    {
        return get<1>(m_DigitNames[Value]);   
    }
    
    static string getTensValue(int Value)
    {
        return get<2>(m_DigitNames[Value]);
    }
};

map<int,string> CGetNumber::m_NumberGroups
{
    {3  , "thousand"},
    {6  , "million"},
    {9  , "billion"},
    {12 , "trillion"},
    {15 , "quadrillion"},
    {18 , "quintillion"},
    {21 , "sextillion"},
    {24 , "septillion"},
    {27 , "octillion"},
    {30 , "nonillion"},
    {33 , "decillion"},
    {36 , "undecillion"},
    {39 , "duodecillion"},
    {42 , "tredecillion"},
    {45 , "quattuordecillion"},
    {48 , "quindecillion"},
    {51 , "sexdecillion"},
    {54 , "septendecillion"},
    {57 , "octodecillion"},
    {60 , "novemdecillion"},
    {63 , "vigintillion"},
    {66 , "unvigintillion"},
    {69 , "duovigintillion"},
    {72 , "trevigintillion"},
    {75 , "quattuorvigintillion"},
    {78 , "quinvigintillion"},
    {81 , "sexvigintillion"},
    {84 , "septenvigintillion"},
    {87 , "octovigintillion"},
    {90 , "novemvigintillion"},
    {93 , "trigintillion"},
    {96 , "untrigintillion"},
    {99 , "duotrigintillion"},
    {100, "googol"},
    {102, "tretrigintillion"},
    {105, "quattuortrigintillio"},
    {108, "quintrigintillion"},
    {111, "sextrigintillion"},
    {114, "septentrigintillion"},
    {117, "octotrigintillion"},
    {120, "novemtrigintillion"},
    {123, "quadragintillion"}
};

map<int, tuple<string,string,string>> CGetNumber::m_DigitNames
{
    {0, make_tuple("",     "ten",      "")},
    {1, make_tuple("one",  "eleven",   "")},
    {2, make_tuple("two",  "twelve",   "twenty")},
    {3, make_tuple("three","thirteen", "thirty")},
    {4, make_tuple("four", "fourteen", "fourty")},
    {5, make_tuple("five", "fifteen",  "fifty")},
    {6, make_tuple("six",  "sixteen",  "sixty")},
    {7, make_tuple("seven","seventeen","seventy")},
    {8, make_tuple("eight","eighteen", "eighty")},
    {9, make_tuple("nine", "nineteen", "ninety")},    
};

CGetNumber g_GetNumber;

bool isInScientificNotation(const string CheckForScientificNotation)
{
    if( string::npos == CheckForScientificNotation.find("E") && string::npos == CheckForScientificNotation.find("e") )
        return false;

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

//TODO: Bugcheck extensively
string convertToScientificNotation(const string Value)
{
    string converted = "";
    int iDigits = 0;
    
    if ( isInScientificNotation(Value) )
        return Value; //already in target Format
       
    //make sure to cleanup
    converted = removeNonNumberCharacters(Value);
    
    iDigits = converted.length();
    converted.insert(1,".");
    
    while ( converted[converted.length()-1] == '0' )
        converted.erase(converted.length()-1);
    
    converted += "e" + to_string(iDigits-1);
    
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
        {
            word = g_GetNumber.getTeensValue( iNumber );
        }
        else
        {
            if ( bTens )
                word = g_GetNumber.getTensValue( iNumber );
            else
                word = g_GetNumber.getOnesValue( iNumber );
        }

        ConvertedToWords += word;
        
        if ( word.length() != 0 )
            ConvertedToWords += " ";

        if ( bNumberInGroup )
        {
            word = g_GetNumber.getUnitsString(i,iNumber);
        
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

    cout << "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input) [type \"quit\" to end]: ";
    cin >> sInput;
    
    while ( sInput != "quit" )
    {
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
        else
        {
            cout << "In Computer Scientific Notation: " << convertToScientificNotation(sInput) << endl;
        }
    
        cout << "In Decimal Format: " << sInput << endl;
        cout << "The Number Is Read As: " << endl;
        
        cout << ConvertNumberToWords(sInput) << endl;
        
        cout << "------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input): ";
        cin >> sInput;
    }

    return 0;
}
