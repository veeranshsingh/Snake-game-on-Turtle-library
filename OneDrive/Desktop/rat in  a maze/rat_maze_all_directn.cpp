#include<bits/stdc++.h>
using namespace std;
int sol[100][100]={0};
bool solved(vector<string> &v,int n,int m,int i,int j){
    if(i==n-1 && j==m-1){
        sol[i][j]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return true;
    }
    sol[i][j]=1;
                               // right
        if(j+1<m && v[i][j+1]!='X' && sol[i][j+1]==0){// not equal to 'x'and never visited before
            if(solved(v,n,m,i,j+1)){
                    return true;
            }
        }
        //down
        if(i+1<n && v[i+1][j]!='X' && sol[i+1][j]==0){
            if(solved(v,n,m,i+1,j)){
                return true;
            }
        }
        if(i-1>=0 && v[i-1][j]!='X' && sol[i-1][j]==0){
            if(solved(v,n,m,i-1,j)){
                return true;
            }
        }
        if(j-1>=0 && v[i][j-1]!='X' && sol[i][j-1]==0){
            if(solved(v,n,m,i,j-1)){
                return true;
            }
        }
        sol[i][j]=0;
        return false;
    }

    

int main(){

    int n,m;
    cin>>n>>m;// n-> rows and m->cols
    

    vector<string> v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         char x;

         cin>>x;  
         v[i].push_back(x); 
        }
    }
    v[0][0]='1';
    solved(v,n,m,0,0);
    cout<<endl;
    // if(what==false)
	// cout<<"NO PATH FOUND"<<endl;

    return 0;
}
