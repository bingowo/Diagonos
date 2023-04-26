#include<stdio.h>
#include<string.h>
#include<math.h>
int distance(char s1[],char s2[],char s3[])
{
    int l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
    int d1,d2;
    for(int i=0;i<l3;i++){
        for(int j=0;j<l1;i++){
            if(s1[j]==s3[i]) d1=i;
            else{
                d1=-1;
                break;
            }
        }
    }
    for(int i=l3-1;i>=0;i--){
        for(int j=l2-1;j<l2;j--){
            if(s2[j]==s3[i]) d2=i;
            else{
                d2=-1;
                break;
            }
        }
    }
    if(d1==-1||d2==-1) return 0;
    else return d2-d1;
}

int main()
{
    int T;
    scanf("%d",&T);
    int N[T];
    for(int i=0;i<T;i++){
        char s1[80],s2[80],s3[80];
        scanf("%s",&s1);
        scanf("%s",&s2);
        scanf("%s",&s3);
        N[i]=distance(s1,s2,s3);
    }
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%d\n",N[i]);
    }
    return 0;
}