#include<iostream>
#include<set>
using namespace std;
int checks(char s,char arr[],int n){
    for(int i=0;i<n;i++)
        if(arr[i]==s)
            return 1;
    return 0;
}
int findi(char s,char arr[],int n){
    for(int i=0;i<n;i++)
        if(arr[i]==s)
            return i;
}
//subs for saving production of variables
struct subs{
    set <string> production;
};
//sub for saving first of variables
struct sub{
    set <char> production;
};
int main(){
    int v,t,i,j;
    cout<<"Enter no. of variables: - ";
    cin>>v;
    cout<<"Enter no. of terminals: - ";
    cin>>t;
    char var[v],term[t];
    cout<<"Enter variables : - ";
    for(i=0;i<v;i++)
        cin>>var[i];
    cout<<"Enter terminals : - ";
    for(i=0;i<t;i++)
        cin>>term[i];
    subs fsv[v];
    for(i=0;i<v;i++){
        int x;
        cout<<"Enter no. of productions for "<<var[i]<<" : - ";
        cin>>x;
        cout<<"Enter productions for "<<var[i]<<" : -";
        for(j=0;j<x;j++){
            string str;
            cin>>str;
            fsv[i].production.insert(str);
        }
    }
    cout<<"Productions : - \n";
    for(i=0;i<v;i++){
        cout<<var[i]<<"-> ";
        for(set<string> :: iterator it = fsv[i].production.begin();it!=fsv[i].production.end();it++){
            cout<<*it<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
    sub first[v];
    //top to down approach
    for(i=0;i<v;i++){
        for(set<string> :: iterator it = fsv[i].production.begin();it!=fsv[i].production.end();it++){
            string temp=*it;
            if(temp=="NULL")
                first[i].production.insert('-');
            else if(checks(temp[0],term,t)){
                first[i].production.insert(temp[0]);
            }
            else{
                int index=findi(temp[0],var,v);
                for(set<char> :: iterator ij=first[index].production.begin();ij!=first[index].production.end();ij++)
                    first[i].production.insert(*ij);
            }
        }
    }
    //bottom to up approach
    for(i=v-1;i>=0;i--){
        for(set<string> :: iterator it = fsv[i].production.begin();it!=fsv[i].production.end();it++){
            string temp=*it;
            if(temp=="NULL")
                first[i].production.insert('-');
            else if(checks(temp[0],term,t)){
                first[i].production.insert(temp[0]);
            }
            else{
                int index=findi(temp[0],var,v);
                for(set<char> :: iterator ij=first[index].production.begin();ij!=first[index].production.end();ij++)
                    first[i].production.insert(*ij);
            }
        }
    }
     for(i=0;i<v;i++){
        cout<<"First("<<var[i]<<")= { ";
        for(set<char> :: iterator it = first[i].production.begin();it!=first[i].production.end();it++){
            cout<<*it<<" , ";
        }
        cout<<"}"<<endl;
    }

    /*sub follow[v];
    follow[0].production.insert('$');
    for(i=0;i<v;i++){
        for(set<string> :: iterator it = fsv[i].production.begin();it!=fsv[i].production.end();it++){
            string temp=*it;
            if(temp!="NULL"){
                for(j=0;j<temp.length();j++){
                    if(checks(temp[j],term,t)){
                        //nothing has to be done while getting a terminal
                    }
                    else{
                        int index=findi(temp[j],var,v);
                        if(j+1<temp.length()){

                        }
                        else{
                            for(set<char> :: iterator ij = follow[i].production.begin;ij!=follow[i].end();ij++){
                                        follow[index].production.insert(*ij);
                            }
                        }
                    }
                }
            }
        }
    }*/
    return 0;
}
