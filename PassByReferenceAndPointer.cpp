/********************************************************
* Example of PassByReference                            *
* void populateVector(vector<string>& receivedVector);  *
* populateVector(mainVector);      <- from main()       *
********************************************************/

/********************************************************
* Example 1 of PassByPointer                            *
* void passByPointer(int* receivedIntAddressAsPointer); *
* passByPointer(&dummyInt);      <- from main()         *
********************************************************/

/********************************************************
* Example 2 of PassByPointer                            *
* void passByPointer(int* receivedIntAddressAsPointer); *
* int* addressOfDummyInt = &dummyInt;                   *
* passByPointer(addressOfDummyInt);     <- from main()  *
********************************************************/

// clear && g++ -o newmyexe PassByReferenceAndPointer.cpp && ./newmyexe

// A pointer is a data type which stores memory address of a variable
// Both passing by pointer and passing by reference in C++ allow you to change the ACTUAL variable

#include <iostream>
#include <vector>

using namespace std;

// When we must modify the original vector or any data we must do pass by reference and use & sign
void populateVector(vector<string>& receivedVector){
    for(int i=0;i<receivedVector.size();i++){
        receivedVector.at(i) = "X";
    }
}

// We are just printing and NOT MODIFYING the original data, so we do not need to use neither pass by reference nor & sign
void printVector(vector<string> receivedVector){
    for(int i=0;i<receivedVector.size();i++){
        cout<<receivedVector.at(i)<<" ";
    }
    cout<<endl;
}

// Pass by reference for int value
void passByReference(int& receivedInt){
   receivedInt = 50;
}

// It recieves the memory address. We must dereference it in order to change the actual value
void passByPointer(int* receivedIntAddressAsPointer){
    cout<<"Address from inside passByPointer()           : "<<receivedIntAddressAsPointer<<endl;
    *receivedIntAddressAsPointer += 500;
    cout<<"Value   from inside passByPointer()           : "<<*receivedIntAddressAsPointer<<endl;
}

int main(){
    
    cout<<"Program started....."<<endl;
    
    vector<string> mainVector;
    
    mainVector.push_back("A");
    mainVector.push_back("B");
    mainVector.push_back("C");
    mainVector.push_back("D");
    mainVector.push_back("E");

    populateVector(mainVector);
    printVector(mainVector);
    
    cout<<endl;
    cout<<"PASS BY REFERENCE EXAMPLE....."<<endl;
    cout<<endl;
    
    int test = 100;
    cout<<"Before calling passByReference() function, test is  : "<< test<<endl;
    passByReference(test);
    cout<<"After calling  passByReference() function, test is  : "<< test<<endl;
    
    cout<<endl;
    cout<<"PASS BY POINTER EXAMPLE....."<<endl;
    cout<<endl;   
    
    int dummyInt = 10;
    int* addressOfDummyInt = &dummyInt;
    cout<<"Before calling passByPointer() the value is   : "<< dummyInt<<endl;
    cout<<"Address from inside main() using & sign       : "<<&dummyInt<<endl;
    passByPointer(addressOfDummyInt); //passByPointer(&dummyInt); also works
    cout<<"Address from inside main() using * sign       : "<<addressOfDummyInt<<endl;
    cout<<"After calling passByPointer() the value is    : "<< dummyInt<<endl;
    
    return 0;

}

/*
Program started.....
X X X X X 

PASS BY REFERENCE EXAMPLE.....

Before calling passByReference() function, test is  : 100
After calling  passByReference() function, test is  : 50

PASS BY POINTER EXAMPLE.....

Before calling passByPointer() the value is   : 10
Address from inside main() using & sign       : 0x16b7e2e08
Address from inside passByPointer()           : 0x16b7e2e08
Value   from inside passByPointer()           : 510
Address from inside main() using * sign       : 0x16b7e2e08
After calling passByPointer() the value is    : 510
*/
