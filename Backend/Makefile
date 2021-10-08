Clang=g++
ReleaseFlags=-O2 -w -pthread -std=gnu++17
CodeQLFlags=-O0 -g -Wall -Wextra -Werror -pthread -std=gnu++17

default: Release

Release: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Books.o ContactSystem/Books.cpp
	@$(Clang) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.o MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/Books.o ContactSystem/Books.cpp
	@$(Clang) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.o MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
