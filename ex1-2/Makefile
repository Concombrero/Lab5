CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

SRCS = src/account.cpp src/bank.cpp src/client.cpp src/main.cpp
EXEC = bin/main

$(shell mkdir -p bin)

all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

clean:
	@echo "Cleaning executable..."
	rm -f $(EXEC)
