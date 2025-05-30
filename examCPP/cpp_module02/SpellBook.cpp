#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it)
    {
        delete it->second;
    }
    spells.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell && spells.find(spell->getName()) == spells.end())
    {
        spells[spell->getName()] = spell->clone();
    }
}

void SpellBook::forgetSpell(const std::string& name)
