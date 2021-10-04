#include "bits/stdc++.h"
using namespace std;
#include "bookingInterface.h"

int main()
{
MovieBookingConcrete *bookingObject =  new MovieBookingConcrete();
bookingObject->initSession(1);
return 0;
}