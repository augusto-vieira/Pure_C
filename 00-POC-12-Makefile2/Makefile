################## Makefile ##################
#Definição de variaveis
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
TARGET=teste
OBJ=teste.o main.o


all: $(TARGET)

@echo "Vou começar a compilação"

#linka os objetos para gerar o executavel
teste: teste.o main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c teste.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
	@echo "compilação pronta"

mrproper: clean
	rm -rf $(TARGET) 
