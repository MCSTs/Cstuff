src = $(wildcard ./*.c)
tar = $(patsubst %.c, %, $(src))

ALL : $(tar)

% : %.c
	cc -o $@ $<

clean :
	-rm $(tar)

.PHONY : ALL clean
