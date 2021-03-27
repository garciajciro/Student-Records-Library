#include "p03.h"
#include <fstream>

using std::ifstream;


//*****************************************************************
//                          FUNDAMENTALS
//*****************************************************************

Node* loadList(string filename) {
    int stand;
    Node* head = nullptr;
    Node* point = head;
    ifstream infile;
    infile.open(filename);
    while (!infile.eof()) {
       if (head == nullptr) {
           head = new Node;
           point = head;
       } else {
           point->next = new Node;
           point = point->next;
       }
       point->next = nullptr;
       infile >> point->data.id >> point->data.firstname;
       infile >> point->data.lastname >> point->data.state;
       infile >> stand >> point->data.gpa;
       if (stand == 1) {
           point->data.standing = FR;
       } else if (stand == 2) {
           point->data.standing = SO;

       } else if (stand == 3) {
           point->data.standing = JR;

       } else {
           point->data.standing = SR;
       }
       }
    infile.close();
    return head;
}

void destroyList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
    }
}

vector<string> getAllIds(Node* head) {
    vector<string> v;
    Node* temp = head;
    Node* point = nullptr;
    while (temp != nullptr) {
        point = temp;
        v.push_back(point->data.id);
        temp = temp->next;
    }
    return v;
}

vector<string> getIdsForLastname(Node* head, string lastname) {
    vector<string> v;
    Node* temp = head;
    Node* point = nullptr;
    while (temp != nullptr) {
        point = temp;
        if (point->data.lastname == lastname) {
           v.push_back(point->data.id);
           temp = temp->next;
        } else {
            temp = temp->next;
        }
    }
    return v;
}


vector<string> getIdsForGpaStanding(Node* head, float gpa, Standing standing) {
    vector<string> v;
    Node* temp = head;
    Node* point = nullptr;
    while (temp != nullptr) {
        point = temp;
        if (point->data.gpa >= gpa && point->data.standing == standing) {
           v.push_back(point->data.id);
           temp = temp->next;
        } else {
            temp = temp->next;
        }
    }
    return v;
}



vector<string> getIdsForStandingState(Node* head,
                                      Standing standing,
                                      string state) {
    vector<string> v;
    Node* temp = head;
    Node* point = nullptr;
    while (temp != nullptr) {
        point = temp;
        if (point->data.standing == standing && point->data.state == state) {
           v.push_back(point->data.id);
           temp = temp->next;
        } else {
            temp = temp->next;
        }
    }

    return v;
}



void updateGpa(Node* head, vector<string> ids, vector<float> gpas) {
    int size1 = ids.size();
    for (int i = 0; i < size1; i++) {
        string id = ids[i];
        float gpa = gpas[i];
        Node* front = head;
        while (front != nullptr) {
            if (front -> data.id == id) {
                front -> data.gpa = gpa;
                front = front -> next;
            } else {
                front = front -> next;
            }
        }
    }
}



vector<string> getFirstLastNames(Node* head, vector<string> ids) {
    vector<string> v;
    int size  = ids.size();
    for (int i = 0; i < size; i++) {
        Node* front = head;
        string id = ids[i];
        while (front != nullptr) {
            if (front -> data.id == id) {
                string firstname = front -> data.firstname;
                string lastname = front -> data.lastname;
                string firstlast = firstname + " " + lastname;
                v.push_back(firstlast);
                front = front -> next;
            } else {
                front = front -> next;
            }
        }
    }
    return v;
}
