##############################################################
#
#	Basic instructions to GNU Make
#
#	To compile one program from multiple source code files, 
#	use gcc -o outputfile file1.c file2.c file3.c
#
#	The standart fuckery that I always use for simple programs
#	gcc FileName.c -o FileNameOutput
#
#	To compile multiple programs at once with multiple source 
#	code files, 
#		Use gcc -c file1.c file2.c file3.c
#		Or g++ -c file1.cpp file2.cpp etc
##############################################################

# Project name
PROJ_NAME = TIAMAT

# Folders
BUILD_DIR = ./out/
INCLUDE_DIR = ./inc/
SRC_DIR = ./src/

# Compiler & Linker if needed
# g++ for c++ | gcc for c
COMPILER = g++

# Flags, Libraries & Includes
# -g -Wall 
CFLAGS = -g -Wall
		 

# What you're compiling
# If more than one, write all of them here 
# With a space separating them
BINS = tiamattest

all:$(BINS)

# Compiles to out/PROJ_NAME
%: %.cpp
	$(COMPILER) $(CFLAGS) $^ -o $(BUILD_DIR)$@

clean:
	$(RM) $(BINS) $(OUT)