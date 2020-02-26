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

// 	static void outputSlowFastAvg(const Activity_Map & activity_map) {
//		auto slowest = activity_map.second.begin();
//		// .....
//	}

/*
	auto slowest = activity_map.begin(); // iterator to first entry in map
	auto fastest = activity_map.end();  // iterator to last entry in map

	std::cout << slowest->first << std::endl;
	std::cout << slowest->second << std::endl;

	std::cout << fastest->first << std::endl;
	std::cout << fastest->second << std::endl;

	// auto median = std::advance(activity_map.begin(), activity_map.size()/2);
	// not working! even with #include <iterator>
*/








#endif /* activitySplitter_hpp */
