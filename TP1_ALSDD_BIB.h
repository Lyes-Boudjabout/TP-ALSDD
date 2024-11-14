#ifndef TP1_BIB_H
#define TP1_BIB_H

//TP1 ALSDD Realised by BOUDJABOUT Lyes and KAMOUCHE Samer From G10
//Our Emails:
//nl_boudjabout@esi.dz
//ns_kamouche@esi.dz

// Declaration of "Node_LL" data structure
typedef struct Node_LL Node_LL;
struct Node_LL
{
    int ID_To_Node; //ID To Node (the ID of the evaluated student)
    int Weight; //The weight of evaluation
    int Timestamp; //The time of evaluation
    Node_LL* Adr; //The address pf the next node
};

// Definition of a new type PtrNode_LL, which is a pointer to a Node_LL
typedef Node_LL* PtrNode_LL;

// Procedure that allocates a Node_LL and returns its address in p
void ALLOCATE_NODE(PtrNode_LL* p);

// Procedure that displays the content of a Node_LL pointed by p
void PRINT_NODE(PtrNode_LL p);

// Procedure that destroys the Node_LL pointed by p
void FREE (PtrNode_LL p);

// Procedure that assigns tid to the field tnode of the Node_LL pointed by p
void ASS_TNODE(PtrNode_LL p, int tid);

// Procedure that assigns w to the field weight of the Node_LL pointed by p
void ASS_WEIGHT(PtrNode_LL p, int w);

// Procedure that assigns t to the field timestamp of the Node_LL pointed by p
void ASS_TIME(PtrNode_LL p, int t);

// Procedure that assigns q to the adr field of the Node_LL pointed by p
void ASS_ADR(PtrNode_LL p, PtrNode_LL q);

// Function that returns the content of the tnode field of the Node_LL pointed by p
int NODE_IDT (PtrNode_LL p);

// Function that returns the content of the weight field of the Node_LL pointed by p
int NODE_WEIGHT (PtrNode_LL p);

// Function that retuns the content of the timestamp field of the Node_LL pointed by p
int NODE_TIME (PtrNode_LL p);

// Function that returns the content of the adr field of the Node_LL pointed by p
PtrNode_LL NEXT (PtrNode_LL p);

/************************************************************************************************************/

// Procedure that builds the array of the dutch college social network
void BUILD_GRAPH(PtrNode_LL Graph[]);

// Procedure that displays the array of the dutch college social network
void DISPLAY_GRAPH(PtrNode_LL Graph[]);

// Procedure that displays the ratings made by one student
void DISPLAY_ONE_STUDENT(PtrNode_LL Graph[]);

// Procedure that adds a new friendship rating between two students to the social network
void ADD_FRIENDSHIP_RATING(PtrNode_LL Graph[]);

// Procedure that removes a student from the social network
void REMOVE_STUDENT(PtrNode_LL Graph[]);

// Procedure that removes the friendship between two given students at a given timepoint
void Remove_friendship_of_two_students_at_time(PtrNode_LL Graph[]);

// Procedure that finds all the friends of a student at a given timepoint
void findAllFriendsAtTime(PtrNode_LL Graph[]);

// Procedure that finds all the shared friends of two students at a given timepoint
void findSharedFriendsAtTime(PtrNode_LL Graph[]);

// Procedure that checks the strength of friendship between two students
void checkFriendshipStrength(PtrNode_LL Graph[]);

// Procedure that finds the closest friends of a student
void findClosestFriends(PtrNode_LL Graph[]);

// Procedure that calculates the average rating made by one given student
void calculateAverageRating(PtrNode_LL Graph[]);


#endif