//
// Created by Haake on 11/2/2020.
//

#ifndef P4_PATIENT_H
#define P4_PATIENT_H


class Patient {
public:
    Patient();
    int compareTo(const Patient &other) const;
    std::string toString() const;
private:
    std::string name;
    std::string priorityCode;
    int arrivalOrder;
    int patientNumber;
};


#endif //P4_PATIENT_H
