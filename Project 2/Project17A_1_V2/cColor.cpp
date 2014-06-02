/* 
 * File:   color.h
 * Author: Devin Taniguchi
 * Created on June 2, 2014, 11:31 AM
 */

#include "cColor.h"
#include <string>
#include <cstring>

/*void color::setCode(char c[]){
    for(int i=0;i<5; i++){
        cCode[i]=c[i];
    }
}

void color::setname(string n){
    name=n;
}*/

const char* color::getCode() const{
    return cCode;
}

const char* color::getname() const{
    return name;
}

color::color(char *n,char *c){
    name=new char[strlen(n)+1];
    cCode=new char[strlen(c)+1];
    strcpy(name,n);
    strcpy(cCode,c);
}

color::~color(){
    delete [] name;
    delete [] cCode;
}

