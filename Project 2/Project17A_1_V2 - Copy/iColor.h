/* 
 * File:   iColor.h
 * Author: Devin
 *
 * Created on June 8, 2014, 11:19 PM
 */

#ifndef ICOLOR_H
#define	ICOLOR_H

#include "cColor.h"
#include <string>
using namespace std;

class iColor : public color{
    private:
        char cCode[5];
        char uCode[5];
        char tries[5];
    public:
        //Set name
        iColor(char [],char []);
        //Resets cCode
        void setcCode(char []);
        //Return computer colors
        const char *getcCode()const;
        //User color combo
        void setuCode(char []);
        //Return user colors
        const char *getuCode()const;
        //tries construct
        void setTries();
        //Return tries
        const char *getTries()const;
        //Check combo
        void check();
        //Initial info
        
};


#endif	/* ICOLOR_H */

