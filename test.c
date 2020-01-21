#include "handler.h"

void dummy_routine(void);

void* foo1(void*)
{
    printf("foo1 was notified!");
}

void* foo2(void*)
{
    printf("foo2 was notified!");
}

void* foo3(void*)
{
    printf("foo3 was notified!");
}

void* foo4(void*)
{
    printf("foo4 was notified!");
}

int main(void)
{
    handler_resgister_CB(ev1,foo1);
    handler_resgister_CB(ev2,foo2);
    handler_resgister_CB(ev1,foo3);
    handler_resgister_CB(ev2,foo4);
    
    dummy_routine();
    
    return 0;
}


void dummy_routine(void)
{
    char user_input = 0;
    bool end_FLG = false;

    do{
        switch(){
            case 'a':
                handler_process_event(ev1);
                break;
            case 'b':
                handler_process_event(ev2);
                break;
            case 'e':
                end_FLG = true;
                break;
            default:
                break;
       } 
    }while(!end_FLG);
}