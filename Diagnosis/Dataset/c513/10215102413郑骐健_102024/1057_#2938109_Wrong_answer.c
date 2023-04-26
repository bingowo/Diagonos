#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct alb
{
    char a;
    struct alb* next;
    struct alb*la;
};



int main()
{
    char c;
    struct alb *p1;
    p1 =NULL;
    struct alb* last;
    while((c = getchar())!='\n')
    {
        if(c <='z')
        {
            c+='A'-'a';
        }
        if(p1 ==NULL)
        {
            p1 = (struct alb*)malloc(sizeof(struct alb*));
            p1->a = c;
            last = p1;
        }
        else
        {
            if(c>(p1->a))
            {
                struct alb*p2 = p1;
                p1 =  (struct alb*)malloc(sizeof(struct alb*));
                p1 ->a =c;
                p1-> next = p2;
                p2->la = p1;
            }
            else
            {
                last ->next = (struct alb*)malloc(sizeof(struct alb*));
                last->next->a =c ;
                last->next->la=last;
                last = last->next;
            }
        }
    }
    last ->next =NULL;
    struct alb*p3 =p1;
    while(p3 != NULL)
    {
        printf("%c",p3->a);
        p3 =p3->next;
    }
    struct alb*p4 =last;
    while(p4!=p1)
    {
        struct alb*p5 = p4;
        free(p5);
        p4 = p4->la;
    }
    free(p1);
    return 0;
}

