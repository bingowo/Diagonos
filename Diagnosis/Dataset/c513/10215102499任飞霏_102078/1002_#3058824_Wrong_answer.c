#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char str[100]={};
        scanf("%s",str);
        //printf("%s",str);
        int table[130]={0},len=0,c=2;
        for(int j=0;j<130;j++)table[j]=-1;
        table[str[len++]]=1;
        while(str[len]==str[len-1])len++;
        table[str[len++]]=0;
        for(int j=len;str[j];j++){
            if(table[str[j]]==-1){
                table[str[j]] = c++;
            }
            len++;
        }
        int res=0;
        for(int j=0;j<len;j++){
            res = res*c + table[str[j]];
        }
        printf("%d\n",res);
    }
    return 0;
}
