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

namespace DigitalRain{

    //Store the characters want to print in vector v
    std::vector<std::string> Rain::v = { "1","2","3","4","5","6", "7","8","9","0"," ","a","b","c","d","e","f","g","h","j","k","l", "`"
    ,"¬","!","£","$", "%","^","&", "*","(", ")", "-", "_", "+", "=", "{","]","}","[","<",">","@", "~","#","/", "|", "¶", "Ô", "ƒ", "Ø", 
     "Â", "â", "ü", "Ç", "Æ", "Ü", "¿"};

    //Default constructor
    Rain::Rain() {
        numChars = v.size();
        SetWidth(100);
        SetFlipsPerColumn(2);
        SetFallSpeed(170);
        columns = new bool[width];
    }

    //All Argument Initialise Constructor 
    Rain::Rain(int w, int flips, int speed)
        : width(w), flipsPerColumn(flips), fallSpeed(speed),
        numChars(v.size()), columns(new bool[width])
    {
     
    }

    // Copy constructor
    Rain::Rain(const Rain& r)
        : width{ r.width }, flipsPerColumn{ r.flipsPerColumn },
        fallSpeed{ r.fallSpeed },  numChars{ r.numChars }, columns{ new bool[width] }
    {
#if VERBOSE
        std::cout << "Digital Rain Copy Constructor " << std::endl;

#endif
    }

    //Rain Destructor
    Rain::~Rain()
    {
    #if VERBOSE
        std::cout << "Rain DESTRUCTOR" << std::endl;
    #endif
    }

    //Assign Copy Constructor
    Rain& Rain::operator=(const Rain& r)
    {
#if VERBOSE
        std::cout << "Digital Rain Copy Assign Operator " << std::endl;

#endif
        width = r.width;
        flipsPerColumn = r.flipsPerColumn;
        fallSpeed = r.fallSpeed;
        
        return *this;

    }



    void Rain::flipColumns() {
        for (int i = 0; i != flipsPerColumn; ++i) {
            int x = rng() % width;
            columns[x] = !columns[x];
        }
    }

    void Rain::run() {

        std::random_device r; // get random seed from hardware
        rng = std::default_random_engine(r()); // initialize random number generator

        for (int i = 0; i < width; i++) {
            columns[i] = false;
        }

        int offset = 0;  // initial offset to prints out in a 45degrees
        while (true) {
            for (auto i = 0; i < width; ++i) {
                int index = (i + offset) % width;  // index for accessing columns
                if (columns[index]) {
                    std::cout << v[rng() % numChars] << " ";
                }
                else {
                    std::cout << "  ";
                }
              
            }
            std::cout << std::endl;
            flipColumns();
            std::this_thread::sleep_for(std::chrono::milliseconds(fallSpeed));
            offset++;  // increment offset for next iteration
        }
    }

    void Rain::run(int slope) {

        std::random_device r; // get random seed from hardware
        rng = std::default_random_engine(r()); // initialize random number generator
           
        for (int i = 0; i < width; i++) {
            columns[i] = false;
        }

        int offset = slope;  // setting the slope value to the offset to define the angle
        while (true) {
            for (auto i = 0; i < width; ++i) {
                int index = (i + offset) % width;  // index for accessing columns
                if (columns[index]) {
                    std::cout << v[rng() % numChars] << " ";
                }
                else {
                    std::cout << "  ";
                }

            }
            std::cout << std::endl;
            flipColumns();
            std::this_thread::sleep_for(std::chrono::milliseconds(fallSpeed));
            offset += slope;
        }
    }
  

    void Rain::SetWidth(int w)
    {
        width = w;
    }

    void Rain::SetFlipsPerColumn(int flips) {
        flipsPerColumn = flips;
    }

    void Rain::SetFallSpeed(int s) {
        fallSpeed = s;
    }
}