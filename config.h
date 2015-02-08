#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "grading/TestCase.h"

const std::string assignment_message = "";


// Submission parameters
const int max_submissions = 200;
const int submission_penalty = 0;


// Compile-time parameters
const int max_cputime = 2;		// in seconds, per test case
const int max_submission_size = 10000;	// in KB, entire submission (could be zip file)
const int max_output_size =     1000;	// in KB, per created output file



// Grading parameters
const int total_pts = 3;
const int auto_pts = 3;
const int ta_pts = 0;
const int extra_credit_pts = 0;

std::vector<TestCase> testcases
{
	TestCase::MakeTest(
		"MyAnacondaDontWantNone",
		"python answer > output.txt",
		"python student > output.txt",
		TestCasePoints(3)
		new TestCaseComparison(&myersDiffbyLinebyChar,		    
            "output.txt",					                    
            "output.txt",					                                           
            1
            ),
        new TestCaseComparison(&warnIfNotEmpty,"STDOUT.txt","STDOUT","", 0),
        new TestCaseComparison(&warnIfNotEmpty,"STDERR.txt","STDERR","", 0)
        )
};