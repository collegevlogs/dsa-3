#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void push(int s[10],int *top,int item){
    *top=*top+1;
    s[*top]=item;
}
int pop(int s[10],int *top){
    int item=s[*top];
    *top=*top-1;
    return item;
}
int main(){
    char post[100],ch;
    int s[100],top=-1,res,a,b;
    printf("Enter the valid  numerical postfix Expression:");
    scanf("%s",post);
    
    for(int i=0;i<strlen(post);i++){
        ch=post[i];
        if(isdigit(ch)){
            push(s,&top,ch-'0');
        }else{
            b=pop(s,&top);
            a=pop(s,&top);
            if(ch=='+')res=a+b;
            if(ch=='-')res=a-b;
            if(ch=='*')res=a*b;
            if(ch=='/')res=a/b;
            push(s,&top,res);
        }
     
    }
    printf("\n %d is Evaluated value",res);
   
    return 0;
}