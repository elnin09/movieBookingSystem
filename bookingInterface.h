#include "bits/stdc++.h"
using namespace std;
#include "datamodel.h"
#include "ticket.h"
#include <ctime>



class MovieBookingInterface 
{
    public:
    virtual ~MovieBookingInterface() = default;
    virtual void initSession(int userID)=0;
    virtual void getFreeSeats(int userID, string date, string moviename, int screen) = 0;
    virtual int book(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual Ticket makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual void exitSession(int userID)=0;
};

class MovieBookingConcrete : public MovieBookingInterface
{
    DataModel model;
    map<int,int> sessions;     // a map of session and the timestamp when they were last active;
    map<int,pair<string,vector<int> > > seatsData;  // seats a particular user has booked
public:
    void initSession(int userID)
    {
        sessions[userID]=time(0);
    }
    void getFreeSeats(int userID, string date, string moviename, int screen)
    {
        model.getAvailableSeats(date,moviename,screen);
    }
    int book(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    {
        if(seatNumbers.size()>5)
        {
            return -1;
        }
        model.reserveSeats(date,moviename,screen,seatNumbers);
        seatsData[userID] = make_pair()
    }

    Ticket makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    {
        
    }
    void exitSession(int userID)
    {
        sessions.erase(userID);
    }
};

/*
Init it first thing in the morning github account

*/