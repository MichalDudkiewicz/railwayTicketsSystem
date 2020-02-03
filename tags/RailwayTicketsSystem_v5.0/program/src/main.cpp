#include <iostream>
#include "CustomerManager.h"
#include "TrainManager.h"
#include "BookingManager.h"
#include "Train.h"
#include "Customer.h"
#include "Booking.h"
#include "FileStream.h"

using namespace std;

int main(){
    try {
        input::customerRepository("../../../customerRepository.csv");
        input::trainRepository("../../../trainRepository.csv");

        bookingPtr b1 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[0],TrainManager::getInstance().getAll()[0],2,3);
        bookingPtr b2 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[0],TrainManager::getInstance().getAll()[1],4,2);
        bookingPtr b3 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[0],TrainManager::getInstance().getAll()[0],8,1);
        bookingPtr b4 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[2],TrainManager::getInstance().getAll()[1],6,3);
        bookingPtr b5 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[2],TrainManager::getInstance().getAll()[0],3,2);
        bookingPtr b6 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[3],TrainManager::getInstance().getAll()[0],4,3);
        bookingPtr b7 = std::make_shared<Booking>(CustomerManager::getInstance().getAll()[3],TrainManager::getInstance().getAll()[2],10,2);
        try {
            BookingManager::getInstance().add(b1);
            BookingManager::getInstance().add(b2);
            BookingManager::getInstance().add(b3);
            BookingManager::getInstance().add(b4);
            BookingManager::getInstance().add(b5);
            BookingManager::getInstance().add(b6);
            BookingManager::getInstance().add(b7);
        }catch(FullTrainException &error){
            throw FileException(error.message(),"logic error");
        }catch(EmptyTrainException &error){
            throw FileException(error.message(),"logic error");
        }
        BookingManager::getInstance().remove(2);

        std::cout<<CustomerManager::getInstance().info();
        std::cout<<TrainManager::getInstance().info();
        std::cout<<BookingManager::getInstance().info();

        output::trainRepository("../../../trainRepository.csv");
        output::customerRepository("../../../customerRepository.csv");
    }catch (FileException &error){
        std::cout<<error.message();
    }
    return 0;
}