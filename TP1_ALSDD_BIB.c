#include <stdio.h>
#include <stdlib.h>
#include "TP1_ALSDD_BIB.h"

//TP1 ALSDD Realised by BOUDJABOUT Lyes and KAMOUCHE Samer From G10
//Our Emails:
//nl_boudjabout@esi.dz
//ns_kamouche@esi.dz

//Beginning of the Abstarct Machine of the Node_LL

void ALLOCATE_NODE(PtrNode_LL* p)
{
    *p = (PtrNode_LL)malloc(sizeof(Node_LL));
}

void PRINT_NODE(PtrNode_LL p)
{
    printf("ID To Node: %d \n",p->ID_To_Node);
    printf("Weight: %d \n",p->Weight);
    printf("Timestamp: %d \n",p->Timestamp);
}

void FREE (PtrNode_LL p)
{
    free(p);
}

void ASS_TNODE(PtrNode_LL p, int tid)
{
    p->ID_To_Node = tid;
}

void ASS_WEIGHT(PtrNode_LL p, int w)
{
    p->Weight = w;
}

void ASS_TIME(PtrNode_LL p, int t)
{
    p->Timestamp = t;
}

void ASS_ADR (PtrNode_LL p, PtrNode_LL q)
{
    p->Adr = q;
}

int NODE_IDT (PtrNode_LL p)
{
    return p->ID_To_Node;
}

int NODE_WEIGHT (PtrNode_LL p)
{
    return p->Weight;
}

int NODE_TIME (PtrNode_LL p)
{
    return p->Timestamp;
}

PtrNode_LL NEXT (PtrNode_LL p)
{
    return p->Adr;
}

//End of the Abstarct Machine

/*********************************************************************************************************************************************************************/

//Beginning of the procedures used to manipulate the social network

//In the following we will use the definition below:

//If a cell on the graph array contains "NULL", it means that the student don't belong to the network

//If a cell on the graph array contains a Node_LL, but both fields timestamp and tid are
//at 0, it means that the student haven't evaluated any student

void BUILD_GRAPH(PtrNode_LL Graph[])
{
    PtrNode_LL p,q,s;
    int idt,idf,w,t,i;
    FILE *fptr; //Define a pointer that points a file
    for (i=0;i<=(31);i++) //Initialize the array to NULL
    {
        Graph[i] = NULL;
    }
    fptr = fopen("Dutch_college_social_network","r"); //Associate the pointer fptr with the file that contains the evaluations and opens the file for reading action
    if (fptr == NULL){
        printf("Error: An error occured in the pointer to the file OR file doesn't exist");
    }
    else
    {
        while((fscanf(fptr,"%i %i %i %i",&idf,&idt,&w,&t)) == 4) //Fill in the lists of the array
        {
            if (Graph[idf-1] == NULL) //When the array cell don't contain any list (creation of the list)
            {
               ALLOCATE_NODE(&p);
               Graph[idf-1] = p;
               ASS_TNODE(p,idt);
               ASS_WEIGHT(p,w);
               ASS_TIME(p,t);
               ASS_ADR(p,NULL);
               s = p;
            }
            else //When the array cell contains already at least a head Node_LL
            {
                ALLOCATE_NODE(&q);
                ASS_TNODE(q,idt);
                ASS_WEIGHT(q,w);
                ASS_TIME(q,t);
                ASS_ADR(s,q);
                ASS_ADR(q,NULL);
                s = q;
            }
        }
    }
    fclose(fptr); //Close the opened file
    i = 0;
    while (i<=(31)) //Search the students that haven't evaluated any student and fill their cells with a Node_LL initialized to 0 (according to the definition above)
    {
        if (Graph[i] == NULL){
             ALLOCATE_NODE(&q);
             ASS_TNODE(q,0);
             ASS_WEIGHT(q,0);
             ASS_TIME(q,0);
             ASS_ADR(q,NULL);
             Graph[i] = q;
        }
        i++;
    }
}

