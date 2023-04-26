#include<stdio.h>
#include<stdlib.h> 
#include<string.h>  
#define MAX 20000
int compare(char* s1,char* s2);  
int main()  
{  
  char str1[MAX],str2[MAX],temp[MAX];    
  while(scanf("%s",temp)!=EOF)
  {
  	strcpy(str1,temp);
  	scanf("%s",temp);
  	strcpy(str2,temp);
  	int a[MAX],b[MAX],len;  
    int i;  
    memset(a,0,sizeof(a));  
    memset(b,0,sizeof(b));
    a[0]=strlen(str1);
  for(i=1;i<=a[0];i++)  
    a[i]=str1[a[0]-i]-'0';  
  b[0]=strlen(str2);  
  for(i=1;i<=b[0];i++)  
    b[i]=str2[b[0]-i]-'0';  
  if((compare(str1,str2))==0)  //澶т簬绛変簬锛屽仛鎸変綅鍑忥紝骞跺鐞嗗€熶綅銆? 
  {  
    for(i=1;i<=a[0];i++)  
      {a[i]-=b[i];  
       if (a[i]<0) {a[i+1]--;a[i]+=10;}  
      }  
    a[0]++;  
    while((a[a[0]]==0)&&(a[0]>1)) a[0]--;  
    for(i=a[0];i>=1;i--)  
      printf("%d",a[i]);  
      printf("\n");  
  }                            
  else  
  {  
    printf("-");  //灏忎簬灏辫緭鍑鸿礋鍙? 
    for(i=1;i<=b[0];i++)  //鍋氭寜浣嶅噺锛屽ぇ鐨勫噺灏忕殑  
      {b[i]-=a[i];  
       if (b[i]<0) {b[i+1]--;b[i]+=10;}  
      }  
    b[0]++;  
    while((b[b[0]]==0)&&(b[0]>1)) b[0]--;  
    for(i=b[0];i>=1;i--)  
      printf("%d",b[i]);  
    printf("\n");          
  }  
  }  
    return 0;
}  
int compare(char* s1,char* s2)  //姣旇緝瀛楃涓诧紙涓や釜鏁帮級鏁板瓧鐨勫ぇ灏忥紝澶т簬绛変簬杩斿洖0锛屽皬浜庤繑鍥?銆? 
{  
  if(strlen(s1)>strlen(s2)) return 0;  //鍏堟瘮杈冮暱搴︼紝鍝釜瀛楃涓查暱锛屽搴旂殑閭ｄ釜鏁板氨澶? 
  if(strlen(s1)<strlen(s2)) return 1;  
  for(int i=0;i<=strlen(s1);i++)  //闀垮害鐩稿悓鏃讹紝灏变竴浣嶄竴浣嶆瘮杈冦€? 
  {  
    if(s1[i]>s2[i]) return 0;  
    if(s1[i]<s2[i]) return 1;                            
  }  
  return 0;   //濡傛灉闀垮害鐩稿悓锛屾瘡涓€浣嶄篃涓€鏍凤紝灏辫繑鍥?锛岃鏄庣浉绛? 
}  