#include<stdio.h>
#include<string.h>

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
    void count(char A[])
    {
        int i=0;
        do{
            if(A[i]==58){
                A[i]=48;
                A[i+1]++;
                i++;
            }
        }while(A[i]==58);
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%s",A);
        strrev(A);
        A[0]++;
        int n=0;
        do{
            if(A[n]==58){
                A[n]=48;
                A[n+1]+=1;
                n++;
            }
        }while(A[n]==58);
        n=0;
        for(;judge(A)!=1;A[0]++){
            do{
            if(A[n]==':'){
                A[n]=48;
                if(isdigit(A[n+1]))A[n+1]+=1;
                else A[n+1]='1';
                n++;
            }
            }while(A[n]==':');
            n=0;
        }
        strrev(A);
        printf("%s\n",A);
    }
    return 0;
}
