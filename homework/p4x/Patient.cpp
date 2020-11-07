//
// Created by Kramer Johnson on 11/2/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 4
// kjohnson5@seattleu.edu
//


#include "Patient.h"

Patient::Patient() {
    this->name = "Gandalf Grey";
    this->priorityCode = "minimal";
    this->arrivalOrder = ++patientNumber;
}

Patient::Patient(const std::string &name, const std::string &priorityCode) {
    this->name = name;
    this-> priorityCode = priorityCode;
    this->arrivalOrder = ++patientNumber;
}

Patient::Patient(const std::string &name, const std::string &priorityCode, int arrivalOrder) {
    this->name = name;
    this-> priorityCode = priorityCode;
    this->arrivalOrder = arrivalOrder;
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

int Patient::getArrivalOrder() const {
    return arrivalOrder;
}

std::string Patient::getPriorityCode() const {
    return priorityCode;
}
