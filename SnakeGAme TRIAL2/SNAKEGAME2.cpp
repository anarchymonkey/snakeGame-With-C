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

/* INSERTING SNAKE TO LINKED LIST */
char insertSnake(char value)
{
    Snake *newNode = new Snake;
    Snake *tailNode;
    newNode->data = value;

    if(head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        tailNode = head;
        while(tailNode->next != NULL)
        {
            tailNode = tailNode->next;
        }
        tailNode->next = newNode;
        newNode->next = NULL;
    }
    return newNode->data;

}

/* END OF INSERTING SNAKE */

/* DELETING THE LASTNODE OF THE SNAKE */
void deleteLastnode()
    {
        Snake *toDelete;
        Snake *preNode;

        if(head == NULL)
        {
            cout<<"NO ELEMENTS THERE"<<endl;
        }
        else
        {
            toDelete = head;
            preNode = head;

            while(toDelete->next != NULL)
            {   preNode = toDelete;
                toDelete = toDelete->next;
            }

            if(toDelete == head)
            {
                head = NULL;
            }
            else{
                preNode->next = NULL;
            }

            delete toDelete;
        }

    }
/* END OF DELETING SNAKE */


/* CREATE THE BOUNDARY */
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

/* END OF CREATING BOUNDARY */

void initSnake(int ROW,int COL)
{
    Snake *init = new Snake;

    init->x = ROW;
    init->y = COL;
    cout<<"ROW IS"<<init->x<<endl;
    cout<<"COL IS"<<init->y<<endl;
     while(startingPoint<5)
    {
        matrix[init->x][(init->y)++] = insertSnake('*');
        startingPoint++;
    }

}

/* DISPLAY THE BOUNDARY */

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

/* CREATE THE BOUNDARY */

void moveSnake(int ROW,int COL)
{
    Snake *movement = new Snake;
    movement->x = ROW;
    movement->y = COL;
    deleteLastnode();
    matrix[movement->x][movement->y] = insertSnake('*');


}

/* CODE FOR MOVEMENT */
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
        cin>>key;


    }

}




int main()
{
    CreateBoundary();
    initSnake(row,col);
    DisplayBoundary();
    cout<<"ENTER\n W TO MOVE UPWARDS\n S TO MOVE DOWNWARDS \n A TO MOVE LEFT \n D TO MOVE RIGHT"<<endl;
    cin>>key;
    movement(key);
}
