#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    char s[101];
    int count[4];
    char sign[4];
    for (int i=0;i<n;i++){
        memset(count,0,sizeof(count));
        memset(sign,0,sizeof(sign));
        scanf("%s",s);
        for (int j=0;j<strlen(s);j++){
            if (s[j]=='!') count[j%4]++;
            else sign[j%4]=s[j];
        }
        printf("case #%d:\n",i);
        char lost;
        if (strchr(s,'R')==NULL) lost='R';
        if (strchr(s,'B')==NULL) lost='B';
        if (strchr(s,'Y')==NULL) lost='Y';
        if (strchr(s,'G')==NULL) lost='G';
        for (int j=0;j<4;j++)
            if (sign[j]==0){
            sign[j]=lost;
        }
        for (int j=0;j<4;j++)
            if (sign[j]=='R') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='B') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='Y') printf("%d ",count[j]);
        for (int j=0;j<4;j++)
            if (sign[j]=='G') printf("%d\n",count[j]);

    }
    return 0;
}
