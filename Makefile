CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = bug_tracker
SRCS := $(shell find src -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)

# Default rule when running 'make'
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
