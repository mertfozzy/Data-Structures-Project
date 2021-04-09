/*
Beykoz University - Computer Enginerring
Name: Mert Altuntas
ID : 1804010005
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MALLOC(x)((x * ) malloc(sizeof(x)))

/*============================================ NODE AND HEAD =============================================*/

struct node {
    char studentName[40], studentSurname[40];
    int midtermScore, finalScore, quizScore, projectScore, totalScore;
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
    int lengtSurname;
    int lengthScore;
};
typedef struct head head_type;

/*============================================= ALLOC_NODE ==============================================*/

node_type* alloc_node(char Name[40], char Surname[40], int Midterm, int FinalScore, int Quiz, int Project, int Total, node_type* ptr) {
    node_type* new_node;
    if (new_node = MALLOC(node_type)) {
        strcpy(new_node->studentName, Name);
        strcpy(new_node->studentSurname, Surname);
        new_node->midtermScore = Midterm;
        new_node->finalScore = FinalScore;
        new_node->quizScore = Quiz;
        new_node->projectScore = Project;
        new_node->totalScore = Total;
        new_node->nextName = ptr;
        new_node->nextSurname = NULL;
        new_node->nextScore = NULL;
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

        new_node->lengtSurname = 0;
        new_node->firstSurname = NULL;
        new_node->lastSurname = NULL;

        new_node->lengthScore = 0;
        new_node->firstScore = NULL;
        new_node->lastScore = NULL;


    }
    return(new_node);
}

/*============================================== INSERT_NODE ==============================================*/

int insert_node(char Name[40], char Surname[40], int Midterm, int FinalScore, int Quiz, int Project, int Total, head_type* list)
{
    node_type* new_node;
    if (new_node = alloc_node(Name, Surname, Midterm, FinalScore, Quiz, Project, Total, list->firstName))

    {
        list->firstName = new_node;

        if (list->lengthName == 0)
            list->lastName = new_node;
        list->lengthName;
        return(1);
    }
    else
    {
        return(0);
    }


}

/*============================================== DISPLAY FUNCTION =========================================*/

void displayList(head_type* list) {
    node_type* current_node;
    int i = 0;
    current_node = list->firstName;

    while (current_node)
    {
        printf("--------------------------------------------------");
        printf("\n    %d. Student Information : \n\n", i + 1);
        printf("    Name of Student: %s\n", current_node->studentName);
        printf("    Surname of Student: %s\n", current_node->studentSurname);
        printf("    Student Midterm Score: %d\n", current_node->midtermScore);
        printf("    Student Final Score: %d\n", current_node->finalScore);
        printf("    Student Quiz Score: %d\n", current_node->quizScore);
        printf("    Student Project Score: %d\n", current_node->projectScore);
        printf("    Student Total Score: %d\n", current_node->totalScore);
        printf("--------------------------------------------------\n\n");

        current_node = current_node->nextName;
        i++;

    }

}
/*============================================ LIST BY FUNCTIONS ==========================================*/
void listbyNAME(head_type* list)
{

}
void listbySURNAME(head_type* list)
{

}
void listbySCORE(head_type* list)
{

}

/*================================================= MAIN ===============================================*/

int main(void) {
    system("COLOR 1F");

    head_type* list;
    list = create();

    //data
    insert_node ( "Mert", "Altuntas", 78, 76, 58, 95, 90, list);
    insert_node ( "Onur", "Oztas", 23, 12, 45, 78, 45, list);
    insert_node ( "Alperen", "Demirturkoglu", 23, 12, 45, 78, 45, list);


        int rakam;
        printf("\n=============================================================\n");
        printf("\n\n\t\tWELCOME TO THE DATA STRUCTURE PROJECT");
        printf("\n\n\t1.  DISPLAY LIST");
        printf("\n\t2.  LIST BY NAME");
        printf("\n\t3.  LIST BY SURNAME");
        printf("\n\t4.  LIST BY SCORE/GRADE");
        printf("\n\t5.  REVERSE LIST BY NAME");
        printf("\n\t6.  REVERSE LIST BY SURNAME");
        printf("\n\t7.  REVERSE LIST BY SCORE/GRADE");
        printf("\n\t8.  DELETE A STUDENT");
        printf("\n\t9.  ADD A NEW STUDENT");
        printf("\n\t10. EXIT");
        printf("\n\n=============================================================\n\n");

        printf("\n\n\tENTER YOUR CHOICE:\t");
        scanf_s("%d", &rakam);
        switch (rakam) {
        
        case 1:
            system("cls");
            displayList(list);
            break;
        case 2:
            listbyNAME(list);
            break;
        case 3:
            listbySURNAME(list);
            break;
        case 4:
            listbySCORE(list);
            break;

        default:
            printf("\nWrong choise. Please enter the correct numbers to use program.\n");
            break;

        }
  
    return 0;
}

/*============================================================================================*/