(CC)=clang



build: main.c ./src/stkalc.c ./src/inputs.c ./src/stack.c | bin
	@echo ""
	$(CC) -g *.c ./src/*.c -o ./bin/stkalc.out
	@echo "Application built successfuly.\n"

run:
	@echo ""
	./bin/stkalc.out
	@echo ""

bin:
	mkdir -p bin


# Test

test: build_test run_test clean_test

build_test: main.c ./src/stkalc.c ./src/inputs.c ./src/stack.c
	@$(CC) -g *.c ./src/*.c -o test.out

run_test:
	@echo ""
	./test.out
	@echo ""

clean_test:
	@rm test.out
