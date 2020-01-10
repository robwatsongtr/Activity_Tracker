/*
 
ActivityTracker 0.8
 
Created by Robert Watson 2019
Copyright © 2019 Robert Watson. All rights reserved.
Additional help by Robert Diamond.

Features implemented in this order:
 
-class structure / variables, 'struct tm' for time
-input loop, output loop
-error handling / input parsing
-stable sorting by time and name
 
TODO:
Some text here. 
Needs Data Structure Kung Fu: Move objects into std::list, then std::lists(s)
into std::map
So as to sort and compute fastest, slowest, average of each activity easily
*/

#include <iostream>
#include <vector>

#include "completeActivity.hpp"
#include "printActivityVector.hpp"
#include "fillActivityVector.hpp"


int main() {
    
    // make the 'master vector'
    std::vector<completeActivity> allActivities;
    
    // program loop for console input:
    fillActivityVector(allActivities);
    
    // sort the master vector
    std::stable_sort(allActivities.begin(), allActivities.end(), completeActivity::sort_by_time());
    std::stable_sort(allActivities.begin(), allActivities.end(), completeActivity::sort_by_name());
    
    // print results to console
    printActivityVector(allActivities);
    
}
