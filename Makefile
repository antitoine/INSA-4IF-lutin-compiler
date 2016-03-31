all: cible

cible:
	if test ! -d build; then mkdir build; fi
	(cd build && cmake ..) && make -C build/

test: cible
	(cd tests && ./mktest.sh)

clean:
	rm -rf build tests/lut tests/*.csv
