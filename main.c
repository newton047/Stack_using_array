#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"
#include <assert.h>



void print_array(uint8_t* arr,uint8_t len) {
    printf("\n");
    for(int i=0;i<len;i++){


        printf("%d ",arr[i]);
    }


}
int main()
{
    volatile Stack_t stack;
    uint8_t status;
    uint32_t capacity=7;
    uint8_t data;
    status = StackCreate(&stack,capacity);

    for(int i=0;i<=2*capacity;i++){

        StackPush(&stack,i*5);


    }

    printf("\n%d",stack.capacity);
    status = StackPeek(&stack,&data);
    printf("\n%d",data);

    for(int i=0;i<=2*capacity;i++){
        StackPop(&stack,&data);
        printf("\nPopped element is %d",data);
    }

    if(stack.top==-1){

        printf("\nStack was empty");
    }
    else
    {
        printf("\n Stack was not empty");
    }
    return 0;
}
