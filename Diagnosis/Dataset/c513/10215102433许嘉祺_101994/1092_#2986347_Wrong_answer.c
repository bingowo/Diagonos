#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1001];
    scanf("%s",s);
    int d[1001];
    memset(d,0,sizeof(d));
    if (strlen(s)==1){
        printf("1");
    }
    else {
        if (s[0]==s[1]) d[0]=1;
        else d[0]=2;
        if (s[strlen(s)-1]!=s[strlen(s)-2]) d[0]=d[0]*2;
        for (int i=1;i<=strlen(s)-2;i++){
            int count=1;
            if (s[i-1]!=s[i]) count++;
            if (s[i+1]!=s[i]) count++;
            for(int j=0;j<1001;j++)
                d[j]=d[j]*count;
            int carry=0;
            for (int j=0;j<1001;j++){
                d[j]=d[j]+carry;
                carry=d[j]/10;
                d[j]=d[j]%10;
            }
        }
        int i=1000;
        while (d[i]==0) i--;
        for (;i>=0;i--)
        printf("%d",d[i]);
    }
    return 0;
}

