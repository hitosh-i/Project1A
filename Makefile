CC=gcc
CFLAGS=-pthread -Wall

all: phase1 phase2 phase3 phase4

phase1: src/phase1_threads.c
	$(CC) $(CFLAGS) -o phase1 src/phase1_threads.c

phase2: src/phase2_mutex.c
	$(CC) $(CFLAGS) -o phase2 src/phase2_mutex.c

phase3: src/phase3_deadlock.c
	$(CC) $(CFLAGS) -o phase3 src/phase3_deadlock.c

phase4: src/phase4_resolution.c
	$(CC) $(CFLAGS) -o phase4 src/phase4_resolution.c

clean:
	rm -f phase1 phase2 phase3 phase4
