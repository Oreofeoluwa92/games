#Variables
PROG = game_of_life
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lncurses

# List of source files
SRCS = main.cpp game.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target to build the program
all: $(PROG)

# Build the executable from object files
$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

# Compile individual source files into object files
%.o: %.cpp game.h
	$(CXX) $(CXXFLAGS) -c $<

# Clean target to remove object files and the executable
clean:
	rm -f $(PROG) $(OBJS)

# Phony targets
.PHONY: all clean

