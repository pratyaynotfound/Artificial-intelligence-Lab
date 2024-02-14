CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = TSP.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

EXEC = TSP

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
