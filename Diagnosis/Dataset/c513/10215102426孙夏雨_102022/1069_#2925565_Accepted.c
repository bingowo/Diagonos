#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ishuiwen(char *s,int len)
{
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]) return 1;
    }
    return 0;
}

int main()
{
    char s0[11];
    scanf("%s",s0);
    int cishu=0,jieguo=0,len=strlen(s0),z1=0;
    while(ishuiwen(s0,len)){
        char s1[11];
        int x=0,y=0,z=0,len1=0;
        for(int j=0;j<len;j++){
            x=x*10+s0[j]-'0';
            y=y+(s0[j]-'0')*pow(10,j);
        }
        z=x+y;
        z1=z;
        while(z>0){
            s1[len1]=z%10+'0';
            z/=10;
            len1++;
        }
        s1[len1]=0;
        len=len1;
        strcpy(s0,s1);
        cishu++;
    }
    jieguo=z1;
    printf("%d %d\n",cishu,jieguo);
    return 0;
}
