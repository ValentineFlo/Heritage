
#include <iostream>




class Personnage
{
public:

    Personnage(unsigned int PDV, unsigned int VITESSE, unsigned int LEVEL) : m_pdv(PDV), m_vitessedep(VITESSE), m_level(LEVEL) // constructeur personalisé
    {
        ptr = new int(5);
        std::cout << "constructeur perso" << std::endl;
    }
    ~Personnage()
    {
        delete ptr;
        std::cout << "destructeur perso" << std::endl;
    }

    

protected :  // seulement cette classe et les classe enfant peuvent y avoir accees
    unsigned int m_pdv, m_vitessedep, m_level;
    unsigned int m_x, m_y;
    int* ptr;

};

class Guerrier : public Personnage
{
public:
    Guerrier(unsigned int FORCE, unsigned int PDV, unsigned int VITESSE, unsigned int LEVEL) : Personnage(PDV, VITESSE, LEVEL), m_force(FORCE){}

    unsigned int coupMarteau()
    {
        return 10 * m_force;
    }
    void displayAttributes()
    {
        std::cout << m_force << std::endl;
        std::cout << m_pdv << std::endl;
        std::cout << m_vitessedep << std::endl;
        std::cout << m_level << std::endl;
    }

protected : 
    unsigned int m_force;
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// autres classes filles

class Magicien : public Personnage
{
public:
    Magicien(unsigned int MAGIE, unsigned int PDV, unsigned int VITESSE, unsigned int LEVEL) : Personnage(PDV, VITESSE, LEVEL), m_magie(MAGIE) {}
    

    unsigned int coupBaguette()
    {
        return 10 * m_magie;
    }
    void displayAttributesMag()
    {
        std::cout << m_magie << std::endl;
        std::cout << m_pdv << std::endl;
        std::cout << m_vitessedep << std::endl;
        std::cout << m_level << std::endl;
    }

private:
    unsigned int m_magie;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////   Classe fille de classe fille   /////////////////////////////////////////////

class GuerrierDef : public Guerrier
{
public: 
    GuerrierDef(unsigned int ARMOR, unsigned int FORCE, unsigned int PDV, unsigned int VITESSE, unsigned int LEVEL) : Guerrier(FORCE, PDV, VITESSE, LEVEL), m_armor(ARMOR)
    {
        std::cout << "constructeur guerrierdef" << std::endl;
    }
    void displayAttributesDef()
    {
        std::cout << m_armor << std::endl;
        std::cout << m_force << std::endl;
        std::cout << m_pdv << std::endl;
        std::cout << m_vitessedep << std::endl;
        std::cout << m_level << std::endl;
    }

private:
    unsigned int m_armor;

};





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{

    Guerrier warrior(5, 150, 10, 2);
    warrior.displayAttributes();
    std::cout << std::endl;
    Magicien wizard(10, 100, 15, 2);
    wizard.displayAttributesMag();
    std::cout << std::endl;
    GuerrierDef warriordef(50, 5, 150, 10, 2);
    warriordef.displayAttributesDef();

    return 0;
}

