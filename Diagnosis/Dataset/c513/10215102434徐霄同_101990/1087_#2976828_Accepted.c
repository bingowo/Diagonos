#include <stdio.h>
#include <string.h>
int p(char s[],int x)
{
    int i=x;
    while(i>=0){
        s[i]=s[i]+1;
        if(s[i]<='9')
            return i;
        s[i]='0';
        i--;
    }
    return i;
}
int main()
{
    char s[102];
    int t,i,j,k,l;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        for(j=0;j<102;j++)
            s[j]='0';
        scanf("%s",s+1);
        l=strlen(s);
        p(s,l-1);
        for(j=1;j<l;j++)
            if(s[j]==s[j-1])
                break;
        if(j!=l){
            j=p(s,j);
            while(j>0){
                if(s[j]!=s[j-1])
                    break;
                j=p(s,j);
            }
            for(k=j+1;k<l;k++)
                s[k]=(k-j+1)%2+'0';
        }
        printf("case #%d:\n",i);
        if(s[0]!='0')
            printf("%s\n",s);
        else
            printf("%s\n",s+1);
    }
    return 0;
}
