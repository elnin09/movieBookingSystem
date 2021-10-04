#include "bits/stdc++.h"
using namespace std;

enum BookingStatus {RESERVED,FREE,BOOKED};
enum SeatType {TYPE_A,TYPE_B,TYPE_C};

class seat
{
    public:
    SeatType type;
    BookingStatus status;
    
    public:
    seat(int arg)
    {
        if(arg==1)
        type = TYPE_A;
        else if(arg==2)
        type = TYPE_B;
        else if(arg==3)
        type = TYPE_C;

        status = FREE;
    }
};

class DataModelAbstract
{
  public:
  virtual vector<int> getAvailableSeats(string key)=0;
  virtual void reserveSeats(string key,vector<int> seats)=0;
  virtual void bookSeats(string key,vector<int> seats)=0;
  virtual void freeSeats(string key,vector<int>seats)=0;
  virtual void insertShow(string key,vector<seat> seats)=0; //admin APIS
  virtual void removeShow(string key)=0; //admin APIS
};

class DataModel : public DataModelAbstract
{

map<string,vector<seat> > dataMap;
public:   
vector<int> getAvailableSeats(string key)
{
    vector<seat> seats = dataMap[key];
    vector<int> freeseats;
    for(int i=0;i<seats.size();i++)
    {
        if(seats[i].status == FREE)
        {
            freeseats.push_back(i);
        }
    }
    return freeseats;
}
void reserveSeats(string key,vector<int> seats)
{
    vector<seat> allSeats = dataMap[key];
    for(int i=0;i<seats.size();i++)
    {
        allSeats[seats[i]].status = RESERVED;
    }
}
void bookSeats(string key,vector<int> seats)
{
    vector<seat> allSeats = dataMap[key];
    for(int i=0;i<seats.size();i++)
    {
        allSeats[seats[i]].status = BOOKED;
    }
}

void freeSeats(string key,vector<int> seats)
{
    vector<seat> allSeats = dataMap[key];
    for(int i=0;i<seats.size();i++)
    {
        allSeats[seats[i]].status = FREE;
    }
}
void insertShow(string key,vector<seat> seats)
{
    dataMap[key] = seats;
}
void removeShow(string key)
{
    dataMap.erase(key);
}
};