void DISPLAY_GRAPH(PtrNode_LL Graph[]) //The option 9
{
    int i,cpt,check;
    PtrNode_LL p,q;
    check = 0;
    for (i=0 ; i<=31 ; i++)
    {
        if (Graph[i] == NULL)
        {
            check++; //Count the number of deleted students
        }
    }
    if (check == 32) //The case of a destroyed network
    {
        printf("There is nothing to display since the network has been destroyed ! (All the students are removed)");
        return;
    }
    i = 0;
    printf("\n--------------------------------------------------------------\n");
    printf("The display is in the form : (ID_To_Node ; Weight ; Timestamp) \n");
    printf("---------------------------------------------------------------\n");
    while ( i <= (31))
    {
        p = Graph[i];
        if (p == NULL) //The case of an array cell of a student removed from the network
        {
            i++;
        }
        else //The normal case
        {
            q = p;
            printf("\n-------> The evaluations of the student number %d: \n \n",i+1);
            cpt = 0;
            while (NEXT(q) != NULL) //The loop for printing a list, we will go to the before last node, because the last node has a special display (Add Null to the end)
            { //All of the following is just to make the display better, if program executed in a terminal window, enlarge the window of the terminal to see it clearly
                if (cpt == 6)
                {
                    cpt = 0;
                    if (NODE_IDT(q) >= 10)
                    {
                        if (NODE_WEIGHT(q) < 0)
                        {
                            printf("(%d ; %d ; %d) --> \n \n",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                        else
                        {
                            printf("(%d ; +%d ; %d) --> \n \n",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                    }
                    else
                    {
                        if (NODE_WEIGHT(q) < 0)
                        {
                            printf("(0%d ; %d ; %d) --> \n \n",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                        else
                        {
                            printf("(0%d ; +%d ; %d) --> \n \n",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                    }
                }
                else
                {
                    cpt++;
                    if (NODE_IDT(q) >= 10)
                    {
                        if (NODE_WEIGHT(q) < 0)
                        {
                            printf("(%d ; %d ; %d) --> ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                        else
                        {
                            printf("(%d ; +%d ; %d) --> ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                    }
                    else
                    {
                        if (NODE_WEIGHT(q) < 0)
                        {
                            printf("(0%d ; %d ; %d) --> ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                        else
                        {
                            printf("(0%d ; +%d ; %d) --> ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                            q = NEXT(q);
                        }
                    }
                }
            }
            if (cpt == 6)
            {
                if (NODE_IDT(q) >= 10)
                {
                    if (NODE_WEIGHT(q) < 0)
                    {
                        printf("(%d ; %d ; %d) -->\n \nNull \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }
                    else
                    {
                        printf("(%d ; +%d ; %d) -->\n \nNull \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }  
                }
                else
                {
                    if (NODE_WEIGHT(q) < 0)
                    {
                        printf("(0%d ; %d ; %d) -->\n \nNull \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }
                    else
                    {
                        printf("(0%d ; +%d ; %d) -->\n \nNull \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }    
                }
            }
            else
            {
                if (NODE_IDT(q) >= 10)
                {
                    if (NODE_WEIGHT(q) < 0)
                    {
                        printf("(%d ; %d ; %d) --> Null \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }
                    else
                    {
                        printf("(%d ; +%d ; %d) --> Null \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }  
                }
                else
                {
                    if (NODE_WEIGHT(q) < 0)
                    {
                        printf("(0%d ; %d ; %d) --> Null \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }
                    else
                    {
                        printf("(0%d ; +%d ; %d) --> Null \n ",NODE_IDT(q),NODE_WEIGHT(q),NODE_TIME(q));
                    }    
                }
            }
            i++; //Go to the next array cell
        }
    }
    printf("\n \n");
}

void DISPLAY_ONE_STUDENT(PtrNode_LL Graph[]){  //The option 10
    PtrNode_LL p;
    int idf;
    printf("Enter the ID of the student to display: ");
    scanf("%d",&idf); //Read the ID of the evaluator
    if (idf > 32 || idf < 1) //Check that the ID provided is correct
    {
        printf("Error: The Entered ID is not correct \n");
    }
    else
    {
        if (Graph[idf-1] != NULL) //If the student hasn't been removed
        {
            p = Graph[idf-1];
            int cpt = 0;
            printf("\n--------------------------------------------------------------\n");
            printf("The display is in the form : (ID_To_Node ; Weight ; Timestamp) \n");
            printf("---------------------------------------------------------------\n");
            while (NEXT(p) != NULL) //Go to the before last node, because the last node has a special display (Add Null to the end)
            { //All of the following is just to make the display better, if program executed in a terminal window, enlarge the window of the terminal to see it clearly
                if (cpt == 6)
                {
                    cpt = 0;
                    if (NODE_IDT(p) >= 10)
                    {
                        if (NODE_WEIGHT(p) < 0)
                        {
                            printf("(%d ; %d ; %d) --> \n \n",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                        else
                        {
                            printf("(%d ; +%d ; %d) --> \n \n",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                    }
                    else
                    {
                        if (NODE_WEIGHT(p) < 0)
                        {
                            printf("(0%d ; %d ; %d) --> \n \n",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                        else
                        {
                            printf("(0%d ; +%d ; %d) --> \n \n",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                    }
                }
                else
                {
                    cpt++;
                    if (NODE_IDT(p) >= 10)
                    {
                        if (NODE_WEIGHT(p) < 0)
                        {
                            printf("(%d ; %d ; %d) --> ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                        else
                        {
                            printf("(%d ; +%d ; %d) --> ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                    }
                    else
                    {
                        if (NODE_WEIGHT(p) < 0)
                        {
                            printf("(0%d ; %d ; %d) --> ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                        else
                        {
                            printf("(0%d ; +%d ; %d) --> ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                            p = NEXT(p);
                        }
                    }
                }
            }
            if (cpt == 6)
            {
                if (NODE_IDT(p) >= 10)
                {
                    if (NODE_WEIGHT(p) < 0)
                    {
                        printf("(%d ; %d ; %d) -->\n \nNull \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }
                    else
                    {
                        printf("(%d ; +%d ; %d) -->\n \nNull \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }  
                }
                else
                {
                    if (NODE_WEIGHT(p) < 0)
                    {
                        printf("(0%d ; %d ; %d) -->\n \nNull \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }
                    else
                    {
                        printf("(0%d ; +%d ; %d) -->\n \nNull \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }    
                }
            }
            else
            {
                if (NODE_IDT(p) >= 10)
                {
                    if (NODE_WEIGHT(p) < 0)
                    {
                        printf("(%d ; %d ; %d) --> Null \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }
                    else
                    {
                        printf("(%d ; +%d ; %d) --> Null \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }  
                }
                else
                {
                    if (NODE_WEIGHT(p) < 0)
                    {
                        printf("(0%d ; %d ; %d) --> Null \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }
                    else
                    {
                        printf("(0%d ; +%d ; %d) --> Null \n ",NODE_IDT(p),NODE_WEIGHT(p),NODE_TIME(p));
                    }    
                }
            }
        }
        else //If the student has been removed
        {
            printf("---------------------------------------------------------------\n");
            printf("Error: The student that you are looking for has been removed ! \n");
            printf("---------------------------------------------------------------\n");
        }
    }
}

void ADD_FRIENDSHIP_RATING(PtrNode_LL Graph[]){  //The option 1
    int idf,idt,w,t;
    PtrNode_LL p,q,r;
    printf("Enter the ID from node (who rated): ");
    scanf("%d",&idf);
    if (idf > 32 || idf < 1) //Check that the ID provided is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The provided ID is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    printf("Enter the ID to node (who have been rated): ");
    scanf("%d",&idt);
    if (idt > 32 || idt < 1) //Check that the ID provided is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The provided ID is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    printf("Enter the given rating: ");
    scanf("%d",&w);
    if (w > 3 || w < (-1) ) //Check that the weight provided is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The provided rating is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    printf("Enter the time of rating: ");
    scanf("%d",&t);
    if (idf == idt) //Check that the evaluator and the evaluated students don't have the same ID
    {
        printf("----------------------------------------------------\n");
        printf("Error: A Student can't evaluate himself ! \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    p = Graph[idf-1]; //In the following, we will keep the List of Nodes sorted (just in the case of a sorted one, because not all of them are sorted)
    q = NULL;    //In the case of not a sorted list, the addition of the rating will look like it has been inserted randomly
    if (p != NULL && Graph[idt-1] != NULL) //Check that the evaluator and the evaluated students exist
    {
        if (NODE_IDT(p) != 0 && NODE_TIME(p) != 0) //Check that the student has already made at least an evaluation
        {
            while (p != NULL && NODE_IDT(p) <= idt){ //A loop to get the adress of the first Node_LL with ID To Node equal to idt and the address of its precedent
                p = NEXT(p);
                if (q == NULL)
                {
                    q = Graph[idf-1];
                }
                else
                {
                    q = NEXT(q);
                }
            }
            if (p == NULL) //The case of the rating with the biggest ID To Node in the list
            {
                ALLOCATE_NODE(&p); //Create the Node_LL, fill in it, and link it with the last Node_LL of the list
                ASS_TNODE(p,idt);
                ASS_WEIGHT(p,w);
                ASS_TIME(p,t);
                ASS_ADR(q,p);
                ASS_ADR(p,NULL);
            }
            else if(q != NULL) // In this case we will insert the rating in the middle of the list
            {
                ALLOCATE_NODE(&r); 
                ASS_TNODE(r,idt);
                ASS_WEIGHT(r,w);
                ASS_TIME(r,t);
                ASS_ADR(q,r);
                ASS_ADR(r,p);
            }
            else //In this case the rating has to be the new head
            {
                ALLOCATE_NODE(&r); 
                ASS_TNODE(r,idt);
                ASS_WEIGHT(r,w);
                ASS_TIME(r,t);
                ASS_ADR(r,p);
                Graph[idf-1] = r;
            }
        }
        else //The case of a student that haven't made any evaluation before
        {
            ALLOCATE_NODE(&r);
            ASS_TNODE(r,idt);
            ASS_WEIGHT(r,w);
            ASS_TIME(r,t);
            ASS_ADR(r,NULL);
            Graph[idf-1] = r;
        }
    }
    else //The case of one of the IDs is an ID of a removed student
    {
        printf("----------------------------------------------------\n");
        printf("Error: One or both of the two students is (are) already removed ! \n");
    }
}

void REMOVE_STUDENT(PtrNode_LL Graph[]){ //The option 2
    PtrNode_LL p,q,r,s;
    int idf,i;
    printf("Enter the ID of the student to remove: ");
    scanf("%d",&idf);
    if (idf>32 || idf<1) //Verify that the provided ID is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The ID of the student is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
    }
    else //The case of a correct provided ID
    {
        if (Graph[idf-1] == NULL) //Check that the ID provided is not of a removed student
        {
            printf("----------------------------------------------------\n");
            printf("The student is already removed ! \n");
        }
        else //The case of the ID of an existing student
        {
            r = Graph[idf-1];
            FREE(r);
            Graph[idf-1] = NULL; //Removing the student according to the definition mentionned above
            for ( i = 0; i <= (31); i++){  //The process of searching for any evaluations (other students that evaluated the removed student)
                p = Graph[i]; //A PtrNode_LL to arrive to the required Node_LL and the last Node_LL of the list
                q = NULL; //A PtrNode_LL to get the pointer to the before required Node_LL and the before last Node_LL of the list
                while (p != NULL) //Searching in a list of Node_LL for any evaluations of the removed student
                {
                    if (NODE_IDT(p) != idf) //The case of an evaluation of an existing student
                    {
                        p = NEXT(p); //Incrementation of the p
                        if (q == NULL) //Incrementation of the q
                        {
                            q = Graph[i];
                        }
                        else
                        {
                            q = NEXT(q);
                        }
                    }
                    else //The case of an evaluation of a removed student (the process of deleting the evaluation)
                    {
                        if (q != NULL) //The case of a node of an evaluation of a removed student is not a head-list
                        {
                            ASS_ADR(q,NEXT(p));
                            FREE(p);
                            p = NEXT(q);
                        }
                        else //The case of a node of an evaluation of a removed student is a head-list
                        {
                            if (NEXT(p) != NULL) //The case of the existence of another evaluation of an existing student
                            {
                                Graph[i] = NEXT(p);
                                FREE(p);
                                p = NEXT(Graph[i]);
                                q = Graph[i];
                            }
                            else //The case of the absence of any other evaluation than the evaluation of the removed student
                            { //The student still exist but with 0 evaluations (haven't evaluated any student)
                                ALLOCATE_NODE(&s);
                                ASS_TIME(s,0);
                                ASS_TNODE(s,0);
                                ASS_WEIGHT(s,0);
                                ASS_ADR(s,NULL);
                                Graph[i] = s;
                                p = NULL;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Remove_friendship_of_two_students_at_time(PtrNode_LL Graph[]) { //The option 3
    PtrNode_LL p,q,s;
    int idf,idt,t,stop;
    printf("Enter the ID of the evaluator student: ");
    scanf("%d",&idf);
    if (idf > 32 || idf < 1) //Check that the provided ID is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The provided Student ID is not correct ! \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }
    printf("Enter the ID of the evaluated student: ");
    scanf("%d",&idt);
    if (idt > 32 || idt < 1) //Check that the provided ID is correct
    {
        printf("----------------------------------------------------\n");
        printf("Error: The provided Student ID is not correct ! \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }
    printf("Enter the time of evaluation : ");
    scanf("%d",&t);
    if (idf == idt) //Check that the IDs are not the same
    {
        printf("----------------------------------------------------\n");
        printf("Error: A Student can't evaluate himself ! \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    // Check if the student idf1 have made at least an evaluation
    if (NODE_IDT(Graph[idf-1]) == 0 && NODE_TIME(Graph[idf-1]) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("Error: The student %d haven't made any evaluation \n",idf);
        printf("So in this case, there is no friendship rating to remove \n");
        return;
    }
    p = Graph[idf-1];
    q = NULL;
    stop = 10; //A variable to stop the loop while in the case of finding the required rating, and it is randomly initialized to enter the loop
    while (p != NULL && stop != 404)
    {
       if (NODE_IDT(p) != idt || NODE_TIME(p) != t) //The case of not the required rating
       {
           p = NEXT(p);
           if (q == NULL)
           {
               q = Graph[idf-1];
           }
           else
           {
               q = NEXT(q);
           }
        }
        else //The case of the required rating
        {
           stop = 404;
           if (p == Graph[idf-1]) //The case of a rating being a head-list
           {
               if (NEXT(p) == NULL) //The case of being the only rating disponible
               {
                    ALLOCATE_NODE(&s);
                    ASS_ADR(s,NULL);
                    ASS_TIME(s,0);
                    ASS_TNODE(s,0);
                    ASS_WEIGHT(s,0);
                    Graph[idf-1] = s;
                    FREE(p);
               }
               else // The case of an evaluation being a head-list and not the only made evaluation
               {
                    Graph[idf-1] = NEXT(p);
                    FREE(p);
                    p = Graph[idf-1];
               }
           }
           else //The case of an evaluation not being a head-list
           {
               if (NEXT(p) == NULL) // The case of an evaluation being the last node on the list
               {
                   ASS_ADR(q,NULL);
                   FREE(p);
                   p = NULL;
               }
               else // The case of an evaluation being in the middle of the list
               {
                   ASS_ADR(q,NEXT(p));
                   FREE(p);
                   p = NEXT(q);
               }
           }
        }
    }
    if (p == NULL) //The case of inexistence of the rating to remove
    {
        printf("----------------------------------------------------\n");
        printf("The rating that you are looking for is not found \n");
    }
}

void findAllFriendsAtTime(PtrNode_LL Graph[]) { //The option 4
    int idf,timePoint;
    printf("Enter the ID of the student: ");
    scanf("%d",&idf);
    printf("Enter the time of the evaluation: ");
    scanf("%d",&timePoint);
    // Check if the student ID is valid Or Not
    if (idf < 1 || idf > 32) {
        printf("----------------------------------------------------\n");
        printf("Error: The ID of the student is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    PtrNode_LL p = Graph[idf - 1];

    if (p == NULL) {
        printf("----------------------------------------------------\n");
        printf("The Student is Already Removed !\n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }
    // Check if the student idf have made at least an evaluation
    if (NODE_IDT(p) == 0 && NODE_TIME(p) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf);
        printf("So in this case, we can't find his friends at a timepoint since he don't have any friends \n");
        return;
    }

    printf("Friends of student %d at time point %d:\n", idf, timePoint);
    printf("------------------------------------\n");

    while (p != NULL) { 
        // Check if the timestamp is as same as the specified time point
        if (NODE_TIME(p) == timePoint && NODE_WEIGHT(p) > 1) {
            printf("Friend ID: %d\n", NODE_IDT(p));
            printf("Friend Weight: %d\n", NODE_WEIGHT(p));
            printf("------------------------------------\n");
        }
        p = NEXT(p);
    }
}

void findSharedFriendsAtTime(PtrNode_LL Graph[]) { //The option 5
    int idf1,idf2,timePoint;
    printf("Enter th ID of the first student :");
    scanf("%d",&idf1);
    printf("Enter th ID of the second student :");
    scanf("%d",&idf2);
    printf("Enter the time of evaluation: ");
    scanf("%d",&timePoint);
    // Check if the student IDs are Valid
    if (idf1 < 1 || idf1 > 32 || idf2 < 1 || idf2 > 32) {
       printf("----------------------------------------------------\n");
       printf("Error: The ID of one / (the two) student(s) is not correct \n");
       printf("You can fix the error by choosing this option in the next time and providing correct information \n");
       return;
    }

    PtrNode_LL p1 = Graph[idf1 - 1];
    PtrNode_LL p2 = Graph[idf2 - 1];

    if (p1 == NULL || p2 == NULL) {
        printf("----------------------------------------------------\n");
        printf("One or both of the students are Removed.\n");
        return;
    }

    // Check if the student idf1 have made at least an evaluation
    if (NODE_IDT(p1) == 0 && NODE_TIME(p1) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf1);
        printf("So in this case, we can't search for shared friends between %d and any other student \n",idf1);
        return;
    }
    // Check if the student idf2 have made at least an evaluation
    if (NODE_IDT(p2) == 0 && NODE_TIME(p2) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf2);
        printf("So in this case, we can't search for shared friends between %d and any other student \n",idf2);
        return;
    }

    printf("Shared friends of students %d and %d at time point %d:\n", idf1, idf2, timePoint);
    printf("------------------------------------------------------\n");

    while (p1 != NULL && p2 != NULL) {
        if (NODE_TIME(p1) == timePoint && NODE_TIME(p2) == timePoint && NODE_IDT(p1) == NODE_IDT(p2) && NODE_WEIGHT(p1) > 1 && NODE_WEIGHT(p2) > 1) {
            // Print information about the shared friend
            printf("Shared Friend ID: %d\n", NODE_IDT(p1));
            printf("Shared Friend Weight (Student %d): %d\n", idf1, NODE_WEIGHT(p1));
            printf("Shared Friend Weight (Student %d): %d\n", idf2, NODE_WEIGHT(p2));
            printf("Shared Friend Timestamp: %d\n", NODE_TIME(p1));
            printf("------------------------------------\n");
        }

        // Move to the next friend
        if (NODE_IDT(p1) < NODE_IDT(p2)) {
            p1 = NEXT(p1);
        } else if (NODE_IDT(p1) > NODE_IDT(p2)) {
            p2 = NEXT(p2);
        } else { // NODE_IDT(p1) == NODE_IDT(p2)
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }
    }
}

void checkFriendshipStrength(PtrNode_LL Graph[]) { //The option 6
    int idf1,idf2;
    printf("Enter th ID of the first student :");
    scanf("%d",&idf1);
    printf("Enter th ID of the second student :");
    scanf("%d",&idf2);
    // Check if the student IDs are valid
    if (idf1 < 1 || idf1 > 32 || idf2 < 1 || idf2 > 32) {
        printf("----------------------------------------------------\n");
        printf("Error: The ID of one / (the two) student(s) is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }
    // Check if the students are the same
    if (idf1 == idf2) {
        printf("----------------------------------------------------\n");
        printf("Error: Both students have the same ID\n");
        return;
    }

    PtrNode_LL student1 = Graph[idf1 - 1];
    PtrNode_LL student2 = Graph[idf2 - 1];

    // Check if both students exist in the network
    if (student1 == NULL || student2 == NULL) {
        printf("----------------------------------------------------\n");
        printf("One or both of the students is (are) already removed.\n");
        return;
    }

    // Check if the student idf1 have made at least an evaluation
    if (NODE_IDT(student1) == 0 && NODE_TIME(student1) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf1);
        printf("So in this case, we can't check the strenght of friendship \n");
        return;
    }
    // Check if the student idf2 have made at least an evaluation
    if (NODE_IDT(student2) == 0 && NODE_TIME(student2) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf2);
        printf("So in this case, we can't check the strenght of friendship \n");
        return;
    }

    // Traverse the adjacency list of the first student to find the friendship rating with the second student
    PtrNode_LL currentFriend1 = student1;
    int friendshipRating1 = 0;
    int cpt;
    cpt = 0;
    while (currentFriend1 != NULL) {
        if (NODE_IDT(currentFriend1) == idf2) {
            friendshipRating1 = friendshipRating1 + NODE_WEIGHT(currentFriend1);
            cpt++;
        }
        currentFriend1 = NEXT(currentFriend1);
    }
    float totalRating1;
    if (cpt != 0)
    {
        totalRating1 = friendshipRating1/cpt;
    }
    else
    {
        printf("----------------------------------------------------\n");
        printf("The first student haven't evaluated the second student \n");
        printf("So in this case, we can't check the strenght of friendship \n");
        return;
    }
    // Traverse the adjacency list of the second student to find the friendship rating with the first student
    PtrNode_LL currentFriend2 = student2;
    int friendshipRating2 = 0;
    cpt = 0;
    while (currentFriend2 != NULL) {
        if (NODE_IDT(currentFriend2) == idf1) {
            friendshipRating2 = friendshipRating2 + NODE_WEIGHT(currentFriend2);
            cpt++;
        }
        currentFriend2 = NEXT(currentFriend2);
    }
    float totalRating2;
    if (cpt != 0)
    {
        totalRating2 = friendshipRating2/cpt;
    }
    else
    {
        printf("----------------------------------------------------\n");
        printf("The second student haven't evaluated the first student \n");
        printf("So in this case, we can't check the strenght of friendship \n");
        return;
    }
    // Calculate the total average rating
    float totalRating = (totalRating1 + totalRating2) / 2;
    if (totalRating <= 0)
    {
        printf("student %d and student %d are in risk of conflict.\n", idf1, idf2);
    }
    if (totalRating > 0 && totalRating <= 1)
    {
        printf("The friendship between student %d and student %d is weak.\n", idf1, idf2);
    }
    if (totalRating > 1 && totalRating <= 2)
    {
        printf("The friendship between student %d and student %d is normal.\n", idf1, idf2);
    }

    if (totalRating > 2 && totalRating < 2.5)
    {
        printf("The friendship between student %d and student %d is good.\n", idf1, idf2);
    }
    if (totalRating >= 2.5 && totalRating <= 3)
    {
        printf("The friendship between student %d and student %d is excellent.\n", idf1, idf2);
    }
}

void findClosestFriends(PtrNode_LL Graph[]) { //The option 7
    int idf;
    printf("Enter the ID of the student: ");
    scanf("%d",&idf);
    // Check if the student ID is valid
    if (idf < 1 || idf > 32) {
        printf("----------------------------------------------------\n");
        printf("Error: The ID of the student is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return;
    }

    PtrNode_LL student = Graph[idf- 1];

    // Check if the student exists in the network
    if (student == NULL) {
        printf("----------------------------------------------------\n");
        printf("The Student is already removed.\n");
        return;
    }

    //Check that the student have at least an evaluation
    if (NODE_IDT(student) == 0 && NODE_TIME(student) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation, so there are no close friends to him \n",idf);
        return;
    }

    // Traverse the adjacency list of the Given student to find the maximum given rating
    PtrNode_LL currentFriend = student;
    int maxRating = -1;
    while (currentFriend != NULL) {
        if (NODE_WEIGHT(currentFriend) >= maxRating)
        {
            maxRating = NODE_WEIGHT(currentFriend);
        }
        currentFriend = NEXT(currentFriend);
    }
    //Find the student's closest friends according to his max rating
    if (maxRating == -1 || maxRating == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d don't have any friends \n",idf);
        return;
    }
    else
    {
        printf("The Closest friends of student %d are: \n", idf);
        printf("---------------------------------------\n");
        currentFriend = student;
        while (currentFriend != NULL)
        {
            if (NODE_WEIGHT(currentFriend) == maxRating)
            {
                PRINT_NODE(currentFriend);
            }
            currentFriend = NEXT(currentFriend);
        }
    }
}

void calculateAverageRating(PtrNode_LL Graph[]) { //The option 8
    int idf;
    printf("Enter the ID of the student: ");
    scanf("%d",&idf);
    // Check if the student ID is valid
    if (idf < 1 || idf > 32) {
        printf("----------------------------------------------------\n");
        printf("Error: The ID of the student is not correct \n");
        printf("You can fix the error by choosing this option in the next time and providing correct information \n");
        return ;
    }

    PtrNode_LL student = Graph[idf - 1];

    // Check if the student exists in the network
    if (student == NULL) {
        printf("----------------------------------------------------\n");
        printf("Student with ID %d does not exist in the network He is Already Removed.\n", idf);
        return ;
    }

    //Check that the student have at least an evaluation
    if (NODE_IDT(student) == 0 && NODE_TIME(student) == 0)
    {
        printf("----------------------------------------------------\n");
        printf("The student %d haven't made any evaluation \n",idf);
        return ;
    }

    int totalRating = 0;
    int ratingCount = 0;

    PtrNode_LL currentFriend = student;
    while (currentFriend != NULL) {
        int friendshipRating = NODE_WEIGHT(currentFriend);


        totalRating += friendshipRating;
        ratingCount++;

        currentFriend = NEXT(currentFriend);
    }

    // Check if the student has received any ratings
    if (ratingCount == 0) {
        printf("----------------------------------------------------\n");
        printf("The Student has not received any friendship ratings.\n");
        return;
    }

    // Calculate the average rating
    float averageRating = (float)totalRating / ratingCount;
    printf("The average rating made by the student %d is %f \n",idf,averageRating);
}

//End of the procedures used to manipulate the social network
