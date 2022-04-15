# ConvertNumberToWords
Conversion of Numbers to written words (e.g. 1 to one, 2 to two, 12 to twelve) with digit group names (e.g. thousand, million)

To sample the running code (Read All Steps Before Continuing... Eventually This Will Become A Website for Ease):
1. Click on Either Link: [https://onlinegdb.com/tpKORiFmM](https://onlinegdb.com/tpKORiFmM) or [https://onlinegdb.com/5e_89S5Zw](https://onlinegdb.com/5e_89S5Zw)
2. Click on "Run" button at top center-ish
3. Enter your desired value at bottom (where you see: "Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input):")
4. Type "quit" to end the program

OR you can copy and paste the cpp file in to any online c++ editor / debugger (but I use OnlineGDB.com and set to C++ 20 in upper right corner)

Currently the highest value is limited to googol (1e100)

A Couple of examples follow (one using computer scientific shorthand notation: 7.5e18 the next is a copy and pasted value: 564065406540654684168879896049044004964864165190, the last one showing the power to cleanup garbled input: "9sdflkjxcv.77430lkjsdfoijvoisjdfe10")

e.g.  
Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input) [type "quit" to end]: 7.5e18</br>
I Received: 7.5e18</br>
In Decimal Format: 7500000000000000000</br>
The Number Is Read As:</br>
seven quintillion five hundred quadrillion 

e.g.  
Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input) [type "quit" to end]: 564065406540654684168879896049044004964864165190</br>
I Received: 564065406540654684168879896049044004964864165190</br>
In Decimal Format: 564065406540654684168879896049044004964864165190</br>
The Number Is Read As:</br>
five hundred sixty four quattuordecillion sixty five tredecillion four hundred six duodecillion five hundred fourty undecillion six hundred fifty four decillion six hundred eighty four nonillion one hundred sixty eight octillion eight hundred seventy nine septillion eight hundred ninety six sextillion fourty nine quintillion fourty four quadrillion four trillion nine hundred sixty four billion eight hundred sixty four million one hundred sixty five thousand one hundred ninety 

e.g.  
Input a number to convert to it's word value (use 117000 or 1.17e+5 or 1.17e5 for input) [type "quit" to end]: 9sdflkjxcv.77430lkjsdfoijvoisjdfe10</br>
I Received: 9sdflkjxcv.77430lkjsdfoijvoisjdfe10</br>
The Number after removing extraneous characters: 9.77430e10</br>
In Decimal Format: 97743000000</br>
The Number Is Read As:</br>
ninety seven billion seven hundred fourty three million

