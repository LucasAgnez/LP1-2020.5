GCC = g++
GCC_FLAGS = -I include -std=c++11
WARNINGS = -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wno-unused-result      \
	-Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2                 \
	-Wduplicated-cond -Wcast-qual -Wcast-align
PROGRAMA = supermercado

$(PROGRAMA): main.o  App.o Estabelecimento.o Cliente.o
	$(GCC) $(GCC_FLAGS) -o supermercado *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

clean:
	rm *.o $(PROGRAMA)
