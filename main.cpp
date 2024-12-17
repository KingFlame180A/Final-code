#include<iostream>
#include<chrono>
#include<Windows.h>
using namespace std;
string inventory[10] = { " "," "," "," "," "," "," "," "," "," " };
int money = 100;
int playerhealth = 100;

//function declarations
void numberpuzzle();
void NPC();
void shop();
void Battlesys();
void golem();
void shop2();
void darkknight();


int main() {

	const int TIME_LIMIT = 150;
	auto start = chrono::steady_clock::now();
	int timeLeft = 150;
	string input;

	srand(time(NULL));
	int room = 1;

	while (timeLeft >= 0) {
		auto now = chrono::steady_clock::now();
		timeLeft = TIME_LIMIT - chrono::duration_cast<chrono::seconds>(now - start).count();
		cout << "Time left: " << timeLeft << "seconds\n";

		cout << "You have fallen into the cave you didn't remember what happened try and escape the cave before it collapse" << endl;
		do {

			cout << "you're inventory:";
			for (int i = 0; i < 10; i++)
				cout << inventory[i] << " | ";
			cout << endl << endl;

			switch (room) {
			case 1:
				cout << "You're in a large domed underground cave. Spiky stalagtites hange precariously from the ceiling. A shaft of sunlight shines dimly from the hole high above. Calm noises of dripping water surround you. You can go east" << endl;
				cout << "you found a dagger!" << endl;
				inventory[0] = "dagger";
				cout << "theres a dusty rug on the floor." << endl;
				cin >> input;
				if (input == "east" || input == "go east")
					room = 2;
				if (input == "rug" || input == "lock")
					input = "quit";
				break;
			case 2:
				shop();
				cout << "you're in a room where you have gone out and look around and see a trail of blood that led somewhere as it showed a corpse. You can go north or south" << endl;
				cin >> input;
				if (input == "south")
					room = 3;
				else if (input == "north")
					room = 1;
				break;
			case 3:
				cout << "you continue the cave but it began to become eerie and silent a bit too silent and would become suspicouse. You can go east or west" << endl;
				cin >> input;
				if (input == "east")
					room = 4;
				else if (input == "west")
					room = 2;
			case 4:
				Battlesys();
				cout << "you killed the conrtolled armor knight as you began to continue you're journey but you would feel some wounds on you. You can go east or west" << endl;
				cin >> input;
				if (input == "east")
					room = 5;
				else if (input == "west")
					room = 3;
			case 5:

				cout << "you continued and find a boot that was on the floor and see someone's foot. You can go east or west" << endl;
				cout << "a mine worker was on the floor and was surprised to see you. he began to follow you" << endl;
				NPC();
				cin >> input;
				if (input == "east")
					room = 6;
				else if (input == "west")
					room = 4;
			case 6:
				cout << "the mine worker would began to feel scared as he began to look around and you would get ready for what is about to happen. you can go north or west" << endl;
				cin >> input;
				if (input == "north")
					room = 7;
				else if (input == "west")
					room = 5;
			case 7:
				golem();
				cout << "you killed a golem but it was a lighter armor as the other one the miner gets the knights sword to defend himself as you two began to continu the journey. You can go north or south" << endl;
				cin >> input;
				if (input == "south")
					room = 6;
				else if (input == "north")
					room = 8;
			case 8:
				numberpuzzle();
				cout << "you made your path through the troll and some of the bats would go in a different away scattered around you but the mine worker helps you to scare away the bats. You can go east or south" << endl;
				cin >> input;
				if (input == "east")
					room = 9;
				else if (input == "south")
					room = 7;
			case 9:
				shop2();
				cout << "you and the mine worker began to go the jounrey from the cave before you see another knight who is standing there who have a sword and shield and behind is the end of the cave. You can go west or east" << endl;
				cin >> input;
				if (input == "west")
					room = 8;
				else if (input == "east")
					room = 10;
			case 10:
				darkknight();
				cout << "you have defeated the last one of the conrtolled knights you see the mine worker yahoo's and run for it to escape the cave. You can go weast or east to exit out the cave" << endl;
				cin >> input;
				if (input == "west")
					room = 9;
				else if (input == "east")
					return 0;

			}
		} while (input != "quit");
	}


}


