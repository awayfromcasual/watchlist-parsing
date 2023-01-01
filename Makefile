
# C compiler
CC=gcc

# Default GCC optimization
OPT=-O0

# Dependency flags:
DEPFLAGS=-MP -MD

# Compiler flags:
#  -g    -> adds debugging information to the executable file
#  -Wall -> turns on most, but not all, compiler warnings
CFLAGS=$(OPT) $(DEPFLAGS) -g -Wall

# Source, object, dependency directories
SRC=src
OBJ=obj

# Source and header files
CFILES=$(wildcard $(SRC)/*.c)
HFILES=$(wildcard $(SRC)/*.h)

# Object files
OBJECTS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFILES))

# Dependency files
DFILES=$(patsubst $(SRC)/%.c, $(OBJ)/%.d, $(CFILES))

# Target executable
BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

run:
	@$(BINARY)

clean:
	@del /s *.o *.d *.exe

dir:
	@dir
	@dir obj
	@dir src

diff:
	@git status
	@git diff --stat

-include $(DFILES)
