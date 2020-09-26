//  ActivityTracker
//  activitySplitter.hpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.
// 'Data structure kung fu'

#ifndef activitySplitter_hpp

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>


#include "completeActivity.hpp"

class activitySplitter {
public:
  // each incoming object gets mapped to an 'act', creates a new set for each
  // completeActivity object by inserting each into a map
  static Activity_Map doSplit(std::vector<completeActivity> & activities) {
	  Activity_Map activity_map; // declare a variable of type Activity_Map
	  for (completeActivity act : activities) {
		  activity_map[act.getWalkName()].insert(act);
	  }
	  return activity_map;
  }

  static void dump(const Activity_Map & activity_map) {
  // for each pair<act name, set of activities>
     for (auto act : activity_map) {
         std::cout << "Activity Name: " << act.first << " " << std::endl;
	    for (auto instance : act.second) {
		std::cout << instance << std::endl;
	    }
     }
  }
};

#endif /* activitySplitter_hpp */
