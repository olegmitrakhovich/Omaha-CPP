
#include "Header.h"


//#include <fstream>



int main(string input, string output)
{
	int handRank = 0;

	//ifstream in("input.txt");
	//if (!in) {
	//	cout << "Cannot open input file.\n";
	//	return 1;
	//}

	//char str[255];

	//int found = 0;

	//while (in) {
	//	in.getline(str, 255);  
	//	if (in) cout << str << endl;

	//	ofstream myfile;
	//	myfile.open("output.txt");
	
	//	if (myfile.is_open()) {
	//		string s(str);
	//		cout << s << endl;
	//		myfile << "oleg" << s;
	//	}
		


	//	for (int i = 0; i <= 255; i++) {
	//		if (str[i] == ':'){
	//			string input;
	//			inputCard(input = {str[i + 1], str[i + 2]});
	//			cout << input << endl;
	//			inputCard(input = {str[i + 4], str[i + 5]});
	//			cout << input << endl;
	//			inputCard(input = {str[i + 7], str[i + 8]});
	//			cout << input << endl;
	//			inputCard(input = {str[i + 10], str[i + 11] });
	//			cout << input << endl;

	//			inputCard2(input = {str[i + 19], str[i + 20] });
	//			cout << input << endl;
	//			inputCard2(input = {str[i + 22], str[i + 23] });
	//			cout << input << endl;
	//			inputCard2(input = {str[i + 25], str[i + 26] });
	//			cout << input << endl;
	//			inputCard2(input = {str[i + 28], str[i + 29] });
	//			cout << input << endl;

	//			inputCard3(input = { str[i + 37], str[i + 38] });
	//			cout << input << endl;
	//			inputCard3(input = { str[i + 40], str[i + 41] });
	//			cout << input << endl;
	//			inputCard3(input = { str[i + 43], str[i + 44] });
	//			cout << input << endl;
	//			inputCard3(input = { str[i + 46], str[i + 47] });
	//			cout << input << endl;
	//			inputCard3(input = { str[i + 49], str[i + 50] });
	//			cout << input << endl;
	//			break;
	//		}

			
	//	}
		
		
	//}

	//in.close();
	
	inputCard("Ac");
	inputCard("4d");
	inputCard("Jd");
	inputCard("3d");

	inputCard2("5c");
	inputCard2("5d");
	inputCard2("6c");
	inputCard2("7d");

	inputCard3("Kc"); //Ah
	inputCard3("Kh"); //Kh
	inputCard3("Ts"); //5s
	inputCard3("9h"); //2s
	inputCard3("8h"); //Qd

	//handA
	//pick 3 of the highest cards on the board
	//	 pick 2 of the highest cards handA
	//		for place them inside another vector to be proccessed
	//			for check the highest hand

	//handB
	//for pick 3 of the highest cards on the board
	//	for pick 2 of the highest cards handA
	//			for place them inside the hand that is being proccessed
	//					for check the highest hand
		
	handRank = calcRank();

	unsigned long long int handScore;
	

    handScore = calcScore(handRank);

	cout << handScore << endl;

	//cout << sortHandByRank("A") << endl;
	//cout << sortHandByRank("B") << endl;

	//vector<Card> hand;

	vector <Card> hand1;
	vector <Card> hand2;

	unsigned long long int highestScoreHand1 = 0;
	unsigned long long int highestScoreHand2 = 0;

	vector<Card> BackUpBoard;
	BackUpBoard = Board;

	for (int i = 0; i < 4; i++) {
		 vector<Card> hand;
		 hand.push_back(BackUpBoard[i]);
		 for (int j = 0; j < 4; j++) {
			 if (j != i ) {
				 hand.push_back(BackUpBoard[j]);
				 for (int x = 0; x < 4; x++) {
					 if (x != j && x != i) {
						 hand.push_back(BackUpBoard[x]); 
						
						 for (int v = 0; v < handA.size(); v++) {
							 hand1 = hand;
							 hand1.push_back(handA[v]);
							 for (int k = 0; k < handA.size(); k++) {
								 if (k != v) {
									 hand1.push_back(handA[k]);
									 for (int r = 0; r < hand1.size(); r++) {
										 //cout << hand1[r].getCard();
									 }
									// cout << "Evaluate: " << endl;
									 Board = hand1;
									 unsigned long long int handScore;
									 handScore = calcScore(calcRank());
									 if (handScore > highestScoreHand1) {
										 highestScoreHand1 = handScore;
										 cout << "HandScore: " << handScore << endl;
										 //cout << "HighestScore: " << highestScoreHand1 << endl;
										// cout << "Highest Score Hand 1" << highestScoreHand1 << endl;
										 //for (int n = 0; n < hand1.size(); n++) {
										//	 cout << hand1[n].getCard();
										// }
									 }
									 hand1.erase(hand1.begin() + hand1.size() - 4);
								 }
							 }
							 hand1.erase(hand1.begin() + hand1.size() - 3);
						 }

						 for (int w = 0; w < handB.size(); w++){

							 ///////////////////////////////
							 hand2 = hand;
							 hand2.push_back(handB[w]);
							 for (int p = 0; p < handB.size(); p++) {
								 if (p != w) {
									 hand2.push_back(handB[p]);
									 for (int y = 0; y < hand2.size(); y++) {
										 //cout << hand1[r].getCard();
									 }
									 // cout << "Evaluate: " << endl;
									 Board = hand2;
									 unsigned long long int handScore2;
									 handScore2 = calcScore(calcRank());
									 if (handScore2 > highestScoreHand2) {
										 highestScoreHand2 = handScore2;
										 cout << "HandScore 2 >>>>>> : " << handScore2 << endl;
										 //cout << "HighestScore: " << highestScoreHand1 << endl;
										// cout << "Highest Score Hand 1" << highestScoreHand1 << endl;
										 //for (int n = 0; n < hand1.size(); n++) {
										//	 cout << hand1[n].getCard();
										// }
									 }
									 hand2.erase(hand2.begin() + hand2.size() - 4);
								 }
							 }
							 hand2.erase(hand2.begin() + hand2.size() - 3);

							 ///////////////////////////////////////


						 }

						 hand.erase(hand.begin() + hand.size() - 2);
					 }
				 }


				 hand.erase(hand.begin() + hand.size() - 1);

				
				 
			 }
			 
		  }
	}
	cout << "=============================" << endl;
	cout << highestScoreHand1 << endl;
	cout << highestScoreHand2 << endl;
	cout << "=============================" << endl;
	//sorted stuff
	//cout << "sorted stuff: " << endl;
	//for (int i = 0; i < handA.size(); i++) {
	//	cout << handA[i].getRank() << endl;
	//}

	return 0;
	

}

