//NAME: PrecondViolatedExcep.cpp
//DESC: implementation of PrecondViolatedException
//USAGE: #include "PrecondViolatedExcep.cpp"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018
#include <stdexcept>
#include <string>

#include "PrecondViolatedExcep.h"

using namespace std;

//constructor
//pre:a message is passed
//post:displays error message with the string
PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}
