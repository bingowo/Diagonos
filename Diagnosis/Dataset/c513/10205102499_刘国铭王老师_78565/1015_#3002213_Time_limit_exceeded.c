#include<stdio.h>
#include<string.h> 
#include<math.h>

#define N 10000
int vis[N],prim[26],ans[30];
int k1,k2;
void is_prim()
{
  int m=(int)sqrt(N+0.5);
  int c=0,i,j;
  memset(vis,0,sizeof(vis));
  for(i=2;i<=m;i++)
  if(!vis[i])
  {
    prim[c++]=i;

    for(j=i*i;j<=N;j+=i)
      vis[j]=1;
  }
}
void add_output(int *temp1,int *temp2)
{
  int i,j;
  int len=k1>k2?k1:k2;
  memset(ans,0,sizeof(ans));
  //printf("%d\n",len);
  for(i=0,j=0;i<len;i++)
  {
    ans[i]+=temp1[i]+temp2[i];
    if(ans[j]>=prim[i]) 
    {
      ans[i+1]+= ans[i]/prim[i];
      ans[i]%=prim[i];
      //printf("%d\n",prim[i]);
      j++;
    }
    else
      j++;

  }
  if(ans[len]!=0)
    len++;
  for(i=len-1;i>=1;i--)
    printf("%d,",ans[i]);
  printf("%d\n",ans[0]);
} 
int main()
{
    char str1[100],str2[100];
  int temp1[100]={0},temp2[100]={0};
    int i,j; int temp,len1,len2;
    is_prim();
    prim[0]=2;
    /*
    for(i=0;i<26;i++)
      printf("%d ",prim[i]);
    printf("\n");
  */
    while(1)
    {
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2)); 
    memset(temp1,0,sizeof(temp1)); 
    memset(temp2,0,sizeof(temp2)); 
        scanf("%s %s",str1,str2);
        k1=k2=0;
        if(str1[0]=='0'&&str2[0]=='0')
            break;
        len1=strlen(str1);
        len2=strlen(str2);
        str1[len1]=',';
    str2[len2]=',';  
    len1++;
    len2++;
        for(i=0,temp=0,k1=0;i<=len1;i++)
        {
      if(str1[i]==',')
      {
        temp1[k1++]=temp;
        temp=0;
        continue;
      }
      temp=temp*10+str1[i]-'0';
    }
    for(i=0,temp=0,k2=0;i<=len2;i++)
        {
      if(str2[i]==',')
      {
        temp2[k2++]=temp;
        temp=0;
        continue;
      }
      temp=temp*10+str2[i]-'0';
    } 
        for(i=0,j=k1-1;j>=i;i++,j--)
        {   
          temp=temp1[j];
            temp1[j]=temp1[i];
            temp1[i]=temp;
        }
        for(i=0,j=k2-1;j>=i;i++,j--)
        {   
          temp=temp2[j];
            temp2[j]=temp2[i];
            temp2[i]=temp;
        }
    add_output(temp1,temp2);
  }
  return 0;
}
