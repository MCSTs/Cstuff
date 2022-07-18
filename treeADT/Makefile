src = $(wildcard *.c)
obj = $(patsubst %.c, obj/%.o, $(src))

ALL : main

main : $(obj)
	cc -o $@ $^

obj/%.o : %.c
	cc -o $@ -c $< -Wall -g

clean :
	-rm -f $(obj)

.PHONY : main clean
