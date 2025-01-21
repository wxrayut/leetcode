# Makefile for Testing LeetCode Solutions.
#
# Usage:
# - To compile and run a file:        	make run file=<filename.c>
# - To run with Valgrind:            	make leak-check file=<filename.c>
# - To clean up generated files:     	make clean file=<filename.c>
# - To clean up all generated files: 	make clean
#
# Variables:
# - CC:      The compiler to use (default: gcc)
# - CFLAGS:  Compiler flags for warnings and standards (default: )
# 
# Example:
# 	make run file=solution.c
# 	make leak-check file=solution.ca

U_NAME = $(shell uname -s)

CC = gcc
CFLAGS = -Wall -Wextra

INCLUDE_DIR = 
STRUCTURE_DIR = 

PYTHON = 

ifeq ($(U_NAME), Linux)
	PYTHON = python3
else
	PYTHON = python
endif

OUTPUT = $(file:.c=)


all:
	@echo "Usage: make run file=<filename> or make leak-check file=<filename>"

run:
	@if [ -z "$(file)" ]; then \
		echo "[ERROR]: Please provide a file name using 'make run file=<filename>'"; \
	elif [ "$(file)" != "$(file:.py=)" ]; then \
		echo "[INFO]: Running Python script $(file) . . .\n"; \
		$(PYTHON) $(file); \
	else \
		echo "[INFO]: Compiling and running $(file) . . .\n"; \
        $(CC) $(CFLAGS) -o $(OUTPUT).o $(file) && ./$(OUTPUT).o; \
        rm -f $(OUTPUT).o; \
	fi

leak-check:
	@if [ -z "$(file)" ]; then \
		echo "[ERROR]: Please provide a file name using 'make leak-check file=<filename>'"; \
	elif [ "$(file)" != "$(file:.py=)" ]; then \
		echo "[ERROR]: Memory leak check is not applicable for Python files."; \
	else \
		echo "[INFO]: Compiling and running $(file) with memory leak check. . .\n"; \
        $(CC) $(CFLAGS) -o $(OUTPUT).o $(file) && valgrind --leak-check=full --show-leak-kinds=all ./$(OUTPUT).o; \
		rm -f $(OUTPUT).o; \
	fi

clean:
	@if [ -z "$(file)" ]; then \
		echo "[INFO]: Cleaning up all generated files. . .\n"; \
		rm -f *.o; \
	else \
		echo "[INFO]: Cleaning up generated file for $(file). . .\n"; \
		rm -f $(OUTPUT).o; \
	fi
