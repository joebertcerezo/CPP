# Makefile for C++ Practice Project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS =

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
EXECUTABLES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%, $(SOURCES))

# Special dependencies
$(BUILD_DIR)/03_pointers_refs: $(SRC_DIR)/03_pointers_refs.cpp $(SRC_DIR)/maTry.cpp $(SRC_DIR)/maTry.h

# Default target: build all executables
all: $(EXECUTABLES)

# Rule to build executables
$(BUILD_DIR)/%: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -o $@

# Special rule for 03_pointers_refs (needs maTry.cpp)
$(BUILD_DIR)/03_pointers_refs: $(SRC_DIR)/03_pointers_refs.cpp $(SRC_DIR)/maTry.cpp $(SRC_DIR)/maTry.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/03_pointers_refs.cpp $(SRC_DIR)/maTry.cpp $(LDFLAGS) -o $@

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run specific program (usage: make run PROGRAM=name)
run: $(BUILD_DIR)/$(PROGRAM)
	./$(BUILD_DIR)/$(PROGRAM)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Clean and rebuild
rebuild: clean all

# Format code using clang-format (assumes format.sh uses clang-format)
format:
	./format.sh

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build all executables"
	@echo "  clean     - Remove build artifacts"
	@echo "  rebuild   - Clean and rebuild all"
	@echo "  format    - Format code using format.sh"
	@echo "  run       - Run specific program (usage: make run PROGRAM=name)"
	@echo "  help      - Show this help"
	@echo ""
	@echo "Executables built:"
	@echo "$(EXECUTABLES)"

.PHONY: all clean rebuild format run help
