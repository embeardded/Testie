# *************************************************************************************************
# Makefile for building and running the Testie unit tests with clang
#
#   make          Build the test binary
#   make test     Build the test binary and run it
#   make clean    Remove all build output
# *************************************************************************************************

# Toolchain ***************************************************************************************

CC          := clang
CFLAGS      ?= -std=c99 -g -O0 -Wall -Wextra
LDFLAGS     ?=
LDLIBS      ?=

# Project settings ********************************************************************************

INCLUDE_DIRS := src test
BUILD_DIR    := build
TARGET       := $(BUILD_DIR)/TestieTests

CPPFLAGS += $(addprefix -I,$(INCLUDE_DIRS))
CPPFLAGS += "-DTESTIE_INCLUDE_CONFIG=<TestieConfig.h>"

# Sources and objects *****************************************************************************

SRCS := $(wildcard src/*.c) $(wildcard test/*.c)
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Shell helpers ***********************************************************************************

# cmd.exe on Windows
mkdir_dir = if not exist "$(subst /,\,$(1))" mkdir "$(subst /,\,$(1))"
remove_dir = if exist "$(subst /,\,$(1))" rmdir /s /q "$(subst /,\,$(1))"
run_program = $(subst /,\,$(1))

# Build rules *************************************************************************************

.PHONY: all test run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: %.c
	@$(call mkdir_dir,$(@D))
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

test: $(TARGET) run

run: $(TARGET)
	@$(call run_program,$(TARGET))

clean:
	@$(call remove_dir,$(BUILD_DIR))

-include $(DEPS)

# End of file *************************************************************************************
