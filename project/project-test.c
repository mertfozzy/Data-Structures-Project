/*
Beykoz University - Computer Enginerring
Name: Mert Altuntas
ID : 1804010005
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MALLOC(x)((x * ) malloc(sizeof(x)))

/*============================================ NODE AND HEAD =============================================*/

struct node {
    char studentName[40], studentSurname[40], Score[2];
    int midtermScore, finalScore, quizScore, projectScore, totalScore, Name;
    struct node* nextName;
    struct node* nextSurname;
    struct node* nextScore;
};
typedef struct node node_type;

struct head {
    int quantityStudents;
    struct node* firstName, * lastName;
    struct node* firstSurname, * lastSurname;
    struct node* firstScore, * lastScore;
    int lengthName;
    int lengthSurname;
    int lengthScore;
};
typedef struct head head_type;

/*============================================= ALLOC_NODE ==============================================*/

node_type* alloc_node(char Name[40], char Surname[40], char Score[2], int Midterm, int FinalScore, int Quiz, int Project, int Total, node_type* ptr) {
    node_type* new_node;
    if (new_node = MALLOC(node_type)) {
        strcpy(new_node->studentName, Name);
        strcpy(new_node->studentSurname, Surname);
        strcpy(new_node->Score, Score);
        new_node->midtermScore = Midterm;
        new_node->finalScore = FinalScore;
        new_node->quizScore = Quiz;
        new_node->projectScore = Project;
        new_node->totalScore = Total;
        new_node->nextSurname = NULL;
        new_node->nextScore = NULL;
        new_node->nextName = Name;
        new_node->nextSurname = Surname;
        new_node->nextScore = Score;
    }
    return (new_node);
}

/*============================================== HEAD_TYPE ===============================================*/

head_type* create() {
    head_type* new_node;
    if (new_node = MALLOC(head_type)) {

        new_node->lengthName = 0;
        new_node->firstName = NULL;
        new_node->lastName = NULL;

        new_node->lengthSurname = 0;
        new_node->firstSurname = NULL;
        new_node->lastSurname = NULL;

        new_node->lengthScore = 0;
        new_node->firstScore = NULL;
        new_node->lastScore = NULL;


    }
    return(new_node);
}

/*============================================== INSERT_NODE ==============================================*/

int insert_node(char Name[40], char Surname[40], char Score[2], int Midterm, int FinalScore, int Quiz, int Project, int Total, head_type* list)
{
    node_type* new_node;
    if (new_node = alloc_node(Name, Surname, Score, Midterm, FinalScore, Quiz, Project, Total, list->firstName))
    {
        list->firstName = new_node;

        if (list->lengthName == 0)
            list->lastName = new_node;
        list->lengthName;
        return(1);
    }
    if (new_node = alloc_node(Name, Surname, Score, Midterm, FinalScore, Quiz, Project, Total, list->firstSurname))
    {
        list->firstSurname = new_node;

        if (list->lengthSurname == 0)
            list->lastSurname = new_node;
        list->lengthSurname;
        return(1);
    }
    if (new_node = alloc_node(Name, Surname, Score, Midterm, FinalScore, Quiz, Project, Total, list->firstScore))
    {
        list->firstScore = new_node;

        if (list->lengthScore == 0)
            list->lastScore = new_node;
        list->lengthScore;
        return(1);
    }
    else
    {
        return(0);
    }
}

/*============================================== DISPLAY FUNCTION =========================================*/

void displayList(node_type* current_node, int i) {

    printf("--------------------------------------------------");
    printf("\n    %d. Student Information : \n\n", i);
    printf("    Name of Student: %s\n", current_node->studentName);
    printf("    Surname of Student: %s\n", current_node->studentSurname);
    printf("    Lettered Score of Student: %s\n", current_node->Score);
    printf("    Student Midterm Score: %d\n", current_node->midtermScore);
    printf("    Student Final Score: %d\n", current_node->finalScore);
    printf("    Student Quiz Score: %d\n", current_node->quizScore);
    printf("    Student Project Score: %d\n", current_node->projectScore);
    printf("    Student Total Score: %d\n", current_node->totalScore);
    printf("--------------------------------------------------\n\n");

}
double highest = 0;
double  average;
double lowest = 9999999;
int cmpStr(char str1[40], char str2[40]) {
    int i = 0;
    while (1) {
        if (str1[i] == str2[i]) {
            i++;
        }
        else {
            break;
        }
    }
    if (str1[i] < str2[i]) {
        return 1;
    }
    else {
        return 0;
    }
}

