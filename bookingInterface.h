#include "bits/stdc++.h"
using namespace std;
#include "datamodel.h"

class MovieBookingInterface 
{
    public:
    virtual ~MovieBookingInterface() = default;
    virtual void initSession(int userID)=0;
    virtual void getFreeSeats(int userID, string date, string moviename, int screen) = 0;
    virtual void book(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual void makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual void exitSession(int userID)=0;
};

class MovieBookingConcrete : public MovieBookingInterface
{
    DataModel model;
    map<int,int> sessions;     // a map of session and the timestamp when they were last active;
public:
    void initSession(int userID)
    {
        cout << "concrete initSession" << endl;
    }
    void getFreeSeats(int userID, string date, string moviename, int screen)
    {
        cout << "concrete getFreeSeats" << endl;
    }
    void book(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    {
        cout << "concrete book" << endl;
    }
    void makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    {
        cout << "concrete makePayment" << endl;
    }
    void exitSession(int userID)
    {
        cout << "concrete exitSession" << endl;
    }
};

/*
Init it first thing in the morning github account

*/