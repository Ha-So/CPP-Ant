#*********************************************************************
#* Program name: Langton's Ant (Turing Machine)
#* File name: makefile
#* Author: Haris Sohail
#* Date: 04/14/2017
#* Description: This is the makefile for the entire Langton's Ant program.
#* Type "make" to compile this program, the executable is named "runAnt" 
#*********************************************************************/


CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = mainAnt.o  inputVal.o Ant.o menu.o

SRCS = mainAnt.cpp inputVal.cpp Ant.cpp menu.cpp

HEADERS = inputVal.hpp Ant.hpp menu.hpp
	

runAnt: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS}  -o runAnt


clean:
	$(RM) *.o 