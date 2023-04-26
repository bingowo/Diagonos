#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int compare(char *a,char *b);
    char a1[520],b1[520];
    int n;
    scanf("%s %s",a1,b1);
    scanf("%d",&n);//输入之后先预处理
    char a[520],b[520];
    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));

    int flag;
    if(a1[0]=='.') {
        a[0]='0';
        strcat(a,a1);
    }
    else if(a1[0]!='.') strcpy(a,a1);
    if(b1[0]=='.'){
        b[0]='0';
        strcat(b,b1);
    }
    else if(b1[0]!='.') strcpy(b,b1);//不管正负最后算绝对值的时候就是用a-b
    flag=strcmp(a,b);

    if(flag==-1)
    {
        char temp[520];
        memset(temp,'\0',520);
        strcpy(temp,a);
        strcpy(a,b);
        strcpy(b,temp);
    }
    else if(flag==0)
    {
        printf("0.");
        for(int zz=0;zz<n;zz++)
            printf("0");
        return 0;
    }
    int laa=strlen(a),lbb=strlen(b);
    int la2=0,lb2=0,l;//la2 lb2 代表小数点后的位数
    int i=laa-1;
    while(a[i]!='.') {la2++;i--;}
    i=lbb-1;
    while(b[i]!='.') {lb2++;i--;}
    //printf("a%da",la2);
    if(la2>=lb2){
        int dl=la2-lb2;
        l=la2;
        for(int kk=0;kk<dl;kk++)
            b[lbb+kk]='0';
    }
    if(lb2>la2){
        int dl=lb2-la2;
        l=lb2;
        for(int kk=0;kk<dl;kk++)
            a[laa+kk]='0';
    }//到这里预处理完成 l表示的是归一之后小数点之后的位数
    //printf("o%so",b);
    int l0=max(strlen(a),strlen(b));

    //printf("kk%dkk",l0);
    int jieflag;//是否要向整数位借数
    for(int end=l0-1,j=0;j<l;j++)
    {
        if(a[end-j]<b[end-j]) {
            int f=1;
            while(a[end-j-f]=='0'&&a[end-j-f]!='.')
            {
                f++;
            }
            if(a[end-j-f]=='.')
            {
                jieflag=1;
                for(int m=end-j-f+1,mm=0;mm<f-1;mm++)
                    a[m+mm]+=9;
                a[end-j]+=10;
            }
            else{
                jieflag=0;
                a[end-j-f]--;
                for(int m=end-j-f,mm=1;mm<f;mm++)
                    a[m+mm]+=9;
                a[end-j]+=10;
            }//分两种情况处理小数部分 并且记录jieflag等到之后的整数部分在处理
            a[end-j]=a[end-j]-b[end-j]+'0';
        }
        else if((a[end-j]>=b[end-j]))
        {
            a[end-j]=a[end-j]-b[end-j]+'0';
        }
    }//之后开始处理整数

    int flaga,flagb;
    int k1=0,k2=0;
    while(a[k1]!='.') k1++;
    while(b[k2]!='.') k2++;
    flaga=k1;flagb=k2;
    if(jieflag==1)
    {
        int zzz=1;
        while(a[flaga-zzz]=='0') zzz++;
        a[flaga-zzz]--;
    }
    //printf("%do",flaga);
    for(int j=flaga-1;j>=0;j--)
    {
        if(a[j]>=b[j]) {a[j]=a[j]-b[j]+'0';}
        else if(a[j]<b[j])
        {
            int f=1;
            while(a[j-f]=='0')
            {
                f++;
            }
            a[j-f]--;
            for(int m=j-f+1,mm=0;mm<f-1;mm++)
                a[m+mm]+=9;
            a[j]+=10;
            a[j]=a[j]-b[j]+'0';
        }
    }
    printf("%s",a);
    return 0;
}


int max(int a,int b)
{
    return (a>=b)?a:b;
}
