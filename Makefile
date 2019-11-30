# I'm going with gcc for nostalgic reasons, and std=gnu99 for "argh
# this is a pain to make work" reasons.  i.e. No guarantee that the
# POSIX extensions I'm using - getline() - will be brought in
# otherwise.

CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -lncurses

themes = $(wildcard themes/*.c) \
         $(wildcard themes/*.h)

curseu = curseu.h curseu.c

# Just a note to self: in a bigger project, would output .o files for
# most input files, for faster recompilation.  This comiles sub-second
# on my laptop, so not really worth setting up :-)

clatter: clatter.h clatter.c $(themes) $(curseu)

# ToDo - over-engineer this, i.e. have curseu and the themes compiled
# and save the .o files for incremental compile.

clean:
	rm -f clatter
