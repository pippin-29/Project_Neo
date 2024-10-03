#*____________________________________________________________________________________________________________________________*#
##*__________________________________________________________________________________________________________________________*##
##**________________________________________________________________________________________________________________________**##
##***     File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/Makefile                                                       ***##
##***     Header Created: Tue Oct 01 2024                                                                                  ***##
##***     Author: Daniel Haddington at <haddingtondaniel5@gmail.com>                                                       ***##
##***     Copyright (c) 2024 Daniel Haddington                                                                             ***##
##**________________________________________________________________________________________________________________________**##
##*__________________________________________________________________________________________________________________________*##

# Define the target executable
TARGET := neo

# Define the compiler and flags
C_COMPILER := g++
LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
ADDSAN := -fsanitize=address -g

# Define source and object directories
SRC_DIR := source/
OBJ_DIR := object/

# Find all .c files in the source directory
SOURCE := $(wildcard $(SRC_DIR)*.cpp)

# Convert source files to object files
OBJECTS := $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) $(FLAGS) $(ADDSAN) $(OBJECTS) $(LDFLAGS) -o $(TARGET)


# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE..."
	$(LINK)

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	echo "COMPILING OBJECTS ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) -c $< -o $@ $(CFLAGS)

# Rule to create the object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Rule to clean up compiled files
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)
	
# Phony targets
.PHONY: clean all help aptlibs
.SILENT: