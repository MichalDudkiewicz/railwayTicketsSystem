#include <iostream>
#include "Booking.h"
#include "Customer.h"
#include "Train.h"

using namespace std;

int main()
{
    trainPtr t = make_shared<Train>("ciapong", 100);
    customerPtr c = make_shared<Customer>("Adam","Saddam");
    Booking b(c,t,2,1);
    cout<<b.info();
    return 0;
}