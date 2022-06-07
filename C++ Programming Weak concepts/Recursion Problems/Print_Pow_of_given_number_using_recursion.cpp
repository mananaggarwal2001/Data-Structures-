#include <bits/stdc++.h>
using namespace std;
int powerCalculation(int base, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else
    {
        return (base * powerCalculation(base, power-1));
    }
}

int main()
{
    int base,power,result;
    cout<<"Enter the base:- ";
    cin>>base;
    cout<<"Enter the power:- ";
    cin>>power;
    cout<<endl;
    result= powerCalculation(base,power);
    cout<<"The value of the given base "<<base<<" is:- "<<result;

    return 0;
}