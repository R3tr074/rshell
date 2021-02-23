PROJECT_NAME := rshell
BINARY := rshell

# Gets the Operating system name
OS := $(shell uname -s)

# Default shell
SHELL := bash

# Color prefix for Linux distributions
COLOR_PREFIX := e
ifeq ($(OS),Darwin)
	COLOR_PREFIX := 033
endif
# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
END_COLOR=\$(COLOR_PREFIX)[0m

# Source code directory structure
SRCDIR := src
LIBDIR := lib

# Source code file extension
SRCEXT := c

# Defines the C Compiler
CC := gcc

# Defines the language standards for GCC
STD := -std=gnu99 # See man gcc for more options

# Protection for stack-smashing attack
STACK := -fstack-protector-all -Wstack-protector

# Specifies to GCC the required warnings
WARNS := -Wall -Wextra -pedantic #-w # -pedantic warns on language standards

# Flags for compiling
CFLAGS := -O3 $(STD) $(STACK) $(WARNS)

# Debug options
DEBUG := -g3 -DDEBUG=1

# Dependency libraries
LIBS := -lm  -I src/include

# %.o file names
NAMES := $(notdir $(basename $(wildcard $(SRCDIR)/*.$(SRCEXT))))
OBJECTS :=$(patsubst %,$(LIBDIR)/%.o,$(NAMES))

default: clean all

all: $(OBJECTS)
	$(CC) -o $(BINARY) $+ $(DEBUG) $(CFLAGS) $(LIBS)
	@echo -en "---\nBinary file placed at" \
			  "$(BROWN)./$(BINARY)$(END_COLOR)\n";


# Rule for object binaries compilation
$(LIBDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo -en "$(BROWN)CC $(END_COLOR)";
	$(CC) -c $^ -o $@ $(DEBUG) $(CFLAGS) $(LIBS)

# Install
install:
	cp ./$(BINARY) /usr/bin

# Rule for cleaning the project
clean:
	@rm -rvf $(BINARY) $(LIBDIR)/*;
