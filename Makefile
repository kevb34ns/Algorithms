CC = g++
CXXFLAGS = -g -Wall -std=c++11

MAIN_DIR = .
OBJS_DIR = $(MAIN_DIR)/build
BIN_DIR = $(MAIN_DIR)/bin

all: $(BIN_DIR)/n-queens $(BIN_DIR)/sortTest

$(OBJS_DIR)/n-queens.o: n-queens/n-queens.cpp $(OBJS_DIR)/.dirstamp
	$(CC) -c $< -o $@ $(CXXFLAGS) -In-queens

$(BIN_DIR)/n-queens: $(OBJS_DIR)/n-queens.o $(BIN_DIR)/.dirstamp
	$(CC) $< -o $@ $(CXXFLAGS)

$(OBJS_DIR)/sortTest.o: sorting/sortTest.cpp sorting/selectionSort.cpp sorting/bubbleSort.cpp sorting/insertionSort.cpp sorting/mergeSort.cpp sorting/quickSort.cpp sorting/radixSort.cpp $(OBJS_DIR)/.dirstamp
	$(CC) -c $< -o $@ $(CXXFLAGS) -Isorting

$(BIN_DIR)/sortTest: $(OBJS_DIR)/sortTest.o $(BIN_DIR)/.dirstamp
	$(CC) $< -o $@ $(CXXFLAGS)

# make sure that $(OBJS_DIR) and $(BIN_DIR) exist
$(OBJS_DIR)/.dirstamp:
	mkdir -p $(OBJS_DIR)
	touch $(OBJS_DIR)/.dirstamp

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean:
	rm -f $(OBJS_DIR)/*.o $(BIN_DIR)/*
