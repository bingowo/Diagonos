#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int len=strlen(s);
    int cnt=1,max=0,start=-1,ending=-1,flag;
    for(int j=1;j<len;j++){
        flag=1;
        for(int i=0;i<j;i++){
            if(s[i]==s[j]){
                flag=0;
                if(cnt>max){max=cnt;start=i;ending=j;}
                cnt=1;
                break;}
        }
        if(flag)cnt++;
    }
    if(start==-1&&ending==-1){start=0;ending=len;}
    for(int k=start;k<ending;k++)printf("%c",s[k]);
    printf("\n");
    return 0;
}
