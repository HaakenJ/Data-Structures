#include <iostream>
#include "Patient.h"
#include "PatientPriorityQueue.h"

using namespace std;

int main() {
    Patient p("Peter",   "minimal");
    Patient q("Quamp",   "immediate");
    Patient r("Richard", "immediate");
    Patient j("Jeremy",  "urgent");
    Patient e("Eric",    "emergency");

    PatientPriorityQueue patientQueue;

    patientQueue.enqueue(p);
    patientQueue.enqueue(q);
    patientQueue.enqueue(r);
    patientQueue.enqueue(j);
    patientQueue.enqueue(e);

    cout << "Is this heap valid? " << (patientQueue.isValid() ? "Yes" : "No") << endl;

    cout << "Should be Quamp: "     << patientQueue.dequeue().toString() << endl;
    cout << "Should be Richard: "   << patientQueue.dequeue().toString() << endl;
    cout << "Should be Eric: "      << patientQueue.dequeue().toString() << endl;
    cout << "Should be Jeremy: "    << patientQueue.dequeue().toString() << endl;
    cout << "Should be Peter: "     << patientQueue.dequeue().toString() << endl;

    cout << "p->q: " << p.compareTo(q) << endl;
    cout << "q->p: " <<  q.compareTo(p) << endl;

    cout << "p->r: " << p.compareTo(r) << endl;
    cout << "r->p: " <<  q.compareTo(p) << endl;

    cout << "q->r: " <<  q.compareTo(r) << endl;
    cout << "r->q: " <<  r.compareTo(q) << endl;

    return 0;
}
