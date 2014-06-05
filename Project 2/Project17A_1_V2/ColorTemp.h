/* 
 * File:   ColorTemp.h
 * Author: rcc
 *
 * Created on June 5, 2014, 1:29 PM
 */

#ifndef COLORTEMP_H
#define	COLORTEMP_H
#include <string>
#include <cstring>
using namespace std;

template <class t>
class ColorTemp{
private:
    char *name;
    char cCode[5];
public:
    //Intial info
    color(char *,char []);
    //Return colors
    const char *getCode()const;
    //Return name
    const char *getname()const;
    //Delete
    ~color();
    
};




#endif	/* COLORTEMP_H */

