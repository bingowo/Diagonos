#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int table[123];
    int T,n,j=1,num=2,flag=0;
    long long int ans=0,weight=1;
    char s[60];
    for(int i=0;i<123;i++)table[i]=-1;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",s);
        n=strlen(s);
        table[s[0]]=1;
        while(s[j]!='\0'){
            if(table[s[j]]==-1&&flag==0){
                table[s[j++]]=0;
                flag=1;
            }
            if(table[s[j]]==-1)
                table[s[j++]]=num++;
            else j++;
        }
        while(n--){
            ans+=weight*table[s[n]];
            weight*=num;
        }
        printf("case #%d:\n%lld\n",i,ans);
        for(int i=0;i<123;i++)table[i]=-1;
        weight=1;j=1;num=2;flag=0;
    }
    system("pause");
    return 0;
}
