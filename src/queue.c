#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
        if (q == NULL)
                return 1;
        return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
        /* TODO: put a new process to queue [q] */
        // Kiem tra dieu kien hang doi full
        if (q == NULL || proc == NULL ||
            q->size >= MAX_QUEUE_SIZE)
                return;

        q->proc[q->size] = proc; // Them proc vao queue
        q->size++;                // Tang so proc
}

struct pcb_t *dequeue(struct queue_t *q)
{
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (q == NULL || q->size == 0)
                return NULL;

        struct pcb_t *proc = q->proc[0]; // Lay proc dau tien trong queue

        // Doi cac proc trong hang doi len 
        for (int i = 1; i < q->size; i++)
        {
                q->proc[i - 1] = q->proc[i];
        }

        q->size--;
        return proc;
}
