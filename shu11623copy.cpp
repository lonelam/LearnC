#include<iostream>
 #include<string>
 #include<sstream>
 using namespace std;
 int main(){
     int x,n,i=0;
     long sum;
     string line;
     while(getline(cin,line)){
         istringstream iss(line);
         sum=0;
         n=0;
         while(iss>>x){
             sum+=x;
             n++;
         }
         cout<<"Case"<<++i<<": "<<n<<", "<<sum<<endl;
     } 
     return 0;
     
 }
