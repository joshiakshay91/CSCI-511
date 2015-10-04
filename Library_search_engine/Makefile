CXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic

PROG = SearchEngine
HDRS = engine.h Media.h book.h film.h Periodicals.h video.h
SRCS = Menu.cpp engine.cpp Media.cpp book.cpp film.cpp Periodicals.cpp video.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROG) : $(OBJS)
	$(CXX)  $(OBJS) -o $(PROG)

men.o :Menu.cpp
	$(CXX) $(CXXFLAGS) Menu.cpp

engi.o :  engine.cpp    engine.h
	$(CXX) $(CXXFLAGS) engine.cpp

medi.o: Media.cpp Media.h
		$(CXX) $(CXXFLAGS) Media.cpp

boo.o: book.cpp book.h
		$(CXX) $(CXXFLAGS) book.cpp

fil.o: film.cpp film.h
		$(CXX) $(CXXFLAGS) film.cpp

perio.o: Periodicals.cpp Periodicals.h
				$(CXX) $(CXXFLAGS) Periodicals.cpp

vid.o: video.cpp vidoe.h
						$(CXX) $(CXXFLAGS) video.cpp

clean :
	rm -f core $(PROG) *.o
