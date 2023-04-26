#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compar(const void *p1,const void *p2);
int main()
{
    int n,i;
    char **address,*temp;
    scanf("%d",&n);
    address=(char**)malloc(n*sizeof(char*));        //这个也是新的尝试
    temp=(char*)malloc(2000000*sizeof(char));
    for(i=0;i<n;i++)
    {           //首先，这题给了我处理容量有限的oj题的思路，先用一个temp指针一次性申请到最大空间，额，由于\0的存在，还是申请两倍吧
        //address[i]=(char*)malloc(1000000*sizeof(char));   
        //scanf("%s",address[i]);
        scanf("%s",temp);
        //address[i]=(char*)malloc(strlen(temp)*sizeof(char));
        //strcpy(address[i],temp);      //这个也会占用大量时间，不建议
        address[i]=temp;
        temp+=strlen(temp)+1;
    }
    qsort(address,n,sizeof(char*),compar);

    for(i=0;i<n;i++)
    {
        puts(address[i]);
    }
    //另外，很离谱的是，free反倒超时，不断和我说什么无效指针，删掉free就全对
    //莫非oj其实会自动free？
    return 0;
}

int compar(const void *p1,const void *p2)
{
    int flag=0,ia,ib;
    char *a,*b,**A,**B;
    A=(char**)p1;B=(char**)p2;
    a=*A;b=*B;
    for(ia=0;ia<strlen(a);ia++)
        if(a[ia]=='@')
            break;
    for(ib=0;ib<strlen(b);ib++)
        if(b[ib]=='@')
            break;
    flag=strcmp(a+ia,b+ib);     //返回值不是+1或-1，只是在我的电脑上这样而已
    if(flag>0)
        flag=1;
    else if(flag<0)
        flag=-1;
    else
    {
        flag=-strcmp(a,b);
        if(flag>0)
            flag=1;
        else
            flag=-1;
    }
    return flag;
}
