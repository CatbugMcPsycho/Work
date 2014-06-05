/* 
 * File:   main.cpp
 * Author: Devin Taniguchi
 * Created on April 27, 2014, 9:32 PM
 * Purpose: Project
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <fstream>
#include "cColor.h"
using namespace std;

//Structures

struct cColor{
        char *name;
        char cCode[5];
    };
//No Global Constants

//Function Prototype
void Menu();
int getN();
void def(int);
void instruct();        //Instructions
void game1(cColor,string [],int &,int &);   //Function to hold game
void game2(cColor [],string []);
void game3(cColor,string []);
void cCLR(cColor &,int);
char test(cColor);

//Execution Starts here
int main(int argc, char** argv) {
    //Declare variables
    string list[10];
    int inN,
        nWins,
        nLoses;
    do{
            Menu();
            inN=getN();
            //reads in file
            //Tells Current win lose ratio
            
            switch(inN){
            case 1: instruct();break;
            case 2:{
                //Read file in
                ifstream in;
                in.open("ratio.dat");
                in>>nWins;
                in>>nLoses;
                cout<<"Current Win Lose record is"<<endl;
                cout<<"Wins: "<<nWins<<endl;
                cout<<"Losses: "<<nLoses<<endl;
                cout<<endl;
                //Play Game
                cColor comp;
                cCLR(comp,5);
                game1(comp,list,nWins,nLoses);
                //Output to same file
                ofstream out;
                out.open("ratio.dat");
                out<<nWins<<endl;
                out<<nLoses<<endl;
                //Close files
                in.close();
                out.close();
                break;
            }
            case 3:{
                cColor player[2];
                game2(player,list);
                break;
            }
            case 4:{
                cColor user;
                /*cColor comp;                
                cCLR(comp,5);
                test(comp);
                cout<<"quack"<<endl;
                game3(user,list);*/
                cCLR(user,5);
                for(int i=0;i<5;i++){
                    cout<<user.cCode[i]<<endl;
                }
                char test[10];
                cout<<"enter"<<endl;
                cin>>test;
                user.name=test;
                color quack(user.name,user.cCode);
                //cout<<"Name: "<<quack.getname()<<endl;
                //cout<<"Code: "<<quack.getCode()<<endl;
                quack.~color();
                break;
            }
            default:   def(inN);}
        }while(inN<5);
        return 0;
    return 0;
}

void cCLR(cColor &c, int k){
    srand(time(0));
    int clrnum;
    for(int i=0;i<k;i++){
        //Random number 0 to 5
	clrnum=(rand()%5)+1;
        
        //Changes numbers into colors
	switch(clrnum){
            case 1:{
               //Red
               c.cCode[i]='R';
               break;
            }
            case 2:{
               //Blue
               c.cCode[i]='B';
               break;
            }
            case 3:{
                //Yellow
               c.cCode[i]='Y';
               break;
            }
            case 4:{
               //Purple
               c.cCode[i]='P';
               break;
            }
            case 5:{
               //Green
               c.cCode[i]='G';
               break;
            }
        }         
    }
}

void game3(cColor c, string p[]){
    
}

