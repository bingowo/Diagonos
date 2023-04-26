#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char a[50];
        scanf("%s\n",a);
        int len=strlen(a),r=0;
        for(int j=0;j<len;j++){
            if(a[j]=='-') r=3*r-1;
            else if(a[j]=='1') r=3*r+1；
            else r*=3;
            }
        printf("case #%d:\n%d\n",i,r);
    }
    return 0;
}