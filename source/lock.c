#include "lock.h"
#include "3140_concur.h"

void l_init(lock_t* l) {
	l->free = 1;
	l->blocked_queue = NULL;
}


void l_lock(lock_t* l){
	NVIC_DisableIRQ(PIT_IRQn);

	if(l->free) {
		l->free = 0;
	} else {
		current_process->is_blocked = 1;
		enqueue(current_process, &(l->blocked_queue));
		process_blocked();
	}

	NVIC_EnableIRQ(PIT_IRQn);
}


void l_unlock(lock_t* l) {
	NVIC_DisableIRQ(PIT_IRQn);

	if(l->blocked_queue != NULL) {
		process_t* p = dequeue(&(l->blocked_queue));
		p->is_blocked = 0;
		l->free = 0;
	} else{
		l->free = 1;
	}

	NVIC_EnableIRQ(PIT_IRQn);
}
