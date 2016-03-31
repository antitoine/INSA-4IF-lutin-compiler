all: cible

lib/re2/libre2.a: lib/re2
	@echo "Making the lib re2 before build projet ..."
	@make -C lib/re2
	@echo "Lib re2 is done."

cible: lib/re2/libre2.a
	@if test ! -d build; then mkdir build; fi
	@(cd build && cmake ..) && make -C build/

test: cible
	@(cd tests && ./mktest.sh)

clean:
	@rm -rf build tests/lut tests/*.csv
