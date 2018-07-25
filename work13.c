/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Example
Given -21->10->4->5, tail connects to node index 1£¬return node 10
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

struct linked_list
{
    int node;
    struct linked_list *next;

};

void creatlist(struct linked_list **headp, int *p, int x);
void getlist();
int getcyclehead();

int a[N], x, n, iscycle = 1;


int main()
{
    struct linked_list *head = NULL, *p;

    getlist();
    creatlist(&head, a, x);

    int t;
    t = getcyclehead(&head);
    if(t == -1) printf("\nnull");
    else printf("\nThe cycle start from:%d", t);


    return 0;
}


int getcyclehead(struct linked_list **headp)
{
    struct linked_list *tag[N], *p;
    int i, j;
    p = *headp;
    for(i = 0 ; i < N && p ;i++)
    {
        tag[i] = p;
        p = p -> next;
        for(j = 0 ; j < i ; j++)
        {
            if(tag[j] == tag[i]) return j;
        }
    }
    return -1;
}


void creatlist(struct linked_list **headp, int *p, int x)
{
    struct linked_list *loc_head = NULL, *tail, *cycle_head;
    loc_head = (struct linked_list *)malloc( sizeof(struct linked_list));
    loc_head -> node = *p;
    tail = loc_head;
    int i;
    for(i = 1 ; i < n ; i++)
    {
        tail -> next = (struct linked_list *)malloc( sizeof(struct linked_list));
        tail = tail -> next;
        tail -> node = a[i];
    }
   *headp = loc_head;

   if(iscycle)
   {
       cycle_head = loc_head;
       for(i = 0 ; i < x ; i++) cycle_head = cycle_head -> next;

       tail -> next = cycle_head ;
   }

   else tail -> next = NULL ;


    return;
}

void getlist()
{
    int i;char c, y;
    printf("Input your linked list ending with \"\\n\"( example:11->2->33->4->55->6\"\\n\"):\n");
    for(i = 0 ; i < N ; i++ )
    {
        scanf("%d-" , &a[i] );
        if( (c = getchar()) == '\n') break;
    }
    n = i + 1;
    printf("\n");
    printf("If your want to create a cycle, input the node index that tail connect to.\nIf not, input \"F\":\n");
    scanf("%c", &y);
    if(y == 'F') iscycle = 0;
    else x = y - '0';


}

