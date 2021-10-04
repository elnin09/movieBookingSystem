#include "bits/stdc++.h"
using namespace std;

enum BookingStatus {RESERVED,FREE,BOOKED};
enum SeatType {TYPE_A,TYPE_B,TYPE_C};

class seat
{
    SeatType type;
    BookingStatus status;
};

class DataModelAbstract
{
  public:
  virtual void getAvailableSeats(string date, string moviename, int screen)=0;
  virtual void updateAvailableSeats(string date, string moviename, int screen,vector<seat> seats)=0;
  virtual void insertShow(string date,string moviename,int screen,vector<seat> seats); //admin APIS
  virtual void removeShow(string date,string moviename,int screen,vector<seat> seats); //admin APIS
};

class DataModel : public DataModelAbstract
{

map<string,vector<seat> > dataMap;   
void getAvailableSeats(string date, string moviename, int screen)
{
    cout<<"concrete implemenation";
}
void updateAvailableSeats(string date, string moviename, int screen,vector<seat> seats)
{
    cout<<"abstract implementation";
}
};