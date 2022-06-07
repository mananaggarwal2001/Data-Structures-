#include <bits/stdc++.h>
using namespace std;

void postOrderTraversal(int number)
{
    if (number > 2)
    {
        postOrderTraversal(number-1);  // first recursive call
        postOrderTraversal(number-2);  // second recursive call
        postOrderTraversal(number-3);  // third recursive call.
    }
    cout<<number<<endl;
}
int main()
{
    int number;
    cout<<"Enter the number which you want the Post Ordertraversal of the tree:- ";
    cin>>number;
    postOrderTraversal(number);
    return 0;
}