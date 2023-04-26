#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int invert(char a)
{
    if('a'<=a && a<='f')return a-'a'+10;
    else if('0'<=a && a<='9')return a-'0';
    else return -1;
}
int main()
{
    char a[100001];

    int aa[50000],cnt=0,max=0,count=0,m;
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='0'){
            if(a[i+1]=='x'){
                if(invert(a[i+2])!=-1){if(cnt){aa[count++]=max;max=0;cnt=0;}
                i+=2;cnt=1;
                }

                }

            }

     if(cnt){
        m=invert(a[i]);
        if(m!=-1)max=max*16+m;
        else {aa[count++]=max;cnt=0;max=0;}}

    }
    if(cnt)aa[count++]=max;
    if(count>0){
    for(int i=0;i<count;i++)printf("%d ",aa[i]);}
    else printf("-1");
    return 0;
}
