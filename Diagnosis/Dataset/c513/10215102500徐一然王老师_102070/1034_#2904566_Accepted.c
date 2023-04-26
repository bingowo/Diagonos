#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

double A[30];

int cmp(const void *a,const void *b)
{
    char ch1,ch2;  
     int p1,p2;        
    ch1=*((char *)a);
    ch2=*((char *)b);
    if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
    if(ch2>='a'&&ch2<='z') p2=ch2-'a';  else p2=ch2-'A';
    if(A[p2]>A[p1])   return 1;  
    else if(fabs(A[p2]-A[p1])<1e-8)        
                    if(p1==p2) return ch2-ch1;  
                    else  return p1-p2;
                               
            else return -1;
}


int main()
{

    int count,count1;
    char S[150];
    int len;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {

        for(int i=0;i<26;i++)
        {
            scanf("%lf",&A[i]);
        }
        scanf("%s",S);
        len=strlen(S);
        qsort(S,len,sizeof(S[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        printf("%s\n",S);
    }

}
