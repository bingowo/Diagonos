#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int z,yu;
}zc;
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s1[4],s2[4];
        zc a[1000];
        scanf("%s%s",s1,s2);
        int len1=strlen(s1),len2=strlen(s2),fz,fm,k,p=0,flag=-1,flag2=-1;
        fz=atoi(s1),fm=atoi(s2);
        if(fz*10>=fm)k=10;
        else k=100;
        while(fz%fm!=0){
            flag=-1;
            fz*=k;
            a[p].z=fz/fm;
            a[p++].yu=fz%fm;
            fz=fz%fm;
            for(int q=0;q<p-1;q++){
                if(a[q].z==a[p-1].z&&a[q].yu==a[p-1].yu){
                    flag=q+1;
                    flag2=p-1;
                    break;
                }
            }
            if(flag!=-1)break;
        }
        int flag3;
        if(flag!=-1){flag3=flag;p=flag2;}
        else flag3=0;
        printf("case #%d:\n0.",i);
        for(int k=0;k<p;k++)printf("%d",a[k].z);
        if(flag3)printf("\n%d-%d\n",flag,flag2);
        else printf("\n");
    }
    return 0;
}