#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
 
typedef struct node 
{ 
    struct node *prev; 
     int data; 
    struct node *next; 
}NODE; 
 
typedef struct  
{ 
    int count; 
    NODE *head; 
}LIST; 
 
NODE* createnode(int value) 
{ 
    NODE *n=(NODE *)malloc(sizeof(NODE)); 
      if(n==NULL) 
      { 
        printf("Memory allocation failed\n"); 
        return NULL; 
      } 
    n->prev=NULL; 
    n->data=value; 
    n->next=NULL; 
    return n; 
} 
 
void insert_front(LIST *list,int value) 
{ 
    NODE *n=createnode(value); 
    if(list->head==NULL) 
    { 
        list->head=n; 
        n->next=list->head;//n 
        n->prev=n;//list->head 
    } 
    else 
    { 
       // NODE *temp=list->head; 
        NODE *last=list->head; 
         while (last->next!=list->head) 
         { 
            last=last->next; 
         } 
        n->next=list->head; 
        n->prev=last; 
        list->head=n;  
        last->next=list->head; 
    } 
    list->count++; 
    printf("%d inserted at front\n",value); 
    printf("count=%d\n",list->count); 
    //return n; 
} 
 
void insert_end(LIST *list,int value) 
{ 
   NODE *n=createnode(value); 
   if(list->head==NULL) 
   { 
      list->head=n; 
      n->next=list->head;//n 
      n->prev=n;//list->head 
   } 
   else 
   { 
      NODE *temp=list->head; 
      NODE *last=list->head; 
      while (last->next!=list->head) 
      { 
         last=last->next; 
      } 
      n->next=last->next; 
      last->next=n; 
      n->prev=last; 
      temp->prev=n; 
   } 
   list->count++; 
   printf("%d inserted at back\n",value); 
   printf("count=%d\n",list->count); 
} 
 
void insert_pos(LIST *list,int value,int pos) 
{ 
   if(pos<1 || pos>list->count+1) 
   { 
      printf("Entered invalid pos\n"); 
      return; 
   } 
   NODE *temp=list->head; 
   if(pos==1)//insert at front 
    insert_front(list,value); 
   else if(pos==list->count+1)//insert at last 
    insert_end(list,value); 
   else 
   { 
      NODE *n=createnode(value); 
      for(int i=0;i<pos-2;i++) 
       temp=temp->next; 
      n->next=temp->next; 
      temp->next=n; 
      n->prev=temp; 
      temp->next->prev=n;  
   }  
   list->count++; 
   printf("%d inserted at pos %d\n",value,pos); 
   printf("count=%d\n",list->count); 
} 
 
void delete_front(LIST *list) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
   NODE *last=list->head; 
   NODE *temp=list->head; 
   while (last->next!=list->head) 
   { 
      last=last->next; 
   } 
   if (list->head == list->head->next)  
   { 
        list->head = NULL; 
   }  
   else  
   { 
        list->head = temp->next; 
        last->next = list->head; 
   } 
 
    printf("%d deleted\n", temp->data); 
    free(temp); 
    list->count--; 
    printf("count=%d\n", list->count); 
} 
 
void delete_end(LIST *list) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
  // NODE *temp=list->head; 
   NODE *last=list->head; 
   while (last->next!=list->head) 
   { 
      last=last->next; 
   } 
   if(list->head==list->head->next) 
    list->head=NULL; 
   else 
   {  
    last->prev->next=last->next; 
    list->head->prev=last->prev; 
   } 
   printf("%d deleted\n",last->data); 
   list->count--; 
   printf("count=%d\n",list->count); 
   free(last); 
} 
 
void delete_pos(LIST *list,int pos) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
   if(pos<1 || pos>list->count) 
   { 
      printf("Entered invalid pos\n"); 
      return; 
   } 
   if(pos==1) 
   { 
      delete_front(list); 
   } 
   else 
   { 
      NODE *temp=list->head; 
      for(int i=0;i<pos-1;i++) 
       temp=temp->next; 
     
      temp->prev->next=temp->next; 
      temp->next->prev=temp->prev; 
      printf("%d deleted\n",temp->data); 
      list->count--; 
      printf("count=%d\n",list->count); 
      free(temp);  
   } 
} 
 
void delete_by_key(LIST *list,int key) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
   NODE *temp=list->head; 
   if(temp->data==key) 
    delete_front(list); 
   else 
   { 
      do 
      { 
         temp=temp->next; 
      } while (temp!=list->head && temp->data!=key); 
      if(temp==list->head) 
      { 
         printf("%d is not found\n",key); 
         return; 
      } 
      temp->prev->next=temp->next; 
      temp->next->prev=temp->prev; 
      printf("%d is deleted\n",temp->data); 
      list->count--; 
      printf("count=%d\n",list->count); 
      free(temp); 
   }  
} 
 
