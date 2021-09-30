Clang=g++
ReleaseFlags=-O2 -w -std=gnu++17
CodeQLFlags=-O0 -g -Wall -Wextra -Werror -std=gnu++17

default: Release

Release: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Contact.link ContactSystem/Contact.cpp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/GroupContact.link ContactSystem/GroupContact.cpp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/ContactBook.link ContactSystem/ContactBook.cpp
	@$(Clang) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	@rm -rf BuildTemp/ && mkdir BuildTemp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/Contact.link ContactSystem/Contact.cpp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/GroupContact.link ContactSystem/GroupContact.cpp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/ContactBook.link ContactSystem/ContactBook.cpp
	@$(Clang) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.link MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
