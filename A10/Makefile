GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary

$(PROGRAMA): main.o App.o Diary.o Date.o Time.o DateTime.o
	$(GCC) $(GCC_FLAGS) -o diary *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

DateTime.o: src/DateTime.cpp include/DateTime.h
	$(GCC) $(GCC_FLAGS) -c src/DateTime.cpp

