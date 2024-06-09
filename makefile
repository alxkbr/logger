.PHONY: all build app test clean

OUTDIR = build

APP_SRC = logger.cpp appl.cpp
APP_FLAGS = -std=c++2a -O0 -g3 -I.

GTEST_SRC = logger.cpp test.cpp
GTEST_IDIR = googletest-1.14.0/googletest/include
GTEST_LDIR = googletest-1.14.0/build/lib

all: build
build: app
app:
	@g++ $(APP_SRC) $(FLAGS) -o appl
	@rm -rf *.o
	@./appl

test:
	@g++ $(GTEST_SRC) -I$(GTEST_IDIR) -I. -o test -L$(GTEST_LDIR) -lgtest -pthread
	@rm -rf *.o
	@./test

clean:
	rm -rf appl
	rm -rf test