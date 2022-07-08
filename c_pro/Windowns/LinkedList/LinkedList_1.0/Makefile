src = $(wildcard ./*.c)
obj = $(patsubst ./%.c, ./object/%.o, $(src))

ALL : Result

Result : $(obj)
	cc -o $@ $^

./object/%.o : ./%.c
	cc -o $@ -c $< -Wall

clean :
	-rm -f $(obj)

.PHONY : ALL clean

