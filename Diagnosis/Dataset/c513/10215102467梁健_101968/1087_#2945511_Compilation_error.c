#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int T;scanf("%d",&T);char A[101];
    int judge(char A[])
    {
        if(strlen(A)==1)return 1;
        for(int step=1;step<strlen(A);step++){
            if(A[step]==A[step-1])break;
            if(step==strlen(A)-1)return 1;
        }
        return 0;
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%s",A);
        strrev(A);
        int n=0;
        do{
            A[0]++;
            while(A[n]==58){
                A[n]=48;n++;
                if(isdigit(A[n]))A[n]+=1;
                else A[n]='1';
            }
            n=0;
        }while(judge(A)==0);
        strrev(A);
        printf("%s\n",A);
    }
    return 0;
}
