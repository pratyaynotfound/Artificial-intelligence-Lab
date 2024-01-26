# Makefile for Missionaries and Cannibals Problem

CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = MandCP.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

EXEC = mission_cannibals

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
