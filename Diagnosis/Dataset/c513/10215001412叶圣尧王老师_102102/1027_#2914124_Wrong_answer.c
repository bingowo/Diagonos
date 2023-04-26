#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct st 
{
    float x;
    float y;
    float p;
    float q;
};

int main()
{
    int T;scanf("%d",&T);int N,i=0,j;
    while(i<T)
    {
        printf("case #%d\n",&i);
        scanf("%d",&N);struct st s[N];
        for(j=0;j<N;j++)
        {
            scanf("%f%f",&s[j].x,&s[j].y);
            s[j].p=sqrt(s[j].x*s[j].x+s[j].y*s[j].y);
            
        }
        printf("1");
        
        i++;
    }
}