GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = bank

$(PROGRAMA): main.o Account.o Client.o Agency.o ClientPJ.o Line.o
	$(GCC) $(GCC_FLAGS) -o bank *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Account.o: src/Account.cpp include/Account.h
	$(GCC) $(GCC_FLAGS) -c src/Account.cpp

Client.o: src/Client.cpp include/Client.h
	$(GCC) $(GCC_FLAGS) -c src/Client.cpp

Agency.o: src/Agency.cpp include/Agency.h
	$(GCC) $(GCC_FLAGS) -c src/Agency.cpp

ClientPJ.o: src/ClientPJ.cpp include/ClientPJ.h
	$(GCC) $(GCC_FLAGS) -c src/ClientPJ.cpp

Line.o: src/Line.cpp include/Line.h
	$(GCC) $(GCC_FLAGS) -c src/Line.cpp

clean:
	rm *.o $(PROGRAMA)
