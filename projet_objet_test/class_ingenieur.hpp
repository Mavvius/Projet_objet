#ifndef __INGENIEUR_H__
#define __INGENIEUR_H__
#include "class_personnel.hpp"
#include <iostream>


class Ingenieur: public Personnel {
  public: 
    using Personnel::Personnel;
    virtual void actionMenu();
}; 

#endif