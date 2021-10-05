Clang=g++
ReleaseFlags=-O2 -w -pthread -std=gnu++17
CodeQLFlags=-O0 -g -Wall -Wextra -Werror -pthread -std=gnu++17

default: Release

Release: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Tags.link ContactSystem/Tags.cpp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Book.link ContactSystem/Book.cpp
	@$(Clang) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/Tags.link ContactSystem/Tags.cpp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/Book.link ContactSystem/Book.cpp
	@$(Clang) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
