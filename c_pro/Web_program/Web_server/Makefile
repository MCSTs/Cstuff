src = $(wildcard ./*.c)
obj = $(patsubst %.c, ./Object/%.o, $(src))

ALL : Server

Server : $(obj)
	cc -o $@ $^


./Object/%.o : %.c
	cc -o $@ $< -c

clean :
	@-rm $(obj) -f

.PHONY : ALL clean
