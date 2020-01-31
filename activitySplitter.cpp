//  ActivityTracker
//  activitySplitter.cpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.


#include "activitySplitter.hpp"

void activitySplitter::vectorToListConvert(std::vector<completeActivity>& vec) {
	std::copy(vec.begin(), vec.end(), std::back_inserter(activity_list));
}
