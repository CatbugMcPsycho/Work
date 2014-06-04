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
public:
    color(char *,char []);
    void setCode(char []);
    void setname(string);
    const char *getCode()const;
    const char *getname()const;
    ~color();
    
};


#endif	/* COLOR_H */

