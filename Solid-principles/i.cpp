#include<bits/stdc++.h>
using namespace std;

// I-  Interface Segregation Principle
//Clients should not be forced to depend on interfaces they do not use.

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : public Worker {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }

    void eat() override {
        throw std::logic_error("Robots do not eat!");
    }
};


// Problem:- Robot is forced to implement eat(), which is not relevant.

// good code:- 

class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class Human : public Workable, public Eatable {
public:
    void work() override {
        std::cout << "Human is working" << std::endl;
    }

    void eat() override {
        std::cout << "Human is eating" << std::endl;
    }
};

class Robot : public Workable {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
};

//Separate Workable and Eatable interfaces
//Robot does not depend on Eatable

