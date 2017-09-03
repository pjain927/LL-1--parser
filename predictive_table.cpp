#include<iostream>
#include<stack>
using namespace std;
int findv(char x,char var[],int v){
    for(int i=0;i<v;i++)
        if(var[i]==x)
            return i;
    return -1;
}
int main(){
    int v,i,t,j,cp=0,flag=1;
    cout<<"Enter no. of variables : - ";
    cin>>v;

    cout<<"Enter no. of terminals : - ";
    cin>>t;

    char var[v],term[t];
    cout<<"Enter the variables : - ";
    for(i=0;i<v;i++)
        cin>>var[i];

    cout<<"Enter the terminals : - ";
    for(i=0;i<t;i++)
        cin>>term[i];

    string table[v][t];
    cout<<"\t";
    for(i=0;i<t;i++)
        cout<<term[i]<<"\t";
    cout<<endl;

    for(i=0;i<v;i++){
        cout<<var[i]<<"\t";
        for(j=0;j<t;j++){
            cin>>table[i][j];
        }
    }
    cout<<endl;
    string str;
    cout<<"Enter string to Parse : - ";
    getline(cin>>ws,str);
    str+="$";

    stack <char> pp;
    pp.push('$');
    pp.push(var[0]);
    string temp;
    while(!pp.empty()){
        if(pp.top()=='$' && cp==str.length()-1)
                break;
        while(pp.top()==str[cp] && cp!=str.length()-1){
            pp.pop();
            cp++;
        }
        if(pp.top()=='$' && str[cp]=='$')
            break;
        int vindex=findv(pp.top(),var,v);
        int tindex=findv(str[cp],term,t);
        cout<<vindex<<" "<<tindex<<endl;
        if(vindex==-1 && tindex==-1)//case where the parsing has completed
            break;
        if(vindex==-1 && tindex>=0){
            //case where the stack becomes empty but the parser cursor has not yet parsed completely
            flag=0;
            break;
        }
        temp=table[vindex][tindex];
        if(temp == "-"){
            flag=0;
            break;//String cannot be parsed
        }
        else if(temp =="NULL"){
            pp.pop();
        }
        else{
            pp.pop();
            for(i=temp.length()-1;i>=0;i--)
                pp.push(temp[i]);
        }
    }

    if(flag==1)
        cout<<"String can be parsed";
    else
        cout<<"String cannot be parsed";
    return 0;
}
