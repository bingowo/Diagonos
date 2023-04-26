#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *p1,*p2,*d1,*d2;
    p1=*((char**)a);
    p2=*((char**)b);

    int j=0;
    while(*(p1+j)!='@') j++;          //查找@的位置
    d1=p1+j+1;                        //d1 指向第一个邮件地址的主机域名

    j=0;
    while(*(p2+j)!='@') j++;          //d2 指向第二个邮件地址的主机域名
    d2=p2+j+1;

    if(strcmp(d1,d2)==0) return strcmp(p2,p1);  // d1 d2直接代表指向后面的一系列字符
                                                //return值大于0 交换
                                                //域名相同 降序
    else return strcmp(d1,d2);                  //域名不同 升序

}



int main()
{
    int n;
    char** email;
    scanf("%d",&n);
    email=(char**)malloc(n*sizeof(char*));   //动态分配指针数组空间

    int i,len;
    char s[1000001],*p;    //从数组到指针？

    for(i=0;i<n;i++){      //输入 存到数组
        scanf("%s",s);
        len=strlen(s);
        p=(char*)malloc(len);     //是否要改成len+1？
                                  //动态分配邮件地址储存空间
        strcpy(p,s);            //把刚刚输入的字符串复制到动态申请的空间中
        *(email+i)=p;           //赋值到大的指针数组空间中

    }
    qsort(email,n,sizeof(char*),cmp);  //排序 注意是char*
    for(i=0;i<n;i++){                  //输出
        printf("%s\n",email[i]);
       
    }
    //释放空间
    for(i=0;i<n;i++){                   
       p=email[i];        //不理解
        free(p);
    }
    free(email);
    return 0;



}
