/* 
 * File:   color.h
 * Author: Devin Taniguchi
 * Created on June 2, 2014, 11:31 AM
 */

#include "cColor.h"
#include <string>
#include <cstring>
#include <time.h>
using namespace std;

//Returns computer Color combo
const char* color::getcCode() const{
    return cCode;
}

//Returns user Color combo
const char* color::getuCode() const{
    return uCode;
}

//Returns name
const char* color::getname() const{
    return name;
}

//Copy user info into class
color::color(char *n,char u[]){
    name=new char[strlen(n)+1];
    strcpy(name,n);
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
        }
}

//Sets Comp combo
void color::cmpClr(char c[]){
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
        }
}

//Check computer combo
void color::check(){
    //Checks if any are right color and position
            for(int i=0;i<5;i++){
                if(cCode[i]==uCode[i]){
                    tries[i]='R';
                }
                
                //Checks if any are the right color
                else{
                    if((cCode[i]==uCode[0]|| 
                        cCode[i]==uCode[1]||
                        cCode[i]==uCode[2]||
                        cCode[i]==uCode[3]||
                        cCode[i]==uCode[4])&&
                        cCode[i]!=uCode[i]){
                        tries[i]='W';
                    }
                    else{
                        tries[i]='B';
                    }
                    
                }
            }
}

void color::nClr(){
    srand(time(0));
    int clrnum;
    for(int i=0;i<5;i++){
        if(tries[i]='B'){
            char wrong=cCode[i];
            while(cCode[i]=wrong){
                //Random number 0 to 5
                clrnum=(rand()%5)+1;

                //Changes numbers into colors
                switch(clrnum){
                    case 1:{
                       //Red
                       cCode[i]='R';
                       break;
                    }
                    case 2:{
                       //Blue
                       cCode[i]='B';
                       break;
                    }
                    case 3:{
                        //Yellow
                       cCode[i]='Y';
                       break;
                    }
                    case 4:{
                       //Purple
                       cCode[i]='P';
                       break;
                    }
                    case 5:{
                       //Green
                       cCode[i]='G';
                       break;
                    }
                }   
            }
            
        }
        if(tries[i]='W'){
            //Random number 0 to 5
            clrnum=(rand()%5)+1;

            //Changes numbers into colors
            switch(clrnum){
                case 1:{
                   //Red
                   cCode[i]='R';
                   break;
                }
                case 2:{
                   //Blue
                   cCode[i]='B';
                   break;
                }
                case 3:{
                    //Yellow
                   cCode[i]='Y';
                   break;
                }
                case 4:{
                   //Purple
                   cCode[i]='P';
                   break;
                }
                case 5:{
                   //Green
                   cCode[i]='G';
                   break;
                }
            }         
        }
        if(tries[i]='R'){
            
        }
    }
}

//Delete 
color::~color(){
    delete []name;
}

