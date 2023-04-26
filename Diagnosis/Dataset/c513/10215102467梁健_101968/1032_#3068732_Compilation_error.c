#include<stdio.h>
#include<string.h>
int comp(const void *a,const void *b){
    int a1,b1;
    a1=*(int*)a;
    b1=*(int*)b;
    int i=0;
    for(i=0;;i++){
        if (a1[i]!=b1[i])return a1[i]>b1[i]?-1:1;
    }
}
int main()
{
    int T,i=0;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        int s[1001][51];
        int t;
        scanf("%d",&t);
        for(int step=0,m=0;step<t;step++,m++){
            int n=0;
            char c;
            do{
                scanf("%d",&s[m][n++]);
            }while(c=getchar()==' ');
        }
        qsort(s,t,sizeof(s[0]),comp);
        for(int k=0;k<t;k++){
            int z=0;
            for(;s[k][z+1]!=-1;z++){
                printf("%d ",s[k][z]);
            }
            printf("%d\n",s[k][z]);
        }
    }
    return 0;
}
