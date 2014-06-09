/* 
 * File:   iColor.h
 * Author: Devin
 * Created on June 8, 2014, 11:19 PM
 * Specification for iColor class
 */

#include "iColor.h"
#include <string>
#include <cstring>
#include <time.h>
using namespace std;

//Set name
iColor::iColor(char c[],char u[]){
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
    }
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
    }
    
}


//Resets the comp color combo
void iColor::setcCode(char c[]){
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
    }
}

//Returns computer Color combo
const char* iColor::getcCode() const{
    return cCode;
}

//Sets USer combo
void color::setuCode(char u[]){
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
        }
}

//Returns user Color combo
const char* iColor::getuCode() const{
    return uCode;
}

//Sets tries
void iColor::setTries(){
    for(int i=0;i<5;i++){
        tries[i]='W';
        }
}

//Returns tries
const char* iColor::getTries() const{
    return tries;
}

//Check combo
void iColor::check(){
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
                    //If none then bad
                    else{
                        tries[i]='B';
                    }
                    
                }
            }
}
