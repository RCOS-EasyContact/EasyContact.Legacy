default: Release

Release: MainExecutable.cpp
	g++ -O2 -w -o EasyContact.so MainExecutable.cpp

CodeQL: ContactSystem/*.h SignalHandler.h MainExecutable.cpp
	g++ -O0 -g -Wall -Wextra -Werror -o CodeQL-Main.so MainExecutable.cpp

Clean:
	rm -f *.so
