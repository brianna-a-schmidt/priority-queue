#include <stdexcept>
#include <string>

#include "PrecondViolatedExcep.h"

using namespace std;

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}