void game1(cColor c,string p[],int &w,int &l){
    char win='n';
    int des,
        turns=0;
    char *guess;
    guess=new char[5];
    //Turn limit is 10, stops there
    while(turns!=10){
        turns++;        
        
        //Rules
        cout<<"Colors to pick from: Blue, Green,";
        cout<<" Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter ";
        cout<<"for your guess(capital letters only)."<<endl;
        cout<<endl;
        cout<<"Turn Number: "<<turns<<endl;
        cout<<endl;
        
            //User enter 4 colors
            for(int i=0;i<5;i++){
                    cout<<"Color"<<i<<": "; 
                    cin>>guess[i];
                    cout<<endl;
            }
            //Checks if any are right color and position
            for(int i=0;i<5;i++){
                if(guess[i]==c.cCode[i]){
                    cout<<"R"<<" ";
                }
                
                //Checks if any are the right color
                else{
                    if((guess[i]==c.cCode[0]|| 
                        guess[i]==c.cCode[1]||
                        guess[i]==c.cCode[2]||
                        guess[i]==c.cCode[3]||
                        guess[i]==c.cCode[4])&&
                        guess[i]!=c.cCode[i]){
                        cout<<"W"<<" ";
                    }
                    
                }
            }
            
            cout<<endl;
            cout<<endl;
            
            //Sends array to a string and puts string into an array
            //temp=c[1][0]<<c[1][1]<<c[1][2]<<c[1][3];
            //l[turns-1]=temp;
            string temp(guess,5);
            p[turns-1]=temp;
            
            //Confirms if all of the colors are right
            if(guess[0]==c.cCode[0]&&
               guess[1]==c.cCode[1]&&
               guess[2]==c.cCode[2]&&
               guess[3]==c.cCode[3]&&
               guess[4]==c.cCode[4]){
                cout<<"You win! Number of tries: "<<turns<<endl;
                cout<<endl;
                
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<turns;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            
                //Too make sure lose doesn't print
                win='y';
                turns=10;
                
                //changing win lose ratio
                w+=1;
            }
            else{
                cout<<"Incorrect."<<endl;
                cout<<endl;
            }
    }
    //If turns exceed 10 you lose
    if(turns==10&&win=='n'){
            cout<<"You lost."<<endl;
            cout<<endl;
            
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<10;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }  
            
            //Changing Win Lose Ratio
            l+=1;
            }
    
    cout<<endl;
    delete [] guess;
}

