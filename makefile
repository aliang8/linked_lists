compile: list.c
	gcc list.c -o list

clean:
	rm *~
	rm *#
run: list
	./list