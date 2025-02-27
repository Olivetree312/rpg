/*INFO - Generic Character --> ALL STATS (0-100)
 * PRIMARY STATS (0-100%)
 * --> serve as MULTIPLIERS affecting secondary stats
 * 1. Strength (STR) >> Mana, Attack
 * 2. Dexterity (DEX) >> Speed, Stealth, Defense
 * 3. Constitution (CONS) >> Health, Stamina
 * 4. Intelligence (INTL) ~ needed to unlock skills
 * 5. Charisma (CHA) >> Affection, Deception
 *
 * SECONDARY STATS (points)
 * --> boosts depend on primary stats
 * 1. Mana Points (MP) ~ spell casting/ magic power
 * 2. Attack Power (AP) ~ power dealt by attack
 * 3. Speed (SPD) ~ how fast movements are
 * 4. Stealth (STH) ~ ability to move unseen
 * 5. Defense (DEF) ~ damage reduced from attacks
 * 6. Health Points (HP) ~ damage taken before dying at 0
 * 7. Stamina (STA) ~ governs attacks thrown before health damaged
 * 8. Affection (AFF) ~ likeability
 * 9. Deception (DCP) ~ ability to trick enemies
 *
 *	COIN (unlimited)
 * 	~used to make purchases and upgrades
 * 	~collected during game
 *
 * POINTS (100 initial upon character declaration, 1 time ONLY)
 * 	~may be allocated by user to any stat category
 *
 * SKILLS (some specific to character type) (0-100)
 *  ~may affect stats points or lead to outcomes
 *
 * INVENTORY (some items specific to character type)
 *  ~ stuff aquired
 *  ~ basics: coin, bread, water, stick
 *
 *CREATING CHARACTERS
 * ~ all characters given 100 points for user to allocate to stats
 *
 */
#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Character{
public:
//Constructors: all default stats 0, but HP is 10 & wealth = 100
	Character();
	//some characters may start off with more or less points
	Character(int points);
	Character(string name, string species);
//GETTERS AND SETTERS
	//getting quantity of specific stat/ skill/ inventory
	int getSTAT(string stat);
	int getINVENTORY(string inventory);
	int getPoints();
	//returning name/species/info
	string getName();
	string getSpecies();
	string getInfo();

	//user accessible setters
	void usePoints(string stat, int num);
	void setName(string name);
	void setSpecies(string species);

	//to display/ print info to ostream object, void bc
	//	chaining implemented in overloaded op
	void displayPROFILE(ostream& out);
	void displaySKILLS(ostream& out);
	void displaySTATS(ostream& out);
	void displayINVENTORY(ostream& out);

	friend ostream& operator<<(ostream& out, Character c);

protected:
	unordered_map<string, int> STATS;
	vector <string> SKILLS;
	unordered_map<string, int> INVENTORY;
	int points;
	string name, species;
	//hidden setters, not directly accessible by user
	void setSTAT(string stat, int num);
	//must update stats after changes --> mult secondary stats
	void updateSTATS(string primary);
	void setSKILL(string skill);
	void setINVENTORY(string inventory, int num);

	bool foundSKILL(string skill);
	bool foundINVENTORY(string inventory);
	bool foundSTAT(string stat);
};



#endif /* CHARACTER_H_ */
