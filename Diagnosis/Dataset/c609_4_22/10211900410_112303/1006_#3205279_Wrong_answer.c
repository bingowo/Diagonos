#include<stdio.h>
#include<string.h>
#include<math.h>
int code(char s[])
{
    int length,num;
    length=strlen(s);
    if(length==1) return 1;//
    char s1[60];
    int i,j,k,message[61];
    strcpy(s1,s);
    for(i=0;i<length;i++){
        for(j=k=i+1;j<length;j++){
            if(s1[j]!=s1[i])
                s1[k++]=s1[j];
        }
    }
    s1[k]='\0';//保证字符串结尾
    num=strlen(s1);
    for(i=0;i<length;i++){
        if(s[i]==s1[0]) message[i]=1;
        else if(s[i]==s1[1]) message[i]=0;
        else{
            for(j=2;j<num;j++){
                if(s[i]==s1[j]){
                    message[i]=j;
                    break;
                }
            }
        }
    }
    for(i=0;i<num;i++){
        printf("%d ",message[i]);
    }
    int sum=0,ret,eop=length;
    for(int i=0;i<length;i++){
        ret=pow(num,(--eop));
        sum=sum+message[i]*ret;
    }
    return sum;
}
int main()
{
    char s[60];
    int T;
    int N[10];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",&s);
        N[i]=code(s);
    }
    for(int j=0;j<T;j++){
        printf("case #%d:\n",j);
        printf("%d\n",N[j]);
    }
    return 0;
}

