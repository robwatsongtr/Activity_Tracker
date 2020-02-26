/*

ActivityTracker

Created by Robert Watson 2019-2020
Copyright © 2019 Robert Watson. All rights reserved.
Additional help by Robert Diamond.

Features implemented in this order:

-class structure / variables, 'struct tm' for time
-input loop, output loop
-error handling / input parsing
-stable sorting by time and name. This will be supplanted by below:

TODO:
sort and compute fastest, slowest, average of each activity easily
*/

#include <iostream>
#include <vector>

#include "completeActivity.hpp"
#include "fillActivityVector.hpp"
#include "activitySplitter.hpp"

int main() {

    // make the 'master vector'
    std::vector<completeActivity> allActivities;

	// fill the vector with some activity data
    fillActivityVector(allActivities);

	// put the activity vector in a map and set combo to sort by name
	auto activity_map = activitySplitter::doSplit(allActivities);

	// print results
	activitySplitter::dump(activity_map);

}
