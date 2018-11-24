// This file compares COOPS to C++.
#include <iostream>
using namespace std;

// I see a benefit already: No unexplainable errors!

class String {
    const char *cString; // Hmm, C++ has private variables
public:
    // Woohoo, C++ has constructors!
    String(const char *cStr) {
        // "this" exists
        this->cString = cStr;
    }
    // 2 benefits here:
    // 1. Classes are types in C++
    // 2. You can define methods inside classes
    static String *fromCString(const char *cStr) {
        return new String(cStr);
    }
    const char *getCString() { return this->cString; }
};
class Tester {
public:
    static String *msg;
    static void test() {
        cout << msg;
    }
};
class Meeper {
    // Again, constructors, and also not everything is static in C++.
public:
    // Oh, I forgot, automatic constructors!
    void meep(String *msg) {
        // I had forgotten how much I love cout.
        cout << "Meep!\n" << msg->getCString() << "\nMeep!\n";
    }
};

main(int argc, char const *argv[])
{
    // Note: C++ has a dangerous amount of intellisense
    String *theMsg = String::fromCString("Hello!");
    // g++ says no to Tester after compilation
    //Tester::msg = String::fromCString("Hi!");
    //Tester::test();
    // Hey, look, an actual initialization operator!
    Meeper *myMeeper = new Meeper();
    myMeeper->meep(theMsg);
    //Tester::msg = String::fromCString("Hello there, world of OOPS!");
    //Tester::test();
    return 0;
}
// It works without Tester...?
// It says "undefined reference to Tester::msg."
// Humph.
// C++ is kinda nice.
// It's also a lot more readable.
// Humph. I'll leave it at that, but please at least try COOPS.