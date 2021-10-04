#include "bits/stdc++.h"

using namespace std;

class PaymentGateWay
{
public:
virtual ~PaymentGateWay() = default;
virtual int makePayment()=0;
};


class PaymentGateWayConcrete
{

public:
int makePayment() 
{
    if(rand()%5==0)
    {
        return -1;
    }
    return 1;
}  
};
