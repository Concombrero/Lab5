CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude
BIN = bin

SRCS_ex12 = src/account.cpp src/bank.cpp src/client.cpp src/main_ex12.cpp
SRCS_ex3 = src/main_ex3.cpp

EXEC_ex12 = $(BIN)/ex12
EXEC_ex3 = $(BIN)/ex3

ALL_EXEC = $(EXEC_ex12) $(EXEC_ex3)

$(shell mkdir -p $(BIN))

.PHONY: all clean docs docs-clean

all: $(ALL_EXEC)

$(EXEC_ex12): $(SRCS_ex12)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(EXEC_ex3): $(SRCS_ex3)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BIN)/*

.PHONY: docs docs-clean
docs: docs/Doxyfile
	doxygen docs/Doxyfile

docs-clean:
	rm -rf docs/html docs/latex
