//#include<iostream>
//using namespace std;
//
//struct StructName{
//	int udbhav;
//	double udbhav1;
//};
//class ud{
//	public:
//		int a;
//		string s;
//	 ud(){
//			cout<<"hey..!!";
//		}
//};
//int main(){
//	StructName st;
//	st.udbhav=10;
//	st.udbhav1=10.09;
//	cout<<st.udbhav<<" \n";
//	cout<<st.udbhav1<<"\n";
//	
//	ud obj;
//	obj.a=56;
//	obj.s="Anshu";
//	
//	cout<<obj.a<<"\n";
//	cout<<obj.s<<"\n";
////	cout<<obj.ud()<<"\n";
//    ud();
//}

#include <iostream>  
//#include <conio.h>  
using namespace std;  
class Hello {  
public:  
  //Constructor  
  Hello () {  
    cout<< "Constructor function is called" <<endl;  
  }  
  //Destructor  
  ~Hello () {  
    cout << "Destructor function is called" <<endl;  
   }   
};  
int main(){  
   //Object created  
   Hello obj;  
   //Member function called  
//   obj.display();  
   return 0;  
}  
