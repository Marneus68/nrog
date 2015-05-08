# Takes the name of the current directory as a the executable and "pr" name
TARGET  := $(shell basename $$PWD | tr '[:upper:]' '[:lower:]')
# Compiler
CC      := g++ -std=c++11
# Warning levels
WARN    :=
# Optimisation
OFLAGS  := 
# Link Options
LDFLAGS := 
# Link Libraries
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LDLIBS 	:= -lncursesw
endif
ifeq ($(UNAME_S),Darwin)
    LDLIBS 	:= -lncurses
endif

# Source directory
SRCDIR	:= src
# Include directory
INCDIR	:= include
# Object directory
OBJDIR	:= obj

CFLAGS	:= -I $(INCDIR)

# setting the vpath (additionnal search path for make)
VPATH	:= $(INCDIR) $(SRCDIR) $(OBJDIR)

CPP_SRCS    = $(wildcard src/*.cpp)
OBJ_FILES   = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(CPP_SRCS))

# Colors
black	= `tput setaf 0`
red		= `tput setaf 1`
green	= `tput setaf 2`
yellow	= `tput setaf 3`
blue	= `tput setaf 4`
magenta = `tput setaf 5`
cyan	= `tput setaf 2`
white	= `tput setaf 7`
reset	= `tput sgr0`

all: ${TARGET}

$(TARGET): $(OBJ_FILES)
	@echo "$(blue)Linking...$(reset)"
	$(CC) $(WARN) $(OFLAGS) $(CFLAGS) $(LDFLAGS) $(OBJ_FILES) -o $@ $(LDLIBS) 
	@echo "$(green)Done.$(reset)"

obj/%.o: %.cpp $(OBJDIR)
	@echo "$(blue)Compiling $(yellow)"$<"$(blue)...$(reset)"
	$(CC) -c $(WARN) $(OFLAGS) $(CFLAGS) $(LDFLAGS) $< -o $@

$(OBJDIR):
	@echo "$(blue)Creating object directory..."$(reset)
	mkdir -p $(OBJDIR)

clean: 
	@echo "$(blue)Cleaning executables...$(reset)"
	rm -rf $(OBJDIR)/*.o

mrproper: clean
	@echo "$(blue)Cleaning executables...$(reset)"
	rm -rf ${TARGET}

install:
	@echo "$(blue)Installing...$(reset)"
	@echo "$(blue)Copying resources...$(reset)"
	# Resources path : /usr/local/games/nrog
	@echo "$(blue)Copying executable...$(reset)"
	# Executable path : /usr/local/bin
	@echo "$(green)Done. Enjoy :)$(reset)"

doc:
	@echo "$(blue)Building documentation...$(reset)"

