#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char *Dic[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int cmp(int*a,int*b)
{
        return *a-*b;
}

void Cut(char *p1,char *p2)
{
    char *a=p1;
    while(*p2)
    {
        while(*p2&&*p1)
        {
            if(*p1==*p2)
            {
                *p1='1';
                break;
            }
            else
            {
                p1++;
            }
        }
        p2++;
        p1=a;
    }
}

int Pan(char *p1,char c)
{
    while(*p1)
    {
        if(c==*p1)
        {
            return 1;
        }
        p1++;
    }
    return 0;
}

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char S[21];


    while(count--)
    {
        int i=0;
        int *A=malloc(10*sizeof(int));
        gets(S);
        while(Pan(S,'Z'))
        {
            Cut(S,Dic[0]);
            A[i]=0;
            i++;
        }

        while(Pan(S,'X'))
        {
            Cut(S,Dic[6]);
            A[i]=6;
            i++;
        }

        while(Pan(S,'G'))
        {
            Cut(S,Dic[8]);
            A[i]=8;
            i++;
        }

        while(Pan(S,'H'))
        {
            Cut(S,Dic[3]);
            A[i]=3;
            i++;
        }

        while(Pan(S,'S'))
        {
            Cut(S,Dic[7]);
            A[i]=7;
            i++;
        }

        while(Pan(S,'V'))
        {
            Cut(S,Dic[5]);
            A[i]=5;
            i++;
        }

        while(Pan(S,'F'))
        {
            Cut(S,Dic[4]);
            A[i]=4;
            i++;
        }

        while(Pan(S,'T'))
        {
            Cut(S,Dic[2]);
            A[i]=2;
            i++;
        }

        while(Pan(S,'O'))
        {
            Cut(S,Dic[1]);
            A[i]=1;
            i++;
        }

        while(Pan(S,'I'))
        {
            Cut(S,Dic[9]);
            A[i]=9;
            i++;
        }
        printf("case #%d:\n",count1-count-1);
        qsort(A,i,sizeof(A[0]),cmp);
        for(int j=0;j<i-1;j++)
        {
            printf("%d",A[j]);
        }
        printf("%d\n",A[i-1]);
        free(A);
    }
}
