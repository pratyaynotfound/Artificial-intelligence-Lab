# Makefile for Missionaries and Cannibals Problem

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files and object files
SRCS = MandCP.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = mission_cannibals

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) $(EXEC)
