#include<iostream>
#include<cstdlib>

using namespace std;

char matrix[3][3]; /*tic-tac-toe matrix*/

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(void)
{
    char done;
    cout<<"this is the game of tic tac toe\n";
    cout<<"you will be playing against computer\n";
    done='\0';
    init_matrix();
    do{
        disp_matrix();
        get_player_move();
        done=check(); /*see if winner */
        if(done!='\0')
            break; /* winner */
        get_computer_move();
        done=check(); /*see if winner */
    }
    while(done=='\0');
    if(done=='X')
        cout<<"you won!\n";
    else
        cout<<"i won\n";
    disp_matrix(); /* show final position */
    return 0;
}
/* initialize the matrix */
void init_matrix(void)
{

    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        matrix[i][j]='\0';
}
/* get players move */
void get_player_move(void)
{
    int x,y;
    cout<<"enter x,y coordinates for your move";
    cin>>x>>y;
    x--;
    y--;
    if(matrix[x][y]!='\0')
    {
        cout<<"invalid move, try again\n";
        get_player_move();
    }
    else matrix[x][y]='X';
}
/* get move from computer */
void get_computer_move(void)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            if(matrix[i][j]=='\0')break;
            if(matrix[i][j]=='\0')break;
    }
    if(i*j==9)
    {
        cout<<"draw\n";
        exit(0);
    }
    else
        matrix[i][j]='O';
}
/* display the matrix on the screen*/
void disp_matrix(void)
{
    int t;
    for(t=0;t<3;t++)
    {
        cout<<matrix[t][0]<<"  | "<<matrix[t][1]<<" |  "<<matrix[t][2];
        if(t!=2)
            cout<<"\n---|---|---\n";
    }
    cout<<"\n";
}
/* see if there is a winner */
char check(void)
{
    int i;
    for(i=0;i<3;i++) /*check rows */
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
        return matrix[i][0];

    for(i=0;i<3;i++) /*check columns */
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
        return matrix[0][i];

    /* test diagonals */
        if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
        return matrix[0][0];

        if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
        return matrix[0][2];

    return '\0';
}
