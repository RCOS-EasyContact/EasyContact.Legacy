default: Release

Release: *.h
  g++ -O2 -w -o EasyContact.so

CodeQL: *.h
  g++ -O0 -g -Wall -Wextra -Werror -o CodeQL.so *.h

Clean:
  rm -f *.so
 
