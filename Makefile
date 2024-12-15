CC = gcc
CFLAGS = -Wall -std=c99 -g
INCLUDE = -I ./src/include

OBJDIR = build
TARGET = bin/main

# Source and object files
SRCS = src/main.c $(wildcard src/include/*.c)
OBJS = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJS)
	@echo "Linking executable $(TARGET)"
	@if not exist "$(dir $(subst /,\,$(TARGET)))" mkdir $(dir $(subst /,\,$(TARGET)))
	$(CC) $(OBJS) -o $(TARGET) $(INCLUDE) $(CFLAGS)

# Rule to build object files in the build directory
$(OBJDIR)/%.o: src/%.c
	@echo "Compiling $< to $@"
	@if not exist "$(dir $(subst /,\,$@))" mkdir $(dir $(subst /,\,$@))
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS)

# Clean generated files
clean:
	del /Q $(subst /,\,$(OBJS))
	del /Q $(subst /,\,$(TARGET))
	rd /s /q $(OBJDIR)
