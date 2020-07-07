GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = bank

$(PROGRAMA): main.o Account.o
	$(GCC) $(GCC_FLAGS) -o bank *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Account.o: src/Account.cpp include/Account.h
	$(GCC) $(GCC_FLAGS) -c src/Account.cpp

clean:
	rm *.o $(PROGRAMA)
