/*
_|_|_|_|_|    _|_|     _|      _|
     _|      _|    _|  _|_|    _|
     _|      _|_|_|_|  _|  _|  _|
     _|      _|    _|  _|    _|_|
     _|      _|    _|  _|      _|
     ***************************
     Student Name : TAN MIN HAN
     Student ID: G00377211
     Project : Digital Rain
     ***************************
*/

#include "rain.h"
#include "TestRain.h"

void RunRain() {
    /*Test Member Variable*/

    //TestWidth();
    //TestFlips();
    //TestFallSpeed();

    /*Test Constructors*/
    TestDefaultRain();
    //TestAllArgsRain();
    //TestCopyRain();
    //TestAssignCopyRain();
}


void TestWidth() {
    DigitalRain::Rain r;
    r.SetWidth(10);
    std::cout << r.GetWidth() << std::endl;
}

void TestFallSpeed() {
    DigitalRain::Rain r;
    r.SetFallSpeed(88);
    std::cout << r.GetFallSpeed() << std::endl;
}

void TestFlips() {
    DigitalRain::Rain r;
    r.SetFlipsPerColumn(8);
    std::cout << r.GetFlipsPerColumn() << std::endl;
}


/*Printing in Black Background and Aqua Words
    * First String = Background Colour
    * Second String = Words Colour
    * A : LIGHT GREEN           1 : BLUE
    * B : LIGHT AQUA            2 : GREEN
    * C : LIGHT RED             3 : AQUA
    * D : LIGHT PURPLE          4 : RED
    *
    * For more colors codes, please refer to https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
    * */

void TestDefaultRain() {
    system("Color 0C");

    DigitalRain::Rain r1;
    r1.run(2);
}

void TestAllArgsRain() {
    system("Color 0B");

    DigitalRain::Rain r(70, 4, 180);

    r.run(3);
}

void TestCopyRain() {
    DigitalRain::Rain r(80, 2, 180);
    DigitalRain::Rain rCopy(r);
    system("Color 0D");

    rCopy.run();
}


void TestAssignCopyRain() {
    DigitalRain::Rain r(90, 3, 200);
    DigitalRain::Rain r1;
    r1 = r;


    r1.run(1);
}


