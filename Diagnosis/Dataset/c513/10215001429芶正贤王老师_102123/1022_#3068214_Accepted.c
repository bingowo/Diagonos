#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    char *p1,*p2,*domain1,*domain2;
    int i=0;
    p1=*((char **)a);
    p2=*((char **)b);
    
    while( *(p1+i)!='@')//查找@的位置
    {
        i++;
    }
    domain1=p1+i+1; //domain1指向第一个邮件地址的主机域名
    
    i=0;
    while( *(p2+i)!='@')
    {
        i++;
    }
    domain2=p2+i+1;//domain1指向第二个邮件地址的主机域名
    
    if(strcmp(domain1,domain2)==0) //主机域名字典序升序
        return strcmp(p2,p1);
    else							//用户名字典序降序
        return strcmp(domain1,domain2);
}



int main()
{
    int n; //1到333333
    char **email;//email表示指向指针的指针,指针的地址
    			 //*email表示地址
    			 //**email表示char型数组
    scanf("%d",&n);
    //给email动态分配指针数组空间
    email=(char **)malloc(n*sizeof(char *));//给email分配动态内存，存n个p
    
    char s[1000001],*p;  //p是个指针
    int i,len;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        //给p动态分配内存
        p=(char *)malloc(len+1);
        //把读入的字符串copy给p
        strcpy(p,s);
        
        
        *(email+i)=p;//把p给email
        
    }
    
    qsort(email,n,sizeof(char *),cmp);
    
    for(int i=0;i<n;i++)
    {
        printf("%s\n",email[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);
    
    return 0;
}
