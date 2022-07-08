src = $(wildcard ./*.c)
obj = $(patsubst ./%.c, ./object/%.o, $(src))

ALL : main

main : $(obj)
	cc -o $@ $^

./object/%.o : ./%.c
	cc -o $@ -c $< -Wall -g

clean :
	-rm -f $(obj)

.PHONY : ALL clean
