.PHONY: all
all: clean compile
clean:
	rm -fv -- main
compile: main
#install:
#	install -Dm755 main /usr/bin/aaaaaaaa
#uninstall:
#	rm -fv -- /usr/bin/aaaaaaaa
