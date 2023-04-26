#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct
{
    int var[200];
    int cnt;
}var;
int breakUp(char *p);//将传入表达式各个元素储存在item中并返回个数
var apl(int l,int r);//返回表达式的结果，cnt为-1则表示返回的是变量的索引
int strtoNum(int po);//转换字符串为数字
int isAllNum(int l,int r);//判断是否为数字组
var addL(var m);
var mulL(var m);
var subL(var m);
var add(var al,var ar);
var sub(var al , var ar);
var mul(var al,var ar);



var v[20000];
char item[60][10];

int isAllNum(int l,int r)//判断是否为数字组
{
    for(int i =l;i<=r;i++)
    {
        int len = strlen(item[i]);
        for(int k =0;k<len;k++)if(!isdigit(item[i][k]))return 0;
    }
    return 1;
}
int strtoNum(int po)//转换字符串为数字
{
    int num=0;
    for(int i=0;i<strlen(item[po]);i++)
    {
        num*=10;
        num+=item[po][i]-'0';
    }
    return num;
}

var apl(int l,int r)//返回表达式的结果，cnt为-1则表示返回的是变量的索引
{
    var res;
    int flag =1;
    while(strcmp(item[l],"(")==0&&strcmp(item[r],")")==0&&flag)//去除最外层括号
    {
        int pl = l;
        int middle =0;
        for(;pl<r;pl++)
        {
            if(strcmp(item[pl],"(")==0)middle +=1;
            else if(strcmp(item[pl],")")==0)middle -=1;
            if(middle ==0)break;
        }
        if(pl==r)
        {
            l+=1;
            r-=1;
        }
        else flag = 0;
    }
    //对数字组进行处理
    if(isAllNum(l,r))
    {
        res.cnt = 0;
        for(int g =l;g<=r;g++)
        {
            res.var[res.cnt++] = strtoNum(g);
        }
        return res;
    }
    //对变量进行编码
    if(l==r)
    {
        int point=0;
        int base = 1;
        for(int d=0;d<strlen(item[l]);d++)
        {
            point+=base*(item[l][d]-'a'+1);
            base *=26;
        }
        res.cnt = -1;
        res.var[0] = point;
        return res;
    }
    //找到从左往右第一个二元操作符分开左右两个运算
    int j=-1,nm=0;
    for(int s=l;s<=r;s++)
    {
        if(strcmp(item[s],"(")==0)nm+=1;
        else if(strcmp(item[s],")")==0)nm-=1;
        else if(nm==0&&s>=l&&(strcmp(item[s],"+")==0||strcmp(item[s],"-")==0||strcmp(item[s],"*")==0||strcmp(item[s],"=")==0))
        {j = s;break;}
    }
    var al,ar;
    if(strcmp(item[j+1],"/")==0)
    {
    ar = apl(j+2,r);
    if(strcmp(item[j],"+")==0)return addL(ar);
    if(strcmp(item[j],"-")==0)return subL(ar);
    if(strcmp(item[j],"*")==0)return mulL(ar);
    }
    else
    {
         ar = apl(j+1,r);
          if(ar.cnt == -1)ar = v[ar.var[0]];
        al = apl(l,j-1);

       
        if(strcmp(item[j],"=")==0)
        {
            v[al.var[0]] =ar;
            return ar;
        }
        if(al.cnt == -1)al = v[al.var[0]];
         if(strcmp(item[j],"+")==0)return add(al,ar);
         if(strcmp(item[j],"-")==0)return sub(al,ar);
         if(strcmp(item[j],"*")==0)return mul(al,ar);
    }

}
var add(var al,var ar)
 {
      if(al.cnt ==1)
        {
            var init = al;
            al = ar;
            ar = init;
        }
    for(int i =0;i<al.cnt;i++)al.var[i]+=ar.var[0];
    return al;
}
var mul(var al,var ar)
{
       if(al.cnt ==1)
        {
            var init = al;
            al = ar;
            ar = init;
        }
    for(int i =0;i<al.cnt;i++)al.var[i]*=ar.var[0];
    return al;
}
var sub(var al,var ar)
{
      if(al.cnt ==1&&ar.cnt!=1)
        {
            var init = al;
            al = ar;
            ar = init;
        }
    for(int i =0;i<al.cnt;i++)al.var[i]-=ar.var[0];
    return al;
}
var addL(var m)
{
    int id;
    if(m.cnt=-1){id = m.var[0];m = v[id];}
    var res = m;
    int mid =0;
    res.cnt = 1;
    for(int k=0;k<m.cnt;k++)
    {
        mid+=m.var[k];
    }
    res.var[0]=mid;

    v[id] = res;
    return res;
}
var mulL(var m)
{
    int id;
    if(m.cnt=-1){id = m.var[0];m = v[id];}
    var res = m;
    int mid =1;
    res.cnt = 1;

    for(int k=m.cnt-1;k>=0;k++)
    {
        mid*=res.var[k];
    }

    res.var[0]=mid;
    v[id] = res;
    return res;
}
var subL(var m)
{
    int id;
    if(m.cnt=-1){id = m.var[0];m = v[id];}
    var res = m;
    int mid =0;
    res.cnt = 1;

    for(int k=m.cnt-1;k>=0;k--)
    {
        mid= res.var[k] -mid;
    }

    res.var[0]=mid;
    v[id] = res;
    return res;
}
int breakUp(char *p)//将传入表达式各个元素储存在item中并返回个数
{
    int len = strlen(p);
    int i;
    int cnt =0;
    for(i=0;i<len;i++)
    {
        if(p[i]!=' ')
           {
            int k =0;
            while(i<len&&p[i]!=' ')
                {
                 item[cnt][k++] = p[i];
                 i++;
                }
            item[cnt][k] = 0;
            cnt++;
            }
    }
    return cnt;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        char mid[200];
        gets(mid);
        int num= breakUp(mid);
        var res = apl(0,num-1);
        if(res.cnt==-1)res = v[res.var[0]];
        for(int po =0;po<res.cnt;po++)
        {
            printf("%d",res.var[po]);
            if(po!=res.cnt-1)printf(" ");
        }
        if(i!=n-1)printf("\n");

    }
    return 0;
}