/*Copyright (c) 2014, Chris Berger, Jesse Freitas, Severin Ibarluzea,
Kiana McNellis, Kienan Knight-Boehm

All rights reserved.
This code is licensed using the BSD "3-Clause" license. Please refer to
"LICENSE.md" for the full license
*/

#include <vector>
#include <string>

#ifndef GRADINGRUBRIC_H_
#define GRADINGRUBRIC_H_

class GradingRubric{
public:

    GradingRubric();

    // ACCESSORS

    int getCompilation() const;
    int getNonHiddenTotal() const;
    int getHiddenTotal() const;
    int getNonHiddenExtraCredit() const;
    int getExtraCredit() const;
    int getTotal() const;
    int getTotalAfterTA() const;

    // PRIVATE VARIABLE ACCESSORS

    int getSubmissionPenalty() const;
    int getNonHiddenReadme() const;
    int getNonHiddenCompilation() const;
    int getHiddenCompilation() const;
    int getHiddenTesting() const;
    int getTAPoints() const;

    // MODIFIERSs

    void setSubmissionPenalty(
            int number_of_submissions,
            int max_submissions,
            int max_penalty);

    void incrREADME(int points, bool hidden);
    void incrCompilation(int points, bool hidden);
    void incrTesting(int points, bool hidden, bool extra_credit);
    void setTA(int points);


    // TEST CASE CODE

    void VerifyTotalAfterTA(int expected_total) const;
    void AddTestCaseResult(bool hidden,
            const std::string & full_message,
            const std::string & hidden_message);
    int NumTestCases() const;
    void GetTestCase(int index, bool & test_case_hidden,
            std::string & test_case_full_messages,
            std::string & test_case_hidden_messages) const;


private:

    // HW Points

    int _nonhidden_readme;
    int _nonhidden_compilation;
    int _nonhidden_testing;
    int _hidden_readme;
    int _hidden_compilation;
    int _hidden_testing;
    int _ta_points;
    int _submission_penalty;
    int _hidden_extra_credit;
    int _nonhidden_extra_credit;

    std::vector<bool> _test_case_hidden;
    std::vector<std::string> _test_case_full_messages;
    std::vector<std::string> _test_case_hidden_messages;

};
#include "GradingRubric.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

// Constructor

GradingRubric::GradingRubric() {

    // Initialize all scores to 0

    _nonhidden_readme = 0;
    _nonhidden_compilation = 0;
    _nonhidden_testing = 0;
    _hidden_readme = 0;
    _hidden_compilation = 0;
    _hidden_testing = 0;
    _ta_points = 0;
    _submission_penalty = 0;
    _hidden_extra_credit = 0;
    _nonhidden_extra_credit = 0;

}

// ACCESSORS

int GradingRubric::getCompilation() const {
    return  _nonhidden_compilation +
            _hidden_compilation;
}

int GradingRubric::getNonHiddenTotal() const {
    return  _submission_penalty +
            _nonhidden_readme +
            _nonhidden_compilation +
            _nonhidden_testing +
            _nonhidden_extra_credit;
}

int GradingRubric::getHiddenTotal() const {
    return  _hidden_readme +
            _hidden_compilation +
            _hidden_testing +
            _hidden_extra_credit;
}

int GradingRubric::getNonHiddenExtraCredit() const {
    return _nonhidden_extra_credit;
}

int GradingRubric::getExtraCredit() const {
    return  _hidden_extra_credit +
            _nonhidden_extra_credit;
}

// Returns total number of hidden and nonhidden points (does
// not include TA's grade)
int GradingRubric::getTotal() const {
    return  getNonHiddenTotal() +
            getHiddenTotal();
}

// Returns total including the TA's grade
int GradingRubric::getTotalAfterTA() const {
    return  getTotal() +
            _ta_points;
}


// PRIVATE VARIABLE ACCESSORS

int GradingRubric::getSubmissionPenalty() const {
	return _submission_penalty;
}

int GradingRubric::getNonHiddenReadme() const {
	return _nonhidden_readme;
}

int GradingRubric::getNonHiddenCompilation() const {
	return _nonhidden_compilation;
}

int GradingRubric::getHiddenCompilation() const {
	return _hidden_compilation;
}

int GradingRubric::getHiddenTesting() const {
	return _hidden_testing;
}

int GradingRubric::getTAPoints() const {
	return _ta_points;
}


// MODIFIERS

// Set submission penalty based on number of submissions and the
// max number of submissions allowed, (10 submissions = -1 point)
void GradingRubric::setSubmissionPenalty(
        int number_of_submissions,
        int max_submissions,
        int max_penalty) {

        // Number of points to lose (if negative, it has no effect)
        // TODO 10 is the number of assignments to deduct 1 point,
        // should this be configurable?
        int penalty = (number_of_submissions - max_submissions)/10;

    _submission_penalty =
            -std::max(0, std::min(max_penalty, penalty));
}

// Increase README points on rubric
void GradingRubric::incrREADME(int points, bool hidden) {
    if (hidden) _nonhidden_readme += points;
    else _hidden_readme += points;
}

// Increase compilation points on rubric
void GradingRubric::incrCompilation(int points, bool hidden) {
    if (hidden) _nonhidden_compilation += points;
    else _hidden_compilation += points;
}

// Increase testing points on rubric
void GradingRubric::incrTesting(int points, bool hidden,
        bool extra_credit) {
    if (!hidden && extra_credit == 0){
        _nonhidden_testing += points;
    }else if (!hidden && extra_credit){
        _nonhidden_extra_credit += points;
    }else if (hidden && extra_credit == 0){
        _hidden_testing += points;
    }else if (hidden && extra_credit){
        _hidden_extra_credit += points;
    }
}

// Set TA points
// TODO more descriptive name?
void GradingRubric::setTA(int points){
    _ta_points += points;
}


// TEST CASE CODE

// Causes error if expected total is different than the
// calculated total in rubric
void GradingRubric::VerifyTotalAfterTA(int expected_total) const {
    if (getTotalAfterTA() != expected_total){
        std::cerr << "ERROR! Expected TotalAfterTA() " << getTotalAfterTA() <<
                " != " << expected_total << std::endl;
        exit(0);
    }
}

// Adds test case to rubric
void GradingRubric::AddTestCaseResult(bool hidden,
        const std::string& full_message, const std::string& hidden_message) {
    _test_case_hidden.push_back(hidden);
    _test_case_full_messages.push_back(full_message);
    _test_case_hidden_messages.push_back(hidden_message);
}

// Returns total number of test cases in rubric
int GradingRubric::NumTestCases() const {
    int arraySizeA = _test_case_hidden.size();
    int arraySizeB = _test_case_full_messages.size();
    int arraySizeC = _test_case_hidden_messages.size();
    if (arraySizeA != arraySizeB || arraySizeA != arraySizeC){
        std::cerr << "ARRAYS NOT EQUAL SIZE" << std::endl;
        exit(0);
    }
    return arraySizeA;
}

// Sets provided strings to test case number {index}
// A bad index (under 0 or above total number of test cases)
// will cause an error
void GradingRubric::GetTestCase(int index, bool& test_case_hidden,
        std::string& test_case_full_messages,
        std::string& test_case_hidden_messages) const {
    if (index < 0 || index > NumTestCases()){
        std::cerr << "BAD TEST CASE NUMBER " << index << std::endl;
        exit(0);
    }
    test_case_hidden = _test_case_hidden[index];
    test_case_full_messages = _test_case_full_messages[index];
    test_case_hidden_messages = _test_case_hidden_messages[index];
}

#endif