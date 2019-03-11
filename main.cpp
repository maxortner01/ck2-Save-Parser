#include "ck2Parser.h"

#include <iostream>

void generateBiography(int id, ck2::SaveFile &sf)
{
	using namespace ck2;
	Character c = sf.getCharacter(id);

	std::string f;
	std::string full_name = c.title() + " " + c.name() + " " + c.nickname();

	f += full_name;
	f += " was born on " + c.birthDate();

	if (c.mother() || c.father())
	{
		f += " to ";

		if (c.mother())
		{
			f += c.mother()->name();
		}

		if (c.mother() && c.father())
		{
			f += " and ";
		}

		if (c.father())
		{
			f += c.father()->name();
		}
	}
	else 
	{
		f += " to unknown parents.";
	}

	if (c.children().size() == 1)
	{
		f += "\nThey have 1 child, " + c.children().at(0)->name() + ".";
	}
	else
	{
		f += "\nThey have " + std::to_string(c.children().size()) + " children.";
	}

	std::cout << f << std::endl;
}

int main()
{
	ck2::File file("Derby775_07_18.ck2");
	ck2::SaveFile saveFile(file);

	//generateBiography(506357, saveFile);

	//std::cout << "Character id: ";
	//unsigned int id;
	//std::cin >> id;
	//std::cout << "\n";
	
	ck2::Character c = saveFile.getCharacter(506357);
	
	std::cout << c.title() << " " << c.name() << " " << c.nickname() << " - " << c.birthDate() << std::endl;
	std::cout << "Traits: " << std::endl;
	
	for (int i = 0; i < c.traits().size(); i++)
	{
		std::cout << "  " << c.traits().at(i).name() << std::endl;
	}
	
	std::cout << "\nAttributes: " << std::endl;
	std::cout << "  Diplomacy:   " << c.attributes().diplomacy() << std::endl;
	std::cout << "  Marshall:    " << c.attributes().marshall() << std::endl;
	std::cout << "  Stewardship: " << c.attributes().stewardship() << std::endl;
	std::cout << "  Intrigue:    " << c.attributes().intrigue() << std::endl;
	std::cout << "  Learning:    " << c.attributes().learning() << std::endl;
	std::cout << "\n\n" << c.children().size() << ((c.children().size() == 1)?" child.":" children.") << std::endl;

	//unsigned int index = 0;
	//for (ck2::Character* father = c.father(); father; father = father->father())
	//{
	//	for (int i = 0; i < index; i++)
	//		std::cout << " ";
	//
	//	std::cout << "Name:   " << father->name() << std::endl;
	//
	//	for (int i = 0; i < index; i++)
	//		std::cout << " ";
	//
	//	if (father->spouse())
	//		std::cout << "Spouse: " << father->spouse()->name() << std::endl;
	//
	//	std::cout << "\n";
	//
	//	index++;
	//}

	//std::cout << c.father()->name() << "  - " << c.father()->birthDate() << std::endl;
	//std::cout << c.mother()->name() << "  - " << c.mother()->birthDate() << std::endl << std::endl;
	//
	//auto children = c.father()->children();
	//for (int i = 0; i < children.size(); i++)
	//{
	//	std::cout << "  ";
	//
	//	std::cout << children.at(i)->name() << " - " << children.at(i)->birthDate();
	//
	//	std::cout << "   Mother: " << children.at(i)->mother()->name() << "  Traits: " << children.at(i)->traits() << std::endl;
	//}

	//std::cout << c.mother()->name() <<  " - " << c.mother()->birthDate() << std::endl;
	int w;
	std::cin >> w;
}