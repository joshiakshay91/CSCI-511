CXX = g++
CXXFLAGS = -c -g -std=c++11

PROG = a.out
HDRS = StreamSource.h deque.h Wrapper.h
SRCS = main.cpp StreamSource.cpp Wrapper.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)


wrapper.o:Wrapper.cpp
		$(CXX) $(CXXFLAGS) Wrapper.cpp

main.o :main.cpp
		$(CXX) $(CXXFLAGS) main.cpp

change.o : StreamSource.cpp
		$(CXX) $(CXXFLAGS) StreamSource.cpp

clean :
		rm -f core $(PROG) *.o
