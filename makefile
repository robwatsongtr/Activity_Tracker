CXXFLAGS = "--std=c++11"
all : activityTracker

clean :
	rm *.o activityTracker

activityTracker : completeActivity.o fillActivityVector.o main.o
	g++ $+ -o $@

completeActivity.o : completeActivity.cpp completeActivity.hpp

fillActivityVector.o : fillActivityVector.cpp fillActivityVector.hpp completeActivity.hpp

main.o : main.cpp completeActivity.hpp fillActivityVector.hpp activitySplitter.hpp
