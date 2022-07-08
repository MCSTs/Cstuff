src = $(wildcard *.c)
tar = $(patsubst %.c, %, $(src))

ALL : $(tar)

% : %.c
	cc -o $@ $<

clean :
	-rm -f $(tar)

.PHONY : ALL clean
