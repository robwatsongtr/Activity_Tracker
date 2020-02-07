//  ActivityTracker
//  completeActivity.cpp
//  Copyright © 2019-2020 Robert Watson. All rights reserved.

#include "completeActivity.hpp"
#include <iostream>

bool completeActivity::parseDate(std::string dateStr) {
    // parse the string and assign a pointer to the parsed string
    char *rest = strptime(dateStr.c_str(), "%D", &m_time);
    if (rest == nullptr || *rest != '\0') { // are there unparsed characters left?
        m_date_is_valid = false; // parse failed
    } else {
        m_date_is_valid = true;  // else parse succeeded
    }
    return m_date_is_valid;
}

bool completeActivity::parseTime(std::string timeStr) {
    char *rest = strptime(timeStr.c_str(), "%T", &m_time);
    if (rest == nullptr || *rest != '\0') {
        m_time_is_valid = false;
    } else {
        m_time_is_valid = true;
    }
    return m_time_is_valid;
}

// the variable stream will be type ostream 
std::ostream & operator<<(std::ostream & stream, const completeActivity & activity) {
	stream << "Date: " << (activity.time_member().tm_mon) + 1
		<< "/" << activity.time_member().tm_mday
		<< "/" << 1900 + (activity.time_member().tm_year) << '\n';
	stream << "Time: " << activity.time_member().tm_hour
		<< ":" << activity.time_member().tm_min
		<< ":" << activity.time_member().tm_sec << '\n';
	stream << "Time(sec): " << activity.getWalkElapsedTimeSec() << '\n';
	stream << "Distance: " << activity.getWalkDistance() << '\n';

	return stream;
}
