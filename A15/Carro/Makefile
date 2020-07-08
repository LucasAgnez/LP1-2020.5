GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = carro

$(PROGRAMA): main.o carro.o motor.o
	$(GCC) $(GCC_FLAGS) -o carro *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

carro.o: src/carro.cpp include/carro.h
	$(GCC) $(GCC_FLAGS) -c src/carro.cpp

motor.o: src/motor.cpp include/motor.h
	$(GCC) $(GCC_FLAGS) -c src/motor.cpp

clean:
	rm *.o $(PROGRAMA)
