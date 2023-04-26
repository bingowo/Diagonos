#include<stdio.h>
#include<string.h>
int comp(const void *a,const void *b){
    int *a1,*b1;
    a1=(int *)a;
    b1=(int *)b;
    int i=0;
    for(i=0;;i++){
        if (a1[i]!=b1[i])return b1[i]-a1[i];
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
            }while(c=getchar()==' '&&s[m][n]!=-1);
            s[m][n]='0';
        }
        qsort(s,t,sizeof(s[0]),comp);
        for(int k=0;k<t;k++){
            int m=0;
            for(m=0;m<strlen(s[k])-1;m++){
                printf("%d ",s[k][m]);
            }
            printf("%d\n",s[k][strlen(s[k])-1]);
        }
    }
    return 0;
}
