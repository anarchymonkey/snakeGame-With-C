#include <iostream>

using namespace std;

int starting_head=0;
int START_SNAKE_LENGTH=4;


struct Snake{
char x;
char y;
char data;
Snake *next;
};
Snake * head_x = NULL;
Snake *head_y = NULL;

int INSERT_HORIZONTAL(char value='*')
{
    Snake *newNode  = new Snake;
    newNode->data = value;

    if(head_x == NULL)
    {
        head_x = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head_x;
        head_x = newNode;
    }

    return newNode->data;
    newNode->next;
}

/* CREATED THE BOX OUTLINE */
void createBox(char gameBoundary[][80])
{
int i , j;
int row = 10;
int col = 40;

    for(i = 0 ; i < 20 ; i++)
    {
        for(j = 0 ; j < 80 ; j++)
        {

            gameBoundary[i][j] = '#';
             gameBoundary[5][5]=INSERT_HORIZONTAL('*');
            if( (i>0 && i<19)  && (j>0 && j<79) )
            {
                gameBoundary[row][col] = INSERT_HORIZONTAL('*');
                // gameBoundary[i][j] =' ';

               cout<<" ";
            }
            else
            {

                cout<<gameBoundary[i][j];
            }
        }
        cout<<"\n";


    }


}
/* BOX OUTLINE ENDS */

int main()
{
    char gameBoundary[20][80];
    createBox(gameBoundary);



}



