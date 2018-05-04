//
//  helper_functions.cpp
//  hotel_guest_tracking_system
//
//  Created by vector on 04/05/2018.
//  Copyright © 2018 vector. All rights reserved.
//

#include "helper_functions.hpp"

void printWelcomeScreen()
{
    std::cout << " ..:: Hotel guests tracking system::.." << std::endl;
}

void printMenu()
{
    std::cout << std::endl << " [ Navigation ] " << std::endl;
    std::cout << "[1] Add new guest with hotel room" << std::endl;
    std::cout << "[2] Show all guests that currently stay in the hotel" << std::endl;
    std::cout << "[3] Remove current guest" << std::endl;
    std::cout << "[4] Exit" << std::endl;
}

std::pair<bool,std::pair<uint,uint>> validateRoomNumber(uint room)
{
    bool valid = true;
    uint maxFloor = 20;
    uint maxRoomPerFloor = 15;
    uint digitsCount = log10(room) + 1;
    uint floorNumber;
    uint roomNumber;
    
    if(digitsCount < 3 || digitsCount >= 5) valid = false;
    
    switch(digitsCount)
    {
        case 4: // XXYY -> XX is floor number, YY is room number
            floorNumber = room/100;
            if(floorNumber >= 10 && floorNumber <= maxFloor)
            {
                roomNumber = room %100;
                if(roomNumber > maxRoomPerFloor)
                {
                    valid = false;
                    std::cerr << "Provided room has invalid room per floor number" << std::endl;
                }
            }
            else
            {
                valid = false;
                std::cerr << "Provided room has invalid floor number" << std::endl;
                
            }
            break;
        case 3: // XYY -> X is floor number, YY is room number
            floorNumber = room/100;
            if(floorNumber >= 1 && floorNumber < 10)
            {
                roomNumber = room %100;
                if(roomNumber > maxRoomPerFloor)
                {
                    valid = false;
                    std::cerr << "Provided room has invalid room per floor number" << std::endl;
                }
            }
            else
            {
                valid = false;
                std::cerr << "Provided room has invalid floor number" << std::endl;
                
            }
            
            break;
        default:
            break;
    }
    if(valid) return std::make_pair(valid, std::make_pair(floorNumber, roomNumber));
    else return std::make_pair(valid, std::make_pair(0, 0));
}
