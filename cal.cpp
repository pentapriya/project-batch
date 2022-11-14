//modified code for addtion of two nos

#include<iostream>
using namespace std;
class cal{
        int x,y;
        public:
        cal(){
                x=0;y=0;
        }
        int add(int,int);
        int sub(int,int);
        int mul(int,int);
        //int div(int,int);
};
int cal::add(int x,int y){
        return x+y;
}
int cal::sub(int x,int y){
        return x-y;
}
int cal::mul(int x,int y){
        return x*y;
}
/*int cal::div(int x,int y){
        return x/y;
}*/
int main(){
        cal obj;
        int a,b;
        cout<<"enter numbers"<<endl;
        cin>>a>>b;
        cout<<"addition: "<<obj.add(a,b)<<endl;
        cout<<"subtraction: "<<obj.sub(a,b)<<endl;
        cout<<"product: "<<obj.mul(a,b)<<endl;
        //cout<<"division: "<<obj.div(a,b)<<endl;
        return 0;
}

