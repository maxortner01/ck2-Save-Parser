# Crusader Kings 2 Save Parser
The Crusader Kings 2 save-game parser is a simple header-only library that extracts information from any Crusader Kings 2 save. At the moment the most basic character information is available to be extracted, but I intend to expand it to all data as it is still very much a **work in progress**.

One downside is the large amount of memory usage (as these files are stored in memory and they are quiet large). This is something I also plan on improving. However, I see it as a necessary evil which compromises memory for quick speeds.

## Installation
To install this into your project, you must copy the header file to your project and include at the top of your code. **The `traits.csv` must be in the directory of your executable**.

```C++
#include "ck2Parser.h"
```
If you are using the Game of Thrones mod and what the trait list, just set the new trait list with 

```C++
ck2::traitCSV = ck2::TraitCSV("traits_agot.csv");
```

**before** any usage of the functions.

## Usage
The library is very easy to use, first you must create a `File` object which loads the `.ck2` save file, then, you must make a `SaveFile` object which parses the data.

```C++
ck2::File file("save.ck2");
ck2::SaveFile save(file);
```

Then, if a character's ID is known, you can retrieve them with

```C++
ck2::Character player = save.getCharacter(504285);
```

From here, to get various information, you can simply call the information as a function.

```C++
std::string             name          = player.name();
std::vector<ck2::Trait> traits        = player.traits();
ck2::Attributes         attributes    = player.attributes();
ck2::Character*         mother        = player.mother();
std::vector<ck2::Character*> children = player.children();
```
