#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <threads.h>
#include <stdatomic.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

atomic_int counter = 0;

enum {MAX_ITER = 1000};

void *printHello(void *thr_id) {
    long tid;
    tid = (long)thr_id;
    printf("thread %ld started incrementing ID - %lu\n", tid, thrd_current());

    for (int i = 0; i < MAX_ITER; ++i) {
        counter += 1;
    }

    return NULL;
}

int main(int argc, char const *argv[]) {
    thrd_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = thrd_create(&threads[t], (thrd_start_t) printHello, (void *)t);
        if (rc == thrd_error) {
            printf("ERORR; thrd_create() call failed\n");
            exit(EXIT_FAILURE);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        thrd_join(threads[t], NULL);
    }
    printf("count = %d\n", counter);

    thrd_exit(EXIT_SUCCESS);
}
