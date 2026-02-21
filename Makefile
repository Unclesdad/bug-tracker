CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude -I$(shell brew --prefix)/include
LDFLAGS = -L$(shell brew --prefix)/lib
LIBS = -lgtest -lgtest_main -pthread

TARGET = bug_tracker

# Files
SRCS := $(shell find src -name "*.cpp")
OBJS = $(SRCS:.cpp=.o)
# Drop main.o for the test build
LIB_OBJS = $(filter-out src/main.o, $(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Rule to compile any .cpp file (in src/ or tests/)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build and run tests
test: $(LIB_OBJS) tests/test_dashboard.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o test_runner $^ $(LIBS)
	./test_runner

clean:
	rm -f $(OBJS) tests/*.o $(TARGET) test_runner

.PHONY: all test clean