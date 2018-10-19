//NAME:PrecondViolatedExcep.h
//DESC: specification of PrecondViolatedExcep class
//USAGE: #include "PrecondViolatedExcep.h"
//COMPILER: GNU g++ compiler on Linux
//AUTHOR: Bri Schmidt
//LAST UPDATED: October 18, 2018

#ifndef PRECOND_VIOLATED_EXCEP_
#define PRECOND_VIOLATED_EXCEP_

#include <stdexcept>
#include <string>

/** @class PrecondViolatedExcep PrecondViolatedExcep.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcep : public std::logic_error
{
public:
    PrecondViolatedExcep(const std::string& message = "");
};


#endif
