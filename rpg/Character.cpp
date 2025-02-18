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
#include "Character.h"
#include <iomanip>
using namespace std;


	Character::Character(){
		points = 100;
		STATS = {
				{"STR", 0}, {"DEX", 0}, {"CONS", 0}, {"INTL", 0}, {"CHA", 0},
				{"MP", 0},{"AP", 0}, {"SPD", 0}, {"STH", 0}, {"DEF", 0},
					{"HP", 0}, {"STA", 0}, {"AFF", 0}, {"DCP", 0},
		};
		SKILLS = {"BREATH"};
		INVENTORY = {{"COIN", 0}};
		name = "Unnamed";
		species = "Unknown";
		info = "None to be found";
	}
	//some characters may start off with more or less points
	Character::Character(int points){
		this->points = points;
		STATS = {
				{"STR", 0}, {"DEX", 0}, {"CONS", 0}, {"INTL", 0}, {"CHA", 0},
				{"MP", 0},{"AP", 0}, {"SPD", 0}, {"STH", 0}, {"DEF", 0},
					{"HP", 0}, {"STA", 0}, {"AFF", 0}, {"DCP", 0},
		};
		SKILLS = {"BREATH"};
		INVENTORY = {{"COIN", 0}};
		name = "Unnamed";
		species = "Unknown";
		info = "None to be found";
	}
	Character::Character(string name, string species){
		points = 100;
		STATS = {
				{"STR", 0}, {"DEX", 0}, {"CONS", 0}, {"INTL", 0}, {"CHA", 0},
				{"MP", 0},{"AP", 0}, {"SPD", 0}, {"STH", 0}, {"DEF", 0},
					{"HP", 0}, {"STA", 0}, {"AFF", 0}, {"DCP", 0},
		};
		SKILLS = {"BREATH"};
		INVENTORY = {{"COIN", 0}};
		this->name = name;
		this->species = species;
		info = "None to be found";
}
//GETTERS AND SETTERS
	//getting quantity of specific stat/ skill/ inventory
	int Character:: getSTAT(string stat){return STATS[stat];}
	int Character:: getPoints(){return points;}
	int Character::getINVENTORY(string inventory){return INVENTORY[inventory];}
	string Character::getName(){return name;}
	string Character::getSpecies(){return species;}
	string Character::getInfo(){return info;}

	void Character::setName(string name){this->name = name;}
	void Character::setInfo(string info){this->info = info;}
	void Character::setSpecies(string species){this->species = species;}

	//display character info
	void Character::displayINVENTORY(ostream& out){
		out << left << setw(10) << "INVENTORY" << right << setw(10) << "QUANTITY" << endl;
		out << setw(20) << string(20, '-') << endl;
		for(const auto& pair : INVENTORY){
			out << left << setw(5) << pair.first << ": "
					<< right << setw(10) << pair.second << endl;
		}
	}
	void Character::displaySKILLS(ostream& out){
		out << left << setw(10) << "SKILLS" << endl;
		out << setw(20) << string(20, '-') << endl;
		for(int i=0; i<SKILLS.size(); i++){
			out << i+1 << ". " << SKILLS[i] << endl;
		}
	}
	void Character::displaySTATS(ostream& out){
		out << left << setw(30) << "PRIMARY STATS" << right << setw(10) << "PERCENTAGE" << endl;
		out << setw(20) << string(40, '-') << endl;
		out << left << setw(20) << "Strength (STR): "
					<< right << setw(19) << STATS["STR"] << "%"<<  endl;
		out << left << setw(20) << "Dexterity (DEX): "
					<< right << setw(19) << STATS["DEX"] << "%"<< endl;
		out << left << setw(20) << "Constitution (CONS): "
					<< right << setw(19) << STATS["CONS"] << "%"<< endl;
		out << left << setw(20) << "Intelligence (INTL): "
					<< right << setw(19) << STATS["INTL"] << "%"<< endl;
		out << left << setw(20) << "Charisma (CHA): "
					<< right << setw(19) << STATS["CHA"] << "%"<< endl;
		out << endl;
		out << left << setw(30) << "SECONDARY STATS" << right << setw(10) << "POINTS" << endl;
		out << left << setw(20) << "~Boosts depend on primary stats~" << endl;
				out << setw(20) << string(40, '-') << endl;
		out << left << setw(20) << "Mana (MP): "
					<< right << setw(20) << STATS["MP"] << endl;
		out << left << setw(20) << "Attack Power (AP): "
					<< right << setw(20) << STATS["AP"] << endl;
		out << left << setw(20) << "Speed (SPD): "
					<< right << setw(20) << STATS["SPD"] << endl;
		out << left << setw(20) << "Stealth (STH): "
					<< right << setw(20) << STATS["STH"] << endl;
		out << left << setw(20) << "Defense (DEF): "
					<< right << setw(20) << STATS["DEF"] << endl;
		out << left << setw(20) << "Health (HP): "
					<< right << setw(20) << STATS["HP"] << endl;
		out << left << setw(20) << "Stamina (STA): "
					<< right << setw(20) << STATS["STA"] << endl;
		out << left << setw(20) << "Affection (AFF): "
					<< right << setw(20) << STATS["AFF"] << endl;
		out << left << setw(20) << "Deception (DCP): "
					<< right << setw(20) << STATS["DCP"] << endl;
	}

	void Character::displayPROFILE(ostream& out){
		out << setw(10) <<"NAME: " << name << endl;
		out << setw(10) << "SPECIES: " << species << endl;
		out << setw(10) << "INFO: " << info << endl;
		out << setw(10) << "POINTS: " << points << endl;
	}

	//setting level of certain stat/ skill/ inventory
	void Character::usePoints(string stat, int num){
		//iterator to key OR end()
		auto it = STATS.find(stat);
		if(it != STATS.end()){
			if(num<=points){
				STATS[stat]+=num;
				points-=num;
				cout << num << " points used --> ";
				cout << stat << " now at " << STATS[stat] << endl;
			}
			else{
				cout << "Insufficient points" << endl;
			}
		}
		else
			cout << "STAT not found" << endl;

	}
	//setters not to be directly used by user
	void Character::setSTAT(string stat, int num){
		STATS[stat] += num;
		if(stat=="STR"||stat=="CONS"||stat=="DEX"||stat=="CHA"){
			updateSTATS(stat);
		}
	}
	//updates secondary stats after primaries changed
	//to be used in setSTAT method
	void Character::updateSTATS(string primary){
		if (primary == "STR") {
            STATS["MP"] += STATS["MP"] * STATS[primary];  
            STATS["AP"] += STATS["AP"] * STATS[primary]; 
        }
        else if (primary == "DEX") {
            STATS["SPD"] += STATS["DEX"] * STATS[primary];
            STATS["STH"] += STATS["DEX"] * STATS[primary];
            STATS["DEF"] += STATS["DEX"] * STATS[primary];
        }
        else if (primary == "CONS") {
            STATS["HP"] += STATS["CONS"] * STATS[primary];
            STATS["STA"] += STATS["CONS"] * STATS[primary];
        }
        else if (primary == "CHA") {
            STATS["AFF"] += STATS["CHA"] * STATS[primary];
            STATS["DCP"] += STATS["CHA"] * STATS[primary];
        }

        cout << "Updated secondary stats based on " << primary << "!" << endl;
	}
	
	void Character::setSKILL(string skill){SKILLS.push_back(skill);}
	void Character::setINVENTORY(string inventory, int num){INVENTORY[inventory] = num;}

	bool Character:: foundSKILL(string skill){
		
	}
	bool Character:: foundINVENTORY(string inventory){
		if(INVENTORY.find(inventory)==INVENTORY.end()){
			cout << "Item not found." << endl;
			return false;
		}
		else
			return true;
	}
	bool Character:: foundSTAT(string stat){
		if(STATS.find(stat)==STATS.end()){
			cout << "Stat not found." << endl;
			return false;
		}
		else
			return true;
	}
	ostream& operator <<(ostream& out, Character c){
		c.displayPROFILE(out);
		out << endl;
		c.displaySTATS(out);
		out << endl;
		c.displaySKILLS(out);
		out << endl;
		c.displayINVENTORY(out);
		return out;
	}

