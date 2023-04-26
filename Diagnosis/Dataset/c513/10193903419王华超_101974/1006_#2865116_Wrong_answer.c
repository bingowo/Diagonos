#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int n;
}qt;
qt qts[10];
int main()
{
    int t,index=0,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[101];
        scanf("%s",s);
        int len=strlen(s),j;
        for(j=0;j<len;j++){
            if(s[j]=='1')
            {
                qts[index].n+=pow(3,len-1-j);
            }
            else if(s[j]=='-'){
                qts[index].n-=pow(3,len-1-j);
            }
        }
        index++;
    }
    for(i=0;i<t;i++){
        printf("case#%d:\n%d\n",i,qts[i].n);
    }
    return 0;
}
