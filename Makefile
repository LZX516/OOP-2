CXX = g++
CXXFLAGS = -Wall -g -std=c++14

# Source files
SRCS = main.cpp Student_info.cpp grade.cpp median.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = program.exe

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)

# Dependencies
main.o: main.cpp Student_info.h grade.h
Student_info.o: Student_info.cpp Student_info.h
grade.o: grade.cpp grade.h median.h Student_info.h
median.o: median.cpp median.h

.PHONY: all clean
