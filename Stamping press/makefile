CXX = g++
BXX =-c -g -std=c++11

PROG = stampout
HDRS = stamp.h stampbuff.h stampstream.h
SRCS = main.cpp stampbuff.cpp stampstream.cpp stamp.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)

main.o :main.cpp
	$(CXX) $(BXX) main.cpp

stampbuff.o :  stampbuff.cpp   stampbuff.h
	$(CXX) $(BXX) stampbuff.cpp

stampstream.o: stampstream.cpp stampstream.h
		$(CXX) $(BXX) stampstream.cpp

stamp.o: stamp.cpp stamp.h
		$(CXX) $(BXX) stamp.cpp

clean :
	rm -f core $(PROG) *.o
