#include<stdio.h>
#include<string.h>
#include<math.h>

char*convert(char str1[],char* temp)
{

    memset(temp,0,sizeof(temp));
    int num,tmp,k=0,l=strlen(str1);
    int i,j;
    for(i=l-1;i>1;i--){
        num=str1[i]-'0';
        for(j=0;j<k||num!=0;j++){
            int z;
            if(j<k) z=temp[j]-'0';
            else z=0;
            tmp=num*10+z;
            temp[j]=tmp/8+'0';
            num=tmp%8;
        }
        k=j;
    }
    int l1=strlen(temp);

    return temp;
}
int main()
{
    int T;
    scanf("%d",&T);
    char N[T][50];
    for(int i=0;i<T;i++){
        scanf("%s",&N[i]);
    }
    char temp[150];
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("0.%s\n",convert(N[i],temp));

    }
}
