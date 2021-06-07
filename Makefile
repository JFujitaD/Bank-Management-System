EXECUTABLE_NAME=main

main: main.o bank_manager.o
	gcc build/main.o build/bank_manager.o -o build/main
	@echo "\nExecutable \"$(EXECUTABLE_NAME)\" in build folder.\nRun using \"make run\"."

main.o: main.c
	gcc -c main.c -o build/main.o

bank_manager.o: bank_manager.c
	gcc -c bank_manager.c -o build/bank_manager.o

clean:
	rm build/*.o build/main
	@echo "\nEmptied out build folder."

run:
	./build/$(EXECUTABLE_NAME)