#include<stdio.h>
#include<string.h>
int main()
{
    char s1[50],s2[50];
    int A,B;
    scanf("%d %s %d",&A,&s1,&B);
    int x,y,z=1,sum=0;
    int l=strlen(s1);
    for(int i=l;i>=0;i--){
        x=(int)s1[i];
        if((x>=65)&&(x<=90)) y=x-55;
        else if((x>=97)&&(x<=122)) y=x-87;
        sum+=y*z;
        z=z*10;
    }
    int a,i=0;
    while(sum!=0){
        a=sum%B;
        sum/=B;
        s2[i]=a;
        i++;
    }
    i--;
    for(;i>=0;i--){
        if(s2[i]>9) printf("%c",s2[i]+55);
        else printf("%d",s2[i]);
    }
    return 0;
}
