###############################################################################
# Incremental C/C++ build for Windows (g++/gcc)
# - Compiles each .c/.cpp into bin/*.obj
# - Rebuilds objects only when their source/headers change
# - Links final executable into build/Data.exe
###############################################################################

# Tools
CC      := gcc
CXX     := g++

# Folders
SRC_DIRS   := . src
INCLUDE_DIR:= include
OBJ_DIR    := bin
BUILD_DIR  := build

# Output
TARGET_NAME := Program.exe
TARGET      := $(BUILD_DIR)/$(TARGET_NAME)

# Flags
CFLAGS   := -Wall -Wextra -O2 -I$(INCLUDE_DIR) -MMD -MP
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -I$(INCLUDE_DIR) -MMD -MP
LDFLAGS  :=

# Cross-platform directory helpers (PowerShell/cmd friendly)
ifeq ($(OS),Windows_NT)
	fixpath = $(subst /,\,$1)
	MKDIR   = @cmd /C if not exist "$(call fixpath,$1)" mkdir "$(call fixpath,$1)"
	RMDIR   = @cmd /C if exist "$(call fixpath,$1)" rmdir /S /Q "$(call fixpath,$1)"
else
	MKDIR   = @mkdir -p "$1"
	RMDIR   = @rm -rf "$1"
endif

# Sources (both C and C++)
CPP_SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))
C_SRCS   := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.c))
SRCS     := $(CPP_SRCS) $(C_SRCS)

# Normalize to remove optional leading ./ for cleaner object paths
SRCS_NODOT := $(patsubst ./%,%,$(SRCS))

# Objects in bin/ mirroring source tree; also generate .d dep files alongside
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.obj,$(patsubst %.c,$(OBJ_DIR)/%.obj,$(SRCS_NODOT)))
DEPS := $(OBJS:.obj=.d)

.PHONY: all clean dirs run
all: $(TARGET)

# Link final binary
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

# Compile C++ sources -> .obj (ensure subdir exists)
$(OBJ_DIR)/%.obj: %.cpp
	$(call MKDIR,$(@D))
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile C sources -> .obj (ensure subdir exists)
$(OBJ_DIR)/%.obj: %.c
	$(call MKDIR,$(@D))
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILD_DIR):
	$(call MKDIR,$(BUILD_DIR))

# Include auto-generated dependency files if they exist
-include $(DEPS)

run: all
	$(TARGET)


# Clean artifacts
clean:
	-@echo Cleaning objects and build outputs
	-$(call RMDIR,$(OBJ_DIR))
	-$(call RMDIR,$(BUILD_DIR))
	-$(call RMDIR,-p)