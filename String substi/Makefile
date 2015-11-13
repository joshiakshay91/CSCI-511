CXX = g++
CXXFLAGS = -c -g -std=c++11

PROG = a.out
HDRS = changer.h deque.h
SRCS = main.cpp changer.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)

main.o :main.cpp
		$(CXX) $(CXXFLAGS) main.cpp

change.o : changer.cpp
		$(CXX) $(CXXFLAGS) changer.cpp

clean :
		rm -f core $(PROG) *.o
