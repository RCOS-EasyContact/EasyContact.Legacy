Clang=g++
ReleaseFlags=-O2 -w -std=gnu++17
CodeQLFlags=-O0 -g -Wall -Wextra -Werror -std=gnu++17

default: Release

Release: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Tags.link ContactSystem/Tags.cpp
	@$(Clang) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Tags.link ContactSystem/Tags.cpp
	@$(Clang) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
