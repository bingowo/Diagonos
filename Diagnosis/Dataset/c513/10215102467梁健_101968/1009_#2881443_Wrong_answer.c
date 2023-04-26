#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    char a=getchar();
    char s[121];
    for(int step=0;step<n;step++){
        gets(s);
        int n=0,r=0,len=strlen(s);
        for(int i=0;i<len;i++){
            char a=s[i];
            r+=8*sizeof(s[i]);
            for(int m=0;m<sizeof(s[i]);m++){
                if(a&1==1)n+=1;
                a=a>>1;
            }
        }
        int max=r,min=n;
        for(int m=min;m>0;m--){
            if(max%m==0&&min%m==0){
                printf("%d/%d\n",min,max);
                break;
            }
        }
    }
    return 0;
}