void shop() {
	char input = 'p';
	cout << endl << endl << "--------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "press p for potion($10), c for chained mace($20), a for armor($30), q to quit" << endl;
		cin >> input;
		switch (input) {
		case 'p':
			if (money >= 10) {
				cout << "you got a potion!" << endl;
				inventory[0] = "potion";
				money -= 10;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		case 'c':
			if (money >= 20) {
				cout << "you got a chained mace!" << endl;
				inventory[1] = "chained mace";
				money -= 20;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		case 'a':
			if (money >= 30) {
				cout << "you got a armor!" << endl;
				inventory[0] = "armor";
				money -= 30;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		}
	}
	cout << "--------------------" << endl;
}


void shop2() {
	char input = 'p';
	cout << endl << endl << "--------------------" << endl;
	cout << "SHOP" << endl;
	while (input != 'q') {
		cout << "press p for full health potion($100), w for warhammer($50), a for armor($30), q to quit" << endl;
		cin >> input;
		switch (input) {
		case 'p':
			if (money >= 100) {
				cout << "you got full health potion!" << endl;
				inventory[3] = "full health potion";
				money -= 10;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		case 'w':
			if (money >= 50) {
				cout << "you got a warhammer!" << endl;
				inventory[4] = "warhammer";
				money -= 50;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		case 'a':
			if (money >= 30) {
				cout << "you got a armor!" << endl;
				inventory[5] = "armor";
				money -= 30;
			}
			else
				cout << "you're broke get outa here!" << endl;
			break;
		}
	}
	cout << "--------------------" << endl;
}


void golem() {
	int monsterhealth = 80;
	int input;
	int num;
	cout << endl << endl << "----------BATTLE TIME!!----------" << endl;
	while (playerhealth > 0 && monsterhealth > 0) {

		if (inventory[0] == "armor") {
			num = rand() % 35 + 35;
			cout << "you're armor takes impact for " << num << " DAMAGE!" << endl;
			playerhealth -= num;
		}
		else {
			num = rand() % 5 + 2;
			cout << "you punch the golem for " << num << "DAMAGE!" << endl;
			playerhealth -= num;
		}

		cout << "the golem swings its sword at you for 40 dmg" << endl;
		playerhealth -= 25;


		cout << "press 1 to attack, 2 to drink health potion, 3 to try to escape!" << endl;
		cin >> input;
		switch (input) {
		case 1:
			if (inventory[1] == "chained mace") {
				num = rand() % 35 + 35;
				cout << "you swing you're weapon at the golem for " << num << " DAMAGE!" << endl;
				monsterhealth -= num;
			}
			else {
				num = rand() % 5 + 2;
				cout << "you punch the golem " << num << "DAMAGE!" << endl;
				monsterhealth -= num;
			}
			cout << "you hit the golem for 30 dmg" << endl;
			monsterhealth -= 80;
		case 2:
			if (inventory[3] == "potion") {
				cout << "drink!" << endl;
				playerhealth += 50;
				inventory[3] = " ";
			}
			else cout << "sorry, you don't have any potions..." << endl;
			break;

			cout << "your health:" << playerhealth << endl;
			cout << "golem's" << monsterhealth << endl;

		case 3:
			num = rand() % 100;
			if (num > 65) {
				cout << "you succesfully run away!" << endl;
				monsterhealth = 0;
			}
			else cout << "you are cornered" << endl;
			break;
		default:
			cout << "sorry not an option" << endl;
		}
	}
	cout << "end of battle-------------------------------------" << endl;
}


void Battlesys() {
	int monsterhealth = 100;
	int input;
	int num;
	cout << endl << endl << "----------BATTLE TIME!!----------" << endl;
	while (playerhealth > 0 && monsterhealth > 0) {

		if (inventory[1] == "armor") {
			num = rand() % 35 + 35;
			cout << "you're armor takes impact for " << num << " DAMAGE!" << endl;
			playerhealth -= num;
		}
		else {
			num = rand() % 5 + 2;
			cout << "you punch the controled knight for " << num << "DAMAGE!" << endl;
			playerhealth -= num;
		}

		cout << "the controled knight swings its sword at you for 40 dmg" << endl;
		playerhealth -= 25;


		cout << "press 1 to attack, 2 to drink health potion, 3 to try to escape!" << endl;
		cin >> input;
		switch (input) {
		case 1:
			if (inventory[0] == "chained mace") {
				num = rand() % 35 + 35;
				cout << "you swing you're weapon at the controled knight for " << num << " DAMAGE!" << endl;
				monsterhealth -= num;
			}
			else {
				num = rand() % 5 + 2;
				cout << "you punch the controled knight " << num << "DAMAGE!" << endl;
				monsterhealth -= num;
			}
			cout << "you hit the controled knight for 30 dmg" << endl;
			monsterhealth -= 30;
		case 2:
			if (inventory[3] == "potion") {
				cout << "drink!" << endl;
				playerhealth += 50;
				inventory[3] = " ";
			}
			else cout << "sorry, you don't have any potions..." << endl;
			break;

			cout << "your health:" << playerhealth << endl;
			cout << "controled knight" << monsterhealth << endl;

		case 3:
			num = rand() % 100;
			if (num > 65) {
				cout << "you succesfully run away!" << endl;
				monsterhealth = 0;
			}
			else cout << "you are cornered" << endl;
			break;
		default:
			cout << "sorry not an option" << endl;
		}
	}
	cout << "end of battle-------------------------------------" << endl; 
	PlaySound(TEXT("sword.wav"), NULL, SND_FILENAME);
}


void darkknight() {
	int monsterhealth = 110;
	int input;
	int num;
	cout << endl << endl << "----------BATTLE TIME!!----------" << endl;
	while (playerhealth > 0 && monsterhealth > 0) {

		if (inventory[1] == "armor") {
			num = rand() % 35 + 35;
			cout << "you're armor takes impact for " << num << " DAMAGE!" << endl;
			playerhealth -= num;
		}
		else {
			num = rand() % 5 + 2;
			cout << "you punch the dark knight for " << num << "DAMAGE!" << endl;
			playerhealth -= num;
		}

		cout << "the dark knight swings its sword at you for 40 dmg" << endl;
		playerhealth -= 25;


		cout << "press 1 to attack, 2 to drink health potion, 3 to try to escape!" << endl;
		cin >> input;
		switch (input) {
		case 1:
			if (inventory[0] == "chained mace") {
				num = rand() % 35 + 35;
				cout << "you swing you're weapon at the dark knight for " << num << " DAMAGE!" << endl;
				monsterhealth -= num;
			}
			else {
				num = rand() % 5 + 2;
				cout << "you punch the controled knight " << num << "DAMAGE!" << endl;
				monsterhealth -= num;
			}
			cout << "you hit the dark knight for 30 dmg" << endl;
			monsterhealth -= 110;
		case 2:
			if (inventory[3] == "potion") {
				cout << "drink!" << endl;
				playerhealth += 50;
				inventory[3] = " ";
			}
			else cout << "sorry, you don't have any potions..." << endl;
			break;

			cout << "your health:" << playerhealth << endl;
			cout << "dark knight" << monsterhealth << endl;

		case 3:
			num = rand() % 100;
			if (num > 65) {
				cout << "you succesfully run away!" << endl;
				monsterhealth = 0;
			}
			else cout << "you are cornered" << endl;
			break;
		default:
			cout << "sorry not an option" << endl;
		}
	}
	cout << "end of battle-------------------------------------" << endl;
}


void NPC() {
	int num = rand() % 100 + 1;
	if (num < 20)
		cout << "I used to be a an worker in the mines unitl it crunmble and broke my arm" << endl;
	else if (num < 30)
		cout << "I was working nightshfit until it shook" << endl;
	else if (num < 25)
		cout << "the mine worker says: there is a monster here hiding in the shadow" << endl;
	else if (num < 50) {
		cout << "the mine worker gets up and gives you 10 gold!" << endl;
		money += 10;
	}
	else if (num < 60) {
		cout << "the mine worker gives you a armor potion" << endl;
		inventory[3] = "armor potion!";
	}

}


void numberpuzzle() {
	int limit = 100;
	auto start = chrono::steady_clock::now();
	int num = rand() % 20 + 1;
	int guess = -1;
	int timeleft = 100;
	system("color 2b");
	cout << "--------------------------------------------" << endl;
	cout << "a troll blocks you and the miner in the way. . . it says: guess a number between 1-20!" << endl;
	while (guess != num && timeleft > 0) {
		auto now = chrono::steady_clock::now();
		timeleft = limit = chrono::duration_cast <chrono::seconds> (now - start).count();
		cin >> guess;
		if (guess != num) {
			cout << "wrong answer!" << endl;
			cout << "time left:" << timeleft << endl;
		}
		else cout << "you got it!" << endl;

	}
}
