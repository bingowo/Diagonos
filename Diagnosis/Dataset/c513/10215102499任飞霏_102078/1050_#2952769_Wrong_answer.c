#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getf(char* a,char* b)
{
    int len1=strlen(a),len2=strlen(b);
    for(int i=0;i<len1-len2+1;i++){
        int j=i,k=0;
        while(a[j]==b[k]&&a[j]!=0&&b[k]!=0){j++;k++;}
        if(b[k]=='\0')return j-1;
    }
    return -1;
}

int gete(char* a,char* b)
{
    int len1=strlen(a),len2=strlen(b),flag=1;
    for(int i=len1-1;i>=len2-1;i--){
        int j=i,k=len2-1,l=0;
        while(a[j]==b[k]&&j>=0&&k>=0){
            j--;
            k--;
            l++;
        }
        if(l==len2)return j+1;
    }
    return -1;
}


int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s1[80]={0},s2[80]={0},s[80]={0};
        scanf("%s%s%s",s1,s2,s);
        int a=getf(s,s1);
        int b=gete(s,s2);
        //printf("a=%d b=%d",a,b);
        if(a!=-1&&b!=-1){
            if(b<a){
                a=getf(s,s1);
                b=gete(s,s2);
            }
            int res=b-a-1;
            if(res>=0)printf("%d\n",res);
            else
                printf("0\n");

        }
    }

    return 0;
}
