################ Makefile ################

# Toolchain
CC = gcc

# Compiler Flags
CFLAGS = -Wall -g 

# Libraries
LDFLAGS := -lm -lpthread -lrt

# Wildcard to get all source files in current directory
SOURCES := $(wildcard *.c)

# Objects files
OBJS := $(SOURCES:.c=.o)

# Target 
TARGET := prog

#recipes

all: $(TARGET)

#Linking all libs and objects
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


# compile all .c file and becomes a .o file
%.o: %.c
	$(CC) -c $(CFLAGS) $^

# Remove all .o files and TARGET
clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(TARGET)

run:
	./$(TARGET)
