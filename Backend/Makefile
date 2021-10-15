Compiler=clang++
ReleaseFlags=-O2 -w -pthread -std=gnu++17
CodeQLFlags=-O0 -g -Wall -Wextra -Werror -pthread -std=gnu++17

default: Release

Release:
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Compiler) $(ReleaseFlags) -c -o BuildTemp/Books.o ContactSystem/Books.cpp
	@$(Compiler) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.o MainExecutable/MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL:
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Compiler) $(CodeQLFlags) -c -o BuildTemp/Books.o ContactSystem/Books.cpp
	@$(Compiler) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.o MainExecutable/MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
