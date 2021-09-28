default: Release

Release: MainExecutable.cpp
	g++ -O2 -w -c -o Contact.link ContactSystem/Contact.cpp
	g++ -O2 -w -c -o GroupContact.link ContactSystem/GroupContact.cpp
	g++ -O2 -w -o EasyContact.so *.link MainExecutable.cpp

CodeQL: ContactSystem/*.h SignalHandler.h MainExecutable.cpp
	g++ -O0 -g -Wall -Wextra -Werror -c -o Contact.link ContactSystem/Contact.cpp
	g++ -O0 -g -Wall -Wextra -Werror -c -o GroupContact.link ContactSystem/GroupContact.cpp
	g++ -O0 -g -Wall -Wextra -Werror -o CodeQL-Main.so *.link MainExecutable.cpp

Clean:
	rm -f *.link
