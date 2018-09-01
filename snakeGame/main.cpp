#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int startingPoint = 0;
int endingPoint = 4;
int row = 10;
int col = 40;
char matrix[20][80];
char key;

struct Snake
{
    int x;
    int y;
    char data;
    Snake *next;
};

Snake *head = NULL;

char insertSnake(char value)
{
    Snake *newNode = new Snake;
    newNode->data = value;

    if(head != NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    return newNode->data;
}

/* CREATE FOOD */

void createFood()
{
    int rowPos=(rand()%(20));
    int colPos=(rand()%(80));
    if(rowPos>1&&rowPos<20||colPos>1&&colPos<80)
    {
    if (matrix[rowPos][colPos] !='#')
    {
        matrix[rowPos][colPos] = '@';
    }
    else
    {
        createFood();
    }
    }
}

/* END CREATING FOOD */

/* DEFINITION OF THE MATRIX FUNCTION */
void CreateBoundary();
/* END OF DEFINITION OF THE MATRIX FUNCTION */

/* DEFINITION OF THE DISPLAY FUNCTION OF THE MATRIX */
void DisplayBoundary();
/* END OF DEFINITION OF THE MATRIX FUNCTION */


/* DECLARATION OF THE ADD FUNCTION , WHERE THE SNAKE IS ADDED TO HEAD */

void addSnake(char matrix[][80])
{
    Snake *temp = head;
    while(startingPoint < endingPoint)
    {
        matrix[row][col++] = insertSnake('*');
        startingPoint++;
    }
}
/* ADD THE MOVEMENT SHIFTER FUNCTION TO IMPLEMENT */

void moveSnake(int a , int b)
{
    struct Snake *t=head;
    t->x = a;
    t->y = b;

    matrix[t->x][t->y] = t->data;


    cout<<"THE ROW LIST IS"<<t->x<<endl;
    cout<<"THE COL LIST IS"<<t->y<<endl;
    struct Snake *node_x = head;
    matrix[node_x->x][node_x->y] = node_x->data;

}
/*END OF THE MOVEMENT FUNCTION */
/* CHECK WEITHER THE THING CONTAINS A STAR */
/* ********************************************* */
/* END OF THE ADD FUNCTION , WHERE THE SNAKE IS ADDED */
void movement(char key)
{


    while(key!='e')
    {


        system("cls");

        switch(key)
        {
            case 'w':
                row=row-1;
                moveSnake(row,col);
                break;
            case 'a':
                col=col-1;
                moveSnake(row,col);
                               break;
            case 's':
                row=row+1;
                moveSnake(row,col);
                break;
            case 'd':
                col=col+1;
                moveSnake(row,col);
                break;
        }
        cout<<"ROW IS "<<row<<endl<<" COL IS "<<col<<endl;
        DisplayBoundary();
        if(kbhit())
        key=getche();


    }

}

/* THE MAIN FUNCTION WHERE ALL THE FUNCTIONS OF DISPLAY,MOVE,EAT ARE CALLED */
int main()
{
    cout<<"WELCOME TO SNAKEEEEEEEEEEEEEE W/H MATRIXXXXXXX"<<endl;
    CreateBoundary(); //creating the boundary;
    cout<<"ENTER\n W to move Up\n S to move Down\n A to move left\n D to move right"<<endl;
    if(kbhit())
    key=getche();
    createFood();
    addSnake(matrix);
    movement(key);




    return 0;
}
/* END OF THE MAIN FUNCTION BODY */


/* DEFINITION */
void CreateBoundary()
{
   int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 80; j++)
        {

            if (i==1 || i==19|| j==1 || j==79)
            {
                matrix[i][j] ='#';
            }
            else
            {
                matrix[i][j] =' ';
            }
        }

        printf("\n");
    }

}

/* DISPLAYING THE BOUNDARY */
void DisplayBoundary()
{int i , j;
     for (i = 1; i <= 20; i++)
    {
        for (j = 1; j <= 80; j++)
        {
          cout<<matrix[i][j];
        }
        cout<<'\n';
    }
}
/* DISPLAY FINISHED */
