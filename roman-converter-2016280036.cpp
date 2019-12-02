
//2016280036 Safak Mert Yildiz 

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

struct RomanNumber
{
public:
  string get ()
  {
    return romanNumber;
  }

  void show ()
  {
    cout << "Roman Number is " << romanNumber << endl;
  }

  RomanNumber (const string & input)
  {
    romanNumber = input;
  }

  int convert ()
  {
    int length = romanNumber.length ();
    int previous = 0;
    bool error = false;
    int nIndex = 0;

    sum = 0;

    while ((error == false) && (nIndex < length))
      {
	switch (romanNumber[nIndex])
	  {
	  case 'M':
	    sum += 1000;
	    if (previous < 1000)
	      {
		sum -= 2 * previous;
	      }
	    previous = 1000;
	    break;
	  case 'D':
	    sum += 500;
	    if (previous < 500)
	      {
		sum -= 2 * previous;
	      }
	    previous = 500;
	    break;
	  case 'C':
	    sum += 100;
	    if (previous < 100)
	      {
		sum -= 2 * previous;
	      }
	    previous = 100;
	    break;
	  case 'L':
	    sum += 50;
	    if (previous < 50)
	      {
		sum -= 2 * previous;
	      }
	    previous = 50;
	    break;
	  case 'X':
	    sum += 10;
	    if (previous < 10)
	      {
		sum -= 2 * previous;
	      }
	    previous = 10;
	    break;
	  case 'V':
	    sum += 5;
	    if (previous < 5)
	      {
		sum -= 2 * previous;
	      }
	    previous = 5;
	    break;
	  case 'I':
	    sum += 1;
	    if (previous < 1)
	      {
		sum -= 2 * previous;
	      }
	    previous = 1;
	    break;
	  default:
	    cout << romanNumber[nIndex] << " Bir roma rakami degil!" << endl;
	    error = true;
	    sum = 0;
	  }

	nIndex++;

      }
    return sum;
  }

  int length ()
  {
    return romanNumber.length ();
  }

private:
  string romanNumber;
  int sum;
};

string
intToRoman (int num)
{

  string m[] = { "", "M", "MM", "MMM" };
  string c[] = { "", "C", "CC", "CCC", "CD", "D",
    "DC", "DCC", "DCCC", "CM"
  };
  string x[] = { "", "X", "XX", "XXX", "XL", "L",
    "LX", "LXX", "LXXX", "XC"
  };
  string i[] = { "", "I", "II", "III", "IV", "V",
    "VI", "VII", "VIII", "IX"
  };

  string thousands = m[num / 1000];
  string hundereds = c[(num % 1000) / 100];
  string tens = x[(num % 100) / 10];
  string ones = i[num % 10];

  string ans = thousands + hundereds + tens + ones;

  return ans;
}



int
main ()
{
  int number;
  cout << "Lutfen cevirmek istediginiz ondalik sayiyi giriniz: ";
  std::cin >> number;
  cout << "Roman rakami hali: " << intToRoman (number) << endl;

  string myInput;
  int value;
  cout << "Lutfen cevirmek istediginiz Roma rakamini giriniz: ";
  cin >> myInput;
  RomanNumber myRomanNumber (myInput);
  value = myRomanNumber.convert ();

  cout << myInput << " esittir: " << value << endl;
}

/* Kaynakca:
1. http://www.cplusplus.com/forum/beginner/53308/
2. https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
3. https://www.dijitalders.com/icerik/77/2818/c_scanf_ve_prinf_kullanimi.html
4. https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
5. https://www.browserling.com/tools/decimal-to-roman
6. https://www.onlinegdb.com/online_c++_compiler
*/
