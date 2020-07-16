GCC = g++
GCC_FLAGS = -I include -std=c++11 -g

WARNINGS = -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wno-unused-result      \
	-Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2                 \
	-Wduplicated-cond -Wcast-qual -Wcast-align

PROGRAMA = supermercado

$(PROGRAMA): main.o  App.o Estabelecimento.o Cliente.o VectorSupermercado.o Fornecedor.o
	$(GCC) $(GCC_FLAGS) -o supermercado *.o

zip: src/* include/* 
	zip $(MATRICULA).zip src/* include/* Makefile README.md .gitignore estoque.csv

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

VectorSupermercado.o: src/VectorSupermercado.cpp include/VectorSupermercado.h
	$(GCC) $(GCC_FLAGS) -c src/VectorSupermercado.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp

clean:
	rm -f *.o $(PROGRAMA)

# Arquivos que não existem no disco
.PHONY: all zip
