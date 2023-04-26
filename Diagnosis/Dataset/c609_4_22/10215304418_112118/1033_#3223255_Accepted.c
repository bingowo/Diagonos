#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[123456];
char f[123456];
int num[123456];

int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<26;i++)
        f[i]='A'+i;
    for (int i=26;i<=51;i++)
        f[i]='a'+i-26;
    for (int i=52;i<=61;i++)
        f[i]='0'+i-52;
    f[62]='+';
    f[63]='/';
    for (int i=1;i<=n;i++){
        scanf("%s",st);
        printf("case #%d:\n",i-1);
        int m=strlen(st)*8;
        if (m%6==0) m=m/6;
        else m=m/6+1;
        if (m%4==0) m=m/4;
        else m=m/4+1;
        m=m*4;
        for (int k=1;k<=m*6;k++) num[k]=-1;
        for (int k=0;k<strlen(st);k++){
            int x=st[k];
            int j=8*k+8;
            while (x!=0){
                num[j]=x%2;
                x=x/2;
                j--;
            }
            while (j%8!=0){
                num[j]=0;
                j--;
            }
        }/*
        for (int k=1;k<=m*6;k++)
            printf("%d ",num[k]);
        printf("\n");*/
        int sum=0;
        for (int k=1;k<=m*6;k++){
            sum*=2;
            if (k%6==1 && num[k]==-1) {
                printf("=");
                k+=5;
                continue;
            }
            else if (num[k]!=-1) sum+=num[k];
            if (k%6==0){
                printf("%c",f[sum]);
                sum=0;
            }
        }
        printf("\n");
    }
    return 0;
}
