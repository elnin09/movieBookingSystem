#include "bits/stdc++.h"

using namespace std;

class PaymentGateWay
{
public:
virtual ~PaymentGateWay() = default;
virtual int makePayment(int tries)=0;
};


class PaymentGateWayConcrete
{

public:
int makePayment(int tries) 
{
    if(rand()%5==0)
    {
        if(tries==1)
        {
            return -1;
        }   
        return makePayment(1);
    }
    return 1;
}  
};
