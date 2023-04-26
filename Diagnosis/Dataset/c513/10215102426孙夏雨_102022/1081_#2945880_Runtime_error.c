#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mul(char* s,int a)
{
    int len=strlen(s);
    char ans[1000],c;
    int jinwei=0,jieguo=0,num=0;
    for(int i=0;i<len;i++){
        c=s[i];
        jieguo=(c-'0')*a+jinwei;
        jinwei=jieguo/10;
        ans[num]=jieguo%10+'0';
        num++;
    }
    if(jinwei>0) ans[num++]=jinwei+'0';
    ans[num]='\0';
    char* p=ans;
    return p;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a=0,n=0;
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",t);
        if(n==0) printf("1\n");
        else {
            char* ans=(char* )malloc(1000*sizeof(char));
            ans[0]=a+'0';
            ans[1]=0;
            for(int i=1;i<n;i++) strcpy(ans,mul(ans,a));
            int num=strlen(ans);
            for(int j=0;j<num;j++) printf("%c",ans[num-1-j]);
            printf("\n");
            free(ans);
        }
    }
    return 0;
}
