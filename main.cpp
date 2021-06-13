#include <iostream>
#include <iomanip>
using namespace std;
int Board[7][6];


struct ConnectFour{
    int ActivePlayer;
    int counter;
    ConnectFour(){
        ActivePlayer = 1;
        for(int r = 0; r < 7; r++){
            for (int c = 0; c  < 6; c++){
                Board[r][c] = 0;
            }
        }
    }
    void ShowOnConsole(){
        cout<<setw(10)<<"  Col  ";
        for (int c = 1; c < 7; c++)
            cout<<setw(10)<<left<<c;
        cout<<endl<<"Row"<<endl;
        for(int r = 0; r < 7; r++){
            cout<<setw(10)<<left<<r+1;
            for (int c = 0; c  < 6; c++){
                if(Board[r][c] == 0)
                    cout<<setw(10)<<left<<".";
                else if(Board[r][c] == 1)
                    cout<<setw(10)<<left<<"O";
                else if(Board[r][c] == -1)
                    cout<<setw(10)<<left<<"X";
            }
            cout<<endl<<endl<<endl;
         }
        cout<<endl<<endl;
        for(int i = 0; i< 50; i++)
            cout<<"-";
        cout<<endl<<endl<<endl;
    }
    int MakeMove(int Col){
        if(Board[0][Col])
            return -1;
        for(int r = 0; r < 6; r++){
            if(Board[r + 1][Col]){
                Board[r][Col] = ActivePlayer;
                ActivePlayer*=-1;
                return 0;
            }
        }
        Board[6][Col] = ActivePlayer;
        ActivePlayer*=-1;
        return 0;
    }
    bool GameOver(){
        counter = 1;
        for(int i = 0 ; i < 7; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                if(Board[i][j] == Board[i][j + 1])
                {
                    counter++;
                }
                if(counter == 4)
                {
                   return true;
                   break;
                }
            }
        }
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if(Board[i][j] == Board[j + 1][i])
                {
                    counter++;
                }
                if(counter == 4)
                {
                   return true;
                   break;
                }
            }
        }
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if(Board[i][j] == Board[j + 1][i+1])
                {
                    counter++;
                }
                if(counter == 4)
                {
                   return true;
                   break;
                }
            }
        }
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 7; j++)
            {
                if(Board[i][j] == Board[j -1 ][i-1])
                {
                    counter++;
                }
                if(counter == 4)
                {
                   return true;
                   break;
                }
            }
        }
    }
};


int main()
{
    int column=0;
    int player=1;
    ConnectFour Game;
    Game.ShowOnConsole();
    do
    {
        cout<<"enter column"<<endl;
        cin>> column;
        Game.MakeMove(column-1);
        Game.ShowOnConsole();
        Game.GameOver();

        cout<<Game.counter<<endl;
    }
    while (Game.GameOver()==false);
    if (Game.ActivePlayer==-1)
    {
        cout<<"player 1 wins"<<endl;
    }
    else
    {
        cout<<"player 2 wins"<<endl;
    }

    return 0;
}
