MAKE := make

win64:
	$(MAKE) -f makefile.win64

win32:
	$(MAKE) -f makefile.win32

	
clean:
	$(MAKE) -f makefile.win32 clean
	$(MAKE) -f makefile.win64 clean
