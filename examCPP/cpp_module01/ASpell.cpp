#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string& name, const std::string& effects)
    : name(name), effects(effects)
{
}

ASpell::~ASpell()
{
}

const std::string& ASpell::getName() const
{
    return name;
}

const std::string& ASpell::getEffects() const
{
    return effects;
}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}