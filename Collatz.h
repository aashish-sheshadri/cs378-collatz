// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h
#define CACHE_SIZE 10000000
//#define CACHE_SIZE 56991483520 
// --------
// includes
// --------

#include <iostream> // istream, ostream

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream&, int&, int&);

// ------------
// collatz_lazy_cache
// -----------

/**
 * stores lazy cache
 * @param num for which collatz length is required 
 * @return int collatz sequence length for input
 */
int collatz_lazy_cache(unsigned int);
 
// ------------
// collatz_compute
// -----------

/**
 * computes collatz length
 * @param num for which collatz length is required 
 * @return int length of collatz sequence for input
 */
int collatz_compute(unsigned int);
 
// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
