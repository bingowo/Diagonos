  #include<stdio.h>  
  #include<stdlib.h>  
  #include<string.h>  
  int main()  
  {char s[1000],t[1000];  
  scanf("%s",s);    
  int k=0;    
  for(int i=0;i<strlen(s);i++)  //16进制转转为2进制    
  { int d;        
    if(s[i]>='A') d=s[i]-'A'+10;        
    else d=s[i]-'0';        
    unsigned int flag=0x8;        
    while(flag)        
    { if(d&flag) t[k++]='1';            
      else t[k++]='0';            
      flag=flag>>1;} }      
      long long int qr=0,qi=0;    
      long long int a,b;    
      for(int i=0;i<k;i++)   //计算复数整数    
      { int r=t[i]-'0';       
        a=-qr-qi+r;     
        b=qr-qi;        
        qr=a;qi=b;    }    
      printf("%d,%lld",r,qi);
      return 0;
  }