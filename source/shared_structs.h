#ifndef __SHARED_STRUCTS_H__
#define __SHARED_STRUCTS_H__

/** Implement your structs here */

/**
 * This structure holds the process structure information
 */
struct process_state {
	unsigned int* sp;
	unsigned int* original_sp;
	unsigned int* size;
	process_t* next;

	//1 if this is a process trying to acquire a lock that is being used by another process
	int is_blocked;
};

/**
 * This defines the lock structure
 */
typedef struct lock_state {
	
	//1 if this lock is free, 0 if not
	int free;
	process_t* blocked_queue;



} lock_t;




#endif
