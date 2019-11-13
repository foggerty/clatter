# I'm going with gcc for nostalgic reasons, and std=gnu99 for "argh
# this is a pain to make work" reasons.  i.e. No guarantee that the
# POSIX extensions I'm using - getline() - will be brought in
# otherwise.

CC = gcc
CFLAGS = -Wall -Wextra -std=gnu99

themes = $(wildcard themes/*.c) \
         $(wildcard themes/*.h)

clatter: clatter.c clatter.h $(themes)

clean:
	rm -f clatter
