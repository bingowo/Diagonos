#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp(const void *aa,const void *bb);
    int n;
    scanf("%d",&n);//要使这n个字符串变换结果都相同
    char **s=(char **)malloc(sizeof(char*)*n);
    char check[120];
    memset(check,'\0',120);
    for(int z=0;z<n;z++)
    {
        int l;
        char temp[120];
        scanf("%s",temp);
        s[z]=(char*)malloc(sizeof(char)*120);
        strcpy(s[z],temp);
    }
    //printf("%s",s[1]);
    //以上是输入过程 输入完毕之后应先判断是否能够消除
    //之后是简化环节 确定是否能够被消除成相同的字符串
    char *simp[100000];
    for(int i=0;i<n;i++)
    {
        char temp[120];
        simp[i]=(char *)malloc(sizeof(char)*120);
        char p[120];
        memset(p,'\0',120);
        memset(temp,'\0',120);
        strcpy(temp,s[i]);
        int l=strlen(temp);//之后是去重操作
        for(int j=0;j<l;j++)
        {
            while(temp[j]==temp[j+1])
            {
                temp[j]='\0';
                j++;
            }
        }
        for(int j=0,k=0;j<l;j++)
        {
            if(temp[j]=='\0') ;
            else {
                p[k]=temp[j];
                k++;
            }
        }
        strcpy(simp[i],p);
    }
    //去重结束得到最简化的 *simp
    /*for(int i=0;i<n;i++)
    {
        printf("%s",simp[i]);
    }*/

    strcpy(check,simp[0]);
    int flag=1;
    for(int j=0;j<n;j++)
    {
        if(strcmp(check,simp[j]))
        {
            flag=-1;
            break;
        }
    }
    //判断是否能够转化 之后看中位数

    if(flag==-1) printf("-1");
    else if(flag==1)
    {
        int l0=strlen(simp[0]);
        int** num=(int**)malloc(sizeof(int*)*l0);
        for(int t=0;t<l0;t++)
        {
            num[t]=(int*)malloc(sizeof(int)*n);//一共有n组数据
        }
        for(int ii=0;ii<l0;ii++)
            for(int jj=0;jj<n;jj++)
            num[ii][jj]=1;

        //printf("%do",l0);
        //for(int i=0;i<n;i++)
            //printf("%s",s[i]);
        for(int i=0;i<n;i++)
        {
             for(int j=0,k=0;j<strlen(s[i]);j++)
                {
                    while(s[i][j]==s[i][j+1])
                        {
                            num[k][i]++;
                            j++;
                        }
                    k++;
                }
        }
        //for(int i=0;i<n;i++)
            //printf("%d ",num[1][i]);

        //建一个num的二维数组对应住s的字符串数组 每个位置对应的每一个字符串的重复数目
        int* mid=(int*)malloc(sizeof(int)*l0);
        //之后求每个数字对应的中位数（这里注意若干行对应的是若干类的字符 a b c....对应的就是
        for(int i=0;i<l0;i++)
        {
                qsort(num[i],n,sizeof(int),cmp);
        }
        //for(int i=0;i<n;i++)
           //printf("%d",num[1][i]);
        //先排序之后找中位数 存成一个数组 最后相加
        for(int i=0;i<l0;i++)
        {
              if(n%2==0)
                {
                    int midd=n/2;
                    mid[i]=num[i][midd];
                }
                else
                {
                    int midd=(n-1)/2;
                    mid[i]=num[i][midd];
                }
        }
        //for(int i=0;i<l0;i++)
            //printf("%d ",mid[i]);

        int ans=0;
        for(int i=0;i<l0;i++)
        {
            for(int j=0;j<n;j++)
                ans=ans+abs(num[i][j]-mid[i]);
        }
        printf("%d",ans);
    }


    return 0;
}

int abs(int input)
{
    if(input<=0) return -input;
    else return input;
}

int cmp(const void *aa,const void *bb)
{
    int a=*(int*)aa;
    int b=*(int*)bb;
    return a-b;
}