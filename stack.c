#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STACK_SIZE 100
#define CYCLES 100

struct Stack{
  int data;
};


void push(int data, struct Stack **stack_pointer) {
  (*stack_pointer)->data = data;
  ++(*stack_pointer);
}

int pop(struct Stack **stack_pointer){
  --(*stack_pointer);
  int data = (*stack_pointer)->data;
  return data;
}

int main(int argc, char const *argv[]) {  
  struct Stack *base_pointer = (struct Stack*) malloc(sizeof(struct Stack) * STACK_SIZE);
  struct Stack *stack_pointer;
  stack_pointer = base_pointer;


  //////////////////////////////////////////////////////////////////////////////
  //  TEST ENVIRONMENT
  //////////////////////////////////////////////////////////////////////////////
  srand(time(NULL));
  for(size_t i = CYCLES; i != 0; i--)
  {
    int data = (rand() % 4);
    printf("PUSH:\t%d\n", data);
    push(data, &stack_pointer);
  }

  for(size_t i = CYCLES; i != 0; i--)
  {
    int data = pop(&stack_pointer);
    printf("POP:\t%d\n", data);
  }

  free(base_pointer);
  return 0;
}
