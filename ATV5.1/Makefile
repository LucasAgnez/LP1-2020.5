GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = supermercado

ALUNOS = ArturMeloSantiagoFerreira_LucasAgnezLima

$(PROGRAMA): main.o  App.o Estabelecimento.o Cliente.o VectorSupermercado.o Fornecedor.o
	$(GCC) $(GCC_FLAGS) -o supermercado *.o

zip: src/* include/* 
	zip $(ALUNOS).zip src/* include/* Makefile README.md .gitignore estoque.csv fornecedor.csv

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

App.o: src/Util.cpp include/Util.h
	$(GCC) $(GCC_FLAGS) -c src/Util.cpp

Estabelecimento.o: src/Estabelecimento.cpp include/Estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp

Cliente.o: src/Cliente.cpp include/Cliente.h
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Fornecedor.o: src/Fornecedor.cpp include/Fornecedor.h
	$(GCC) $(GCC_FLAGS) -c src/Fornecedor.cpp

VectorSupermercado.o: src/VectorSupermercado.cpp include/VectorSupermercado.h
	$(GCC) $(GCC_FLAGS) -c src/VectorSupermercado.cpp

clean:
	rm *.o $(PROGRAMA)
