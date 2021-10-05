#include "bits/stdc++.h"
using namespace std;
#include "datamodel.h"
#include "ticket.h"
#include <ctime>
#include "payment.h"
#define threshhold 5

class MovieBookingInterface
{
public:
    virtual ~MovieBookingInterface() = default;
    virtual void initSession(int userID,int timestamp) = 0;
    virtual vector<int> getFreeSeats(int userID, string date, string moviename, int screen,int timestamp) = 0;
    virtual int reserveFreeSeats(int userID, string date, string moviename, int screen, vector<int> seatNumbers,int timestamp) = 0;
    virtual TicketData makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers,int timestamp) = 0;
    virtual void exitSession(int userID,int timestamp) = 0;
    virtual map<int, pair<string, vector<int> > > getSeatsSessionData()=0;
};

class MovieBookingConcrete : public MovieBookingInterface
{
    PaymentGateWayConcrete payment;
    DataModel model;
    map<int, int> sessions;                          // a map of session and the timestamp when they were last active;
    map<int, pair<string, vector<int> > > seatsData; // seats a particular user has booked
public:
    MovieBookingConcrete()
    {
        vector<seat> seats = vector<seat>(10,seat(1));
        model.insertShow("Date1,Movie1,1",seats);
        model.insertShow("Date1,Movie1,2",seats);
        model.insertShow("Date2,Movie1,1",seats);
        model.insertShow("Date2,Movie2,2",seats);
    }
    void initSession(int userID,int timestamp)
    {
        sessions[userID] = timestamp;
    }
    vector<int> getFreeSeats(int userID, string date, string moviename, int screen,int timestamp)
    {
        initSession(userID,timestamp);
        updateTimeStamp(timestamp);
        string key = date + "," + moviename + "," + to_string(screen);
        return model.getAvailableSeats(key);
    }
    int reserveFreeSeats(int userID, string date, string moviename, int screen, vector<int> seatNumbers,int timestamp)
    {
        sessions[userID] = timestamp;
        updateTimeStamp(timestamp);
        string key = date + "," + moviename + "," + to_string(screen);
        if (seatNumbers.size() > 5)
        {
            return -1;
        }
        int retval = model.reserveSeats(key, seatNumbers);
        if(retval==1)seatsData[userID] = make_pair(key, seatNumbers);
        return retval;
    }

    TicketData makePayment(int userID, string date, string moviename, int screen, vector<int> seatNumbers,int timestamp)
    {
        sessions[userID] = timestamp;
        updateTimeStamp(timestamp);
        TicketData movieTicket;
        string key = date + "," + moviename + "," + to_string(screen);
        if (payment.makePayment(5) != -1)
        {
            model.bookSeats(key, seatNumbers);
            if(seatsData.find(userID)!=seatsData.end())seatsData.erase(userID);
            movieTicket.errorCode = 1;
            movieTicket.ticketID = rand();
        }
        else
        {
            movieTicket.errorCode = -1;
            exitSession(userID,timestamp);
        }
        return movieTicket;
    }

    void exitSession(int userID,int timestamp)
    {
        if(seatsData.find(userID)!=seatsData.end())model.freeSeats(seatsData[userID].first, seatsData[userID].second);
        if(seatsData.find(userID)!=seatsData.end())seatsData.erase(userID);
        if(sessions.find(userID)!=sessions.end())sessions.erase(userID);
    }

    void updateTimeStamp(int currentTimeStamp)
    {
        if(sessions.size()==0) return;
        vector<int> sessionsToBeRemoved;
        for(auto it : sessions)
        {
            if(it.second+threshhold<currentTimeStamp)
            {
                sessionsToBeRemoved.push_back(it.first);
            }
        }
        for(auto id : sessionsToBeRemoved)
        {
            exitSession(id,currentTimeStamp);
        }
    }

    map<int, pair<string, vector<int> > > getSeatsSessionData()
    {
      return this->seatsData;
    }
};

 
