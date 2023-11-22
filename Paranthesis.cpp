#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool Is_balanced(char* x, int y){
    stack<char> temp;
    for(int i=0; i<y; i++){
        if((x[i] == '(')||(x[i] == '[')||(x[i] == '{')){
            temp.push(x[i]);
        }
        else if(x[i] = ')'){
            if(temp.top() != '('){
                return false;
            }
            else{
                temp.pop();
            }
        }
        else if(x[i] = ']'){
            if(temp.top() != '['){
                return false;
            }
            else{
                temp.pop();
            }
        }
        else if(x[i] = '}'){
            if(temp.top() != '{'){
                return false;
            }
            else{
                temp.pop();
            }
        }
    }

    return true;
}

int main(){
    char name[100];
    bool result;
    cout<<"Enter an expression: \n";
    cin>>name;
    result = Is_balanced(name, strlen(name));
    if(result == true){
        cout<<"Balanced"<<endl;
    }
    else if(result == false){
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}