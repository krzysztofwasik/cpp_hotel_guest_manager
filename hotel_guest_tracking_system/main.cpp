//
//  main.cpp
//  hotel_guest_tracking_system
//
//  Created by Krzysztof Wasik on 16/04/2018.
//  Copyright © 2018 Krzysztof Wasik. All rights reserved.
//

//1. Keep track of guests in a hotel - for now, just use a name
//  * the hotel has 20 floors with 15 rooms each
//  * rooms are numbered as [floor #][room #], for example 114, 502, 1408
//      * 114 -> 4 room on 11 floor
//      * 502 -> 2 room on 5 floor
//      * 1408 -> 8 room on 14 floor
//  * do not accept duplicate entries

#include "helper_functions.hpp"

#include <iostream>
#include <string>
#include <map>
#include <cmath>


int main(int argc, const char * argv[]) {
    
    uint userOption = 0;
    uint room;
    std::map<std::pair<uint,uint>,std::string> guestList;
    
    printWelcomeScreen();
    
    while(1)
    {
        printMenu();
        std::cin >> userOption;
        if(0 == userOption || 4 <= userOption) break;
        
        switch(userOption)
        {
            case 1:
            {
                std::string guestFullName;
                
                std::cout << "Please provide guest full name" << std::endl;
                std::cin.ignore();
                std::getline(std::cin,guestFullName);
                
                std::cout << "Please provide guest room and on which floor, pattern: [floor][room]" << std::endl;
                std::cin >> room;
                
                auto newGuest = validateRoomNumber(room);
                if(newGuest.first)
                {
                    auto opStatus = guestList.emplace(newGuest.second, guestFullName);
                    if(opStatus.second) std::cout << "Added guest to hotel guest list in room " << newGuest.second.second << " on floor " << newGuest.second.first << std::endl;
                    else std::cerr << "Cannot added guest to hotel list, propably this guest is already check in" << std::endl;
                }
            }
                break;
            case 2:
            {
                for(auto it = guestList.begin();it != guestList.end();it++)
                {
                    std::cout << "Guest name: " << it->second << std::endl;
                    std::cout << "Floor:" << it->first.first << " Room:" << it->first.second << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
            }
                break;
            case 3:
            {
                std::cout << "Please provide room to checkout and on which floor, pattern: [floor][room] " << std::endl;
                std::cin >> room;
                auto roomToCheckout = validateRoomNumber(room);
                if(roomToCheckout.first)
                {
                    auto it = guestList.find(roomToCheckout.second);
                    if(it->first == roomToCheckout.second) guestList.erase(it);
                    std::cout << "Room " << roomToCheckout.second.first << roomToCheckout.second.second << " checkout successfull" << std::endl;
                }
                else std::cerr << "Provide room is not on hotel guest list" << std::endl;
            }
                break;
            case 4:
            default:
                break;
        }
        
    }
    
    return 0;
}
