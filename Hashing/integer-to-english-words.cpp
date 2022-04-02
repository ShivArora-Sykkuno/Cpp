#include <bits/stdc++.h>
using namespace std;

string chunk(int num, vector<string> num1to9, vector<string> num11to19, vector<string> num10s, vector<string> denominations)
{
    int ones = num % 10;
    num /= 10;
    int tens = num % 10;
    num /= 10;
    int hundreds = num % 10;
    num /= 10;
    string res = "";

    if (hundreds != 0)
    {
        res += num1to9[hundreds - 1] + ' ' + "Hundred ";
    }

    if (tens != 0)
    {
        if (tens == 1 && ones != 0)
        {
            res += num11to19[ones - 1];
            return res;
        }
        res += num10s[tens - 1];
        if (ones == 0)
        {
            return res;
        }
        res += ' ';
    }

    if (ones != 0)
    {

        res += num1to9[ones - 1];
    }
    return res;
}

string numberToWords(int num)
{
    vector<string> num1to9;
    vector<string> num11to19;
    vector<string> num10s;
    vector<string> denominations;

    if (num == 0)
    {
        return "Zero";
    }
    num1to9 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    num11to19 = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    num10s = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    denominations = {"", "Thousand", "Million", "Billion"};
    vector<string> res;
    int j = 0;
    string ret = "";

    while (num > 0)
    {

        string temp = chunk(num % 1000, num1to9, num11to19, num10s, denominations);
        if (temp.back() == ' ')
        {
            temp.pop_back();
        }
        if (temp.size() != 0)
        {
            temp = temp + ' ' + denominations[j];
            res.push_back(temp);
        }
        num /= 1000;
        j++;
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        ret += res[i] + ' ';
    }
    while (ret.back() == ' ')
    {
        ret.pop_back();
    }
    return ret;
}