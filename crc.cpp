#include<bits/stdc++.h>
#include<string.h>
using namespace std;

const string g= "1101" ;

int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

bool receiverSide(string codeWord){
  int i,j,divisions= codeWord.length()-g.length()+1;
  bool flag= true;
  for( i=0; i<divisions ; i++) {
    if(codeWord[i] == '1') {
      for( j=0; j<g.length() ;j++) {
        if(codeWord[i+j] == g[j]) 
          codeWord[i+j] = '0';
        else codeWord[i+j]='1';
      } }else{
        for( j=0; j<g.length() ;j++) {
        if(codeWord[i+j] == '0') 
          codeWord[i+j] = '0';
        else codeWord[i+j]='1';
      }
    }

    if(codeWord[i] == '1'){
      flag=false;
    }
  }

  for (; i<codeWord.length(); i++){
    if(codeWord[i]=='1')
      flag = false;
  }

  cout <<"\ncodeWord:"<<codeWord<<"  flag:"<<flag;

  return flag;
}

int main() {
    string data, result, temp;

    cout<<"Enter the data to be transfered: ";
    cin>>data;
    temp=data;
    cout<<"\n data:"<<data;
    for(int i=1 ; i<g.length() ; i++) {
        data.push_back('0');
    }
    
    cout<<"\n data.:"<<data;
    int no_of_divisions = ( data.length() - g.length() + 1 );
    
    
    for(int i=0; i<no_of_divisions ; i++) {
        cout<<"\n";

        if( data[i] == '1' ){
            for(int j=0; j<g.length() ; j++) {
                cout<<"  "<<data[i+j]<<"^"<<g[j];
                if(data[i+j] == g[j]) {
                    data[i+j] = '0';
                    cout<<"="<<data[i+j];
                } else {
                    data[i+j] = '1';
                    cout<<"="<<data[i+j];

                }
            }
        }else{
            for(int j=0; j<g.length() ; j++) {
                cout<<"  "<<data[i+j]<<"^"<<g[j];
                if(data[i+j] == '0') {
                    cout<<"="<<data[i+j];
                    data[i+j] = '0';
                } else {
                    cout<<"="<<data[i+j];
                    data[i+j] = '1';
                }
            }
        }
    }
    cout<<"\n Result:"<<data;

    for( int i=temp.length() ; i< data.length() ; i++ ) {
        temp.push_back(data[i]);
    }

/*
    10001000000100001
*/
    return 0;
