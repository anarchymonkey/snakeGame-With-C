#include<iostream>
#include<stdio.h>
#include<windows.h>
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

/* FOR GETTING THE COORDINATES [ to be understood by Anmol Jande ] */
void getCoords(int a,int b)
{
    struct Snake *t=head;
    t->x = a;
    t->y = b;
}
/* END FUNCTION */
/* ADD THE MOVEMENT SHIFTER FUNCTION TO IMPLEMENT */

void moveSnake(char matrix[][80])
{
    struct Snake *node_x = head;
    matrix[node_x->x][node_x->y] = node_x->data;
}

/*END OF THE MOVEMENT FUNCTION */
/* END OF THE ADD FUNCTION , WHERE THE SNAKE IS ADDED */
void movement(char matrix[][80],char key)
{

    while(key!='e')
    {
        addSnake(matrix);

        switch(key)
        {
            case 'w':
                system("cls");
                row=row-1;
                getCoords(row,col);
                moveSnake(matrix);
                break;
            case 'a':

                system("cls");
                col=col-1;
                getCoords(row,col);
                moveSnake(matrix);


                                break;
            case 's':
               system("cls");
                row=row+1;
                getCoords(row,col);
                moveSnake(matrix);


                break;
            case 'd':
                system("cls");
                col=col+1;
                getCoords(row,col);
                moveSnake(matrix);

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
    system("cls");
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
   system("cls");
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
system("cls");
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
