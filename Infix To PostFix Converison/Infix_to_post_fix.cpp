#include <bits/stdc++.h>
using namespace std;
stack<char> infixStack;

int Precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infix_to_postfix()
{
    string Expression;
    string Postfix_String;
    char StoredChar;
    char Stored_char2;
    cout << "Enter the Expression: ";
    cin >> Expression;
    for (int i = 0; i < Expression.size(); i++)
    {
        if (isoperator(Expression[i]))
        {
            if (infixStack.empty())
            {
                infixStack.push(Expression[i]);
            }
            else if (Precedence(Expression[i]) > Precedence(infixStack.top()))
            {
                infixStack.push(Expression[i]);
            }
            else
            {
                while (true)
                {
                    if ((Precedence(Expression[i]) < Precedence(infixStack.top())) || (Precedence(Expression[i]) == Precedence(infixStack.top())))
                    {
                        StoredChar = infixStack.top();
                        Postfix_String.push_back(StoredChar);
                        infixStack.pop();
                        if(infixStack.empty()){
                            break;
                        }
                        continue;
                    }
                    break;
                }

                infixStack.push(Expression[i]);
            }
        }
        else
        {
            StoredChar = Expression[i];
            Postfix_String.push_back(StoredChar);
        }
    }

    while (!infixStack.empty())
    {
        Stored_char2 = infixStack.top();
        Postfix_String.push_back(Stored_char2);
        infixStack.pop();
    }

    return Postfix_String;
}

int main()
{
    string final_String = infix_to_postfix();

    cout << "The postfix Expression is: " << final_String;

    return 0;
}