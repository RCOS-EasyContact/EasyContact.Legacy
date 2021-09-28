default: Release

Release: MainExecutable.cpp
	mkdir BuildTemp
	g++ -O2 -w -c -o BuildTemp/Contact.CXXLink ContactSystem/Contact.cpp
	g++ -O2 -w -c -o BuildTemp/GroupContact.CXXLink ContactSystem/GroupContact.cpp
	g++ -O2 -w -c -o BuildTemp/ContactBook.CXXLink ContactSystem/ContactBook.cpp
	g++ -O2 -w -o EasyContact.so BuildTemp/*.CXXLink MainExecutable.cpp
	rm -rf BuildTemp/

CodeQL: MainExecutable.cpp
	mkdir BuildTemp
	g++ -O0 -g -Wall -Wextra -Werror -c -o BuildTemp/Contact.CXXLink ContactSystem/Contact.cpp
	g++ -O0 -g -Wall -Wextra -Werror -c -o BuildTemp/GroupContact.CXXLink ContactSystem/GroupContact.cpp
	g++ -O0 -g -Wall -Wextra -Werror -c -o BuildTemp/GroupContact.CXXLink ContactSystem/ContactBook.cpp
	g++ -O0 -g -Wall -Wextra -Werror -o CodeQL-Main.so BuildTemp/*.CXXLink MainExecutable.cpp
	rm -rf BuildTemp/

Clean:
	rm -rf BuildTemp/
	rm -f EasyContact.so
	rm -f CodeQL-Main.so