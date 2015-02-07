/* Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm, Sam Seng

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license.
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "grading/TestCase.h"

const std::string assignment_message = "";

// Submission parameters
const int max_submissions = 20;
const int submission_penalty = 5;

// Compile-time parameters
const int max_clocktime = 2;		// in seconds
const int max_cputime = 2;			// in seconds
const int max_submission_size = 100000;	// in KB
const int max_output_size = 100000;	// in KB
	// OTHERS?

// Grading parameters
const int total_pts = 14;
const int auto_pts = 14;
const int ta_pts = 0;
const int extra_credit_pts = 0;


// Test cases
std::vector<TestCase> testcases
{

/************* README AND COMPILATION *****************/

  TestCase::MakeCompilation
  (
   "Compilation of Submitted Files (for Dr. Memory): g++ -m32 -g -Wall *cpp -o submitted_32.out",
   "/usr/bin/clang++ -m32 -g -Wall -o submitted_32.out -- *.cpp",
   "submitted_32.out",	
   TestCasePoints(2)
   ),

  TestCase::MakeCompilation
  (
   "Compilation of Submitted Files (for Valgrind): g++ -g -Wall *cpp -o submitted.out",
   "/usr/bin/clang++ -g -Wall -o submitted.out -- *.cpp",
   "submitted.out",
   TestCasePoints(2)
   ),

/******************** TEST CASES **********************/


TestCase::MakeTestCase
  (
   "Under Dr Memory",
   "drmemory -brief -- ./submitted_32.out",
   "/projects/submit3/drmemory/bin/drmemory  -brief -- ./submitted_32.out",
   TestCasePoints(5),
   new TestCaseComparison(&errorIfEmpty,"STDOUT.txt","STDOUT"),
   new TestCaseTokens(&searchToken,"STDERR.txt","STDERR", std::vector<std::string>(1,std::string("NO ERRORS FOUND:")))
   ),

TestCase::MakeTestCase
  (
   "Under Valgrind",
   "valgrind --leak-check=full ./submitted.out",
   "/usr/bin/valgrind --leak-check=full ./submitted.out",
   TestCasePoints(5),
   new TestCaseComparison(&errorIfEmpty,"STDOUT.txt","STDOUT"),
   new TestCaseTokens(&searchToken,"STDERR.txt","STDERR", std::vector<std::string>(1,std::string("ERROR SUMMARY: 0 errors from 0 contexts")))
   )

};


#endif
