//
// Created by Kramer Johnson on 11/2/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 4
// kjohnson5@seattleu.edu
//

#ifndef P4_PATIENT_H
#define P4_PATIENT_H

#include <iostream>
#include <map>

/**
 * The Patient class represents patients that are awaiting help
 * in the emergency room triage.  The name, priority, and order
 * of each patient is stored.
 */
class Patient {
public:

    /**
     * Default ctor
     */
    Patient();

    /**
     * Ctor that takes a patient's name and priority
     * @param name         the name of the patient
     * @param priorityCode the priority of the patient
     */
    Patient(const std::string &name, const std::string &priorityCode);

    /**
     * Ctor that takes a patient's name, priority, and arrival order
     * The ctor does not increment the number of patients
     * @param name         the name of the patient
     * @param priorityCode the priority of the patient
     * @param arrivalOrder the arrival order of the patient
     */
    Patient(const std::string &name, const std::string &priorityCode, int arrivalOrder);

    /**
     * Compares two Patients to see which patient is more urgent
     * @param other the Patient to compare this Patient to
     * @return      -1 if this Patient is more urgent,
     *               1 if other is more urgent
     */
    int compareTo(const Patient &other) const;

    /**
     * Converts this Patient's info to a string format
     * Name { priority, arrivalOrder }
     * @return string formatted to display a Patient's info
     */
    std::string toString() const;

    /**
     * Get this Patient's name
     * @return the name of this Patient
     */
    std::string getName() const;

    /**
     * Get this Patient's arrival order
     * @return the arrival order of this Patient
     */
     int getArrivalOrder() const;

     /**
     * Get this Patient's priority code
     * @return the priority code of this Patient
     */
     std::string getPriorityCode() const;

private:
    // The number of total Patient instances
    static int patientNumber;

    // Map of priorities to the integer's that represent their value
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
