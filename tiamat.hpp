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
*            C/C++ Math, bit & HEX hacking lib
*                For x86, Arduino & others.
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
*                         V 0.8
*------------------------------------------------------*/
/* ======== TIAMAT ======== */
#ifndef TIAMAT_H_
#define TIAMAT_H_ // !TIAMAT_H_
#pragma once

#include <stdbool.h>

/* ======== PROTOTYPES AND DECLARATIONS ======== */
/* binary operations */

long toBinary(long n);

long toInt(long bin);

char binToHex(int bin);

char toHex(int num);

void xorSwap(long *x, long *y);

/* math operations */

double pown(long base, long exponent);

float inverseSqrt(float number);

float sqrt(float number, int precision);

float log2(float x);

float fastLog(float x);

float lerp(float a, float b, float t);

float ilerp(float a, float b, float v);

float remap(float inputMin, float inputMax, 
            float outputMin, float outputMax, float v);

float clamp(float d, float min, float max);

double linearCombination(double p, double q, double divisor);

double oddOrEven(long x);

long getMin(long x, long y);

long getMax(long x, long y);

/* bithack operations */

int isNbitSet(int x, int n);

int setNthBit(int x, int n);

int unsetNthBit(int x, int n);

int toggleNthBit(int x, int n);

int turnOffRightmost1Bit(int x, int n);

int isolateTheRightmost1Bit(int x, int n);

int isolateTheRightmost0Bit(int x, int n);

int countBits(unsigned int v, unsigned int c);

int trailing(unsigned int v);

/* memory related operations */

// --- NULL --- 

/* search operations */

long linearSearch(long *p, long b, long find);

long binarySearch(long array[], long start, long end, long element);

/* sorting operations */

void quickSort(long array[], long start, long end);

/* ======== BINARY OPERATIONS ======== */

// XOR Swap
// Change two values without temporary cache
void xorSwap(long *x, long *y) {
    if (x != y) {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
    return;
}


// Takes an integer and converts to binary
// Returns a long with its value
long toBinary(long n) {
    int i = 0;
    long number = 0;

    while (n >= 1) {
        number = pown(10, i) * (n % 2) + number;

        n = n / 2;
        i++;
    }
    return number;
}

// Convert binary to int
// returns a long
long toInt(long bin) {
    int remanescent, buffer, i;
    buffer = 0;
    i = 0;

    while (bin != 0) {
        remanescent = bin % 10;
        bin /= 10;
        buffer += remanescent * pown(2, i);
        ++i;
    }
    return buffer;
}

// Convert a binary number to HEX format
// returns a char
char binToHex(int bin) {
    int n = 0;

    bin = toInt(bin);
    n = toHex(bin);
    return n;
}

// Integer to HEX
// At the moment, its capped at numbers until +-2147483647.
// Returns a char
char toHex(int num) {
    char hexa[50];
    int i, j;
    
    i = 0;
    j = 0;

    while (num > 0) {
        int temp = 0;
        temp = num % 16;

        if (temp < 10) {
            hexa[i] = temp + 48;
            i++;
        }
        else {
            hexa[i] = temp + 55;
            i++;
        }
        num = num / 16;
    }

    for (int j = i - 1; j >= 0; j--) {
        return hexa[j];
    }
    return hexa[j];
}

long hexToInt(char hex) {
    return hex;
}


// TODO
long hexToBin(char hex) {
    int convert = hexToInt(hex);
    int temp = toBinary(convert);
    return temp;
}

/* ======== MATH OPERATIONS ======== */

// X to the power of N
// as in 2 to the power of 3 = 2 * 2 * 2 for example.
double pown(long base, long exponent) {
    long double result = 1.0;

    while (exponent != 0) {
        result *= base;
        --exponent;
    }
    return result;
}

// Fast inverse square root DOOM STYLE
// Returns a float.
float inverseSqrt(float number) {
    long i;
    float x2, y;

    const float threeHalfs = 1.5f;

    x2 = number * 0.5f;
    y = number;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1); // wtf
    y = *(float *)&i;
    y = y * (threeHalfs - (x2 * y * y));

    return y;
}

// Standard square root algorithm with normalization to N=4 decimal places.
// Returns a float.
float sqrt(float number) {   
    int precision;
    float start, end, mid, answer;
 
    // Decimal places normalization
    precision = 4;
    start = 0;
    end = number;
 
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            answer = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    float increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (answer * answer <= number) {
            answer += increment;
        }
        answer = answer - increment;
        increment = increment / 10;
    }
    return answer;
}

// logX / logY = result
float log2(float x) {
    return ((x > 1.0f) ? 1.0f + log2(x / 2.0f) : 0);
}

// logX = result
// Fast AS FUCK but not very precise
float fastLog(float x) {
    return (log2(x) * 0.69314718f);
}

// Clamp
// Limits a value for both max and min of a range
// Useful with LERP and ILERP
float clamp (float d, float min, float max) {
    const float t = d < min ? min : d;
    return t > max ? max : t;
}


// LERP - Linear Interpolation
// Blends a & b and gives a value  of the blend 
// based on t
float lerp(float a, float b, float t) {
    float value = (a * (1.0f - t)) + (b * t);
    return value;
}

// Inverse LERP - Inverse Linear Interpolation
// Returns a fractional t based on blend between a & b
float ilerp(float a, float b, float v) {
    float t = (v - a) / (b - a);
    return t;
}

