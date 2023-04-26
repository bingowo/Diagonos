#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
 int n;
 scanf("%d",&n);//输入问题数
 int i;
 for(i=0;i<n;i++)//循环一次解决一个问题
 {
  char a[100];
  scanf("%s",a); //输入字符串
  int k,t,q,p=1,sum=0;
  t=strlen(a);//字符串有多少个字符
  int num[t];//定义一个数组，其长度为字符串长度，每个字符所代表的数字存在数组中
  num[0]=1;//神秘数字是有意义的，所以第一位必定是1
  while(a[p]==a[p-1])//找到第一个与第一位字符不同的字符，并将前面的字符代表的数字（同一个数字）存在数组中
  {
   num[p]=1;
   p++;
  }
  if(p==1)num[1]=0;//如果第二字符就与第一个字符不同，那么第二个字符代表的数字就是0
  for(k=2,q=(p==1?2:0);k<t;k++,q++)
  {
   int j;
   for(j=0;j<k;j++)//判断字符是否与前面重复
   {
    if(a[k]==a[j])
    {
     q=num[j];
     break;
    }
   }
   num[k]=q;
  }
  for(k=t-1;k>=0;k--)
  {
   sum=sum+num[k]*pow(q,t-k-1);
  }
  printf("case #%d:\n",i);
  printf("%d\n",sum);
 }
}
