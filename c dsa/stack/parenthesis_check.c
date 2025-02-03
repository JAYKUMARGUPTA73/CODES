#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30    //"don't use ; at end here"
char stack[max];
int top=-1;
void push(char c){
    if(top==max-1){
        printf("Stack-overflow.\n");
        exit(1);
    }else{
        top++;
        stack[top]=c;
    }
}
int pop(){
    if(top==-1){
        printf("Stack-underflow.\n");
        return -1;
    }else{
        int temp=top;
        top--;
        return temp;
    }
}
int match(char a,char b){
    if(a=='[' && b==']'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    return 0;

}
int main(){
    char exp[max];
    printf("Enter your expression.\n");
    scanf("%[^\n]%*c",exp);
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]!=' '){
            if(exp[i]=='[' || exp[i]=='{' || exp[i]=='('){
                push(exp[i]);
            }
            if(exp[i]==']' || exp[i]=='}' || exp[i]==')'){
                int temp=pop();
                if(temp!=-1){
                if(match(exp[i],exp[temp])){
                    printf("parenthesis doesn't match.\n");
                    exit(1);
                }

                }else{
                    printf("left parenthesis are more than right parenthesis.\n");
                    exit(1);
                }
            }
        }
    }
    if(top==-1){
        printf("valid expression.\n");
    }else{
        printf("Right parenthesis is more than left parenthesis.\n");
    }

    
}