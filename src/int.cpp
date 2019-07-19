#include<random>
#include<deque>
#include<string>
using namespace std;
/*
deque<void (*)()> rules;

struct Servant
{
	string name;
	int attack, life, cost;
	int mod_attack=0, mod_life=0, mod_cost=0;
	void (*death_rattle)() = nullptr;
	void (*war_cry)(Servant*) = nullptr;
	void (*effect)() = nullptr;
	int operator>>(Servant& r) {
		mod_life -= r.attack;
		r.mod_life -= attack;
		if(mod_life + life <= 0) {
			death_rattle();
			field[side].

	}
};

struct Magic
{
	string name;
	int cost;
	int mod_cost=0;
	void (*effect)() = nullptr;
};

struct Hero {
	int life = 30;
	int mod_life = 0;
	void (*ability)() = nullptr;
	int side, accum = 0;
	void draw_card() {
		if(deck(side).empty()) mod_life -= ++accum;
		else {
			if(hand[side].size() < 10) hand[side].push_back(deck[side].front());
			deck[side].pop_front();
		} 
	}
	bool play_card(int h, int f, Servant* sv = nullptr) {
		if(mana < hand[side][h].cost) return false;
		if(field[side].size() == 7) return false;
		mana -= hand[side][h].cost;
		field[side].insert(field[side].begin() + f);
		if(hand[side][h].war_cry) *hand[side][h].war_cry(sv);
		if(hand[side][h].effect) rules.push_back(hand[side][h].effect);
	}
};

random_device rd;
mana = 10;
Servant north_cleric;
north_cleric.name = "북녁골 성직자";
north_cleric.attack = 1;
north_cleric.life = 3;
north_cleric.cost = 1;
north_cleric. = 1;
north_cleric.effect = &하수인 하나가 회복되면 카드 드로

Servant silvanas;
silvanas.name = "실바나스 윈드러너";
silvanas.attack = 5;
silvanas.life = 5;
silvanas.cost = 6;
silvanas.death_rattle = []() {
	random_int_distribution<> di{0, field[0].size() - 1};
	di(rd);


Magic change;
change.cost = 0;
change.effect = 상대편과 하수인들을 바꾼다;

Magic charge;
charge.cost = 0;
charge.effect = 내 마나수정을 모두 회복;

Magic heal_rune;
heal_rune.cost = 0;
heal_rune.effect = 모든 하수인 4 회복;
Servant akinai;
akinai.name = "아키나이 영혼 사제";
akinai.cost = 4;
akinai.attack = 3;
akinai.life = 5;
akinai.effect = 내 회복 카드과 능력이 피해를 줌;

Servant magic_cone;
magic_cone.cost = 3;
magic_cone.life = 3;
magic_cone.attack = 3;
magic_cone.war_cry = 모든 아군 캐릭터의 생명력 2 회복;

Servant gernalist;
gernalist.cost = 2;
gernalist.attack = 1;
gernalist.life = 2;
gernalist.war_cry = 하수인 하나를 선택하여 둘 복사하여 덱의 맨 위에;

Servant elf;
elf.cost = 1;
elf.life = 1;
elf.attack = 1;
elf.war_cry = 1피해;

Magic protect;
protect.cost = 1;
protect.effect = 하수인 하나에 생명력 +2. 카드 뽑기;

Magic heal_chain;
heal_chain.cost = 1;
heal_chain.effect = 하수인 하나와 내영웅의 생명력 5 회복;

Magic betray;
betray.cost = 3;
betray.effect = 아군 하수인 하나를 준다.


Servant crazy;
crazy.cost = 2;
crazy.attack = 3;
crazy.life = 2;
crazy.effect = 내가 주문시 모든 하수인에게 1 피해;

deque<Card> hand[2], field[2], deck[2];
Hero hero[2] = {
	{999, 0, nullptr},
	{30, -29, 2회복}
};

deck[1].push_back(crazy);
field[0].push_back(north_cleric);
field[1].push_back(north_cleric);
field[1].push_back(silvanas);


*/
template<typename T>
T add(const T a, const T b)
{
    return a + b;
}
int main()
{
    const char a = 1;
    const char b = 2;

    const char c = add<char>(a, b); // a and b implicitely converted to int.
                                    // Assignement to c fails (narrowing)

    (void)c;

    return c;
}


