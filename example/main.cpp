#include<iostream>
#include"MySharedPtr.h"

using namespace std;


class MyClass {
public:
    MyClass(int a, int b): m_a(a), m_b(b){};

    void setData(int a, int b){
               m_a = a;
               m_b = b;
    }

    void printData(){
        cout << "a = " << m_a << endl;
        cout << "b = " << m_b << endl; 
    }

private:
    int m_a;
    int m_b;
};



int main(){
// //
// // Code example 1 start
// //
// MySharedPtr<int> msp1 (new int (25));
// MySharedPtr<int> msp2 (msp1);

// cout << (*msp2) << endl;
// //
// // Code example 1 end
// // 


// //
// // Code example 2 start
// //
// {
//     MySharedPtr<MyClass> sh_ptr1 = new MyClass(1,2);
//     {
//         MySharedPtr<MyClass> sh_ptr2 = sh_ptr1;
//         sh_ptr2->printData();
//         sh_ptr2->setData(0,0);
//         cout << sh_ptr1.get_count() <<endl;
//     }
//     cout << sh_ptr1.get_count() << endl;
//     sh_ptr1->printData();
// }
// cout << "The Code example 2 is complete" << endl;
// //
// // Code example 2 end
// // 

    // MySharedPtr<int> ptr0(new int(5));
    // MySharedPtr<int> ptr1(new int(5)); 
    // MySharedPtr<int> ptr2 = ptr1;
    // std::cout << "ptr1 count: " << ptr1.get_count() << std::endl;
    // std::cout << "ptr2 count: " << ptr2.get_count() << std::endl;

    // ptr2 = ptr0;
    
    // std::cout << "ptr2 count: " << ptr2.get_count() << std::endl;

    MySharedPtr<int> ptr1(new int(42)); 
    MySharedPtr<int> ptr2(std::move(ptr1));
    std::cout << *ptr2 << std::endl;
    std::cout << ptr2.get_count() << std::endl;
    MySharedPtr<int> ptr3;
    ptr3 = std::move(ptr2); 
    std::cout << *ptr3 << std::endl;


    return 0;
}    
