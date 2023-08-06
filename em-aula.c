#include <stdlib.h>
#include <stdio.h>

typedef struct Student {
    int favorite;
    struct Student *next;
} Student;

typedef struct {
    Student *first;
    Student *last;
    int preferCircle;
    int preferSquare;
} StudentsQueue;

typedef struct {
    int type;
    struct Sandwich *next;
} Sandwich;

typedef struct {
    Sandwich *top;
} SandwichesStack;

void queuePush( StudentsQueue *sq, int favorite ) {
    if ( favorite == 1 ) {
        sq->preferSquare++;
    } else {
        sq->preferCircle++;
    }

    Student *student = ( Student* ) malloc( sizeof( Student ) );
    student->favorite = favorite;

    if ( sq->first == NULL ) {
        sq->first = student;
        sq->last = student;
    } else {
        sq->last->next = student;
        sq->last = student;
    }
}

void queuePop( StudentsQueue *sq ) {
    if ( sq->first->favorite == 1 ) {
        sq->preferSquare--;
    } else {
        sq->preferCircle--;
    }

    Student *popped = sq->first;
    sq->first = sq->first->next;
    free( popped );
}

void stackPush( SandwichesStack *ss, int type ) {
    Sandwich *sandwich = ( Sandwich* ) malloc( sizeof( Sandwich ) );
    sandwich->type = type;

    sandwich->next = ss->top;
    ss->top = sandwich;
}

void stackPop( SandwichesStack *ss ) {
    Sandwich *popped = ss->top;
    ss->top = ss->top->next;
    free( popped );
}

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSize ) {
    StudentsQueue *sq = ( StudentsQueue* ) malloc( sizeof( StudentsQueue ) );
    sq->first = NULL;
    sq->last = NULL;
    sq->preferCircle = 0;
    sq->preferSquare = 0;

    for ( int i = 0; i < studentsSize; i++ ) {
        queuePush( sq, students[i] );
    }

    SandwichesStack *ss = ( SandwichesStack* ) malloc( sizeof( SandwichesStack ) );
    ss->top = NULL;

    for ( int i = sandwichesSize - 1; i >= 0; i-- ) {
        stackPush( ss, sandwiches[i] );
    }

    while ( 1 ) {
        if ( ss->top->type != sq->first->favorite ) {
            queuePush( sq, sq->first->favorite );
            queuePop( sq );
        } else {
            queuePop( sq );
            stackPop( ss );
        }

        if ( ss->top == NULL ) return 0;
        if ( sq->preferCircle == 0 && sq->preferSquare == 0 ) return 0;
        if ( sq->preferSquare == 0 && ss->top->type == 1 ) return sq->preferCircle;
        if ( sq->preferCircle == 0 && ss->top->type == 0 ) return sq->preferSquare;

    }
    return 0;
}

int main( int argc, char const *argv[] )
{
    int students1[] = {1, 0}, sandwiches1[] = {0, 0};
    int output1 = countStudents( students1, 2, sandwiches1, 2 );
    printf( "Teste 1:\nInput: students = [1,0]; sandwiches = [0,0]\nOutput: %d\n\n", output1 );

    int students2[] = {1, 1, 0, 0}, sandwiches2[] = {0, 1, 0, 1};
    int output2 = countStudents( students2, 4, sandwiches2, 4 );
    printf( "Teste 2:\nInput: students = [1,1,0,0]; sandwiches = [0,1,0,1]\nOutput: %d\n\n", output2 );

    int students3[] = {1, 1, 1, 0, 0, 1}, sandwiches3[] = {1, 0, 0, 0, 1, 1};
    int output3 = countStudents( students3, 6, sandwiches3, 6 );
    printf( "Teste 3:\nInput: students = [1,1,1,0,0,1]; sandwiches = [1,0,0,0,1,1]\nOutput: %d\n\n", output3 );
    return 0;
}
