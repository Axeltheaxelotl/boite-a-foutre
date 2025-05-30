#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell {
    protected:
        std::string name;
        std::string effects;
    public:
        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell();
        const std::string& getName() const;
        const std::string& getEffects() const;
        virtual ASpell* clone() const = 0;
        void launch(const ATarget &target) const;
};

#endif