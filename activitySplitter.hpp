//  ActivityTracker
//  activitySplitter.hpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

// quesitons 1/30/2019
// would it be best to ditch printActivityVector and use this class
// for the output as well? does cpp file get the includes of the hpp ?

#ifndef activitySplitter_hpp

#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "completeActivity.hpp"


class activitySplitter {
private:
	std::map<std::string, std::set<completeActivity>> activity_map;
	std::list<completeActivity> activity_list;

public:
	void vectorToListConvert(std::vector<completeActivity>& vec);
	void doSplit(std::list<completeActivity>& activity);
	void dump();

};












#endif /* activitySplitter_hpp */
