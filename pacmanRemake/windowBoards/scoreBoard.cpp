#include "scoreBoard.h"



void scoreBoard::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	for (int i = 0; i < 9; i++)
		target.draw(scoreBoardTexts[i], state);
}

void scoreBoard::setTextsScoreBoard(sf::Font* titleFont, sf::Font* textFont, unsigned int playerScore, std::string playerName)
{
	//Tytul
	scoreBoardTexts[0]=sf::Text("SCORE BOARD", *titleFont, 65);
	scoreBoardTexts[0].setFillColor(sf::Color::Yellow);
	
	//Najlepszy wynik-tytul
	scoreBoardTexts[1]=sf::Text("Best Score", *titleFont, 40);
	scoreBoardTexts[1].setFillColor(sf::Color::Blue);

//Najepszy wynik
	if (playerScore < (unsigned int)std::stoi(this->scoresValue[0])) //Wynik gracza mniejszy od najlepszego
	{
		scoreBoardTexts[2] = sf::Text(this->scoresValue[0] + " " + this->scoresValue[1], *textFont, 20);
		scoreBoardTexts[2].setFillColor(sf::Color::White);
	}
	else //Wynik gracza wiekszy od najlepszego
	{
		scoreBoardTexts[2] = sf::Text(std::to_string(playerScore) + " " + playerName, *textFont, 20);
		scoreBoardTexts[2].setFillColor(sf::Color::White);
	}
	
	//Ostatnie 5 wynikow-tytul
	scoreBoardTexts[3]=sf::Text("Last 5 scores", *titleFont, 40);
	scoreBoardTexts[3].setFillColor(sf::Color::Blue);
	
	//Ostatnie 4 wyniki- wartosci i nazwy graczy
	int scoreValuesIndex = 2;
	for (int i=4; i<8;i++)
	{
		scoreBoardTexts[i]=sf::Text(this->scoresValue[scoreValuesIndex]+" "+this->scoresValue[scoreValuesIndex+1], *textFont, 20);
		scoreBoardTexts[i].setFillColor(sf::Color::White);
		scoreValuesIndex+=2;
	}
	
	//Wynik gracza na koniec
	scoreBoardTexts[8] = sf::Text(std::to_string(playerScore)+" "+playerName, *textFont, 20);
	scoreBoardTexts[8].setFillColor(sf::Color::White);

}

void scoreBoard::setPositionScoreBoard()
{
	scoreBoardTexts[0].setPosition(20.0f,30.0f); //ScoreBoard
	scoreBoardTexts[1].setPosition(170.0f,150.0f); //BestScore
	scoreBoardTexts[2].setPosition(200.0f,220.0f); //BestScoreValue
	scoreBoardTexts[3].setPosition(150.0f,270.0f); //Last5Scores
	scoreBoardTexts[4].setPosition(200.0f,350.0f); //Score
	scoreBoardTexts[5].setPosition(200.0f,400.0f); //Score
	scoreBoardTexts[6].setPosition(200.0f,450.0f); //Score
	scoreBoardTexts[7].setPosition(200.0f,500.0f); //Score
	scoreBoardTexts[8].setPosition(200.0f,550.0f); //Score
}

void scoreBoard::loadFromFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName,std::ios::in);
	if (!file.is_open())
	{
		std::string error = "Unable to open file at scoreBoard|loadFromFile\n";
		throw error;
	}
	else
	{
		file.clear();
		std::string score;
		
		for (int i = 0; i < 10; i++)
			file >> scoresValue[i];

		file.close();
	}
}

void scoreBoard::saveToFile(unsigned int playerScore, std::string playerName)
{
	std::ofstream file;
	file.open("resources/textFiles/scoreBoard.txt", std::ios::out);
	if (!file.is_open())
	{
		std::string error = "Unable to open file at scoreBoard|saveToFile\n";
		throw error;
	}
	else
	{
		//Wyporwadzenie najlepszego wyniku
		if (playerScore < (unsigned int)std::stoi(this->scoresValue[0])) //Wynik gracza mniejszy od najlepszego
		{
			file << scoresValue[0] << " ";; //Wyprowadza poprzedni najlepszy wynik
			file << scoresValue[1] << std::endl;; //Wyporwadza nazwe uzytkownika z najlepszym wynikiem
		}
		else
		{
			file << playerScore << " ";; //Wyprowadza nowy najlepszy wynik
			file << playerName << std::endl; //Wyporwadza nazwe uzytkownika z najlepszym wynikiem
		}
		for (int i = 4; i < 10; i+=2) //Wyprowadza 3 ostatnie wyniki
		{
			file << scoresValue[i] << " ";
			file << scoresValue[i + 1] << std::endl;
		}
			//Wyprowadza nowy ostatni wynik
			file << playerScore << " ";;
			file << playerName << std::endl;
	}
}


