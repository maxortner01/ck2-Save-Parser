#include "ck2Parser.h"

#include <iostream>

int main()
{
	ck2::File file("Derby775_07_18.ck2");
	ck2::SaveFile saveFile(file);
	
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

	std::getchar();
}