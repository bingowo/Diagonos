#include <stdio.h>
#include <string.h>
char ans[100];
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
    if(c!=0){
        ans[l]=c+'0';
        ans[l+1]=0;
    }
}
int main()
{
    int t,a,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&a,&n);
        ans[0]='1';
        ans[1]=0;
        for(j=0;j<n;j++)
            mul(a);
        printf("case #%d:\n",i);
        for(j=strlen(ans)-1;j>=0;j--)
            printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}