#include <stdint.h>
#include <stddef.h>
#include "assert.h"


typedef struct {

 int8_t top;   /*index position of top*/
 uint32_t capacity;  /* capacity of the stack*/
 uint8_t * element;  /*pointer to memory*/


}Stack_t;

typedef enum{

    NO_ERROR=0,            /*No error*/
    MEMORY_ERROR,       /*System doesn't have enough memory*/
    UNDEFINED_ERROR,    /*Undefined error has poped up*/
    STACK_FULL,
    STACK_EMPTY,

}Std_error_t;


uint8_t StackCreate(Stack_t* Stack,uint32_t capacity);                     /*Create the stack of required size*/
uint8_t GetStackSize(Stack_t* Stack,uint32_t* capacity);    /*Get current stack size*/
uint8_t GetStackCapacity(Stack_t* Stack,uint32_t* capacity); /*get maximum size of stack*/
uint8_t DoubleStackSize(Stack_t* Stack);                    /*Double the size of stack*/
uint8_t StackPop(Stack_t* Stack,uint8_t *data);             /*Pop from stack*/
uint8_t StackPush(Stack_t* Stack,uint8_t  data);            /* Push inside of stack*/
uint8_t StackPeek(Stack_t* Stack,uint8_t *data);              /*See the data at the top of stack*/
