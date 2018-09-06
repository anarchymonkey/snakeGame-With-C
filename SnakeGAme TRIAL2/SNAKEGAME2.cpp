#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

/* GLOBAL VARIABLES */
int startingPoint = 0;
int endingPoint = 4;
int row = 10;
int col = 40;
char matrix[20][80];
char key;
int foodRow;
int foodCol;
int poisonRow;
int poisonCol;

/* **************************** */
struct Snake
{
    int x;
    int y;
    char data;
    Snake *next;
};

Snake *head = NULL;
/* INSERT MATRIX FUNCTION */
void insertMatrix()
{
  struct Snake *newNode;
  newNode=head;
  while(newNode->next!=NULL)
  {
    matrix[newNode->x][newNode->y]=newNode->data;
    newNode=newNode->next;
  }
    matrix[newNode->x][newNode->y]=' ';
};
/* ***************** */
/* CREATE MEMORY */

struct Snake* create(int ROW,int COL,char VALUE)
  {
    struct Snake *initNode;
    initNode=(struct Snake*)malloc(sizeof(struct Snake));
    initNode->x=ROW;
    initNode->y=COL;
    initNode->data=VALUE;
    initNode->next=NULL;
    return initNode;
  }

/* ******************* */

/* INSERT HEAD FUNCTION */

void insert(int ROW,int COL,char VALUE)
{
  struct Snake *newNode=create(ROW,COL,VALUE);
  struct Snake *tailNode=head;
  if(head==NULL)
  {
    head=newNode;
  }
  else
  {
    newNode->next=head;
    tailNode->data='*';
    head=newNode;
  }
}

/* END OF INSERT HEAD FUNCTION */

/* START OF DELETE FUNCTION */
void deleteSnake()
{
  Snake *toDelete=head;
Snake *tailDelete;
 while(toDelete->next!= NULL)
 {
   tailDelete=toDelete;
   toDelete=toDelete->next;
 }
 free(tailDelete->next);
 tailDelete->next=NULL;
}


/* END OF DELETE FUNCTION */



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
/* INITIALISED THE PRESENT BODY OF THE SNAKE */

void initSnake()
{
    while(startingPoint<endingPoint)
    {
        insert(row,col++,'*');
        startingPoint++;
    }
}
/* ***************************************** */

/* CREATE THE FOOD FOR THE SNAKE CAUSE THE SNAKE IS HUNGRYYYYYYYYYYYYYYYYYYYYY */

struct snakeFood
{
    int food_X;
    int food_Y;
    char theFood;
};


void createFood(char VALUE)
{
    snakeFood *newFood = new snakeFood;
    newFood->theFood = VALUE;

    foodRow = rand()%20;
    foodCol = rand()%80;
    newFood->food_X = foodRow;
    newFood->food_Y = foodCol;
    cout<<"ROW IS "<<foodRow<<endl<<"COL IS"<<foodCol<<endl;
    if((foodRow > 1 && foodRow < 19 )&&(foodCol>1 && foodCol<79))
    {
    matrix[newFood->food_X][newFood->food_Y] = newFood->theFood;
    }
    else
    {
        createFood(VALUE);
    }
}
/* **************************************************************************** */

/* CREATING THE POISON FOR THE SNAKE */
struct snakePoison
{
    int poison_X;
    int poison_Y;
    char thePoison;
};

void createPoison(char VALUE)
{
 snakePoison *newPoison = new snakePoison;
 newPoison->thePoison = VALUE;

 poisonRow = rand()%20;
 poisonCol = rand()%80;
 newPoison->poison_X = poisonRow;
 newPoison->poison_Y = poisonCol;
 cout<<"POISON ROW IS "<<poisonRow<<endl<<"POISON COL IS"<<poisonCol<<endl;

     if((poisonRow>1 && poisonRow <10) && (poisonCol>1 && poisonCol<70))
     {
         matrix[newPoison->poison_X][newPoison->poison_Y]=newPoison->thePoison;
     }
     else
     {
        createPoison(VALUE);
     }
}
/* **************************************************************************** */
/* **************************************************************************** */
/* CODE FOR MOVEMENT KEYS */
void movement(char key)
{


    while(1)
    {
        switch(key)
        {
            case 'w':
                row = row - 1; // going UP
                insert(row,col,'*'); // MAKING A NEW NODE AND ASSIGNING ITS DATA TO *
                insertMatrix(); // INSERTING THE init->data to the matrix position
                deleteSnake(); // DELETING THE LAST UNUSED NODE
                break;
            case 'a':
                col = col - 1; //going LEFT
                insert(row,col,'*');
                insertMatrix();
                deleteSnake();
                break;
            case 's':
                row = row + 1; //GOING DOWN
                insert(row,col,'*');
                insertMatrix();
                deleteSnake();
                break;
            case 'd':
                col = col + 1;//GOING RIGHT
                insert(row,col,'*');
                insertMatrix();
                deleteSnake();
                break;
        }
         system("cls");
        cout<<"ROW IS "<<row<<endl<<" COL IS "<<col<<endl;
        cout<<"FOOD ROW IS"<<foodRow<<endl<<"FOOD COL IS"<<foodCol<<endl;

        if(foodRow == row && foodCol == col)
        {
            insert(row,col,'*');
            createFood('@');

        }
        if(poisonRow == row && poisonCol == col)
        {



            matrix[row][col] = ' ';
            deleteSnake();
            createPoison('P');

        }

        DisplayBoundary();
        cin>>key;


    }

}

/* END CODE FOR MOVEMENT KEYS */


int main()
{   /* THE OUTER BOUNDARY IS CREATED */
    CreateBoundary();
    /* ***************************** */

    /* THE BODY OF THE SNAKE IS DECLARED */
    initSnake();
    /* ************************************ */

        createFood('@');
        createPoison('P');

    /* GIVING THE OPTIONS TO THE USER */
    cout<<"ENTER\n W TO MOVE UPWARDS\n S TO MOVE DOWNWARDS \n A TO MOVE LEFT \n D TO MOVE RIGHT"<<endl;
    cin>>key;
    movement(key);
    /* END OF GIVING OPTIONS TO THE USER */
}