void search_by_key(LIST *list,int key) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
   NODE *temp=list->head; 
   int pos=1; 
   if(temp->data==key) 
   { 
      printf("%d found at pos %d\n",key,pos); 
   } 
   else 
   { 
      do 
      { 
         temp=temp->next; 
         pos++; 
      } while (temp!=list->head && temp->data!=key); 
      if(temp==list->head) 
      { 
         printf("%d is not found\n",key); 
         return; 
      } 
      printf("%d is fount at pos %d\n",key,pos); 
   } 
} 
 
void create_order_list(LIST *p,int value) 
{ 
   void display(LIST *); 
    if(p->head==NULL || value <= p->head->data) 
    { 
       insert_front(p,value); 
    } 
    else 
    { 
        NODE *n=createnode(value); 
        NODE *temp=p->head; 
        NODE *prev=NULL; 
        do 
        { 
           prev=temp; 
           temp=temp->next; 
        } while (temp!=p->head && temp->data < n->data); 
       n->next=temp; 
       prev->next=n; 
       n->prev=prev; 
       temp->prev=n; 
       p->count++;  
    } 
    printf("Ordered list:"); 
    display(p); 
} 
 
void reverse(LIST *list) 
{ 
   void display(LIST *); 
   if(list->head==NULL) 
   { 
      printf("NOTHING TO REVERSE\n"); 
      return; 
   } 
   NODE *next=list->head; 
   NODE *temp; 
   do 
   { 
   temp=next->prev; 
   next->prev=next->next; 
   next->next=temp; 
   next=next->prev; 
   }while (next!=list->head); 
   list->head=next->next; 
   printf("REVERSED LIST IS:\n"); 
   display(list); 
} 
 
LIST* create_copy_list(LIST *list) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return NULL; 
   } 
   LIST *newlist=(LIST *)malloc(sizeof(LIST)); 
   newlist->count=0; 
   newlist->head=NULL; 
 
   NODE *cur=list->head; 
   do 
   { 
      insert_end(newlist,cur->data); 
      cur=cur->next; 
   } while (cur!=list->head); 
 
   return newlist; 
} 
 
void display(LIST *list) 
{ 
   if(list->head==NULL) 
   { 
      printf("LIST IS EMPTY\n"); 
      return; 
   } 
   else 
   { 
    NODE *temp=list->head; 
    do 
    { 
      printf("%d ",temp->data); 
      temp=temp->next; 
    } while (temp!=list->head); 
    printf("count=%d\n",list->count); 
   }  
} 
 
void main() 
{ 
    int choice,value,position,key; 
    LIST *list=(LIST *)malloc(sizeof(LIST)); 
    list->count=0; 
    list->head=NULL; 
     
    LIST *p=(LIST *)malloc(sizeof(LIST)); 
    p->head=NULL; 
    p->count=0; 
 
    LIST *copy; 
    do 
    { 
        printf("\n\n1.INSERT AT FRONT\n2.INSERT AT END\n3.INSERT AT 
POS\n4.DELETE FRONT\n5.DELETE REAR\n6.DELETE AT POS\n"); 
        printf("7.DELETE BY KEY\n8.SEARCH BY KEY\n9.CREATE ORDERED 
LIST\n10.REVERSE THE LIST\n11.CREATE THE COPY\n"); 
        printf("12.DISPLAY\n13.EXIT\n"); 
         printf("Enter your choice\n"); 
          scanf("%d",&choice); 
 
         switch (choice) 
         { 
         case 1: 
            printf("Enter the value to insert at front\n"); 
              scanf("%d",&value); 
            insert_front(list,value); 
             break;  
         case 2: 
            printf("Enter the value to insert at end\n"); 
              scanf("%d",&value); 
            insert_end(list,value); 
            break;    
         case 3: 
            printf("Enter the value and pos to be inserted\n"); 
              scanf("%d %d",&value,&position); 
            insert_pos(list,value,position); 
            break;   
         case 4: 
            delete_front(list); 
            break;    
        case 5: 
            delete_end(list); 
            break;    
        case 6: 
            printf("Enter the pos to be deleted\n"); 
              scanf("%d",&position); 
            delete_pos(list,position); 
            break;   
         case 7: 
            printf("Enter the key to be deleted\n"); 
              scanf("%d",&key); 
            delete_by_key(list,key); 
            break;      
        case 8: 
            printf("Enter key to be searched\n"); 
              scanf("%d",&key); 
            search_by_key(list,key); 
            break;      
        case 9: 
            printf("Creating an ordered list\n"); 
            for(; ;) 
            { 
                int value; 
                printf("\nenter -1 to stop or enter value to continue\n"); 
                  scanf("%d",&value); 
                 if(value==-1) 
                  break; 
                 create_order_list(p,value);   
            }    
        case 10: 
             reverse(list); 
             break;    
        case 11: 
             copy=create_copy_list(list); 
             if(copy!=NULL) 
             { 
              printf("\nlist copied succefully\n"); 
              display(copy); 
             }  
             else 
              printf("\nfailed to copy\n"); 
              break;    
         case 12: 
display(list);    
break;  
case 13: 
free(list); 
printf("EXITING FROM THE PROGRAM\n"); 
exit(1);     
default: 
printf("INVALID CHOICE\n"); 
break; 
}  
}while (choice!=13); 
}
