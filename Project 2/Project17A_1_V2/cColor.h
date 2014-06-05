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
    //Intial info
    color(char *,char []);
    //Computer color combo
    void cmpClr(char []);
    //Check computer combo
    void check();
    //Redoes Computer combo
    void nClr();
    //Return computer colors
    const char *getcCode()const;
    //Return user colors
    const char *getuCode()const;
    //Return name
    const char *getname()const;
    //Delete
    ~color();
    
};


#endif	/* COLOR_H */

