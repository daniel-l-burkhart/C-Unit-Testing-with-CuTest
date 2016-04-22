SHELL := /bin/bash

CC=gcc
CFLAGS=-Wall -g
SOURCES=parse_utils.c
HEADERS=parse_utils.h
TEST_SOURCES=test_find_parens_depth.c

tests: $(SOURCES) $(TEST_SOURCES) $(HEADERS)
	# ensure the make-tests.sh script is executable	
	chmod a+x make-tests.sh
	# use make-tests to extract all test methods and put them into AllTests.c (which should contain main()).
	./make-tests.sh > AllTests.c
	# compile all the test methods into an executable (named AllTests) that will run them
	$(CC) $(CFLAGS) -o AllTests  AllTests.c CuTest.c $(SOURCES) $(TEST_SOURCES)
	# actually run the tests.  AllTests will report failures and successes for each test.
	./AllTests

clean:
	rm -f AllTests AllTests.c

