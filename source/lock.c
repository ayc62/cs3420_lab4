#include "lock.h"

void l_init (lock_t* l) {
    // pee pee poo poo
    l->lock_status=0;
    l->blocked_processes=NULL;
}

void l_lock (lock_t* l) {
    
}

void l_unlock (lock_t* l) {

}