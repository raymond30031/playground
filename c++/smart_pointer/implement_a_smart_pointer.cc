/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// reference:
// https://www.acodersjourney.com/the-quest-for-a-perfect-c-interview-question/
// https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/garbageCollection/pages/referenceCounting.html
// https://www.geeksforgeeks.org/copy-constructor-in-cpp/

#include <iostream>
#include <string>

class ReferenceCounter {
public:
    void increment(){
        count_++;
    }
    int decrement(){
        return --count_;
    }
    int getCount() const {
       return count_; 
    }
private:
    int count_ = 0;
};

template <typename T>
class smartPtr {
public:
    smartPtr(T* object) 
        : object_(object),
          counter_(new ReferenceCounter()) {
        counter_->increment();
        std::cout<<"Created smart pointer, the count is: "<<counter_->getCount()<<std::endl;
    }
    
    virtual ~smartPtr() {
        if (counter_) {
            int current_count = counter_->decrement();
            // no one is refering to this object
            if (current_count == 0 ){
                delete object_;
                delete counter_;
                object_ = nullptr;
                counter_ = nullptr;
            }
        }
    }
    
    // copy constructor
    // we can access same class private members because access is per class base
    // dont modify the other content and set local pointers to the other's pointers
    smartPtr (const smartPtr<T>& other) {
        object_ = other.object_;
        counter_ = other.counter_;
        counter_->increment();
        std::cout<<"Copy constructor: ref count: "<<counter_->getCount()<<std::endl;
    }
    
    // overload assignment operator
    smartPtr<T>& operator= (const smartPtr<T>& other) {
        // prevent self assignment
        if(this != &other) {
            // check if the object of the pointer that we are replacing
            // needs to be destroyed
            if (counter_ && counter_->decrement() == 0){
                delete object_;
                delete counter_;
            }
            
            // assign this pointer to other pointer
            object_ = other.object_;
            counter_ = other.counter_;
            counter_->increment();
        }
        std::cout<<"Assigning pointer, ref counter = "<<counter_->getCount()<<std::endl;
        return *this;
    }
    
    // dereference operator overload
    T& operator* () {
        return *object_;
    }
    
    // member access operator overload
    T* operator->() {
        return object_;
    }
private:
    T* object_ = nullptr;
    ReferenceCounter* counter_ = nullptr;
};

// driver class
class Driver{
public:
    
    Driver() : name_("No name") {
        std::cout<<"Object with No name is created"<<std::endl;
    }
    
    Driver(const std::string& name) : name_(name) {
        std::cout<<"Object with name "<< name<< " is created"<<std::endl;
    }
    
    ~Driver() {
        std::cout<<"Object with name "<<name_<<" is destroyed"<<std::endl;
    }
    
    void setName(const std::string& new_name) {
        name_ = new_name;
    }
    
private:
  std::string name_;
};

int main()
{
    std::cout<<"Hello World"<<std::endl;
    // object with no name
    smartPtr<Driver> ptr_1(new Driver);
    // test access member
    ptr_1->setName("magic");
    
    // copy constructor
    smartPtr<Driver> ptr_2 = ptr_1;
    // test dereference
    (*ptr_2).setName("not magic");
    
    // test assignment, counter should = 3 now
    smartPtr<Driver> ptr_3(new Driver);
    ptr_3 = ptr_2;
    
    return 0;
}
