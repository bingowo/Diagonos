#include <stdio.h>
#include <stdlib.h>

void jisuan(int h)
{
    int p[9];memset(p,0,sizeof(int)*9);
    int i=0,k=0;
    for(i=8;i>=0;i--)scanf("%d",&p[i]);
    printf("case #%d:\n",h);
    for(i=8;i>=0;i--)
    {
        if(p[i]==0 && i!=0)continue;
        if(p[i]==0 && i==0){if(k==0)printf("0");}
        if(p[i]!=0)
        {
            if(p[i]==1)
            {if(i==0){if(k==0)printf("1");if(k>0)printf("+1");k++;}
             else if(i==1){if(k==0)printf("x");if(k>0)printf("+x");k++;}
            else{if(k==0)printf("x^%d",i);if(k>0)printf("+x^%d",i);k++;}}
            else if(p[i]==-1)
            {if(i==0){if(k==0)printf("-1");if(k>0)printf("-1");k++;}
            else if(i==1){printf("-x");k++;}
            else{printf("-x^%d",i);k++;}}
            else if(p[i]>0)
            {if(i==0){if(k==0)printf("%d",p[0]);if(k>0)printf("+%d",p[0]);k++;}
            else if(i==1){if(k==0)printf("%d""x",p[i]);if(k>0)printf("+%d""x",p[i]);k++;}
            else{if(k==0)printf("%d""x^%d",p[i],i);if(k>0)printf("+%d""x^%d",p[i],i);k++;}}
            else if(p[i]<0)
            {if(i==0){if(k==0)printf("%d",p[0]);if(k>0)printf("%d",p[0]);k++;}
            else if(i==1){printf("%d""x",p[i]);k++;}
            else{printf("%d""x^%d",p[i],i);k++;}}
        }

    }
    printf("\n");

}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
