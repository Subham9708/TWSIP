#include<iostream>
using namespace std;
char area[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char possibility = 'x';
int row,column;
bool tie =false;
void display_area(){
    system("cls");
    cout<<"Tic Tac Toe Game"<<endl; 
    cout<<"    PlayerA [x] \n    PlayerB [0] \n\n";

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t " << area[0][0] <<"   | "<< area[0][1]<<"   |  "<<area[0][2] <<" \n";
    cout<<"\t\t ____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t " << area[1][0] <<"   | "<< area[1][1]<<"   |  "<<area[1][2] <<" \n";
    cout<<"\t\t ____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t " << area[2][0] <<"   | "<< area[2][1]<< "   |  "<<area[2][2] <<" \n";
    cout<<"\t\t     |     |     \n";

}
void player_possibility(){
    int digit;
    if(possibility== 'x')
    cout<<"\n\t PlayerA [x] possibility:";
    if(possibility== 'o')
    cout<<"\n\t PlayerB [o] possibility:";
    cin>>digit;
    switch(digit){
        case 1: row=0;column =0; break;
        case 2: row=0;column =1; break;
        case 3: row=0;column =2; break;
        case 4: row=1;column =0; break;
        case 5: row=1;column =1; break;
        case 6: row=1;column =2; break;
        case 7: row=2;column =0; break;
        case 8: row=2;column =1; break;
        case 9: row=2;column =2; break;
        default: 
        cout<<"NULLIFY DIGIT   OR \n ";
        break;
    }
    if(possibility=='x' && area[row][column]!= 'x'&& area[row][column]!= 'o'){
        area[row][column]= 'x';
        possibility = 'o';
    }
    else if(possibility=='o'&& area[row][column]!= 'x'&& area[row][column]!= 'o'){
        area[row][column]= 'o';
        possibility = 'x';
    }
    else{
        cout<<"BOX is already filled.\n Try Again!!\n\n";
        player_possibility();
    }
    display_area();
}
bool gameend(){
    //win check
    for(int i=0;i<3;i++)
    if(area[i][0] == area[i][1] && area[i][0] == area[i][2] || area[0][i] == area[1][i] && area[0][i] == area[2][i])
    return false;

    if(area[0][0] == area[1][1] && area[0][0]==area[2][2] || area[0][2] == area[1][1] && area[0][2]==area[2][0])
    return false;
    // if there is any box not filled
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(area[i][j] != 'x' && area[i][j]!='o')
    return true;
    // Game draw out
    tie=true;
    return false;
    
}
 int main(){
 while(gameend()){
    display_area();
    player_possibility();
    gameend();
 }
 if(possibility == 'x' && tie==false )
 cout<<"PlayerB [o] wins!! \n";
 else if(possibility == 'o'&& tie==false )
 cout<<"PlayerA [x] wins!! \n"; 
 else{
    cout<<"Game Is Draw out! \n";
 }
}
