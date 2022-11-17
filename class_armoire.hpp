#ifndef __CLASS_LOCALISATION_HPP__
#define __CLASS_LOCAlISATION_HPP__


class Armoire: public Localisation{
    public:
        void setName(std::string name);
        std::string getName();
};

#endif