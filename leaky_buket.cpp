#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, dataRate, bucketSize, outputRate=0, contents=0;

    cout<<"Enter size of bucket:";
    cin>>bucketSize;
    cout<<"Enter output rate:";
    cin>>outputRate;
    cout<<"Enter number of iterations:";
    cin>>n;

    for(int i=0; i<n ; i++ ) {

        contents -= outputRate;
        if(contents < 0) contents = 0;

        cout<<"Enter packet size";
        cin>>dataRate;
        if( dataRate > bucketSize ){
            cout<<"\n Frame size is greater than bucket size\n";
            continue;
        }

        if( dataRate > ( bucketSize - contents ) ) {
            cout<<"\n Bucket overflow\n";
            continue;
        } else {

            contents += dataRate ;
            cout<<"\n Added to bucket\n Current bucket contents:"<<contents;

        }




    }



}
