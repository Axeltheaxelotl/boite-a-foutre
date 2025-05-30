#ifndef DUNNY_HPP
#define DUNNY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget {
    public:
        Dummy();
        virtual ~Dummy();
        virtual Dummy* clone() const;
};

#endif