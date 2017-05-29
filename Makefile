all:
	cd src; qmake; make
	cd test; qmake; make

clean:
	cd src; qmake; make clean
	cd test; qmake; make clean
	rm src/Makefile
	rm test/Makefile
	rm lib/*.a
	rm -f bin/CQPaint
