#include <iostream>
#include "Patient.h"

using namespace std;

int main() {
    Patient p("Frank", "minimal");
    Patient q("Todd", "immediate");
    Patient r("Theodore", "immediate");

    cout << p.toString() << endl;
    cout << q.toString() << endl;
    cout << r.toString() << endl;

    cout << "p->q: " << p.compareTo(q) << endl;
    cout << "q->p: " <<  q.compareTo(p) << endl;

    cout << "p->r: " << p.compareTo(r) << endl;
    cout << "r->p: " <<  q.compareTo(p) << endl;

    cout << "q->r: " <<  q.compareTo(r) << endl;
    cout << "r->q: " <<  r.compareTo(q) << endl;

    return 0;
}
