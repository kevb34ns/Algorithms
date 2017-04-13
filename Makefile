CC = g++
CXXFLAGS = -g -Wall -std=c++11

MAIN_DIR = .
OBJS_DIR = $(MAIN_DIR)/build
BIN_DIR = $(MAIN_DIR)/bin

all: $(BIN_DIR)/n-queens

$(OBJS_DIR)/n-queens.o: n-queens/n-queens.cpp $(OBJS_DIR)/.dirstamp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/n-queens: $(OBJS_DIR)/n-queens.o $(BIN_DIR)/.dirstamp
	$(CC) $(CXXFLAGS) $< -o $@

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
