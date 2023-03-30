#include "lock.h"
#include "3140_concur.h"

void l_init(lock_t* l) {
	l->free = 1;
	l->blocked_queue = NULL;
}


void l_lock(lock_t* l){

	NVIC_DisableIRQ(PIT_IRQn); // disable interrupts

	// allow current process to enter critical zone
	// lock the lock
	if(l->free) {
		l->free = 0;

	// mark process as blocked
	} else {
		current_process->is_blocked = 1;
		enqueue(current_process, &(l->blocked_queue));
		process_blocked(); // enables global interrupts
		NVIC_DisableIRQ(PIT_IRQn); // do we need this?
	}

	NVIC_EnableIRQ(PIT_IRQn); // enable interrupts
}


void l_unlock(lock_t* l) {

	NVIC_DisableIRQ(PIT_IRQn); // disable interrupts

	// remove next process from blocked queue
	// unblock next process
	// add next process to the process queue
	if(l->blocked_queue != NULL) {
		process_t* p = dequeue(&(l->blocked_queue));
		p->is_blocked = 0;
		enqueue(p, &process_queue);
	}

	l->free = 1; // free the lock 
	NVIC_EnableIRQ(PIT_IRQn); // enable interrupts
}
