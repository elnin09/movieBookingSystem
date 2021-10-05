#include "bits/stdc++.h"
using namespace std;
#include "bookingInterface.h"


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
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1,100);
bookingObject->initSession(2,100);
bookingObject->initSession(3,100);
vector<int> freeSeats1 = bookingObject->getFreeSeats(1,"Date1","Movie1",1,105);
vector<int> temp = {0,1,2};
bookingObject->reserveFreeSeats(1,"Date1","Movie1",1,temp,110);
cout<<"CHECKPOINT 1"<<endl;
vector<int> freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,114);
cout<<"CHECKPOINT 2"<<endl;
vector<int> freeSeats3 = bookingObject->getFreeSeats(3,"Date1","Movie1",1,116);
cout<<"CHECKPOINT 2"<<endl;

print(freeSeats1);
print(freeSeats2);
print(freeSeats3);

return 0;
}
