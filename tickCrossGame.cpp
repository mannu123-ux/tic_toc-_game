#include<iostream>
using namespace std;

 char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
  
 char turn='X';
 int row,column;
 bool draw=false;

 void display()
 {
     system("cls");
   
   cout<<"\n\t\tT I C K   C R O S S   G A M E\n";
    cout<<"\tPlayer 1 [X]\n\tPlayer 2 [O]";

    cout<<"\n\n\t\t          |          |     \n";
    cout<<"\n\n\t\t    "<<board[0][0]<<"     |    "<<board[0][1]<<"     |   "<<board[0][2]<<"  \n";
    cout<<"\n\n\t\t__________|__________|__________\n";
    cout<<"\n\n\t\t          |          |     \n";
    cout<<"\n\n\t\t    "<<board[1][0]<<"     |    "<<board[1][1]<<"     |   "<<board[1][2]<<"  \n";
    cout<<"\n\n\t\t__________|__________|__________\n";    
    cout<<"\n\n\t\t          |          |     \n";
     cout<<"\n\n\t\t    "<<board[2][0]<<"     |    "<<board[2][1]<<"     |   "<<board[2][2]<<"  \n";
    cout<<"\n\n\t\t          |          |     \n";

 }

 void player_turn()
 {
     char choice;
    if(turn=='X'){

    cout<<"\n player 1 [X] Turn : ";
    }
    if(turn=='O'){

    cout<<"\n player 2 [O] Turn : ";
    }
    
    cin>>choice;

    switch(choice)
    {
        case '1':
         row=0;column=0; break;
        case '2':
         row=0;column=1; break;
        case '3':
         row=0;column=2; break;
        case '4':
         row=1;column=0; break;
        case '5': 
        row=1;column=1; break;
        case '6': 
        row=1;column=2; break;
        case '7': 
        row=2;column=0; break;
        case '8':
         row=2;column=1; break;
        case '9': 
        row=2;column=2; break;

        default:
        cout<<"Invalid Number";
        break;
            

    }

   if(turn=='X' && board[row][column]!='X' && board[row][column]!='O')
   {
       board[row][column]='X';
       turn='O';
   }
   else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O')
   {
       board[row][column]='O';
       turn='X';
   }
   else{
       cout<<"\tBOX allready filled\n\tPlease try again";
       player_turn();

   }
    display();


 }

  bool game_over()
 {
     //che ck win
     for(int i=0;i<3;i++)
     {
         if(board[i][0]==board[i][1] && board[i][0]==board[i][2]  || board[0][i]==board[1][i] && board[0][i]==board[2][i])
         return false;

         if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
         return false;

         
     }
     //if there is any box not filled    
     for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){

         if(board[i][j]!='X' && board[i][j]!='O')
         return  true;

     }
     }

     //game draw

     draw=true;
     return false;

 }

int main()
{
     
     while (  game_over())
     {     
     display();
     player_turn();
     game_over();
     
     }

     if(turn=='X' && draw==false)
     {
         cout<<"Player 2 [O] Win !!! CONGRESS.....\n";
     }
     else if(turn=='O' && draw==false)
     {
         cout<<"Player 1 [X] Win !!! CONGRESS.....\n";
     }

     else{
         cout<<"GAME DRAW...!!!!!!!!!!!!!!!\n";
     }
    return 0;
}