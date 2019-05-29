#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct Card {

public:
	int rank;
	string card;
	string suit;


	string getSuit();
	string getCard();
	int getRank();

};

string Card::getSuit() {
	return suit;
};

string Card::getCard() {
	return card;
};

int Card::getRank() {
	return rank;
};

//storage
vector<Card> handA;
vector<Card> handB;
vector<Card> Board;

//inputs
void inputCard(string card);
void inputCard2(string card);
void inputCard3(string card);

//evaluators 
int calcRank();
const bool isFlush();
const bool isStraight();
const bool isFourOfAKind();
const bool isFullHouse();
const bool isThreeOfKind();
const bool isTwoPair();
const bool isOnePair();
int highCard();

unsigned long long int calcScore(int handRank);

//helpers
string sortByRank();
string sortHandByRank(string whichHand);