#Generic info

cc := gcc
flags := -Wall -Wextra -W -O1 -Werror 

rm := rm -rf

final := test

src := $(wildcard *.c)
obj := $(src:.c=.o)

$(final): $(obj)
	$(cc) $(flags) $^ -o $@

.PHONY: clean
clean:
	$(rm) $(obj) $(final)
