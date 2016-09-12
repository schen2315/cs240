#
# Specifiy the target
all:	Hello

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
Hello:	Chen_Song_Hello.o Hello_Class.o
	g++  Chen_Song_Hello.o Hello_Class.o -o Chen_Song_Hello.exe

# Specify how the object files should be created from source files
Hello.o:	Chen_Song_Hello.cpp Hello_Class.cpp
	g++ -c Hello_Class.cpp Chen_Song_Hello.cpp 

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Chen_Song_Hello.exe

