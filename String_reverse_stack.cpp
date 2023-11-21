#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

void Reverse(char *x, int y){
    stack<char> temp;

    for(int i = 0; i < y; i++){
        temp.push(x[i]);
    }

    for(int j = 0; j < y; j++){
        x[j] = temp.top();
        temp.pop();
    }
}

int main()
{
    char name[50];
    cout<<"Enter a name: \n";
    cin>>name;
    int z = strlen(name);

    Reverse(name, z);

    cout<<name;
}