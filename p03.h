#ifndef __P03_H__
#define __P03_H__


#include <string>
#include <vector>

using std::string;
using std::vector;

// Class standing: freshman, sophomore, junior, senior
enum Standing { FR, SO, JR, SR };

struct Student {
    string id;          // a unique string for every student
    string firstname;
    string lastname;
    string state;       // a two-character abbreviation (like "SC")
    Standing standing;  // the class standing as above
    float gpa;          // a float between 0.0 - 4.0, inclusive
};


struct Node {
    Student data;
    Node* next;
};



//*****************************************************************
//                          FUNDAMENTALS
//*****************************************************************

// This function opens and reads from the file specified by the
// filename parameter. The file format is space separated where
// each row is as follows:
//
// ID FirstName LastName State StandingInt GPA
//
// For example,
//
// W0570 Karie Duilleain PA 2 2.46
// W0304 Farrel Danter CA 3 3.87
// W6529 Ripley Dear NY 1 1.79
//
// Notice that the standing is an integer in the file, where 1 is
// freshman, 2 is sophomore, 3 is junior, and 4 is senior.
//
// Your function should read the file and return a pointer to a list
// of the same data in the same order as the entries in the file.
Node* loadList(string filename);

// This function deallocates all memory associated with the specified
// list. You must ensure that you deallocate the memory for each node
// in the list.
void destroyList(Node*& head);

// This function returns a vector containing all of the IDs in the
// specified list in the same order as they occur in the list.
vector<string> getAllIds(Node* head);

// This function returns a vector containing all of the IDs in the
// specified list where the corresponding last name matches the given
// lastname. The order must be the same as they occur in the list.
vector<string> getIdsForLastname(Node* head, string lastname);

// This function returns a vector containing all of the IDs in the
// specified list where the corresponding GPA is greater than or equal
// to the specified gpa and the standing matches the specified standing.
// The order must be the same as they occur in the list.
vector<string> getIdsForGpaStanding(Node* head, float gpa, Standing standing);

// This function returns a vector containing all of the IDs in the specified
// list where the corresponding standing matches the specified standing and
// the state matches the specified state. The order must be the same as they
// occur in the list.
vector<string> getIdsForStandingState(Node* head,
                                      Standing standing,
                                      string state);


//*****************************************************************
//                          PROFICIENCY
//*****************************************************************

// This function takes the head of a list of Students, a vector of strings
// representing student IDs, and a vector of floats representing GPAs. The
// two vectors are guaranteed to be the same length. The function should
// update the students in the list whose IDs match those in the ids vector
// changing their GPAs to the corresponding GPA in the gpas vector. For
// instance, if the ids vector contained ["W1234", "W0987", "W2222"] and
// the GPAs contained [1.0, 3.0, 2.0], then the student in the list with
// ID "W1234" should have the GPA changed to 1.0, while the student with
// ID "W2222" would now have a GPA of 2.0. If an ID in the ids vector does
// not exist in the full list, then it is simply skipped with no change made.
void updateGpa(Node* head, vector<string> ids, vector<float> gpas);



//*****************************************************************
//                            MASTERY
//*****************************************************************

// This function returns a vector containing the first and last names
// (concatenated with a separating space) for the IDs given in the ids
// vector. The order of the names vector must match the order that of
// the ids vector. For instance, consider the following list data:
//
// W0570 Karie Duilleain PA 2 2.46
// W0304 Farrel Danter CA 3 3.87
// W6529 Ripley Dear NY 1 1.79
//
// If the ids vector was ("W0304", "W6529", "W0570"), then the returned
// vector should be ("Farrel Danter", "Ripley Dear", "Karie Duilleain").
vector<string> getFirstLastNames(Node* head, vector<string> ids);


#endif
