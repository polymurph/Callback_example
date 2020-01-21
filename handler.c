#include <stdbool.h>
#include "handler.h"

// defines the max number of clients that can be registerd
enum{
    n_ev1 = 2,
    n_ev2 = 2
}

static callback_t ev1_clients[n_ev1] = {};
static callback_t ev2_clients[n_ev1] = {};



void _notify()
{

}

void handler_process_event(event_t event)
{

}


// returns -1 if failed to register client
// if successfull: returns id
int handler_resgister_CB(event_t ev, callback_t client)
{
    
}