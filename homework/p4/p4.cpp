//
// Created by Kevin Lundeen on 10/21/20.
// For Seattle University, CPSC 5005, P4.Triage
//
// Code completed by Kramer Johnson on 11/2/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 4
// kjohnson5@seattleu.edu
//

#include <fstream>
#include <iostream>
#include <string>
#include "Patient.h"
#include "PatientPriorityQueue.h"

using namespace std;

/**
 * Prints help menu.
 */
void help() {
    cout << "add <priority-code> <patient-name>" << endl
         << "            Adds the patient to the triage system." << endl
         << "            <priority-code> must be one of the 4 accepted priority codes:"
         << endl
         << "                1. immediate 2. emergency 3. urgent 4. minimal"
         << endl
         << "            <patient-name>: patient's full legal name (may contain spaces)"
         << endl
         << "next        Announces the patient to be seen next. Takes into account the"
         << endl
         << "            type of emergency and the patient's arrival order."
         << endl
         << "peek        Displays the patient that is next in line, but keeps in queue"
         << endl
         << "list        Displays the list of all patients that are still waiting"
         << endl
         << "            in the order that they have arrived."
         << endl
         << "load <file> Reads the file and executes the command on each line"
         << endl
         << "help        Displays this menu" << endl
         << "quit        Exits the program" << endl;
}

/**
 * Prints welcome message.
 */
void welcome() {
    cout << "******** Welcome to Patient Triage 2020 ********" << endl;
    cout << "      Enter 'Help' to see your options or       " << endl;
    cout << "            enter an option to start            " << endl;
}

/**
 * Prints farewell message.
 */
void goodbye() {
    cout << "****** Thank you for using Patient Triage ******" << endl;
    cout << "                   Goodbye!                     " << endl;
}

/**
 * Delimits (by space) the string from user or file input.
 * @param s string from user or file input (return value is also erased from it)
 * @return the substring of s up to the first space (or to end of string if no
 *         spaces)
 */
string delimitBySpace(string &s) {
    const char delimiter = ' ';
    string result;
    int pos = s.find(delimiter);
    if (pos != string::npos) {
        result = s.substr(0, pos);
        s.erase(0, pos + 1);
    } else {
        result = s;
    }
    return result;
}

/**
 * Remove whitespace from the left side of a string
 * @param str string to remove whitespace from
 * @return    either a substring of str with no whitespace, or
 *            str if there is no whitespace
 */
string ltrim(const string &str) {
    int pos = str.find_first_not_of(' ');
    if (pos != string::npos)
        return str.substr(pos);
    else
        return str;
}

/**
 * Remove whitespace from the right side of a string
 * @param str string to remove whitespace from
 * @return    either a substring of str with no whitespace, or
 *            str if there is no whitespace
 */
string rtrim(const string &str) {
    int pos = str.find_last_not_of(' ');
    if (pos != string::npos)
        return str.substr(0, pos + 1);
    else
        return str;
}

/**
 * Adds the patient to the waiting room.
 * @param line     command line
 * @param priQueue queue to manipulate
 */
void addPatientCmd(string line, PatientPriorityQueue &priQueue) {
    string priority, name;

    // get priority and name
    priority = delimitBySpace(line);
    if (priority.length() == 0) {
        cout << "Error: no priority code given." << endl;
        return;
    }
    name = line;
    if (name.length() == 0) {
        cout << "Error: no patient name given." << endl;
        return;
    }

    // trim whitespace from name and priority
    name = rtrim(ltrim(name));
    priority = rtrim(ltrim(priority));

    // determine if priority is valid
    if (
            priority != "immediate" &&
            priority != "emergency" &&
            priority != "urgent"    &&
            priority != "minimal"
            )
    {
        cout << "Error: priority is invalid." << endl;
        return;
    }

    // add patient
    Patient newPatient(name, priority);
    priQueue.enqueue(newPatient);
    cout << "Added patient \"";
    cout << newPatient.getName();
    cout << "\" to the priority system" << endl;
}

/**
 * Displays the next patient in the waiting room that will be called.
 * @param priQueue queue to manipulate
 */
void peekNextCmd(PatientPriorityQueue &priQueue) {
    cout << "Highest priority patient to be called next: ";
    cout << priQueue.peek().getName() << endl;
}

/**
 * Removes a patient from the waiting room and displays the name on the screen.
 * @param priQueue queue to manipulate
 */
void removePatientCmd(PatientPriorityQueue &priQueue) {
    try {
        Patient next = priQueue.dequeue();
        cout << "This patient will now be seen: ";
        cout << next.getName() << endl;
    } catch (std::exception const &exc) {
        cout << "Nobody is in the queue." << endl;
    }
}

/**
 * Displays the list of patients in the waiting room.
 * @param priQueue queue to manipulate
 */
void showPatientListCmd(PatientPriorityQueue &priQueue) {
    cout << "# patients waiting: " << priQueue.size() << endl;
    for (int i = 0; i < priQueue.size(); i++) {
        cout << priQueue.peek(i).toString() << endl;
    }
}

// forward declare:
void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue);

/**
 * Process the line entered from the user or read from a file.
 * @param line     command text
 * @param priQueue queue to manipulate
 * @return         false to quit; true otherwise
 */
bool processLine(string line, PatientPriorityQueue &priQueue) {
    // get command
    string cmd = delimitBySpace(line);
    if (cmd.length() == 0) {
        cout << "Error: no command given.";
        return false;
    }

    // process user input
    if (cmd == "help")
        help();
    else if (cmd == "add")
        addPatientCmd(line, priQueue);
    else if (cmd == "peek")
        peekNextCmd(priQueue);
    else if (cmd == "next")
        removePatientCmd(priQueue);
    else if (cmd == "list")
        showPatientListCmd(priQueue);
    else if (cmd == "load")
        execCommandsFromFileCmd(line, priQueue);
    else if (cmd == "quit")
        return false;
    else
        cout << "Error: unrecognized command: " << cmd << endl;

    return true;
}

/**
 * Reads a text file with each command on a separate line and executes the
 * lines as if they were typed into the command prompt.
 * @param filename  of file with text commands
 * @param priQueue  queue to manipulate
 */
void execCommandsFromFileCmd(string filename, PatientPriorityQueue &priQueue) {
    ifstream infile;
    infile.open(filename);
    if (infile) {
        string line;
        while (getline(infile, line)) {
            cout << endl << "triage> " << line;
            cout << endl;
            processLine(line, priQueue);
        }
    } else {
        cout << "Error: could not open file." << endl;
    }
    infile.close();
}

/**
 * Main entry into triage program.
 * @return EXIT_SUCCESS
 */
int main() {

    welcome();

    // process commands
    PatientPriorityQueue priQueue;
    string line;
    do {
        cout << endl << "triage> ";
        getline(cin, line);
    } while (processLine(line, priQueue));

    goodbye();
    return EXIT_SUCCESS;
}
