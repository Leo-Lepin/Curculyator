#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sch(bool &mulpl, bool &divi, bool &minu, double& c, double& tmp, 
         vector <double> &numbers) {
    if (mulpl) 
    {
        numbers.push_back(c * tmp);// Умножение
        mulpl = 0;
        tmp = 0;
    }
    else if (minu) 
    {
        numbers.push_back(-c);// Минус
        minu = 0;
        tmp = 0;
    }
    else if (divi && c) 
    {
        numbers.push_back(tmp / c);// Деление
        divi = 0;
        tmp = 0;
    }
    else 
    {
        numbers.push_back(c);// +
    }
    c = 0;
    return 0;
}

double body(string str)
{
    vector <double> numbers;
    double c = 0, tmp = 0;
    double sum = 0;
    bool isinp = 0, mulpl = 0, divi = 0, minu = 0;
    for (int j = 0; j < str.size(); j++)
    {
      char i = str[j];
        if (48 <= i && i <= 57) 
        {
            c = c * 10 + int(i) - 48;
            isinp = 1;
        }

        else if (isinp) 
        {
            isinp = sch(mulpl, divi, minu, c, tmp, numbers);
        }
      
        if ('/' == i)
        {
            tmp = numbers.back();
            numbers.pop_back();
            divi = 1;
        }
        else if ('*' == i)
        {
            tmp = numbers.back();
            numbers.pop_back();
            mulpl = 1;
        }
        else if ('-' == i)
        {

            minu = 1;
        }
        else if ('(' == i)
        {
            string buf = "";
            int open = 1;
            j++;
            for(; j < str.size(); j++)
            {
                if ('('  == str[j])
                {
                    ++open;
                }
                else if (')' == str[j])
                {
                    --open;
                }
                if (open == 0)
                {
                    break;
                }
                buf.push_back(str[j]);
            }
            // cout << str[j] << endl;
            double s1 = body(buf);
            isinp = sch(mulpl,divi, minu, s1, tmp, numbers);
        } 
    }
    if (isinp) {
        isinp = sch(mulpl,divi, minu, c, tmp, numbers);
    }
    for (auto i : numbers) 
    {
        // cout << '\t' << i << endl;
        sum += i;
    }
    return sum;
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    string str = "";
    bool issk = 0;
    getline(cin, str);
    cout << body(str);
    
}
