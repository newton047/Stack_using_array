#include "stack_array.h"


uint8_t StackCreate(Stack_t* Stack,uint32_t capacity)                     /*Create the stack of required size*/
{
    Stack->top = -1;                                     /*current pointer of stack*/
    Stack->capacity =capacity;                            /*Capacity the stack can hold*/
    Stack->element  = calloc(capacity,sizeof(uint8_t));
    if(Stack->element==NULL){
        return MEMORY_ERROR;                               /*Unable to allocate memory*/
    }

    return NO_ERROR;
}


uint8_t GetStackSize(Stack_t* Stack,uint32_t* capacity)    /*Get current stack size*/
{
    assert(Stack!=NULL);                                    /*Asumming a valid stack pointer */
    *capacity = ((Stack->top)+1);
    return NO_ERROR;
}

uint8_t GetStackCapacity(Stack_t* Stack,uint32_t* capacity)    /*Get maximum stack size*/
{
    assert(Stack!=NULL);                                    /*Asumming a valid stack pointer */
    *capacity = (Stack->capacity);
    return NO_ERROR;
}

uint8_t DoubleStackSize(Stack_t* Stack)                   /*Double the size of stack*/
{
    assert(Stack!=NULL);                                    /*Asumming a valid stack pointer */
    Stack->element = realloc(Stack->element,2*Stack->capacity);
    Stack->capacity *=2;
    return NO_ERROR;

}
uint8_t StackPop(Stack_t* Stack,uint8_t *data)             /*Pop from stack*/
{
    assert(Stack!=NULL) ;                                   /*Asumming a valid stack pointer */
    if(Stack->top==-1){                                    /*Stack was empty*/
        return STACK_EMPTY;
    }

    *data = Stack->element[Stack->top--];
    //Stack->top--;
    return NO_ERROR;

}
uint8_t StackPush(Stack_t* Stack,uint8_t  data)           /* Push inside of stack*/
{
    assert(Stack!=NULL) ;                                   /*Asumming a valid stack pointer */

    if((Stack->top)==Stack->capacity-1){
       DoubleStackSize(Stack)  ;                            /*Stack was full*/
    }
    Stack->element[++Stack->top] = data;
    return NO_ERROR ;                                       /*Stack as sucessfully filled*/


}
uint8_t StackPeek(Stack_t* Stack,uint8_t *data)             /*See the data at the top of stack*/
{
    assert(Stack!=NULL) ;                                   /*Asumming a valid stack pointer */

    *data = Stack->element[Stack->top];
    return NO_ERROR;

}