void updateScore(head_type* list)
{

    char letter[4];
    node_type* newNode;
    newNode = list->firstName;
    double sum = 0;
    while (newNode != NULL)
    {
        sum += newNode->totalScore;
        if (newNode->totalScore > highest)
        {
            highest = newNode->totalScore;
        }
        if (newNode->totalScore < lowest)
        {
            lowest = newNode->totalScore;
        }
        newNode = newNode->nextName;
    }

    if (newNode == NULL)
    {
        newNode = list->lastName;
        sum += newNode->totalScore;
        if (newNode->totalScore > highest) {
            highest = newNode->totalScore;
        }
        if (newNode->totalScore < lowest) {
            lowest = newNode->totalScore;
        }
    }

    average = sum / list->quantityStudents;

    int st1 = (highest - lowest) / 3;
    int st2 = (average - lowest) / 2;
    newNode = list->firstName;

    while (newNode != NULL) {

        if (newNode->totalScore > (100 - st1) && newNode->totalScore <= 100) {
            strcpy(newNode->Score, "AA");
        }
        else if (newNode->totalScore > (100 - 2 * st1) && newNode->totalScore <= (100 - st1)) {
            strcpy(newNode->Score, "BB");
        }
        else if (newNode->totalScore > 2 * st2 + lowest && newNode->totalScore <= (100 - 2 * st1)) {
            strcpy(newNode->Score, "CC");
        }
        else if (newNode->totalScore > st2 + lowest && newNode->totalScore <= 2 * st2 + lowest) {
            strcpy(newNode->Score, "DD");
        }
        else if (newNode->totalScore < st2 + lowest) {
            strcpy(newNode->Score, "F");
        }
        else {
            strcpy(newNode->Score, "XD");
        }
        newNode = newNode->nextName;
    }

    if (newNode == NULL) {
        newNode = list->lastName;
        if (newNode->totalScore > (100 - st1) && newNode->totalScore <= 100) {
            strcpy(newNode->Score, "AA");
        }
        else if (newNode->totalScore > (100 - 2 * st1) && newNode->totalScore <= (100 - st1)) {
            strcpy(newNode->Score, "BB");
        }
        else if (newNode->totalScore > 2 * st2 + lowest && newNode->totalScore <= (100 - 2 * st1)) {
            strcpy(newNode->Score, "CC");
        }
        else if (newNode->totalScore > st2 + lowest && newNode->totalScore <= 2 * st2 + lowest) {
            strcpy(newNode->Score, "DD");
        }
        else if (newNode->totalScore < st2 + lowest) {
            strcpy(newNode->Score, "FF");
        }

    }

}





/*============================================ LIST BY FUNCTIONS ==========================================*/
void listbyNAME(head_type* list)
{
    node_type* current_node;
    current_node = list->firstName;
    int i = 1;
    while (current_node) {
        displayList(current_node, i);
        current_node = current_node->nextName;
        i++;
    }

}
void listbySURNAME(head_type* list)
{
    node_type* current_node;
    current_node = list->firstSurname;
    int i = 1;
    while (current_node) {
        displayList(current_node, i);
        current_node = current_node->nextSurname;
        i++;
    }

}
void listbySCORE(head_type* list)
{
    node_type* current_node;
    current_node = list->firstScore;
    int i = 1;
    while (current_node) {
        displayList(current_node, i);
        current_node = current_node->nextScore;
        i++;
    }

}

/*================================================= MAIN ===============================================*/

int main(void) {
    system("COLOR 1F");
    head_type* list;
    list = create();

    //data
    insert_node("Alperen", "Demirturkoglu", "AA", 65, 52, 44, 88, 44, list);
    insert_node("Mert", "Altuntas", "AB", 78, 76, 58, 95, 90, list);
    insert_node("Onur", "Oztas", "AA", 23, 12, 45, 78, 45, list);



    int rakam;
    printf("\n=============================================================\n");
    printf("\n\n\t\tWELCOME TO THE DATA STRUCTURE PROJECT");
    printf("\n\t1.  LIST BY NAME");
    printf("\n\t2.  LIST BY SURNAME");
    printf("\n\t3.  LIST BY SCORE/GRADE");
    printf("\n\t4.  REVERSE LIST BY NAME");
    printf("\n\t5.  REVERSE LIST BY SURNAME");
    printf("\n\t6.  REVERSE LIST BY SCORE/GRADE");
    printf("\n\t7.  DELETE A STUDENT");
    printf("\n\t8.  ADD A NEW STUDENT");
    printf("\n\t9. EXIT");
    printf("\n\n=============================================================\n\n");

    printf("\n\n\tENTER YOUR CHOICE:\t");
    scanf_s("%d", &rakam);
    switch (rakam) {

    case 1:
        system("cls");
        listbyNAME(list);
        exit(1);
    case 2:
        system("cls");
        listbySURNAME(list);
        exit(1);
    case 3:
        system("cls");
        listbySCORE(list);
        exit(1);


    default:
        printf("\nWrong choise. Please enter the correct numbers to use program.\n");
        break;

    }

    return 0;
}

/*============================================================================================*/
