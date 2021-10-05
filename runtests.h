#include "bits/stdc++.h"
using namespace std;
#include "bookingInterface.h"


class TestCases
{

public:
void runBlockedSeatsTest();
void runSessionEndTest();
void runBookedSeatsTest();
void reserveSeatRaceCondition();
void print(vector<int>vec);
};

void TestCases::print(vector<int>vec)
{
    for(int v : vec)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}

void TestCases::runBlockedSeatsTest()
{
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1,100);
bookingObject->initSession(2,100);

cout<<"----------------------------------------"<<endl;
cout<<"TESTCASE BLOCKED SEATS TEST"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"FREE SEATS CALLED BY USER 1 at timestamp 105"<<endl;
vector<int> freeSeats1 = bookingObject->getFreeSeats(1,"Date1","Movie1",1,105);
print(freeSeats1);
vector<int> temp = {0,1,2};

cout<<"RESERVE SEATS CALLED BY USER 1 at timestamp 110"<<endl;
bookingObject->reserveFreeSeats(1,"Date1","Movie1",1,temp,110);
cout<<"FREE SEATS CALLED BY USER 2 at timestamp 114"<<endl;
vector<int> freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,114);
print(freeSeats2);
/*
bookingObject->makePayment(1,"Date1","Movie1",1,temp,11);
cout<<"CHECKPOINT 1"<<endl;
*/

/*
cout<<"CHECKPOINT 2"<<endl;
vector<int> freeSeats3 = bookingObject->getFreeSeats(3,"Date1","Movie1",1,117);
cout<<"CHECKPOINT 2"<<endl;
*/

}

void TestCases::runSessionEndTest()
{
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1,100);
bookingObject->initSession(2,100);

cout<<"----------------------------------------"<<endl;
cout<<"TESTCASE SESSION END TEST"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"FREE SEATS CALLED BY USER 1 at timestamp 105"<<endl;
vector<int> freeSeats1 = bookingObject->getFreeSeats(1,"Date1","Movie1",1,105);
print(freeSeats1);
vector<int> temp = {0,1,2};

cout<<"RESERVE SEATS CALLED BY USER 1 at timestamp 110"<<endl;
bookingObject->reserveFreeSeats(1,"Date1","Movie1",1,temp,110);
cout<<"FREE SEATS CALLED BY USER 2 at timestamp 114"<<endl;
vector<int> freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,114);
print(freeSeats2);
cout<<"FREE SEATS CALLED BY USER 2 at timestamp 117"<<endl;
freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,117);
print(freeSeats2);

}


void TestCases::runBookedSeatsTest()
{
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1,100);
bookingObject->initSession(2,100);

cout<<"----------------------------------------"<<endl;
cout<<"TESTCASE SEATS BOOKED TEST"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"FREE SEATS CALLED BY USER 1 at timestamp 105"<<endl;
vector<int> freeSeats1 = bookingObject->getFreeSeats(1,"Date1","Movie1",1,105);
print(freeSeats1);
vector<int> temp = {0,1,2};

cout<<"RESERVE SEATS CALLED BY USER 1 at timestamp 110"<<endl;
bookingObject->reserveFreeSeats(1,"Date1","Movie1",1,temp,110);
cout<<"FREE SEATS CALLED BY USER 2 at timestamp 114"<<endl;
vector<int> freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,114);
print(freeSeats2);


bookingObject->makePayment(1,"Date1","Movie1",1,temp,115);
cout<<"MakePayment  CALLED BY USER 1 at timestamp 115"<<endl;

cout<<"FREE SEATS CALLED BY USER 2 at timestamp 117"<<endl;
freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,117);
print(freeSeats2);
}


void TestCases::reserveSeatRaceCondition()
{
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1,100);
bookingObject->initSession(2,100);

cout<<"----------------------------------------"<<endl;
cout<<"RESERVE SEATS RACE TEST"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"FREE SEATS CALLED BY USER 1 at timestamp 105"<<endl;
vector<int> freeSeats1 = bookingObject->getFreeSeats(1,"Date1","Movie1",1,105);
print(freeSeats1);
vector<int> temp = {0,1,2};


cout<<"FREE SEATS CALLED BY USER 2 at timestamp 105"<<endl;
vector<int> freeSeats2 = bookingObject->getFreeSeats(2,"Date1","Movie1",1,105);
print(freeSeats2);

std::thread t1(&MovieBookingConcrete::reserveFreeSeats,bookingObject,1,"Date1","Movie1",1,temp,110);
std::thread t2(&MovieBookingConcrete::reserveFreeSeats,bookingObject,2,"Date1","Movie1",1,temp,110);
t1.join();
t2.join();


map<int, pair<string, vector<int> > > seatData = bookingObject->getSeatsSessionData();

for(auto it : seatData)
{
    cout<<"Data for user "<<it.first<<endl;
    print(it.second.second);
}

}



