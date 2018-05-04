//
//  helper_functions.hpp
//  hotel_guest_tracking_system
//
//  Created by vector on 04/05/2018.
//  Copyright © 2018 vector. All rights reserved.
//

#ifndef helper_functions_hpp
#define helper_functions_hpp

#include <iostream>
#include <string>
#include <map>
#include <cmath>

void printWelcomeScreen();
void printMenu();
std::pair<bool,std::pair<uint,uint>> validateRoomNumber(uint room);

#endif /* helper_functions_hpp */
