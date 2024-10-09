/*
 * @Author: Clark
 * @Email: haixuanwoTxh@gmail.com
 * @Date: 2024-01-16 19:35:39
 * @LastEditors: Clark
 * @LastEditTime: 2024-01-17 10:19:18
 * @Description: file content
 */

#include <string>
#include <iostream>

class Endangered
{
public:
    enum Status { critical, environment, improving };

    Endangered(Status stat = improving): animal_status(stat)
    {

    }

    virtual ~Endangered()
    {
        std::cout << "Endangered::~Endangered" << std::endl;
    }

    virtual std::ostream& print(std::ostream&) const
    {
        return std::cout << "Endangered::print" << std::endl;
    }

    virtual void highlight() const
    {
        std::cout << "Endangered::highlighted" << std::endl;
    }

private:
    Status animal_status;
};

class ZooAnimal;
extern std::ostream& operator<<(std::ostream&, const ZooAnimal&);

class ZooAnimal
{
public:
    ZooAnimal() = default;
    ZooAnimal(std::string animal, bool exhibit, std::string family)
        : nm(animal), exhibit_stat(exhibit), fam_name(family)
    {

    }

    virtual ~ZooAnimal()
    {
        std::cout << "ZooAnimal::~ZooAnimal" << std::endl;
    }

    virtual std::ostream &print(std::ostream&) const
    {
        std::cout << "ZooAnimal::print" << std::endl;
    }

    virtual int population() const
    {
        std::cout << "ZooAnimal::population" << std::endl;
        return 0;
    }

    // accessors
    std::string name() const
    {
        return nm;
    }

    std::string family_name() const
    {
        return fam_name;
    }

    bool onExhibit() const
    {
        return exhibit_stat;
    }

protected:
    std::string nm;
    bool exhibit_stat = false;
    std::string fam_name;

private:
};

// the order of the keywords public and virtual is not significant
class Raccoon : public virtual ZooAnimal
{
public:
    Raccoon() = default;

    Raccoon(std::string name, bool onExhibit=true);

    virtual std::ostream& print(std::ostream&) const
	{
        return  std::cout << "Raccoon::print" << std::endl;
    }

    bool pettable() const
    {
        return pettable_flag;
    }

    void pettable(bool petval)
    {
        pettable_flag = petval;
    }
    // . . .

protected:
    bool pettable_flag = false;
    // . . .
};

class Bear : virtual public ZooAnimal
{
public:
    // when the most derived class
    Bear(std::string name, bool onExhibit=true);

protected:
    // when an intermediate derived class
    Bear() : dance_flag(two_left_feet) { }

public:
    enum DanceType { two_left_feet, macarena, fandango };

    virtual std::ostream &print(std::ostream&) const
	{
        return  std::cout << "Bear::print" << std::endl;
    }

    virtual std::string isA() const
	{
        std::cout << "Bear::isA" << std::endl; return "Bear";
    }

    int mumble(int)
	{
        std::cout << "Bear::mumble" << std::endl; return 0;
    }

    void dance(DanceType) const
	{
        std::cout << "Bear::dance" << std::endl;
    }

	virtual ~Bear()
    {
        std::cout << "Bear::~Bear" << std::endl;
    }

private:
    std::string name;
    DanceType dance_flag;
};

class Panda : public Bear, public Raccoon, public Endangered
{
public:
    Panda() = default;

    Panda(std::string name, bool onExhibit=true);

    virtual std::ostream& print(std::ostream&) const
	{
        return  std::cout << "Panda::print" << std::endl;
    }

    bool sleeping() const
    {
        return sleeping_flag;
    }

    void sleeping(bool newval)
    {
        sleeping_flag = newval;
    }
    // . . .

protected:
    bool sleeping_flag = false;
    // . . .
};

Bear::Bear(std::string name, bool onExhibit)
    : ZooAnimal(name, onExhibit, "Bear")
{

}

Raccoon::Raccoon(std::string name, bool onExhibit)
    : ZooAnimal(name, onExhibit, "Raccoon")
{

}

Panda::Panda(std::string name, bool onExhibit)
      : ZooAnimal(name, onExhibit, "Panda"),
        Bear(name, onExhibit),
        Raccoon(name, onExhibit),
        Endangered(Endangered::critical),
        sleeping_flag(false)
{

}
