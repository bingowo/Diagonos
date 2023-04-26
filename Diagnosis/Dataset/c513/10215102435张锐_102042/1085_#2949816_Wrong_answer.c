#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000]={'\0'},b[1000]={'\0'};int bo;
    while(scanf("%s %s",a,b)!=EOF)
    {
        int ans[1000]={0};int ii=0;
        int la=strlen(a),lb=strlen(b);
        bo=1;
        if(strcmp(a,b)==0) bo=0;
        if(la>lb||((la==lb)&&strcmp(a,b)==1))
        {
            int i,j;
            for(i=lb-1,j=la-1;i>=0;i--,j--)
            {
                int temp=(a[j]-'0')-(b[i]-'0');
                if(temp>=0) ans[ii++]=temp;
                else
                {
                    ans[ii++]=(a[j]-'0')+10-(b[i]-'0');
                    for(int k=j-1;;k--)
                    {
                        if(a[k]>'0') {a[k]--;break;}
                        else if(a[k]=='0') a[k]='9';
                    }
                }
            }
            for(;j>=0;j--) ans[ii++]=a[j]-'0';
        }
        else
        {
            int i,j;
            for(i=la-1,j=lb-1;i>=0;i--,j--)
            {
                int temp=(b[j]-'0')-(a[i]-'0');
                if(temp>=0) ans[ii++]=temp;
                else
                {
                    ans[ii++]=(b[j]-'0')+10-(a[i]-'0');
                    for(int k=j-1;;k--)
                    {
                        if(b[k]>'0') {b[k]--;break;}
                        else if(b[k]=='0') b[k]='9';
                    }
                }
            }
            for(;j>=0;j--) ans[ii++]=b[j]-'0';
            if(bo) printf("-");
        }
        for(;;ii--)
        {
            if(ans[ii]!=0) break;
        }
        if(bo==0) printf("0");
        else for(int kk=ii;kk>=0;kk--) printf("%d",ans[kk]);
        printf("\n");
    }
    return 0;
}