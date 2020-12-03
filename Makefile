SOURCEDIR = src
SOURCEFILES = Game.cpp Player.cpp PlayerController.cpp Animation.cpp main.cpp
HEADERFILES = Game.h Player.h PlayerController.h Animation.h
BINNAME = Game

CC = g++
CCFLAGS = -Wextra -Wall -Werror -pedantic
OPTIMIZE = -O2
CLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY :
	clean
	binclean
	binary
	setup

binary : $(SOURCEFILES) $(HEADERFILES) 
	$(CC) $(CCFLAGS) $(OPTIMIZE) $(SOURCEFILES) $(HEADERFILES) -o $(BINNAME) $(CLIBS)

main.cpp : setup

Game.cpp : setup

Player.cpp : setup

PlayerController.cpp : setup

Animation.cpp : setup

Game.h : setup

Player.h : setup

PlayerController.h : setup

Animation.h : setup

setup :
	cp $(SOURCEDIR)/* .

clean :
	rm -f $(SOURCEFILES) $(HEADERFILES) $(BINNAME)

polish :
	rm -f $(SOURCEFILES) $(HEADERFILES)
