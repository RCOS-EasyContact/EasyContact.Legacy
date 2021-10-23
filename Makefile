Compiler=clang++
ReleaseFlags=-O2 -w -pthread -std=gnu++17
FullCheckingFlags=-O0 -g -Wall -Wextra -Werror -pthread -std=gnu++17

default: Release

Release:
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Compiler) $(FullCheckingFlags) -c -o BuildTemp/Books.o Backend/ContactSystem/Books.cpp
	@$(Compiler) $(FullCheckingFlags) -c -o BuildTemp/CSVReadWrite.o Backend/DiskRW/CSVReadWrite.cpp
	@$(Compiler) $(FullCheckingFlags) -c -o BuildTemp/DatabaseReadWrite.o Backend/DiskRW/DatabaseReadWrite.cpp
	@$(Compiler) $(FullCheckingFlags) -o Executable/EasyContact.so BuildTemp/*.o Backend/Executable/Main.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
