src = $(wildcard ./*.c)
tar = $(patsubst %.c, %, $(src))

ALL : $(tar)

% : %.c
	cc -o $@ $< -Wall

clean :
	-rm $(tar)

.PHONY : ALL clean
