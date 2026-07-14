# Makefile for the DSA Lab Workbook
# Usage:
#   make          - compile every program in its own folder
#   make run      - run each compiled program with its sample input
#   make clean    - remove all compiled binaries
#   make list     - list every C source file

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11

# Every C source file in the tree (excluding outputs/).
SOURCES := $(shell find . -name '*.c' -not -path './outputs/*')
BINARIES := $(SOURCES:.c=)

.PHONY: all clean run list

all: $(BINARIES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@echo "==> Running each program with sample input. Press Ctrl-C to skip."
	@for bin in $(BINARIES); do \
		echo ""; echo "=============================="; \
		echo "Running $$bin"; \
		echo "=============================="; \
		./$$bin < /dev/null || true; \
	done

clean:
	@for src in $(SOURCES); do \
		bin="$${src%.c}"; \
		if [ -f "$$bin" ]; then \
			echo "rm $$bin"; rm -f "$$bin"; \
		fi; \
	done

list:
	@for s in $(SOURCES); do echo "$$s"; done
