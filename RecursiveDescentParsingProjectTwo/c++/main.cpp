#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int A();
int E();
int P(int k);
int L();
int I();
int UI();
int UL();

string data;
int i,j;

int main(){
    ifstream infile; 
    infile.open("/Users/johnnymayo/Documents/GitHub/CS280/RecursiveDescentParsingProjectTwo/c++/input.txt");
    //  infile.open("input.txt");

    while(!infile.eof()) {
        i=0;
        j=0;
        infile >> data; 
        
        if(A()!=-1&&i==data.length())
            cout<<data<<" is in the language.\n";
        else
            cout<<data<<" is not in the language.\n";
    }
    infile.close();
    return 0;
}

int A() {
    if(I()!=-1) {
        i=j;
        if(data[i++]=='=') {
            if(E()!=-1)
                return 0;
        } else {
            i=0;
            if(E()!=-1)
                return 0;
        }
    } else {
        i=0;
        if(E()!=-1)
        return 0;
    }
    return -1;
}

int E() {
        if(P(-1)!=-1) {
        if(i==data.length())
            return 0;
        else {
            if(data[i]=='+'||data[i]=='-'||data[i]=='*'||data[i]=='/') {
                i++;
                if(P(1)!=-1)
                    return 0;
            }
        }
    }
    return -1;
}


int P(int k) {
    if(I()!=-1){

        if(k==-1){
            i=j;
            return 0;
        }
    else {
        if(j==data.length()){
            i=j;
            return 0;
        }
        else
            return E();
        }

    }

    else if(L()!=-1)
    {
    if(k==-1)
    {
    i=j;
    return 0;
    }
    else 
    {
    if(j==data.length())
    {
    i=j;
    return 0;
    }
    else
    return E();
    }
    }

    else if(UI()!=-1)
    {
    if(k==-1)
    {
    i=j;
    return 0;
    }
    else 
    {
    if(j==data.length())
    {
    i=j;
    return 0;
    }
    else
    return E();
    }
    }

    else if(UL()!=-1)
    {
    if(k==-1)
    {
    i=j;
    return 0;
    }
    else 
    {
    if(j==data.length())
    {
    i=j;
    return 0;
    }
    else 
    return E();
    }
    }
    else if(k==1)
    return E();
    else
    return -1;
    return -1;
}


int L(){
    j=i;
    while(j<data.length()){
        if(data[j]>='0'&&data[j]<='9')
            j++;
        else
            break;
    }

    if(j==i)
        return -1;
    else
        return 0;
}

int I(){
    j=i;
    while(j<data.length()){
        if(data[j]>='a'&&data[j]<='z')
            j++;
        else
            break;
    }

    if(j==i)
        return -1;
    else
        return 0;
}

int UI(){
    j=i;
    int k=i;

    if(j<data.length()&&(data[j]=='+'||data[j]=='-'||data[j]=='!')){
        j++;
        i=j;

        if(I()!=-1){
            i=j;
            return 0;
        }
    }

    i=k;
    return -1;
}

int UL(){
    j=i;
    int k=i;

    if(j<data.length()&&(data[j]=='+'||data[j]=='-'||data[j]=='!')){

        j++;
        i=j;
        if(L()!=-1){

            i=j;
            return 0;
        }
    }

    i=k;
    return -1;
}