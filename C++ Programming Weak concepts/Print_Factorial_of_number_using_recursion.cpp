#include <stdio.h>
#include <stdlib.h>
using namespace std;

int factorialNotation(int number)
{
    if (number == 1)
    {
        return 1;
    }
    else
    {
        return (number * factorialNotation(number-1));
    }
}

int main()
{
    int result;
    printf("The result of the factorial number is %d ", factorialNotation(5));
}