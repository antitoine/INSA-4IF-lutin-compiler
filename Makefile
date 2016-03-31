all: cible

cible:
	if test ! -d build; then mkdir build; fi
	if test ! -f lib/re2/libre2.a; then make -C lib/re2; fi
	(cd build && cmake ..) && make -C build/

test: cible
	(cd tests && ./mktest.sh)

clean:
	rm -rf build tests/lut tests/*.csv
