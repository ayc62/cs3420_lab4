#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 */
struct process_state {
	unsigned int* sp;
	unsigned int* original_sp;
	int size;
	struct process_state* next;
	int blocked; // 0 if unblocked, 1 if blocked
};

/**
 * This defines the lock structure
 */
typedef struct lock_state {

	// 0 if owned by a process, 1 if available
	int lock_status;

	// list of blocked processes
	process_t* blocked_processes;
	
} lock_t;


#endif
