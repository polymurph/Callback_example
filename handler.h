#ifndef _HANDLER_H_
#define _HANDLER_H_

// callback typedef
typedef void *(*callback_t)(void *);

typedef enum{
    ev1,
    ev2
}event_t;

int handler_process_event(event_t event);

int handler_resgister_CB(event_t event, callback_t client);

int handler_unregsiter_CB(unsigned int id, event_t event);

#endif // _HANDLER_H_