#include <stdbool.h>
#include "handler.h"

// defines the max number of clients that can be registerd per event
typedef enum{
    n_ev1 = 2,
    n_ev2 = 2
}n_event_t;

// arrays which hold the clients for the respective events 
static callback_t ev1_clients[n_ev1] = {};
static callback_t ev2_clients[n_ev1] = {};

// local functions

void _notify();
void _registerCallback(callback_t client, 
                       callback_t client_list[], 
                       n_event_t n_ev);

// interface functions

void handler_process_event(event_t event)
{
    
}


// returns -1 if failed to register client
// if successfull: returns id
int handler_resgister_CB(event_t event, callback_t client)
{
    switch(event){
        case ev_1:
            return _registerCallback(client, ev1_clients, n_ev1);
            break;
        case ev_2:
            return _registerCallback(client, ev2_clients, n_ev2);
            break;
        default:
            // invalid event
            return -1;
            break;
    };

    return (-1);
}

int handler_unregsiter_CB(unsigned int id, event_t event)
{
    switch(event){
        case ev_1:
            return _unregisterCallback(id, ev1_clients, n_ev1);
            break;
        case ev_2:
            return _unregisterCallback(id, ev2_clients, n_ev2);
            break;
        default:
            // invalid event
            return -1;
            break;
    };
}

void _notify(callback_t client_array[], n_event_t n)
{
    int i;
    for(i = 0; i < n; i++){
        // check if entry exists
        if(client_array[i] != 0){
            // execute the callback ("call back to the client!")
            client_array[i]();
        }
    }
}

int  _registerCallback(callback_t client, 
                       callback_t client_list[], 
                       n_event_t n_ev)
{
    int i;
    for(i = 0; i < n_ev; i++){
        // check for free slot
        if(client_list[i] == 0){
            // add new callback
            client_list[i] = client;
            // return i for the client for later deletion of the callback (indexing)
            return i;
        }
    }
    // list is full
    return (-1);
}

int _unregisterCallback(unsigned int id,
                        callback_t client_list[], 
                        n_event_t n_ev)
{
    if(id < n_ev){
        // remove the client callback by setting the function pointer to 0
        client_list[id] = 0;
        return 0;
    }
    return -1;
}