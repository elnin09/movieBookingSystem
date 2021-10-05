#include "bits/stdc++.h"
using namespace std;
#include "runtests.h"

void print(vector<int>vec)
{
    for(int v : vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}

int main()
{
TestCases t1;
t1.runBlockedSeatsTest();    
return 0;
}
