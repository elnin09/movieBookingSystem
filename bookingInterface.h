#include "bits/stdc++.h"
using namespace std;
#include "datamodel.h"
#include "ticket.h"
#include <ctime>
#include "payment.h"



class MovieBookingInterface 
{
    public:
    virtual ~MovieBookingInterface() = default;
    virtual void initSession(int userID)=0;
    virtual vector<int> getFreeSeats(int userID, string date, string moviename, int screen) = 0;
    virtual int reserveFreeSeats(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual Ticket makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers) = 0;
    virtual void exitSession(int userID)=0;
};

class MovieBookingConcrete : public MovieBookingInterface
{
    PaymentGateWayConcrete payment;
    DataModel model;
    map<int,int> sessions;     // a map of session and the timestamp when they were last active;
    map<int,pair<string,vector<int> > > seatsData;  // seats a particular user has booked
public:
    MovieBookingConcrete()
    {
    }
    void initSession(int userID)
    {
        sessions[userID]=time(0);
    }
    vector<int> getFreeSeats(int userID, string date, string moviename, int screen)
    {
        string key = date+","+moviename+","+ to_string(screen);
        return model.getAvailableSeats(key);
    }
    int reserveFreeSeats(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    {
        string key = date+","+moviename+","+ to_string(screen);
        if(seatNumbers.size()>5)
        {
            return -1;
        }
        model.reserveSeats(key,seatNumbers);
        seatsData[userID] = make_pair(key,seatNumbers);
        return 1;
    }

    Ticket makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers)
    { 

    }
    void exitSession(int userID)
    {
        model.freeSeats(seatsData[userID].first,seatsData[userID].second);
        seatsData.erase(userID);
        sessions.erase(userID);
    }
};

/*
Init it first thing in the morning github account

*/