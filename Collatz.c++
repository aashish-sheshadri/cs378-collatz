// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_lazy_cache
// -----------

int collatz_lazy_cache(unsigned int num){
    assert(num > 0);
    assert(CACHE_SIZE > 0);

    if(num > CACHE_SIZE)
        return collatz_compute(num);
    
    static int lazyCache[CACHE_SIZE] = {};  
   
    if(lazyCache[num] == 0){
        lazyCache[num] = collatz_compute(num);
    }
    return lazyCache[num];
}

// ------------
// collatz_compute
// ------------

int collatz_compute (unsigned int num) {
    assert(num > 0);

    int length = 1;
    while(num!=1){
        if(num % 2 == 0){
            num >>= 1;
        } else {
            num = (num << 1) + num + 1;
        }
        length++;
    }
    return length;
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    
    if(i>j){
        int temp = j;
        j = i;
        i = temp;
    }

    int v = 1;
    while(i<=j) {
        int tempLength = collatz_lazy_cache(i);
        if(v < tempLength){
            v = tempLength;
        }
        i++;
    }
    assert(v > 0);
    return v;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
