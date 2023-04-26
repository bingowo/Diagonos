#include <stdio.h>
#include <string.h>
char s[101];
char c[5]={"RBYG"};
int ml(int x)
{
    if(x>2)
        return x-3;
    else
        return 0;
}
int mr(int x)
{
    if(x<strlen(s)-3)
        return x+3;
    else
        return strlen(s)-1;
}
int main()
{
    int sum[4],sum0[4],num[100];
    int i,j,l,k,n,t;
    char ch;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        n=0;
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        for(j=0;j<l;j++)
            if(s[j]!='!')
                num[j]=-1;
            else{
                n++;
                for(k=ml(j);k<=mr(j);k++)
                    if(s[k]!='!')
                        num[j]++;
            }
        while(n>0){
            for(j=0;j<l;j++)
                if(num[j]>=3){
                    memset(sum0,0,sizeof(sum0));
                    for(k=ml(j);k<=mr(j);k++)
                        if(s[k]=='R')
                            sum0[0]++;
                        else if(s[k]=='B')
                            sum0[1]++;
                        else if(s[k]=='Y')
                            sum0[2]++;
                        else if(s[k]=='G')
                            sum0[3]++;
                    for(k=0;k<4;k++)
                        if(sum0[k]==0){
                            ch=c[k];
                            sum[k]++;
                            break;
                        }
                    for(k=ml(j);k<=mr(j);k++)
                        if(num[k]>=0)
                            num[k]++;
                    s[j]=ch;
                    num[j]=-1;
                    n--;
                }
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",sum[0],sum[1],sum[2],sum[3]);
    }
    return 0;
}
