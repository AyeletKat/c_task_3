# Flags and commands
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean
#make all = make both our exe files
all: StrList

StrList: main.o libmy.a
	gcc $(CFLAGS) $^ -o $@

libmy.a: StrList.o
	ar $(AFLAGS) $@ $<

main.o: main.c StrList.h
	gcc $(CFLAGS) -c $<

StrList.o: StrList.c StrList.h
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o *.a StrList