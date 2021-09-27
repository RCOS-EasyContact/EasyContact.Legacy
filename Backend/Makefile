default: Release

Release: *.h
	g++ -O2 -w -o EasyContact.so MainExecutable.cpp

CodeQL: *.h
	g++ -O0 -g -Wall -Wextra -Werror -o CodeQL-Main.so *.h MainExecutable.cpp

Clean:
	rm -f *.so
