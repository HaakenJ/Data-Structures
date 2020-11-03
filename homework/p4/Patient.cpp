//
// Created by Haake on 11/2/2020.
//

#include "Patient.h"

Patient::Patient() {
    this->name = "Gandalf Grey";
    this->priorityCode = "minimal";
    this->arrivalOrder = ++patientNumber;
}

Patient::Patient(const std::string &n, const std::string p) {
    this->name = n;
    this-> priorityCode = p;
    this->arrivalOrder = ++patientNumber;
}

int Patient::compareTo(const Patient &other) const {
    if (priority.at(this->priorityCode) < priority.at(other.priorityCode))
        return -1;
    else if (priority.at(this->priorityCode) > priority.at(other.priorityCode))
        return 1;
    else if (this->arrivalOrder <= other.arrivalOrder)
        return -1;
    return 1;

}

std::string Patient::toString() const {
    return std::__cxx11::string();
}

int Patient::patientNumber = 0;
