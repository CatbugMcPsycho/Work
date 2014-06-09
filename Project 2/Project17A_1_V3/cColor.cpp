/* 
 * File:   color.h
 * Author: Devin Taniguchi
 * Created on June 2, 2014, 11:31 AM
 * cColor specification
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

//Returns tries
const char* color::getTries() const{
    return tries;
}

//Returns name
const char* color::getname() const{
    return name;
}

//Copies user Color combo
void color::copycCode(char c[]){
    for(int i=0;i<5;i++){
        c[i]=cCode[i];
    }
}

//Copies tries results
void color::copyTries(char t[]){
    for(int i=0;i<5;i++){
        t[i]=tries[i];
    }
}

//Resets the comp color combo
void color::setcCode(char c[]){
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
    }
}

//Sets tries
void color::setTries(){
    for(int i=0;i<5;i++){
        tries[i]='W';
        }
}

//Copy user info into class
color::color(char *n,char u[],char c[]){
    name=new char[strlen(n)+1];
    strcpy(name,n);
    //copy user code
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
    }
    //copy comp code
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
    }
    //initial tries
    for(int i=0;i<5;i++){
        tries[i]='W';
    }
}

//Sets Comp combo
void color::cmpClr(char c[]){
    for(int i=0;i<5;i++){
        cCode[i]=c[i];
        }
}

//Sets USer combo
void color::setuCode(char u[]){
    for(int i=0;i<5;i++){
        uCode[i]=u[i];
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
                    //If none then bad
                    else{
                        tries[i]='B';
                    }
                    
                }
            }
}

//Delete 
color::~color(){
    delete []name;
}

