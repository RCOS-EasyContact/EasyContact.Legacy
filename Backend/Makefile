Clang=g++
ReleaseFlags=-O2 -w
CodeQLFlags=-O0 -g -Wall -Wextra -Werror

default: Release

Release: MainExecutable.cpp
	@mkdir BuildTemp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/Contact.CXXLink ContactSystem/Contact.cpp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/GroupContact.CXXLink ContactSystem/GroupContact.cpp
	@$(Clang) $(ReleaseFlags) -c -o BuildTemp/ContactBook.CXXLink ContactSystem/ContactBook.cpp
	@$(Clang) $(ReleaseFlags) -o EasyContact.so BuildTemp/*.CXXLink MainExecutable.cpp
	@rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	@mkdir BuildTemp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/Contact.CXXLink ContactSystem/Contact.cpp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/GroupContact.CXXLink ContactSystem/GroupContact.cpp
	@$(Clang) $(CodeQLFlags) -c -o BuildTemp/ContactBook.CXXLink ContactSystem/ContactBook.cpp
	@$(Clang) $(CodeQLFlags) -o CodeQL-Main.so BuildTemp/*.CXXLink MainExecutable.cpp
	@rm -rf BuildTemp/

Clean:
	@rm -rf BuildTemp/ || true
	@rm -f EasyContact.so || true
	@rm -f CodeQL-Main.so || true
