#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j;
    char a[4000][15];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
        scanf("%s",a[i]);
    char s[5001],b[5001];
    scanf("%s",s);

    do{
    int flag = 0;
    strcpy(b,s);
    for(i = strlen(s);i>0;i--)
    {
        b[i] = '\0';
        for(j = 0;j< n;j++)
        {if(strcmp(b,a[j])==0) {flag = 1;break;}}
        if(flag==1) {printf("%s ",b);break;}
        if(i==1) {printf("%s ",b);break;}
    }
    int k = 0;
    for(i = strlen(b);i<strlen(s);i++)
        s[k++] = s[i];
    s[k] = '\0';
    }while(strlen(s)!=0);
    return 0;


}
