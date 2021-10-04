```
*------------------------------------------------------*
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
*   Show me the great treasures that only such life 
*   could possibly bring. And yet again, here you are.
*   
*                          0.3
*------------------------------------------------------*
```

# ========= Manual & Documentation =========

### What is Tiamat?
    Tiamat is a Single Header Math, Bit & Hex hacking lib,
    it has so many included functions and implementations
    without the need to call thousands of another libraries.

    Some of the implementations are faster than anothers, but
    overall it is a fast and improving library with the Main
    usage in embedded systems, but not only that.

    Some implementations are aproximations with n(x)
    margin of error, but again, good enough to run on an
    embedded system who needs to compute thousands of things.

    Tiamat is fully compatible with ANSI C, and from the start
    it was planned to be writen only in C, but with the majority 
    of controllers using C++, the need to change it has arrived.

        



### Main features:

    Tiamat handles at this point:
    - Int conversion to binary (up to X base 10):
        At this moment, it uses a long type integer because of 
        practicity and future proofing.

    - Binary conversion to base 10 (up to X bin):
        At this moment, it uses a long type integer because of 
        practicity and future proofing.

    - Integer to Hexadecimal: 
        At this moment, it uses a char to return the value.

    - Binary to Hexadecimal:
        Uses a char type to return the value.

    - Elevate X at Y potency:
        Double type function that acepts two long integers.

    - Check if the number is even or odd:
        
    - Get the minimal value between X and Y min(X, Y):

    - Get the maximal value between X and Y max(X, Y):

    - 


### Known bugs:


### Usage:
    See the tiamat_test.cpp to simple usage, also see the tiamat_arduino_test.ino to see a basic project usage.
    

### License:
    GPLv3


### Credits:
    Matheus da Fonseca Dummer
    
