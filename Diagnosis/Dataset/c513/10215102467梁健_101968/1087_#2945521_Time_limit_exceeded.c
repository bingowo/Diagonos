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
        char s[101];
        for(int q=0;q<101;q++)s[q]=0;
        for(int rev=0;rev<strlen(A);rev++){
            s[rev]=A[strlen(A)-1-rev];
        }
        strcpy(A,s);
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
        char p[101];
        for(int q=0;q<101;q++)p[q]=0;
        for(int rev=0;rev<strlen(A);rev++){
            p[rev]=A[strlen(A)-1-rev];
        }
        strcpy(A,p);
        printf("%s\n",A);
    }
    return 0;
}