void game2(cColor c[],string p[]){
    char win='n';
    int des,
        turns1=0,
        turns2=0;
    char *guess1,*guess2;
    guess1=new char[5];
    guess2=new char[5];
    cout<<"Player 1 please enter your name."<<endl;
    cin>>c[0].name;
    cin.ignore();
    cout<<"Player 2 please enter your name."<<endl;
    cin>>c[1].name;
    cin.ignore();
    cout<<c[0].name;
    cout<<" please enter your color combo while ";
    cout<<c[1].name;
    cout<<" looks away."<<endl;
    for(int i=0;i<5;i++){
            cout<<"Color"<<i<<": "; 
            cin>>c[0].cCode[i];
            cout<<endl;
    }
    cout<<c[1].name;
    cout<<" please enter your color combo while ";
    cout<<c[0].name;
    cout<<" looks away."<<endl;
    for(int i=0;i<5;i++){
            cout<<"Color"<<i<<": "; 
            cin>>c[1].cCode[i];
            cout<<endl;
    }
    //Turn limit is 10, stops there
    cout<<"Now it's time for Player 1 to guess Player 2's combo."<<endl;
    while(turns1!=10){
        turns1++;        
        
        //Rules
        cout<<"Colors to pick from: Blue, Green,";
        cout<<" Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter ";
        cout<<"for your guess(capital letters only)."<<endl;
        cout<<endl;
        cout<<"Turn Number: "<<turns1<<endl;
        cout<<endl;
        
            //User enter 5 colors
            for(int i=0;i<5;i++){
                    cout<<"Color"<<i<<": "; 
                    cin>>guess1[i];
                    cout<<endl;
            }
        
            //Checks if any are right color and position
            for(int i=0;i<5;i++){
                if(guess1[i]==c[1].cCode[i]){
                    cout<<"R"<<" ";
                }
                
                //Checks if any are the right color
                else{
                    if((guess1[i]==c[1].cCode[0]|| 
                        guess1[i]==c[1].cCode[1]||
                        guess1[i]==c[1].cCode[2]||
                        guess1[i]==c[1].cCode[3]||
                        guess1[i]==c[1].cCode[4])&&
                        guess1[i]!=c[1].cCode[i]){
                        cout<<"W"<<" ";
                    }
                    
                }
            }
            
            cout<<endl;
            cout<<endl;
            
            //Sends array to a string and puts string into an array
            //temp=c[1][0]<<c[1][1]<<c[1][2]<<c[1][3];
            //l[turns-1]=temp;
            string temp(guess1,5);
            p[turns1-1]=temp;
            
            //Confirms if all of the colors are right
            if(guess1[0]==c[1].cCode[0]&&
               guess1[1]==c[1].cCode[1]&&
               guess1[2]==c[1].cCode[2]&&
               guess1[3]==c[1].cCode[3]&&
               guess1[4]==c[1].cCode[4]){
                cout<<"You win! Number of tries: "<<turns1<<endl;
                cout<<endl;
                
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<turns1;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            
                //Too make sure lose doesn't print
                win='y';
                turns1=10;
      
            }
            else{
                cout<<"Incorrect."<<endl;
                cout<<endl;
            }
    }
    //If turns exceed 10 you lose
    if(turns1==10&&win=='n'){
            cout<<"You lost."<<endl;
            cout<<endl;
            
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<10;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            }
    //Turn limit is 10, stops there
    cout<<"Now it's time for Player 2 to guess Player 1's combo."<<endl;
    while(turns2!=10){
        turns2++;        
        
        //Rules
        cout<<"Colors to pick from: Blue, Green,";
        cout<<" Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter ";
        cout<<"for your guess(capital letters only)."<<endl;
        cout<<endl;
        cout<<"Turn Number: "<<turns2<<endl;
        cout<<endl;
        
            //User enter 5 colors
            for(int i=0;i<5;i++){
                    cout<<"Color"<<i<<": "; 
                    cin>>guess2[i];
                    cout<<endl;
            }
        
            //Checks if any are right color and position
            for(int i=0;i<5;i++){
                if(guess2[i]==c[0].cCode[i]){
                    cout<<"R"<<" ";
                }
                
                //Checks if any are the right color
                else{
                    if((guess2[i]==c[0].cCode[0]|| 
                        guess2[i]==c[0].cCode[1]||
                        guess2[i]==c[0].cCode[2]||
                        guess2[i]==c[0].cCode[3]||
                        guess2[i]==c[0].cCode[4])&&
                        guess2[i]!=c[0].cCode[i]){
                        cout<<"W"<<" ";
                    }
                    
                }
            }
            
            cout<<endl;
            cout<<endl;
            
            //Sends array to a string and puts string into an array
            //temp=c[1][0]<<c[1][1]<<c[1][2]<<c[1][3];
            //l[turns-1]=temp;
            string temp(guess1,4);
            p[turns1-1]=temp;
            
            //Confirms if all of the colors are right
            if(guess2[0]==c[0].cCode[0]&&
               guess2[1]==c[0].cCode[1]&&
               guess2[2]==c[0].cCode[2]&&
               guess2[3]==c[0].cCode[3]&&
               guess2[4]==c[0].cCode[4]){
                cout<<"You win! Number of tries: "<<turns2<<endl;
                cout<<endl;
                
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<turns2;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            
                //To make sure lose doesn't print
                win='y';
                turns2=10;
      
            }
            else{
                cout<<"Incorrect."<<endl;
                cout<<endl;
            }
    }
    //If turns exceed 10 you lose
    if(turns2==10&&win=='n'){
            cout<<"You lost."<<endl;
            cout<<endl;
            
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<10;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            }
    
    cout<<endl;
    delete [] guess1;
    delete [] guess2;
}

void instruct(){
    //Rules
    cout<<"The main objective is to solve the computer's code."<<endl;
    cout<<endl;
    cout<<"With a 4 color combination for a code and 5 colors"<<endl;
    cout<<" to choose from you have the guess the combo in 10 "<<endl;
    cout<<"or you lose."<<endl;
    cout<<endl;
    cout<<"Additionally each time you guess you will be told "<<endl;
    cout<<"Whether you have a right color in the right "<<endl;
    cout<<"position or a right color in the wrong position "<<endl;
    cout<<"by the Rs and Ws at the end of your code."<<endl;
    cout<<"(Rs for right spot and color and Ws for only right color)"<<endl;
    cout<<endl;
}

void Menu(){
            cout<<"MASTERMIND"<<endl;
            cout<<"Type 1 for the Instructions"<<endl;
            cout<<"Type 2 to guess the computer's code"<<endl;
            cout<<"Type 3 to Play against a friend on the same computer"<<endl;
            cout<<"Type 4 to have the computer guess your code"<<endl;
            cout<<"Type anything else to exit"<<endl;
}

    int getN(){
            int inN;
            cin>>inN;
            return inN;
}
    
void def(int inN){
            cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
