.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/sistema.o build/executor.o build/concessionaria.o build/veiculo.o build/carro.o build/moto.o build/caminhao.o


#para adicionar novas regras apenas siga o formato
#build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h
#	g++ -Iinclude src/concessionaria.cpp -c

objects: $(OBJECTS)

build/programa.o: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o bin/programa

build/sistema.o: src/sistema.cpp include/sistema.h
	g++ -Iinclude src/sistema.cpp -c -o build/sistema.o

build/executor.o: src/executor.cpp include/executor.h 
	g++ -Iinclude src/executor.cpp -c -o build/executor.o

build/concessionaria.o: src/concessionaria.cpp include/concessionaria.h 
	g++ -Iinclude src/concessionaria.cpp -c -o build/concessionaria.o

build/veiculo.o: src/veiculo.cpp include/veiculo.h 
	g++ -Iinclude src/veiculo.cpp -c -o build/veiculo.o

build/carro.o: src/carro.cpp include/carro.h 
	g++ -Iinclude src/carro.cpp -c -o build/carro.o

build/moto.o: src/moto.cpp include/moto.h 
	g++ -Iinclude src/moto.cpp -c -o build/moto.o

build/caminhao.o: src/caminhao.cpp include/caminhao.h 
	g++ -Iinclude src/caminhao.cpp -c -o build/caminhao.o
	
programa: objects src/programa.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o build/programa

clean:
	rm build/*.o bin/programa

all: programa

run:
	./bin/programa