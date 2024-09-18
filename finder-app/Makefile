CC = $(CROSS_COMPILE)gcc

writer: writer.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $^

.PHONY: clean
clean:
	rm -f writer *.o
