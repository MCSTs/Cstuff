src = $(wildcard ./*.c)
tar = $(patsubst %.c, %, $(src))

ALL : $(tar)

% : %.c
	gcc $< -o $@

clean :
	-rm -rf $(tar)

.PHONY : clean ALL
