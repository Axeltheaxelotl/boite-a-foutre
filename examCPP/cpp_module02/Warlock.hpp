#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    std::string name;
    std::string title;

    Warlock(const Warlock&);
    Warlock& operator=(const Warlock&);

    std::map<std::string, ASpell*> spells;

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& newTitle);
    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(std::string spellName);
    void launchSpell(std::string spellName, const ATarget& target);
};

#endif