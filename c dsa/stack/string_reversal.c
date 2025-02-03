#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 30
int top=-1;
char stack[max];
void push(char c){
    if(top==max-1){
        printf("stack-overflow.\n");
        exit(1);
    }else{
        top++;
        stack[top]=c;
    }
}
int pop(){
    if(top==-1){
        printf("stack-underflow.\n");
        return -1;
    }else{
        int temp=top;
        top--;
        return temp;
    }
}
int main(){
    char string1[max];
    printf("Enter your string.\n");
    scanf("%[^\n]%*c",string1);//"%[^\n]s",%[] is scanset specifiers,* discards new-line-c(xor)
    
    for(int i=0;i<strlen(string1);i++){
        push(string1[i]);
    }
    //pop command
    for(int i=0;i<strlen(string1);i++){
        int index=pop();
        printf("%c",stack[index]);
    }
    
}
//observations:
//macros values can't be changed("lvalue required as decrement operand");
//buffers are areas of memory set to hold data(gets() has issue of b-overflow)
//buffer overflow isan anomaly whereby a program writes data beyond its buffer's allocated memory.