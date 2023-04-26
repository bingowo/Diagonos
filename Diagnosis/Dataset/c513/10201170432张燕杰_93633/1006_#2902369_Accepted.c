#include<stdio.h>

int main()
{
    int num[127]={'\0'};
    num['1']= 1;
    num['-']= -1;
    num['0']=0;

    int T;
    scanf("%d\n",&T);
    for(int i =0;i<T;i++)
    {
        char a[100] = {'\0'};
        int key = 0;
        while((a[key]=getchar())!='\n')
        {
            key++;
            continue;
        }
        key = key-1;
        long long int S=0;
        for(int j =0;j<key;j++)
        {
            S = (S+num[a[j]])*3;
        }
        printf("case #%d:\n%lld\n",i,S+num[a[key]]);
    }
    return 0;
}
