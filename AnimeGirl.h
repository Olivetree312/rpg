/*INFO - Anime Girl
PRIMARY STATS:
STR: 40% (Not that strong, but not weak either)
DEX: 80% (Very fast and agile)
CONS: 70% (High stamina for running around and yelling "Sugoi!")
INTL: 30% (She’s not dumb, just... easily distracted)
CHA: 95% (Everyone loves her, even if she’s a bit much)

SECONDARY STATS;
MP: 20 (Doesn't use magic much)
AP: 35 (Not much attack power, but she can slap hard)
SPD: 90 (Fast as heck, always running late)
STH: 30 (Too loud to be sneaky)
DEF: 50 (Can tank some damage but mostly avoids getting hit)
HP: 60 (Not super tanky but won’t go down easily)
STA: 95 (Boundless energy—can talk and run for hours)
AFF: 100 (Radiates main character energy; everyone wants to be her friend)
DCP: 20 (Too honest and expressive to deceive anyone)

DEFAULT ANIMEGIRL:
species = human
info ^^
INVENTORY = {{"diary",1}, {"love letter", 1}, {"piece of toast",1}, {"cute stationary",1}, {"homemade bento",1}};
//all temporary
SKILLS = {"Shoujo Sparkle (+10 DEF): temporarily blinds enemies",
		 "Blushing Stutter (+20 AFF): increases affection when talking to crushes",
		 "Tearful Zoom (+10 SPD): increases speed dramatically when running away",
		 "Exaggerated Slap (+25 AP): powerful slap, most effective when embarrased"}
 */
#ifndef ANIMEGIRL_H_
#define ANIMEGIRL_H_

#include "Character.h"
using namespace std;

class AnimeGirl : public Character{
public:
//Constructors: all default stats 0, but HP is 10 & wealth = 100
	AnimeGirl();
	//some characters may start off with more or less points
	AnimeGirl(int points);

	//delete functions to prevent mod in child class
	void setSpecies(string species) = delete;

	void setHairColor(string hairColor);
	void setDereType(string dereType);
	void setCatchphrase(string catchphrase);
	void setAffectionMeter(string target, int points);

	void ShoujoSparkle();
	void BlushingStutter();
	void TearfulZoom();
	void ExaggeratedSlap();

	friend ostream& operator<<(ostream& out, AnimeGirl& c);

protected:
	//default: pink
	string hairColor;
	//default: Tsundere
	string dereType;
	//default: Baka!
	string catchphrase;
	//shows affection meter for each person
	unordered_map<string, int> affectionMeter;
};



#endif /* ANIMEGIRL_H_ */
