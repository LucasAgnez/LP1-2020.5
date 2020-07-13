GCC = g++
GCC_FLAGS = -I include -std=c++11
WARNINGS = -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wno-unused-result      \
	-Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2                 \
	-Wduplicated-cond -Wcast-qual -Wcast-align
PROGRAMA = empresa

$(PROGRAMA): main.o Funcionario.o Empresa.o
	$(GCC) $(GCC_FLAGS) -o empresa *.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Funcionario.o: src/Funcionario.cpp include/Funcionario.h
	$(GCC) $(GCC_FLAGS) -c src/Funcionario.cpp

Empresa.o: src/Empresa.cpp include/Empresa.h
	$(GCC) $(GCC_FLAGS) -c src/Empresa.cpp

clean:
	rm *.o $(PROGRAMA)
