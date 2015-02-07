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
const int max_clocktime = 10;		// in seconds
const int max_cputime = 10;			// in seconds
const int max_submission_size = 100000;	// in KB
const int max_output_size = 100000;	// in KB

// Grading parameters
const int total_pts = 50;
const int auto_pts = 25;
const int ta_pts = 25;
const int extra_credit_pts = 5;

// Test cases
std::vector<TestCase> testcases
{
    /************* README AND COMPILATION *****************/

    TestCase::MakeFileExists(
    "README",
    "README.txt",
    TestCasePoints(2)
    ),

    TestCase::MakeCompilation(
    "Compilation",
    "/usr/bin/g++ -Wall -o a.out -- *.cpp",
    "a.out",		// name of .exe created by student
    TestCasePoints(3)
    ),

    /******************** TEST CASES **********************/
    TestCase::MakeTestCase(
        "left justify example",                                 // title
        "./justify.exe example.txt output.txt 16 flush_left",   // details
        "./a.out example.txt output.txt 16 flush_left",	        // command
        TestCasePoints(3),                                      // points=0, hidden=false, extra_credit=false, view_test_case=true,  view_points=false
        new TestCaseComparison(&myersDiffbyLinebyChar,		    // compare function [V]
            "output.txt",					                    // output file name [V]
            "output.txt",					                    // output file description
            "example_16_flush_left.txt",                        // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "right justify example",                                // title
        "./justify.exe example.txt output.txt 16 flush_right",  // details
        "./a.out example.txt output.txt 16 flush_right",        // command
        TestCasePoints(3),                                      // points=0, hidden=false, extra_credit=false, view_test_case=true,  view_points=false
        new TestCaseComparison(&myersDiffbyLinebyChar,          // compare function [V]
            "output.txt",                                       // output file name [V]
            "output.txt",                                       // output file description
            "example_16_flush_right.txt",                       // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "full justify example",                                 // title
        "./justify.exe example.txt output.txt 16 full_justify", // details
        "./a.out example.txt output.txt 16 full_justify",       // command
        TestCasePoints(4),                                      // points=0, hidden=false, extra_credit=false, view_test_case=true,  view_points=false 
        new TestCaseComparison(&myersDiffbyLinebyChar,          // compare function [V]
            "output.txt",                                       // output file name [V]
            "output.txt",                                       // output file description
            "example_16_full_justify.txt",                      // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "left justify gettysburg address",                                  // title
        "./justify.exe gettysburg_address.txt output.txt 70 flush_left",    // details
        "./a.out gettysburg_address.txt output.txt 70 flush_left",          // command
        TestCasePoints(2,true,false),                                       // hidden, not extra credit
        new TestCaseComparison(&myersDiffbyLinebyChar,                      // compare function [V]
            "output.txt",                                                   // output file name [V]
            "output.txt",                                                   // output file description
            "gettysburg_address_70_flush_left.txt",                         // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "right justify gettysburg address",                                 // title
        "./justify.exe gettysburg_address.txt output.txt 70 flush_right",   // details
        "./a.out gettysburg_address.txt output.txt 70 flush_right",         // command
        TestCasePoints(2,true,false),                                       // hidden, not extra credit
        new TestCaseComparison(&myersDiffbyLinebyChar,                      // compare function [V]
            "output.txt",                                                   // output file name [V]
            "output.txt",                                                   // output file description
            "gettysburg_address_70_flush_right.txt",                        // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "full justify gettysburg address",                                  // title
        "./justify.exe gettysburg_address.txt output.txt 70 full_justify",  // details
        "./a.out gettysburg_address.txt output.txt 70 full_justify",        // command
        TestCasePoints(3),
        new TestCaseComparison(&myersDiffbyLinebyChar,                      // compare function [V]
            "output.txt",                                                   // output file name [V]
            "output.txt",                                                   // output file description
            "gettysburg_address_70_full_justify.txt",                       // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "full justify long word",                                       // title
        "./justify.exe long_word.txt output.txt 15 full_justify",       // details
        "./a.out long_word.txt output.txt 15 full_justify",             // command
        TestCasePoints(3),
        new TestCaseComparison(&myersDiffbyLinebyChar,                  // compare function [V]
            "output.txt",                                               // output file name [V]
            "output.txt",                                               // output file description
            "long_word_15_full_justify.txt",                            // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        "lengthier document",                                           // title
        "./justify.exe hidden_input.txt output.txt 100 full_justify",	// details
        "./a.out hansel_and_gretel.txt output.txt 100 full_justify",	// command
        TestCasePoints(3,true,true),                                    // hidden, extra credit!
        new TestCaseComparison(&myersDiffbyLinebyChar,			       	// compare function [V]
            "output.txt",                                               // output file name [V]
            "output.txt",                                               // output file description
            "hansel_and_gretel_100_full_justify.txt",                   // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        ),
    TestCase::MakeTestCase(
        " lots of long words",                                          // title
        "./justify.exe hidden_input.txt output.txt 20 flush_right",     // details
        "./a.out longestwords.txt output.txt 20 flush_right",           // command
        TestCasePoints(2,true,true),                                    // hidden,extra credit
        new TestCaseComparison(&myersDiffbyLinebyChar,                  // compare function [V]
            "output.txt",                                               // output file name [V]
            "output.txt",                                               // output file description
            "longestwords_20_flush_right.txt",                          // expected output file [V]
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        )
};


#endif
