#include "3140_concur.h"
#include <stdlib.h>
#include <MKL46Z4.h>
#include "shared_structs.h"


process_t* process_queue = NULL;
process_t* current_process = NULL;

// add process p at the end of the process queue
void enqueue(process_t* p, process_t** queue) {
	process_t* tmp;

	if(*queue == NULL) {
		(*queue) = p;
		p->next = NULL;
	}
	else {
		tmp = (*queue);
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = p;
		p->next = NULL;
	}
}

// removes the first element from the queue, returns a pointer to the removed element.
process_t* dequeue(process_t** queue) {
	process_t* first;

	first = (*queue);

	if(*queue != NULL){
		(*queue) = (*queue)->next;
	}

	return first;
}



int process_create (void (*f)(void), int n){

	process_t* new_process=malloc(sizeof(process_t));

	unsigned int* sp = process_stack_init(f, n);

	// If process stack init successful, set values for process
	if(sp != NULL && new_process != NULL) {
		new_process->original_sp = sp; // set original sp
		new_process->size = n;
		new_process->sp = sp; // set current sp 
		new_process->next = NULL; // set next pointer NULL
		new_process->is_blocked = 0;
		enqueue(new_process, &process_queue); // enqueue new process

		return 0;
	}

	free(sp);
	return -1;

	};



void process_start() {
	
	// Interrupt Handler set up
	NVIC_EnableIRQ(PIT_IRQn);


	// PIT set up
	SIM->SCGC6 = SIM_SCGC6_PIT_MASK;
	//PIT->MCR |= (1<<1);
	PIT->MCR = PIT_MCR_MDIS(0);// Turn on PIT by setting to 0


	// Load value for PIT0
	PIT->CHANNEL[0].LDVAL |= 0x60000;

	// Enable PIT0 interrupts
	//PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN(1);
	PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TIE(1);

	//PIT->MCR &= !(1<<1);

	process_begin();
}

/* Select the next ready process. Return NULL if no process ready.
Return the value of the stack pointer for the next ready process
if process ready. */
unsigned int * process_select (unsigned int * cursp) {

	// dequeue the first process (currently running process) in the queue (which must be cursp if
	//it is not null), and put it at the end of the queue.
	if(cursp != NULL) {	// update current process if cursp not complete
		current_process->sp = cursp;

		// only add process if it's not blocked
		if (!(current_process->is_blocked)) {
			enqueue(current_process, &process_queue);
		}

	// free current process if no process is running
	} else if (cursp == NULL && current_process != NULL){
		process_stack_free(current_process->original_sp, current_process->size);
		free(current_process);
	}


	if(process_queue == NULL) {
		current_process = NULL;
		return NULL;
	} else {
		current_process = dequeue(&process_queue);

		//check if this is a blocked process
		// if(current_process->is_blocked == 1) {
		// 	enqueue(current_process, &process_queue);
		// 	current_process = dequeue(&process_queue);
		// }

		return current_process->sp;
	}
}
