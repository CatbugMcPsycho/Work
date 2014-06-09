/* 
 * File:   color.h
 * Author: Devin Taniguchi
 * Created on June 2, 2014, 11:31 AM
 */

#ifndef COLOR_H
#define	COLOR_H

#include <string>
#include <cstring>
using namespace std;


class color{
private:
    char *name;
    char cCode[5];
    char uCode[5];
    char tries[5];
    
public:
    //Initial info
    color(char *,char [],char []);
    color(char *);
   // color();
    //Computer color combo
    void cmpClr(char []);
    //User color combo
    void setuCode(char []);
    //tries construct
    void setTries();
    //Check computer combo
    void check();
    //Return computer colors
    const char *getcCode()const;
    //Return user colors
    const char *getuCode()const;
    //Return tries
    const char *getTries()const;
    //Copy comp colors
    void copycCode(char []);
    //Copy tries
    void copyTries(char []);
    //Resets cCode
    void setcCode(char []);
    //Return name
    const char *getname()const;
    //Delete
    ~color();
    
};


#endif	/* COLOR_H */

