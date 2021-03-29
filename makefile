IDIR =headers
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lgtest -lpthread

_DEPS = romanos.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romanos.o testa_romanos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runTests: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean lint

lint:
	for f in $$(find . -type f); do  \
		if [ "$$(echo "$${f##*.}")" = "cpp" ] \
			|| [ "$$(echo "$${f##*.}")" = "hpp" ] \
			|| [ "$$(echo "$${f##*.}")" = "h" ]; \
		then \
			cpplint $$f; \
		fi \
	done

check:
	cppcheck --enable=warning .

valgrind: runTests
	valgrind --leak-check=full ./runTests

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 