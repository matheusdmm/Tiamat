/*------------------------------------------------------*
*                        
*                   ,     \    /      ,        
*                  / \    )\__/(     / \       
*                 /   \  (_\  /_)   /   \      
*            ____/_____\__\@  @/___/_____\____ 
*           |             |\../|              |
*           |              \VV/               |
*           |             TIAMAT              |
*           |_________________________________|
*           |    /\ /      \\       \ /\    | 
*           |  /   V        ))       V   \  | 
*           |/     `       //        '     \| 
*           `              \\               '
*                           V
*
*               Mem, bit & HEX hacking lib
*               For Arduino & others.
*
*   "From your womb: The vacuum between code and hardware
*   And your eyes turned into tears of bits while your
*   Tail compiles into pure chaos."
*   
*
*                 Matheus ------ oct/2021
*
*   For more explanations and usage, see:
*       ./examples/tiamat    
*
*                         V 0.3
*------------------------------------------------------*/

//
//  Use this file to test already implemented functions on TIAMAT_H_
//  Please, if you're testing new things before implementation, 
//  use the playground.cpp file.
//

//  Changelog:
//  
//
//
//
//
//
/*------------------------------------------------------*/
/* ================ TIAMAT - MAIN TESTS  ================ */
#include "tiamat.hpp"
#include <iostream>

int main(void) {

    // int to binary 
    int test = 234;
    int testBinary = toBinary(test);
    std::cout << "base 10: " << test << " binary: " << testBinary << "\n\n";

    // binary to int
    int testBinaryToInt = toInt(testBinary);
    std::cout << "binary: " << testBinary << " base 10: " << testBinaryToInt << "\n\n";

    // POW 
    // First base, then exponent
    int exponent = 2;
    int testPown = pown(test, exponent);
    std::cout << "value of: " << test << " elevated at " << exponent << " pow: " << testPown << "\n\n";

    // Get min
    int testGetMin = getMin(test, exponent);
    std::cout << "the min betweem " << test << " and " << exponent << " is: " << testGetMin << "\n\n";

    int testGetMax = getMax(test, exponent);
    std::cout << "the max betweem " << test << " and " << exponent << " is: " << testGetMax << "\n\n";

    // Log(n)
    float log2Test = log2(16.0);
    std::cout << "Log2 of 16 is: " << log2Test << "\n\n";

    float fastLogTest = fastLog(16.0);
    std::cout << "Fast Log of 16.0 is: " << fastLogTest << "\n\n";

    // Square Root
    float squareRootTest = sqrt(50);
    std::cout << "Square root of 50 with 4 decimal precision is: " << squareRootTest << "\n\n";

    // Inverse square root
    float inverseSquareRootTest = inverseSqrt(256);
    std::cout << "Inverse square root of 256: " << inverseSquareRootTest << "\n\n\n";


    // To hex
    int n = 2545;
    int b = toHex(n);
    std::cout << "HEX OF 1245 is: " << b << "\n\n";



    system ("pause");
	return EXIT_SUCCESS;
}
/* ================ TIAMAT - MAIN TESTS  ================ */