test_prg: Date.o Time.o test_prg.o Report.o
	g++ Date.o Time.o test_prg.o Report.o -o test_prg

test_prg.o: test_prg.cpp Report.h
	g++ -c test_prg.cpp

Report.o: Report.cpp Date.h Time.h Report.h
	g++ -c Report.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp

Time.o: Time.cpp Date.h
	g++ -c Time.cpp
