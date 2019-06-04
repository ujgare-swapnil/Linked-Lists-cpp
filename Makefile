src+=list.cpp singly_list.cpp
EXTRA_CFLAGS+=-I$(PWD)
EXTRA_CFLAGS+=-L$(PWD)
utility = test_utility
LIBS+=-llist
src+=$(subst .o,.c,${objs})
all:
	g++ -g -Wall -fPIC -c ${src} ${EXTRA_CFLAGS}
	g++ -shared  -fPIC ${EXTRA_CFLAGS} *.o -o liblist.so
util:
	g++ main.cpp -g -o ${utility} ${EXTRA_CFLAGS} ${LIBS}
.PHONY: clean
clean:
	rm *.o *.so
clean_util:
	rm ${utility}
