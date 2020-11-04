//
// Created by Haake on 11/2/2020.
//

#ifndef P4_PATIENT_H
#define P4_PATIENT_H

#include <iostream>
#include <map>

class Patient {
public:
    Patient();
    Patient(const std::string &name, const std::string priorityCode);
    int compareTo(const Patient &other) const;
    std::string toString() const;

    int getPatientNumer() {
        return patientNumber;
    }

    int getArrivalNum() {
        return arrivalOrder;
    }
private:
    static int patientNumber;
    std::map<std::string, int> priorMap = {
            {"immediate", 1},
            {"emergency", 2},
            {"urgent", 3},
            {"minimal", 4}
    };
    std::string name;
    std::string priorityCode;
    int arrivalOrder;
};


#endif //P4_PATIENT_H
