
#include <iostream>
#include <vector>


using namespace std;


int main (){
vector <int> myvector;
 myvector.push_back(4);
 myvector.push_back(30);
 myvector.push_back(40);
 myvector.push_back(50); 
 myvector.push_back(60); 
 myvector.push_back(6);
 myvector.push_back(7);
 myvector.push_back(24);
 myvector.push_back(21);

cout<<"vector:";
for(unsigned int i=0;i<myvector.size();i++){
 cout<<myvector[i]<<" ";
 }
 myvector.insert(myvector.begin()+5,100);
 
 cout<<endl<<"vector:";

for (unsigned int i=0;i<myvector.size();i++){
    cout<<myvector[i]<<" ";
}
    myvector.pop_back();
    myvector.pop_back();
     cout<<endl<<"vector:";
    for (unsigned int i=0;i<myvector.size();i++){
    cout<<myvector[i]<<" ";
}
if(myvector.empty()){
    
    cout<<endl<<"its empty!"; 
}
else{
    cout<<endl<<"its not empty";
}
 cout<<endl;
    return 0;
}
    

