#include <stdio.h>
#include <string.h>
char ans[1000];
void mul(int a)
{
    int i,c,l;
    char t;
    c=0;
    l=strlen(ans);
    for(i=0;i<l;i++){
        t=ans[i];
        ans[i]=((t-'0')*a+c)%10+'0';
        c=((t-'0')*a+c)/10;
    }
    ans[l]=c+'0';
    ans[l+1]=0;
    i=l;
    while(ans[i]=='0'){
        ans[i]=0;
        i--;
    }
}
int main()
{
    char w[1001];
    int a[1000];
    int i,l;
    scanf("%s",w);
    l=strlen(w);
    if(l==1)
        printf("1\n");
    else{
        if(w[0]!=w[1])
            a[0]=2;
        else
            a[0]=1;
        if(w[l-1]!=w[l-2])
            a[l-1]=2;
        else
            a[l-1]=1;
        for(i=1;i<l-1;i++)
            if(w[i]!=w[i-1]&&w[i]!=w[i+1])
                a[i]=3;
            else if((w[i]!=w[i-1]&&w[i]==w[i+1])||(w[i]!=w[i+1]&&w[i]==w[i-1]))
                a[i]=2;
            else
                a[i]=1;
        ans[0]='1';
        ans[i]=0;
        for(i=0;i<l;i++)
            mul(a[i]);
        for(i=strlen(ans)-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
