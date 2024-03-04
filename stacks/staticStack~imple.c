
#include <stdio.h>
#include <stdlib.h>
#define size 10
struct Stack{
    int stk[size]; // Array to Implement Stack
    int top; // Index Of Top Of Stack
}S;
//Function to Push an Element into Stack 
void push(int X)
{
    //Checking if Stack is Full
    if(S.top==size-1)
        printf("Stack Overflow\n");
    else
        S.stk[++S.top] = X;
}
//Function to Pop an Element from Stack 
void pop()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("Deleted Element : %d\n",S.stk[S.top]);
        S.top--;
    }
}
//Function to Display the top Element of Stack 
void peek()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
        printf("%d\n",S.stk[S.top]);
}
//Function to Display all Elements of Stack 
void display()
{
    //Checking if Stack is Empty
    if(S.top==-1)
        printf("Stack UnderFlow\n");
    else
    {
        printf("The Stack is :\n");
        for(int i=S.top;i>=0;i--)
            printf("%d\n",S.stk[i]);
    }
}
//Main Function
void main()
{
    int choice,X;
    S.top=-1; //Initailizing Empty Stack
    for(;;)
    {
        printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the value to be pushed : ");
                     scanf("%d",&X);
                     push(X);
                     break;
            case 2 : pop();
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
                     break;
            case 5 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}
