//
// Created by Haake on 11/2/2020.
//

#include "Patient.h"

Patient::Patient() {
    this->name = "Gandalf Grey";
    this->priorityCode = "minimal";
    this->arrivalOrder = ++patientNumber;
}

Patient::Patient(const std::string &n, const std::string &p) {
    this->name = n;
    this-> priorityCode = p;
    this->arrivalOrder = ++patientNumber;
}

int Patient::compareTo(const Patient &other) const {
    if (priorMap.at(this->priorityCode) < priorMap.at(other.priorityCode))
        return -1;
    else if (priorMap.at(this->priorityCode) > priorMap.at(other.priorityCode))
        return 1;
    else if (this->arrivalOrder <= other.arrivalOrder)
        return -1;
    else
        return 1;

}

std::string Patient::toString() const {
    return name + " " + "{ pri=" +
                    priorityCode +
                    ", arrival=" +
                    std::to_string(arrivalOrder) +
                    " }";
}

std::string Patient::getName() const {
    return name;
}

int Patient::patientNumber = 0;
