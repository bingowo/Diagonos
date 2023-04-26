#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *p1,const void *p2);
int main()
{
    int n=100,i=0;
    char **address,*temp;
    address=(char**)malloc(n*sizeof(char*));
    temp=(char*)malloc(10000*sizeof(char));
    while(scanf("%s",temp)!=EOF)
    {
        address[i++]=temp;
        temp+=strlen(temp)+1;
    }
    n=i;
    qsort(address,n,sizeof(char*),compar);

    for(i=0;i<n;i++)
    {
        //puts(address[i]);
        printf("%s ",address[i]);
    }

    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0,ia,ib,numa=0,numb=0,lennuma=0,lennumb=0,temp=0;
    char *a,*b,**A,**B;
    A=(char**)p1;B=(char**)p2;
    a=*A;b=*B;
    for(ia=0;ia<strlen(a);ia++)
    {
        if(a[ia]>='0'&&a[ia]<='9')
        {
            numa=1;break;
        }
    }
    for(ib=0;ib<strlen(b);ib++)
    {
        if(b[ib]>='0'&&b[ib]<='9')
        {
            numb=1;break;
        }
    }
    if(numa==0&&numb==0)
    {
        if(strcmp(a,b)>0)
            flag=1;
        else
            flag=-1;
    }
    else if(numa==1&&numb==0)
        flag=1;
    else if(numa==0&&numb==1)
        flag=-1;
    else if(numa==1&&numb==1)
    {
        while(a[ia]=='0')
            ia++;
        temp=ia;
        while((a[ia]>='0'&&a[ia]<='9'))
            ia++;
        lennuma=ia-temp;
        ia=temp;

        while(b[ib]=='0')
            ib++;
        temp=ib;
        while(b[ib]>='0'&&b[ib]<='9')
            ib++;
        lennumb=ib-temp;
        ib=temp;

        if(lennuma>lennumb)
            flag=1;
        else if(lennuma<lennumb)
            flag=-1;
        else
        {
            while((a[ia]==b[ib])&&(a[ia]<='9'&&a[ia]>='0'))     //就挺奇怪的，明明好像是改了一个无关紧要的错误，但是答案却就奇迹般地对了
            {
                //哦！不是无关紧要的错误，因为如果越过了\0，那么就是下一个指针指向的值了，其间数字说不定会搞出什么幺蛾子
                ia++;
                ib++;
            }
            if((a[ia]>='0'&&a[ia]<='9')&&(b[ib]>='0'&&b[ib]<='9'))
            {
                if(a[ia]>b[ib])
                    flag=1;
                else if(a[ia]<b[ib])
                    flag=-1;
            }
            else if(!((a[ia]>='0'&&a[ia]<='9')||(b[ib]>='0'&&b[ib]<='9')))
            {
                if(strcmp(a,b)>0)
                    flag=1;
                else
                    flag=-1;
            }
            else if((a[ia]>='0'&&a[ia]<='9')&&(!(b[ib]>='0'&&b[ib]<='9')))
                flag=1;
            else
                flag=-1;
        }

    }
    return flag;
}
