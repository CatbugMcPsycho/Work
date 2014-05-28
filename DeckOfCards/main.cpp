/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 30, 2014, 12:54 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//Our Libraries
#include "Card.h"
#include "Deck.h"

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Create an array of 52 cards
    int nCards=52;
    Card **card=new Card*[nCards];
    Deck deck(nCards);
    //Check out all the cards
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i);
        cout<<card[i]->name()<<card[i]->suit();
        cout<<" "<<static_cast<int>(card[i]->value());
        cout<<" "<<static_cast<int>(card[i]->getNumber())<<endl;
    }
    //Delete the arrays
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    //Exit stage right
    cout<<"Press a number key"<<endl;
    int dum;
    cin>>dum;
    return 0;
}

