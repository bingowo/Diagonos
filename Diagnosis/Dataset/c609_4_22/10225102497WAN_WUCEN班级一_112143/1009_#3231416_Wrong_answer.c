#include <stdio.h>
#include <stdlib.h>

int pick(int a,int i)
{int b;
    b=(a&(~(~0<<i)&(~0<<i-1)))>>(i-1);
    return b;
}

int main()
{
    int i=0,j=0,k=0,T=0,sum=0,n=0;
    char **read;
    scanf("%d",&T);getchar();
    read=malloc(10*sizeof(char*));
    for(i=0;i<T;i++)
        {*(read+i)=malloc(240*sizeof(char));
        gets(*(read+i));}
    for(i=0;i<T;i++)
        {for(j=0;*(*(read+i)+j)!='\0';j++)
            {for(k=1;k<9;k++)
            if(pick(*(*(read+i)+j),k))sum++;
            if(*(*(read+i)+j+1)=='\0')
            {   n=8*(j+1);
                while(!(sum%2)){sum/=2;n/=2;}
                while(!(sum%3)){sum/=3;n/=3;}
                while(!(sum%5)){sum/=5;n/=5;}
                while(!(sum%7)){sum/=7;n/=7;}
            }
            }
        printf("%d/%d\n",sum,n);sum=0;}
}
