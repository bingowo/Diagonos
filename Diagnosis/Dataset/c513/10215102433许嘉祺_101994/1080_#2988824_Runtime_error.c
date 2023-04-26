#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void div2(int*a1){
    int i=100;
    int carry=0;
    while(a1[i]==0&&i>=0) i--;
    if (a1[i]==1){
        carry=1;
        a1[i--]=0;
    }

    for (;i>=0;i--){
        a1[i]+=carry*10;
        carry=a1[i]%2;
        a1[i]=a1[i]/2;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    char s[101];
    int a1[101];
    for (int i=0;i<t;i++){
        scanf("%s",s);
        memset(a1,0,sizeof(a1));
        for (int j=0;j<strlen(s);j++)
            a1[j]=s[strlen(s)-1-j]-'0';
        int len=strlen(s)-1;
        int slen=0;
        int b[500];


        memset(b,0,sizeof(b));
        while (len!=0||a1[0]!=0){
            b[slen++]=a1[0]%2;
            div2(a1);
            len=100;
            while (a1[len]==0&&len>=0) len--;
            if (len<0) len=0;

        }

        int a2[101];

        memset(a2,0,sizeof(a2));
        for (int j=0;j<slen;j++){
            for (int k=0;k<101;k++)
                a2[k]=a2[k]*2;
            int carry=b[j];
            for (int k=0;k<101;k++){
                a2[k]+=carry;
                carry=a2[k]/10;
                a2[k]=a2[k]%10;
            }
        }
        printf("case #%d:\n",i);
        int j=100;
        while (a2[j]==0&&j>=0) j--;
        if (j==-1) printf("0");
        for (;j>=0;j--) printf("%d",a2[j]);
        printf("\n");
    }


    return 0;
}
