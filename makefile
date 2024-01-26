a.out : main.o driver.o drivers.o economy.o basic.o group.o luxury.o passenger.o passengers.o ride.o rides.o
	g++ main.o driver.o drivers.o economy.o basic.o group.o luxury.o passenger.o passengers.o ride.o rides.o -o a.out

main.o : main.cpp driver.h economy.h basic.h group.h luxury.h passenger.h ride.h drivers.h passengers.h rides.h
	g++ -Wall -c main.cpp

driver.o : driver.cpp driver.h
	g++ -Wall -c driver.cpp

drivers.o : drivers.cpp driver.h drivers.h economy.o basic.o group.o luxury.o
	g++ -Wall -c drivers.cpp

economy.o : economy.cpp economy.h driver.h
	g++ -Wall -c economy.cpp

basic.o : basic.cpp basic.h driver.h
	g++ -Wall -c basic.cpp

group.o : group.cpp group.h driver.h
	g++ -Wall -c group.cpp

luxury.o : luxury.cpp luxury.h driver.h
	g++ -Wall -c luxury.cpp

passenger.o : passenger.cpp passenger.h
	g++ -Wall -c passenger.cpp

passengers.o : passengers.cpp passenger.h passengers.h
	g++ -Wall -c passengers.cpp

ride.o : ride.cpp ride.h
	g++ -Wall -c ride.cpp

rides.o : rides.cpp ride.h rides.h
	g++ -Wall -c rides.cpp

clean :
	rm *.o a.out
