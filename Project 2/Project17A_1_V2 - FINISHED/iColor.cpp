/* 
 * File:   iColor.h
 * Author: Devin
 * Created on June 8, 2014, 11:19 PM
 * Specification for iColor class
 */

#include "iColor.h"
#include "cColor.h"
#include <string>
#include <cstring>
#include <time.h>
#include <iostream>
using namespace std;

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
void iColor::setuCode(char u[]){
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
        }
}

//Returns user Color combo
const char* iColor::getuCode() const{
    return uCode;
}



//Returns tries
const char* iColor::getTries() const{
    return tries;
}

//Check combo
void iColor::check(){
    //Checks if any are right color and position
            for(int i=0;i<5;i++){
                if(uCode[i]==cCode[i]){
                    tries[i]='R';
                }
                
                //Checks if any are the right color
                else{
                    if((uCode[i]==cCode[0]|| 
                        uCode[i]==cCode[1]||
                        uCode[i]==cCode[2]||
                        uCode[i]==cCode[3]||
                        uCode[i]==cCode[4])&&
                        uCode[i]!=cCode[i]){
                        tries[i]='W';
                    }
                    //If none then bad
                    else{
                        tries[i]='B';
                    }
                    
                }
            }
}
