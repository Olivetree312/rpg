#include <iostream>
#include "Character.h"

using namespace std;

int main(){
	Character c("Princess Peach", "Human");
	cout << c;
	c.usePoints("STH", 5);
	cout << c;
}
