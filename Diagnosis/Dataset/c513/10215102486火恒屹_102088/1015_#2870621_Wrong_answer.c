#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int qusnum;
    scanf("%d",&qusnum);
    int primenum[33]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
    for(int i=0;i<qusnum;i++)
    {
        char A[100]={'0'};
        char B[100]={'0'};
        int groupA[30]={0};
        int groupB[30]={0};
        int numofA=0;
        int numofB=0;
        scanf("%s",&A);
        scanf("%s",&B);
        char temponum[5]={'0'};
        int f=0;
        int g=0;
        for(int e=0;e<strlen(A)+1;e++)
        {
            if((A[e]!=',')&&(A[e]!=0))
            {
                temponum[g]=A[e];
                g=g+1;
            }
            else
            {
                groupA[f]=atoi(temponum);
                f=f+1;
                g=0;
                numofA++;
                memset(temponum,0,strlen(temponum));
            }
        }
        f=0;
        g=0;
        for(int e=0;e<strlen(B)+1;e++)
        {
            if((B[e]!=',')&&(B[e]!=0))
            {
                temponum[g]=B[e];
                g=g+1;
            }
            else
            {
                groupB[f]=atoi(temponum);
                f=f+1;
                g=0;
                numofB++;
                memset(temponum,0,strlen(temponum));
            }
        }
        int big=0;
        if(numofA>=numofB)
            big=numofA;
        else big=numofB;
        int result[30]={0};
        int h=0;
        for(int j=29;j>29-big;j=j-1)
        {
            int AAA=numofA-1-h;
            int BBB=numofB-1-h;
            if (AAA<0)
                AAA=29;
            if(BBB<0)
                BBB=29;
            result[j]=groupA[AAA]+groupB[BBB];
            if(result[j]>=primenum[h])
            {
                result[j-1]=result[j-1]+1;
                result[j]=result[j]-primenum[h];
            }
            h++;
        }
        int begin=0;
        for(int j=0;j<30;j++)
        {
            if(result[j]!=0)
                {begin=j;
                break;}
        }
        printf("case #%d:\n",i);
        for(int j=begin;j<29;j++)
            printf("%d,",result[j]);
        printf("%d\n",result[29]);
    }
    return 0;
}
