#include <stdio.h>
#include <string.h>
typedef struct{double a;int b;int up;int low;}P;

int cmp(const void*x,const void*y)
{
    P*px=(P*)x;
    P*py=(P*)y;
    if(px->a == py->a){return px->b - py->b;}
    else {return ((px->a)-(py->a))>0?-1:1;}
}

int main()
{
    int t=0,T,i;
    scanf("%d",&T);
    char s[105];
    P p[26];
    while(t++<T)
    {
        printf("case #%d:\n",t-1);
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
