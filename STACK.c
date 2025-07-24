//Implementation of Stack using C
#include <stdio.h>
#define true 1
#define false 0 
#define MAX 5
 
struct STACK
{
    int TOS;
    int data[MAX];
};

int isFull(struct STACK *s)
{
    return (s->TOS == MAX - 1) ? true : false;
}
int isEmpty(struct STACK *s)
{
    return (s->TOS == -1) ? true : false;
}

void push(struct STACK *s, int element)
{
    
        s->data[++s->TOS] = element;
    }
int pop(struct STACK *s)
{
    return s->data[s->TOS--];
}

int peek(struct STACK *s)
{
    return s->data[s->TOS];
}

int main()
{
 int choice ,value;
    struct STACK S={-1};

    do
    {
      printf ("\n1.PUSH\n2.POP\n3.PEEK\n4.EXIT") ; 
      printf("\n>");
      scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (isFull(&S))
                {
                    printf("Stack is full\n");
                }
                else
                {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&S, value);
                    printf("Pushed %d onto stack\n", value);
                }
                break;
            case 2:
                if (isEmpty(&S))
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    value = pop(&S);
                    printf("Popped %d from stack\n", value);
                }
                break;
            case 3:
                if (isEmpty(&S))
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    value = peek(&S);
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!=4);
    printf("Program terminated.\n");
    return 0;
    

}
