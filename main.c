#include <stdio.h>
#include <stdlib.h>
#include "TP1_ALSDD_BIB.h"
#include "TP1_ALSDD_BIB.c"

//TP1 ALSDD Realised by BOUDJABOUT Lyes and KAMOUCHE Samer From G10
//Our Emails:
//nl_boudjabout@esi.dz
//ns_kamouche@esi.dz

void main(){
    int choice;
    PtrNode_LL Gra[32];
    BUILD_GRAPH(Gra); //Create the array of lists of Node_LL and prepare it to use it in the operations
    printf("\n\t---Welcome to the Dutch College Social Network---\t\n");
    printf("Choose an option: \n");
    printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
    printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
    printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
    printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
    printf("\nYour Choice: ");
    while (choice != 11){
        scanf("%i",&choice);
        switch (choice){
        case 1: //Add a friendship rating between two students at a specific time point
            ADD_FRIENDSHIP_RATING(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("You can see the result of this operation (if executed successfully) by choosing the option: 10: Display Ratings Made by One Student \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 2: //Remove a student from the social network
            REMOVE_STUDENT(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("You can see the result of this operation (if executed successfully) by choosing the option: 10: Display the Dutch College Social Network \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 3: //Remove a friendship rating between two students at a specific time point
            Remove_friendship_of_two_students_at_time(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("You can see the result of this operation (if executed successfully) by choosing the option: 10: Display Ratings Made by One Student \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 4: //Find all friends of a student at a specific time point
            findAllFriendsAtTime(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 5: //Find shared friends of two students at a specific time point
            findSharedFriendsAtTime(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 6: //Check the strength of friendship between two students at a specific time point
            checkFriendshipStrength(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 7: //Find the closest friends of a student
            findClosestFriends(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 8: //Calculate the average friendship rating of a student
            calculateAverageRating(Gra);
            printf("----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 9: //Display the Dutch College Social Network
            DISPLAY_GRAPH(Gra);
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        case 10: //Display Ratings Made by One Student
            DISPLAY_ONE_STUDENT(Gra);
            printf("\n----------------------------------------------------\n");
            printf("The Execution of the Task is Finished ! \n");
            printf("----------------------------------------------------\n");
            printf("Press Enter to get back to the menu :\n");
            getchar();
            getchar();
            printf(" 1: Add a friendship rating between two students at a specific time point \n 2: Remove a student from the social network \n 3: Remove a friendship rating between two students at a specific time point \n ");
            printf("4: Find all friends of a student at a specific time point \n 5: Find shared friends of two students at a specific time point \n 6: Check the strength of friendship between two students at a specific time point \n ");
            printf("7: Find the closest friends of a student \n 8: Calculate the average friendship rating of a student \n 9: Display the Dutch College Social Network \n");
            printf(" 10: Display Ratings Made by One Student \n 11: Exit \n");
            printf("\nYour Choice: ");
            break;
        }
        if (choice > 11 || choice < 1)
        {
            printf("\nYour Choice: ");
        }
    }
    printf("\n Exiting ..... \n"); //The case of 11 is exiting the loop and to arrive to the last part of the program which is exiting
    printf("Press Enter to continue ...\n");
    getchar();
    getchar(); //Waits for enter key press
}
