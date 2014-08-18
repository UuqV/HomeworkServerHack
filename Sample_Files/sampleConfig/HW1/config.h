/* Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm, Sam Seng

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license.
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "grading/TestCase.h"
//#include "GradingRubric.h"

const std::string id = "HW1";
const std::string name = "Text Justification";
const std::string due_date = "2014-05-15 11:59:59.0";

// Compile Command (executed in student FILES directory)
//const std::string compile_command = "g++ -g *.cpp";  /* should not be in config file */

// Submission parameters
const int max_submissions = 20;
const int submission_penalty = 5;

// Compile-time parameters
const int max_clocktime = 2;		// in seconds
const int max_cputime = 2;			// in seconds
const int max_output_size = 100;	// in KB
	// OTHERS?

// Grading parameters
const int total_pts = 50;
const int auto_pts = 30;
//const int readme_pts = 2;
//const int compile_pts = 3;
const int ta_pts = 20;

// File directories

// input files directory
const char* input_dir = "test_input/hw1/";
//../../CSCI1200/testingInput/HW1";
// expected output files directory
const char* expected_out_dir = "test_output/hw1/";
//../../CSCI1200/Scripts/expectedOutput/HW1/";

// Test cases
const int num_testcases = 11;

TestCase testcases[11] = {

/************* README AND COMPILATION *****************/

TestCase(
	"README",
	"",
	"FILE_EXISTS",
	"README.txt",
	"",
	"",
	2, //readme_pts,				// points for readme
	false,
	false,
	DONT_CHECK,
	DONT_CHECK,
	false,
	"",
	NULL
),
TestCase(
	"Compilation",
	"",
	"FILE_EXISTS",
	"a.out",		// name of .exe created by student
	"",
	"",
	3, //compile_pts,				// points for compilation
	false,
	false,
	DONT_CHECK,
	DONT_CHECK,
	false,
	"",
	NULL
),

/******************** TEST CASES **********************/
TestCase(
	"left justify example",							// title
	"./justify.exe example.txt output.txt 16 flush_left",						// details
	"./a.out example.txt output.txt 16 flush_left",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",					// output file description
	"example_16_flush_left.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar				// compare function [V]
),
TestCase(
	"right justify example",							// title
	"./justify.exe example.txt output.txt 16 flush_right",						// details
	"./a.out example.txt output.txt 16 flush_right",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"example_16_flush_right.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar				// compare function [V]
),
TestCase(
	"full justify example",							// title
	"./justify.exe example.txt output.txt 16 full_justify",						// details
	"./a.out example.txt output.txt 16 full_justify",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"example_16_full_justify.txt",				// expected output file [V]
	4,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"left justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 70 flush_left",						// details
	"./a.out gettysburg_address.txt output.txt 70 flush_left",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_flush_left.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"right justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 70 flush_right",						// details
	"./a.out gettysburg_address.txt output.txt 70 flush_right",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_flush_right.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"full justify gettysburg address",							// title
	"./justify.exe gettysburg_address.txt output.txt 70 full_justify",	// details
	"./a.out gettysburg_address.txt output.txt 70 full_justify",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"gettysburg_address_70_full_justify.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"full justify long word",							// title
	"./justify.exe long_word.txt output.txt 15 full_justify",	// details
	"./a.out long_word.txt output.txt 15 full_justify",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"long_word_15_full_justify.txt",				// expected output file [V]
	3,									// points [V]
	false,								// hidden [V]
	false,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	"lengthier document",							// title
	"./justify.exe hidden_input.txt output.txt 100 full_justify",	// details
	"./a.out hansel_and_gretel.txt output.txt 100 full_justify",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"hansel_and_gretel_100_full_justify.txt",				// expected output file [V]
	3,									// points [V]
	true,								// hidden [V]
	true,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
),
TestCase(
	" lots of long words",							// title
	"./justify.exe hidden_input.txt output.txt 20 flush_right",	// details
	"./a.out longestwords.txt output.txt 20 flush_right",	// command
	"output.txt",					// output file name [V]
	"Expected output.txt",				// output file description
	"longestwords_20_flush_right.txt",				// expected output file [V]
	2,									// points [V]
	true,								// hidden [V]
	true,								// extra credit [V]
	WARN_IF_NOT_EMPTY,					// check cout? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	WARN_IF_NOT_EMPTY,					// check cerr? [DONT_CHECK, WARN_IF_NOT_EMPTY, CHECK] [V]
	false, 								// recompilation
	"",									// recompilation command
	&myersDiffbyLinesByChar							// compare function [V]
)
};

//TestCase* readmeTestCase = &testcases[0];
TestCase* compileTestCase = &testcases[1];

#endif
