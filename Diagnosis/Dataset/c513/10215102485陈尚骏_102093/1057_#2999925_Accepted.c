#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct Node{
    char c;
    struct Node *next;
}Node,*Tree;

int main()
{
    Tree tree=malloc(sizeof(Node));
    Tree end=malloc(sizeof(Node));
    end->c=toupper(getchar());
    end->next=NULL;
    tree->next=end;
    char c;
    while((c=getchar())!='\n')
    {
        c=toupper(c);
        Tree temp=malloc(sizeof(Node));
        temp->c=c;
        if(temp->c>=tree->next->c)
        {
            temp->next=tree->next;
            tree->next=temp;
        }
        else
        {
            end->next=temp;
            temp->next=NULL;
            end=temp;
        }
    }
    Tree p=tree->next;
    while(p)
    {
        printf("%c",p->c);
        p=p->next;
    }
    printf("\n");
    return 0;
}
