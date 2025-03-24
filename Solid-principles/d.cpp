#include<bits/stdc++.h>
using namespace std;

// D- Dependency Inversion Principle (DIP)

//High-level modules should not depend on low-level modules. Instead, both should depend on abstractions.

class FileLogger {
public:
    void log(const std::string& message) {
        std::cout << "Logging to file: " << message << std::endl;
    }
};

class Application1 {
private:
    FileLogger logger;  // Direct dependency
public:
    void run() {
        logger.log("Application started");
    }
};


//Application is tightly coupled to FileLogger

// Changing the logging mechanism (e.g., logging to the cloud) requires modifying Application

// good code:- 

class ILogger {
public:
    virtual void log(const std::string& message) const = 0;
    virtual ~ILogger() {}
};

class FileLogger : public ILogger {
public:
    void log(const std::string& message) const override {
        std::cout << "Logging to file: " << message << std::endl;
    }
};

class CloudLogger : public ILogger {
public:
    void log(const std::string& message) const override {
        std::cout << "Logging to cloud: " << message << std::endl;
    }
};

class Application {
private:
    ILogger& logger;  // Depend on abstraction
public:
    Application(ILogger& log) : logger(log) {}

    void run() {
        logger.log("Application started");
    }
};

int main() {
    FileLogger fileLogger;
    CloudLogger cloudLogger;

    Application app1(fileLogger);
    app1.run();

    Application app2(cloudLogger);
    app2.run();

    return 0;
}


//ILogger is an abstraction
//Application depends on ILogger, allowing different logging implementations