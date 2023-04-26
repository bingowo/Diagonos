#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct num
{
    int cnt;
    int v[501];
}NUM;
NUM CTI(char *a);
void MINUS(NUM a,NUM b);
int main()
{
   int i;
   char c;
   do
   {
       NUM A,B;
       A.cnt=0,B.cnt=0;
       char a[501],b[501];
       scanf("%s",a);
       scanf("%s",b);
       A=CTI(a);
       B=CTI(b);
       MINUS(A,B);
   }while((c=getchar())=='\n');
   return 0;
}
NUM CTI(char *a)
{
    int n=strlen(a)-1;
    NUM res;
    res.cnt=0;
    for(;n>=0;n--)
    {
        res.v[res.cnt++]=a[n]-'0';
    }
    return res;
}
void MINUS(NUM a,NUM b)
{
    NUM R;
    R.cnt=0;
    int i,sign=1;
    if(a.cnt<b.cnt){sign=-1;NUM T=b;b=a;a=T;}
    else if(a.cnt==b.cnt)
    {
        i=a.cnt-1;
        for(;i>=0;i--)
        {
            if(a.v[i]<b.v[i]){sign=-1;NUM T=b;b=a;a=T;break;}
            else if(a.v[i]>b.v[i])break;
        }
    }
    int record=0,t=0;
    for(i=0;i<b.cnt;i++)
    {
        t=a.v[i]-b.v[i]-record;
        if(t<0){t=10+t;R.v[R.cnt++]=t;record=1;}
        else {R.v[R.cnt++]=t;record=0;}
    }//i=b.cnt
    if(i<a.cnt)
    {
        for(i=b.cnt;i<a.cnt;i++)
        {
            t=a.v[i]-record;
            if(t<0){t=10+t;R.v[R.cnt++]=t;record=1;}
            else {R.v[R.cnt++]=t;record=0;}
        }
    }
    i=R.cnt-1;
    while(R.v[i]==0)i--;
    if(i==-1)printf("0\n");
    else
    {
        if(sign==-1)printf("-");
        for(;i>=0;i--)
        {
            printf("%d",R.v[i]);
        }
        printf("\n");
    }

}

