#ifndef RUIMTE_H
#define RUIMTE_H

#include "GameObject.hpp"


class Ruimte : public GameObject
{
    public:
        Ruimte(std::string aName);
        virtual ~Ruimte();
        bool checkCollisions();
    protected:
    private:
};

#endif // RUIMTE_H
