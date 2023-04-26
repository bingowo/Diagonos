#include <stdio.h>
#include <string.h>
typedef struct{double a;int b;int up;int low;}P;

int cmp(const void*x,const void*y)
{
    P*px=(P*)x;
    P*py=(P*)y;
    if(px->a == py->a){return py->b - px->b;}
    else {return ((px->a)-(py->a))>0?-1:1;}
}
int main()
{
    int T,i;
    scanf("%d",&T);
    char s[105];
    P p[26];
    while(T--)
    {
        for(i=0;i<26;i++)
        {
            p[i].b=i+1;
            p[i].up=0;
            p[i].low=0;
            scanf("%lf",&p[i].a);
        }
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]<'a'){p[s[i]-'A'].up++;}
            else{p[s[i]-'a'].low++;}
        }
        /*for(i=0;i<26;i++)
        {
            printf("%d %d\n",i,p[i].low);
        }*/
        qsort(p,26,sizeof(P),cmp);
        for(i=0;i<26;i++)
        {
            while(p[i].low--)
            {
                printf("%c",p[i].b+96);
            }
            while(p[i].up--)
            {
                printf("%c",p[i].b+64);
            }
        }
        printf("\n");
    }
    return 0;
}
