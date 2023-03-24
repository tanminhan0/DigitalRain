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

#ifndef RAIN_H
#define RAIN_H

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <random>

#define VERBOSE 0

namespace DigitalRain {
    class Rain {
        public:
            Rain(); //Default Constructor
            Rain(int ,int ,int); //All Arguments Constructor
            Rain(const Rain& r); //Copy Constructor
            ~Rain(); //Destructor
            Rain& operator=(const Rain&); // Assign Copy Operators

            void run();
            void run(int);

            void SetFallSpeed(int);
            int GetFallSpeed() const { return fallSpeed; };

            void SetFlipsPerColumn(int);
            int GetFlipsPerColumn() const { return flipsPerColumn; };

            void SetWidth(int);
            int GetWidth() const { return width; };

        private:
            int width;
            int flipsPerColumn;
            int fallSpeed;
            int numChars;
            static std::vector<std::string> v;
            bool* columns;
            void flipColumns();
            std::default_random_engine rng;
        };
}
#endif
