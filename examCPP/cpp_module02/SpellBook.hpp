#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <map>
#include <string>
#include "ASpell.hpp"

class SpellBook {
    SpellBook(const SpellBook&);
    SpellBook& operator=(const SpellBook&);
    std::map<std::string, ASpell*> spells;
public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    ASpell* createSpell(const std::string& name);
};

#endif
