#include<iostream>
#include<stdio.h>
using namespace std;
int startingPoint = 0;
int endingPoint = 4;
int row = 10;
int col = 40;
char matrix[20][80];
char key;
struct Snake
{
    char x;
    char y;
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

/* DEFINITION OF THE MATRIX FUNCTION */
void CreateBoundary(char matrix[][80]);
/* END OF DEFINITION OF THE MATRIX FUNCTION */

/* DEFINITION OF THE DISPLAY FUNCTION OF THE MATRIX */
void DisplayBoundary(char matrix[][80]);
/* END OF DEFINITION OF THE MATRIX FUNCTION */


/* DECLARATION OF THE ADD FUNCTION , WHERE THE SNAKE IS ADDED TO HEAD */

void addSnake(char matrix[][80])
{

    while(startingPoint < endingPoint)
    {
        matrix[row][col++] = insertSnake('*');
        startingPoint++;
    }
}

/* END OF THE ADD FUNCTION , WHERE THE SNAKE IS ADDED */
void movement(char matrix[][80],char key)
{

    while(key!='e')
    {
        addSnake(matrix);

        switch(key)
        {
            case 'w':
                endingPoint++;
                startingPoint++;
                matrix[row--][col]='*';
                break;
            case 'a':
                break;
            case 's':
                endingPoint++;
                startingPoint++;
                matrix[row++][col]='*';
                break;
            case 'd':endingPoint++;
                break;
        }
        DisplayBoundary(matrix);
        cin>>key;

    }

}

/* THE MAIN FUNCTION WHERE ALL THE FUNCTIONS OF DISPLAY,MOVE,EAT ARE CALLED */
int main()
{
    system("cls");
    cout<<"WELCOME TO SNAKEEEEEEEEEEEEEE W/H MATRIXXXXXXX"<<endl;
    CreateBoundary(matrix); //creating the boundary;
    cout<<"ENTER\n W to move Up\n S to move Down\n A to move left\n D to move right"<<endl;
    cin>>key;
    movement(matrix,key);



    return 0;
}
/* END OF THE MAIN FUNCTION BODY */


/* DEFINITION */
void CreateBoundary(char matrix[][80])
{
   int i, j;
   int row = 10;
   int col = 40;

    for (i = 1; i <= 20; i++)
    {
        for (j = 1; j <= 80; j++)
        {

            if (i==1 || i==20 || j==1 || j==80)
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
void DisplayBoundary(char matrix[][80])
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