unsigned long long int  calcScore(int handRank) {


    unsigned long long int score = 0;

	score = Board[0].getRank();
	score = score + (Board[1].getRank() * 100);
	score = score + (Board[2].getRank() * 10000);
	score = score + (Board[3].getRank() * 1000000);
	score = score + (Board[4].getRank() * 100000000);
	cout << "print score" << score << endl;

	if (handRank == 9) {
		score = score * 1000000000;    
		//cout << "Board Hand Score is: " << score << endl;
	    return score;
	}   
	else

	if (handRank == 8) {
		score = score * 100000000;
		cout << "Board Hand Score is: " << score << endl;
		return score;
			
	}
	else

	if (handRank == 7) {
		score = score * 10000000;
			cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 6) {
				score = score * 1000000;
			    cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 5) {
			score = score * 100000;
			cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 4) {
				score = score * 10000;
			cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 3) {
				score = score * 100;
			   cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 2) {
			score = score * 10;
			//cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
	else
			if (handRank == 1) {
			score = score;
			cout << "Board Hand Score is: " << score << endl;
			return score;
			
	}
}

int calcRank() {

	if (isStraight() && isFlush()) {
		cout << "You have a straight Flush" << endl;
		return 9;
	}else

	if (isFourOfAKind()) {
		cout << "Is Four of A kind? " << isFourOfAKind() << endl;
		return 8;
	}else

	if (isFullHouse()) {
		cout << "Is Full House? " << isFullHouse() << endl;
		return 7;
	}else

	if (isFlush()) {
		cout << "Is it a Flush? " << isFlush() << endl;
		return 6;
	}else

	if (isStraight()) {
		cout << "Is it a Straight? " << isStraight() << endl;
		return 5;
	}else

	if (isThreeOfKind()) {
		cout << "Is 3 of a kind ? " << isThreeOfKind() << endl;
		return 4;
	}else

	if (isTwoPair()) {
		cout << "Is Two Pair ? " << isTwoPair() << endl;
		return 3;
	}else
	
	if (isOnePair()) {
		//cout << "Is One Pair ? " << isOnePair() << endl;
		return 2;
	}else

	if (highCard()) {
		//cout << "What is High card ? " << highCard() << endl;
		return 1;
	}
		
	
}



int highCard() {
	sortByRank();

	return Board[Board.size() - 1].getRank();
}



const bool isOnePair() {
	bool a1, a2, a3, a4;

	if (Board.size() != 5)
		return false;

	if (isFourOfAKind() || isFullHouse() || isThreeOfKind() || isTwoPair())
		return false;             

	sortByRank();

	
	a1 = Board[0].getRank() == Board[1].getRank();

	
	a2 = Board[1].getRank() == Board[2].getRank();

	
	a3 = Board[2].getRank() == Board[3].getRank();

	
	a4 = Board[3].getRank() == Board[4].getRank();

	return a1 || a2 || a3 || a4;
}

const bool isTwoPair() {
	bool a1, a2, a3;

	if (Board.size() != 5)
		return false;

	if (isFourOfAKind() || isFullHouse() || isThreeOfKind())
		return false;          

	sortByRank();

	
	a1 = Board[0].getRank() == Board[1].getRank() &&
		Board[2].getRank() == Board[3].getRank();

	
	a2 = Board[0].getRank() == Board[1].getRank() &&
		Board[3].getRank() == Board[4].getRank();

	
	a3 = Board[1].getRank() == Board[2].getRank() &&
		Board[3].getRank() == Board[4].getRank();

	return a1 || a2 || a3;
}

const bool isThreeOfKind(){
	bool a1, a2, a3;

	if (Board.size() != 5)
		return false;

	sortByRank();        

	a1 = Board[0].getRank() == Board[1].getRank() &&
		Board[1].getRank() == Board[2].getRank() &&
		Board[3].getRank() != Board[0].getRank() &&
		Board[4].getRank() != Board[0].getRank() &&
		Board[3].getRank() != Board[4].getRank();

	a2 = Board[1].getRank() == Board[2].getRank() &&
		Board[2].getRank() == Board[3].getRank() &&
		Board[0].getRank() != Board[1].getRank() &&
		Board[4].getRank() != Board[1].getRank() &&
		Board[0].getRank() != Board[4].getRank();

	
	a3 = Board[2].getRank() == Board[3].getRank() &&
		Board[3].getRank() == Board[4].getRank() &&
		Board[0].getRank() != Board[2].getRank() &&
		Board[1].getRank() != Board[2].getRank() &&
		Board[0].getRank() != Board[1].getRank();

	return a1 || a2 || a3;

}

const bool isFullHouse() {
	bool a1, a2;

	if (Board.size() != 5)
		return false;

	sortByRank();      


	a1 = Board[0].getRank() == Board[1].getRank() &&
		Board[1].getRank() == Board[2].getRank() &&
		Board[3].getRank() == Board[4].getRank();

	a2 = Board[0].getRank() == Board[1].getRank() &&
		Board[2].getRank() == Board[3].getRank() &&
		Board[3].getRank() == Board[4].getRank();

	return a1 || a2;
}

const bool isFourOfAKind() {
	bool a1, a2;

	if (Board.size() != 5)
		return false;

	sortByRank();         

	a1 = Board[0].getRank() == Board[1].getRank() &&
		Board[1].getRank() == Board[2].getRank() &&
		Board[2].getRank() == Board[3].getRank();


	
	a2 = Board[1].getRank() == Board[2].getRank() &&
		Board[2].getRank() == Board[3].getRank() &&
		Board[3].getRank() == Board[4].getRank();

	return a1 || a2;
}



const bool isStraight() {
	int i, testRank;

	if (Board.size() != 5)
		return false;

	sortByRank();      

	if (Board[4].getRank() == 14){
		
		bool a = Board[0].getRank() == 2 && Board[1].getRank() == 3 &&
			Board[2].getRank() == 4 && Board[3].getRank() == 5;
		bool b = Board[0].getRank() == 10 && Board[1].getRank() == 11 &&
			Board[2].getRank() == 12 && Board[3].getRank() == 13;

		return a || b;
	}
	else
	{
		
		testRank = Board[0].getRank() + 1;

		for (i = 1; i < 5; i++) {
			if (Board[i].getRank() != testRank)
				return false;       

			testRank++;   
		}

		return true;        
	}
}

string sortHandByRank(string whichHand) {
	
	int i, j, min_j;

	if (whichHand == "A") {
		for (i = 0; i < handA.size(); i++) {

			min_j = i;

			for (j = i + 1; j < handA.size(); j++) {
				if (handA[j].getRank() < handA[min_j].getRank()) // change < to > to sort the other way
				{
					min_j = j;
				}
			}

			Card help = handA[i];
			handA[i] = handA[min_j];
			handA[min_j] = help;
		}
		return "sorted Hand A by rank";
	}
	else  {
		for (i = 0; i < handB.size(); i++) {

			min_j = i;

			for (j = i + 1; j < handB.size(); j++) {
				if (handB[j].getRank() < handB[min_j].getRank()) // change < to > to sort the other way
				{
					min_j = j;
				}
			}

			Card help = handB[i];
			handB[i] = handB[min_j];
			handB[min_j] = help;
		}


		return "sorted Hand B by rank";
	}


}


string sortByRank() {
	
	int i, j, min_j;

	for (i = 0; i < Board.size(); i++) {
	
		min_j = i;   

		for (j = i + 1; j < Board.size(); j++) {
			if (Board[j].getRank() < Board[min_j].getRank()) // change < to > to sort the other way
			{
				min_j = j;    
			}
		}

		Card help = Board[i];
		Board[i] = Board[min_j];
		Board[min_j] = help;
	}

	return "sorted by rank";
}

const bool isFlush() {
	const bool isFlush = ((Board[0].suit == Board[1].suit) && (Board[2].suit == Board[3].suit) && (Board[4].suit == Board[3].suit));
	return isFlush;
}

void inputCard(string card) {

	handA.push_back(Card());
	

	handA[handA.size() - 1].card = card[0];
	handA[handA.size() - 1].suit = card[1];
	

	if (handA[handA.size() - 1].card == "A") {
		handA[handA.size() - 1].rank = 14;
	}
	else if (handA[handA.size() - 1].card == "K") {
		handA[handA.size() - 1].rank = 13;
	}
	else if (handA[handA.size() - 1].card == "Q") {
		handA[handA.size() - 1].rank = 12;
	}
	else if (handA[handA.size() - 1].card == "J") {
		handA[handA.size() - 1].rank = 11;
	}
	else if (handA[handA.size() - 1].card == "T") {
		handA[handA.size() - 1].rank = 10;
	}
	else if (handA[handA.size() - 1].card == "9") {
		handA[handA.size() - 1].rank = 9;
	}
	else if (handA[handA.size() - 1].card == "8") {
		handA[handA.size() - 1].rank = 8;
	}
	else if (handA[handA.size() - 1].card == "7") {
		handA[handA.size() - 1].rank = 7;
	}
	else if (handA[handA.size() - 1].card == "6") {
		handA[handA.size() - 1].rank = 6;
	}
	else if (handA[handA.size() - 1].card == "5") {
		handA[handA.size() - 1].rank = 5;
	}
	else if (handA[handA.size() - 1].card == "4") {
		handA[handA.size() - 1].rank = 4;
	}
	else if (handA[handA.size() - 1].card == "3") {
		handA[handA.size() - 1].rank = 3;
	}
	else if (handA[handA.size() - 1].card == "2") {
		handA[handA.size() - 1].rank = 2;
	}

	
}

void inputCard2(string card) {

	handB.push_back(Card());

	handB[handB.size() - 1].card = card[0];
	handB[handB.size() - 1].suit = card[1];


	if (handB[handB.size() - 1].card == "A") {
		handB[handB.size() - 1].rank = 14;
	}
	else if (handB[handB.size() - 1].card == "K") {
		handB[handB.size() - 1].rank = 13;
	}
	else if (handB[handB.size() - 1].card == "Q") {
		handB[handB.size() - 1].rank = 12;
	}
	else if (handB[handB.size() - 1].card == "J") {
		handB[handB.size() - 1].rank = 11;
	}
	else if (handB[handB.size() - 1].card == "T") {
		handB[handB.size() - 1].rank = 10;
	}
	else if (handA[handA.size() - 1].card == "9") {
		handB[handB.size() - 1].rank = 9;
	}
	else if (handA[handA.size() - 1].card == "8") {
		handB[handB.size() - 1].rank = 8;
	}
	else if (handB[handB.size() - 1].card == "7") {
		handB[handB.size() - 1].rank = 7;
	}
	else if (handB[handB.size() - 1].card == "6") {
		handB[handB.size() - 1].rank = 6;
	}
	else if (handB[handB.size() - 1].card == "5") {
		handB[handB.size() - 1].rank = 5;
	}
	else if (handB[handB.size() - 1].card == "4") {
		handB[handB.size() - 1].rank = 4;
	}
	else if (handB[handB.size() - 1].card == "3") {
		handB[handB.size() - 1].rank = 3;
	}
	else if (handB[handB.size() - 1].card == "2") {
		handB[handB.size() - 1].rank = 2;
	}

}

void inputCard3(string card) {

	Board.push_back(Card());

	Board[Board.size() - 1].card = card[0];
	Board[Board.size() - 1].suit = card[1];
	
	
	if (Board[Board.size() - 1].card == "A") {
		Board[Board.size() - 1].rank = 14;
	}
	else if (Board[Board.size() - 1].card == "K") {
		Board[Board.size() - 1].rank = 13;
	}
	else if (Board[Board.size() - 1].card == "Q") {
		Board[Board.size() - 1].rank = 12;
	}
	else if (Board[Board.size() - 1].card == "J") {
		Board[Board.size() - 1].rank = 11;
	}
	else if (Board[Board.size() - 1].card == "T") {
		Board[Board.size() - 1].rank = 10;
	}
	else if (Board[Board.size() - 1].card == "9") {
		Board[Board.size() - 1].rank = 9;
	}
	else if (Board[Board.size() - 1].card == "8") {
		Board[Board.size() - 1].rank = 8;
	}
	else if (Board[Board.size() - 1].card == "7") {
		Board[Board.size() - 1].rank = 7;
	}
	else if (Board[Board.size() - 1].card == "6") {
		Board[Board.size() - 1].rank = 6;
	}
	else if (Board[Board.size() - 1].card == "5") {
		Board[Board.size() - 1].rank = 5;
	}
	else if (Board[Board.size() - 1].card == "4") {
		Board[Board.size() - 1].rank = 4;
	}
	else if (Board[Board.size() - 1].card == "3") {
		Board[Board.size() - 1].rank = 3;
	}
	else if (Board[Board.size() - 1].card == "2") {
		Board[Board.size() - 1].rank = 2;
	}

	

}