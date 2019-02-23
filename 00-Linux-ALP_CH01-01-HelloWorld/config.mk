CC	?= gcc
CXX	?= g++
AR	?= ar
RM	:= rm -rf
MD	:= mkdir -p
CP	:= cp

DIR	:= src

CPPFLAGS	+= -g -O0 -std=c++11  -I$(DIR)
CFLAGS		+= -g -O0 -std=c99    -I$(DIR)

SRC_CPP = $(wildcard $(DIR)/*.cpp)
SRC_C   = $(wildcard $(DIR)/*.c)

OBJ_CPP = $(patsubst %.cpp,%.o,$(SRC_CPP))
OBJ_C   = $(patsubst %.c,%.o,$(SRC_C))