// REMAP
float remap(float inputMin, float inputMax, float outputMin, 
            float outputMax, float v) {
    float t = ilerp(inputMin, inputMax, v);
    float output = lerp(outputMin, outputMax, t);
    return output;
}


// Linear combination
// TODO
double linearCombination(double x, double y, double divisor) {
    return x;
}

// Derivative 
float derivative(float n) {
    return n;
}

// Checks if X is even, and if its even, then returns X
// Else returns NULL.
double oddOrEven(long x) {
    if ((x & 1) == 0) {
        return x;
    }
    else {
        return 0;
    }
}

// Get the MIN from a min max comparison
// min(X, Y)
long getMin(long x, long y) {
    int j = (y ^ ((x ^ y) & -(x < y)));
    return j;
}

// Get the MAX from a min max comparison
// max(X, Y)
long getMax(long x, long y) {
    int j = (x ^ ((x ^ y) & -(x < y)));
    return j;
}

/* ======== BITHACKFUCKERY ======== */

// Check if the N-th bit set
// Where X is the binary and N is the nth number
int isNbitSet(int x, int n) {
    if (x & (1 << n)) {
        return n;
    }
    else {

    }
    return x;
}

// Set the n-th bit
// Where X is the binary and N is the nth number
int setNthBit(int x, int n) {
    int y = (x | (1 << n));
    return y;
}

// Unset the n-th bit
// Where X is the binary and N is the nth number
int unsetNthBit(int x, int n) {
    int y = (x & ~(1 << n));
    return y;
}

// Toggle the n-th bit
// Where X is the binary and N is the nth number
int toggleNthBit(int x, int n) {
    int y = (x ^ (1 << n));
    return y;
}

// Rightmost bit is the least significant one
// always in the far right

// Turn off the rightmost 1BIT
// Where X is the binary and N is the nth number
int turnOffRightmost1Bit(int x, int n) {
    int y = (x & (x - 1));
    return y;
}

// Isolate the rightmost 1BIT
// Where X is the binary and N is the nth number
int isolateTheRightmost1Bit(int x, int n) {
    int y = (x & (~x));
    return y;
}

// Isolate the rightmost 0BIT
// Where X is the binary and N is the nth number
int isolateTheRightmost0Bit(int x, int n) {
    int y = (x | (x + 1));
    return y;
}

// Brian Kernighan's style of counting bits
// V count the number of bits in V
// C accumulates the total bits set in V
int countBits(unsigned int v, unsigned int c) {
    v &= v - 1;
    return v;
}

// Trailing - count the consecutive zeros on the right linearly
// V input to count trailing zero bits
// C will count Vs trailing
// And if V is 1101000, then C will be 3
// Because 3 zeros
int trailing(unsigned int v) {
    // unsigned int v;
    int c;

    if (v) {
        v = ((v ^ (v - 1)) >> 1);

        for (c = 0; v; c++) {
            v >>= 1;
        }
    }
    else {
        c = __CHAR_BIT__ * sizeof(v);
    }
    return v;
}

/* ======== RAM FUCKERY ======== */

/* takes input and reads from it in RAM */
void memoryAccess(int a, int b, char c) {

}

// Hex address fuckery
// Change proccesses in real time
void hexChange(int a, int b, int c) {

}

/* ======== SEARCH ======== */

// Linear simple
// checks if int or char is null and then
// searches for it
long linearSearch(long *p, long b, long find) {
    long c;

    for (c = 0; c < b; c++) {
        if (*(p + c) == find) { 
            return c;
            }
        }
    return -1;
}

// Recursive binary search
// FAST AF BOI
// Input the array, the start & end and then the element for search;
long binarySearch(long array[], long start, long end, long element) {
    if (end >= start) {
        long middle = start + (end - start) / 2;

        if (array[middle] == element) {
            return middle;
        }
        if (array[middle] > element) {
            return binarySearch(array, start, middle - 1, element);
        }
        return binarySearch(array, middle + 1, end, element);
    }
    return -1;
}

/* ======== SORT ======== */

// Quick sort
// inputs an array, the start element and the end element
// Needs to have the array initialized
void quickSort(long array[], long start, long end) {
    long i, j, pivot, temp;

    if (start < end) {
        pivot = start;
        i = start;
        j = end;

        while (i < j) {
            while (array[i] <= array[pivot]) {
                j++;
            }
            while (array[j] > array[pivot]) {
                j--;
            }

            if (i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[j] = temp;
        quickSort(array, start, j - 1);
        quickSort(array, j + 1, end);
    }
}

// RADIX
// Still bugged
void radixSort(int *a, int n) {
    #define I for (i = n - 1; i >= 0; i--)
    #define J for (i = 0; i < 256; i++)
    #define R for (r = 0; r < 4; r++)
    #define F(p, q, k) I p[--c[k][q[i] >> 8 * k & 255]] = q[i]

        int *A = a, i, r, x, c[4][257], B[1 << 20];

        R J c[r][i] = 0;
        I {
            x = A[i] ^= A[i] >> 31 | 1 << 31;
            R c[r][x >> 8 * r & 255]++;
        }
        J R c[r][i + 1] += c[r][i];

        F(B, A, 0);
        F(A, B, 1);
        F(B, A, 2);
        F(A, B, 3) ^ (~B[i] >> 31 | 1 << 31);
}

#endif // !TIAMAT_H_