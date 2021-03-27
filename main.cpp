#include <iostream>
#include "p03.h"

using std::cout;
using std::endl;


int main() {
    Node* head = loadList("data.txt");
    
    vector<string> all = getAllIds(head);
    cout << ((all.size() == 50)? "(SUCCESS)" : "(FAILURE)");
    cout << "  Load from file  [50 IDs == " << all.size() << " IDs]" << endl;
    vector<string> piff = getIdsForLastname(head, "Piff");
    if (piff.size() == 1 && piff[0] == "W4779") {
        cout << "(SUCCESS)  Search by name  ['W4779' == 'W4779']" << endl;
    } else {
        cout << "(FAILURE)  Search by name";
        cout << "  ['W4779' == '" << piff[0] << "']" << endl;
    }
    vector<string> threeJr = getIdsForGpaStanding(head, 3.0, JR);
    if (threeJr.size() == 3 && threeJr[0] == "W0304" &&
        threeJr[1] == "W0128" && threeJr[2] == "W0099") {
        cout << "(SUCCESS)";
    } else {
        cout << "(FAILURE)";
    }
    cout << "  Search by GPA and standing" << endl;
    vector<string> frSC = getIdsForStandingState(head, FR, "SC");
    if (frSC.size() == 1 && frSC[0] == "W2956") {
        cout << "(SUCCESS)";
    } else {
        cout << "(FAILURE)";
    }
    cout << "  Search by standing and state" << endl;

    destroyList(head);

    return 0;
}

