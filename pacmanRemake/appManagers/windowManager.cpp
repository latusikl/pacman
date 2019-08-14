#include "windowManager.h"

void windowManager::makeSubMenu(sf::RenderWindow& mainWindow, Sprite controlInfo, Text back)
{
	bool intersects = false;
	while (true)
	{
		mainWindow.clear(Color::Black);
		
		Event mainEvent;//Pobiera eventy z okna

		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okn
		
		if (mainEvent.type == Event::Closed) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
		{
			break;
		}
		//AABB dla myszki
		sf::FloatRect mousePosition{ Vector2f(sf::Mouse::getPosition(mainWindow)),sf::Vector2f(1,1) };
		
		//Efekt powiekszenia napisu back
		if (mousePosition.intersects(back.getGlobalBounds())) //Z napisem back
		{
			menuBoard::sizeBackTextUp(back); // Efekt powiekszenia napisu
			intersects = true;
		}
		else if (intersects)
		{
			menuBoard::sizeBackTextDown(back);
		}

///Eventy
		if (mainEvent.mouseButton.button == sf::Mouse::Left && mousePosition.intersects(back.getGlobalBounds()))
		{
			break;
		}


		mainWindow.draw(controlInfo);
		mainWindow.draw(back);
		mainWindow.display();
	}
}

void windowManager::makeSubMenu(sf::RenderWindow& mainWindow, Text generalInfo, Text back)
{
	bool intersects = false;
	while (true)
	{
		mainWindow.clear(Color::Black);

		Event mainEvent;//Pobiera eventy z okna

		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okna

		if (mainEvent.type == Event::Closed) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
		{
			break;
		}

		//AABB dla myszki
		sf::FloatRect mousePosition{ Vector2f(sf::Mouse::getPosition(mainWindow)),sf::Vector2f(1,1) };

		//Efekt powiekszenia napisu back
		if (mousePosition.intersects(back.getGlobalBounds())) //Z napisem back
		{
			menuBoard::sizeBackTextUp(back); // Efekt powiekszenia napisu
			intersects = true;
		}
		else if (intersects)
		{
			menuBoard::sizeBackTextDown(back);
		}

		//Eventy
		if (mainEvent.mouseButton.button == sf::Mouse::Left && mousePosition.intersects(back.getGlobalBounds()))
		{
			break;
		}
	

		mainWindow.draw(generalInfo);
		mainWindow.draw(back);
		mainWindow.display();
	}
}

windowManager& windowManager::getInstance()
{
	static windowManager obj;
	return obj;
}

void windowManager::makeMenu(sf::RenderWindow& mainWindow,sf::Texture* menuGraphicsTexture, sf::Texture* menuGraphicsTexture2, sf::Texture* controlTexture, sf::Font* titleFont, sf::Font* optionsFont)
{
	menuBoard Menu(menuGraphicsTexture, menuGraphicsTexture2,controlTexture,titleFont, optionsFont);
	bool intersection = false; //Sprawdza czy zostala powiekszona czcionka napisow
	while (true)
	{
		mainWindow.clear(Color::Black); //Czyœci okno i wype³nia na czarno

		Event mainEvent;//Pobiera eventy z okna

		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okna 


	//Eventy
		if (mainEvent.type == Event::Closed) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
		{
			mainWindow.close();
			break;
		} 
	//Kolizje	

		//AABB dla myszki
		sf::FloatRect mousePosition{Vector2f(sf::Mouse::getPosition(mainWindow)),sf::Vector2f(1,1)};
		
	//Efekt powiekszania napisow
		//Sprawdzanie czy kursor znajdue sie na napisach
		if (mousePosition.intersects(Menu.getStartBoundries())) //Z napisem Start
		{
			intersection = true;
			Menu.sizeChangeUp(startType); // Efekt powiekszenia napisu
		}
		else if (mousePosition.intersects(Menu.getAboutBoundries()))//Z napisem Menu
		{
			intersection = true;
			Menu.sizeChangeUp(aboutType);// Efekt powiekszenia napisu
		}
		else if (mousePosition.intersects(Menu.getControlBoundries()))//Z napisem Control
		{
			intersection = true;
			Menu.sizeChangeUp(controlType);// Efekt powiekszenia napisu
		}
		else if (intersection)//Jezeli bylo powiekszenie, a myszka nie znajduje sie juz na napisie
		{
			Menu.sizeChangeDown(); //Efekt zmniejszenia napisu
		}

	//Zmiana podmenu
		if (mainEvent.type == sf::Event::MouseButtonPressed) //Jezeli wcisnieto przycisk myszy
		{
			//Przycisk wcisniety i kursor na napisie start
			if (mainEvent.mouseButton.button == sf::Mouse::Left && mousePosition.intersects(Menu.getStartBoundries()))
			{
				return;
			}
			else if (mainEvent.mouseButton.button == sf::Mouse::Left && mousePosition.intersects(Menu.getAboutBoundries()))
			{
				this->makeSubMenu(mainWindow, Menu.getGeneralInfoText(), Menu.getBackText());
			}
			else if (mainEvent.mouseButton.button == sf::Mouse::Left && mousePosition.intersects(Menu.getControlBoundries()))
			{
				this->makeSubMenu(mainWindow, Menu.getControlInfo(), Menu.getBackText());
			}
		}

		mainWindow.draw(Menu); //Rysuje menu

		mainWindow.display(); //Wyswietla okno

	}
}

void windowManager::makeScoreBoard(sf::RenderWindow& mainWindow,sf::Font* titleFont, sf::Font* optionsFont, unsigned int playerScore , const std::string& playerName,const std::string& fileName)
{
	scoreBoard board;
	try{ board.loadFromFile(fileName); }
	catch (std::string n)
	{
		throw n;
	}
	
	board.setTextsScoreBoard(titleFont,optionsFont,playerScore,playerName);
	board.setPositionScoreBoard();
	bool intersects = false;
	while (true)
	{
		mainWindow.clear(Color::Black);

		Event mainEvent;//Pobiera eventy z okna

		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okn

		if (mainEvent.type == Event::Closed) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
		{
			mainWindow.close();
			break;
		}

		mainWindow.draw(board);
		mainWindow.display();
	}
	board.saveToFile(playerScore, playerName);
}

std::string windowManager::makeOverBoard(sf::RenderWindow& mainWindow, sf::Font* titleFont, sf::Font* optionsFont, unsigned int playerScore,sf::Clock clock)
{
	gameOverBoard overBoard(titleFont, optionsFont, playerScore);
	std::string playerName;//Zmienna przechowujaca wprowadzona nazwe gracza
	sf::Time lastUpdateTime= clock.getElapsedTime();
	bool drawName = true;
	while (true)
	{
	
		sf::Time currentTime = clock.getElapsedTime(); //Pobranie czasu dostarczonego z funkcji main
		const int changeTime = 150; //Roznica czasu miedzy zmianami tekstury
		
		mainWindow.clear(Color::Black);

		
///Eventy
		Event mainEvent;//Pobiera eventy z okna

		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okn

		if (mainEvent.type == Event::Closed) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
		{
			return "Unknown"; //Zwraca pusty string
		}
		else if (mainEvent.type == sf::Event::TextEntered  && (currentTime.asMilliseconds() > lastUpdateTime.asMilliseconds() + 150)) //Odczyt tekstu z klawiatury (szybkosc ograniczona czasowo)
		{
			//Odczyt odpowiednich znakow z klawiatury
			if (mainEvent.text.unicode <= 57 && mainEvent.text.unicode >= 48 //cyfry
				|| mainEvent.text.unicode <= 90 && mainEvent.text.unicode >= 65 //duze litery
				|| mainEvent.text.unicode <= 122 && mainEvent.text.unicode >= 97 //male litery
				&& playerName.size() < 10)//Ograniczenie ilosci wprowadzonych znakow
			{
				if(!drawName)//Ponownie wysiwetla imie
				drawName = true; 
				
				playerName += (char)mainEvent.text.unicode;//Dodanie wprowadzonego znaku do nazwy gracza
				lastUpdateTime = currentTime; //Zmienia czas ostatniej zmiany
			}
			else if (mainEvent.text.unicode == 8) //Kod backspace
			{
				if (playerName.size() > 0)
					playerName.pop_back();//Usuniecie ostatniego znaku 
				
				lastUpdateTime = currentTime;//Zmienia czas ostatniej zmiany
			}
			else if (mainEvent.text.unicode == 13) //Kod entera
			{
				if (std::regex_match(playerName, std::regex("([[:alpha:]]{1,7}[[:digit:]]{3})"))) //Sprawdzenie poprawnosci wprowadzonej nazy gracza
					return playerName; //Poprawna to zwracamy imie do maina
				else //Nie poprawna to komunikat bedzie drukowany zamiast nazwy
				{
					drawName = false;
					playerName.clear();
				}
			}
		}

		overBoard.setName(playerName); //Ustawia wprow imie
		

		if (drawName)
			mainWindow.draw(overBoard.name);
		else
			mainWindow.draw(overBoard.wrongName);


		mainWindow.draw(overBoard);//Rysuje skladowe okna
		
		mainWindow.display();
	}
}

void windowManager::makeGameWindow(RenderWindow& mainWindow, pacman& pac, std::vector<ball>& ballVector, std::vector<wall>& wallVector, std::vector<bonus>& bonusVector,bonus& specialBonus, std::vector <ghost>& ghostVector,statusStrapBoard& strap,sf::Clock & clock)
{
	Time savedTime = clock.getElapsedTime();
	
	specialBonus.destroy();
	
	animationManager& animationMan = animationManager::getInstance();
	animationMan.GhostAnimationOn();
	
	collisionManager& collsionMan = collisionManager::getInstance();
	
	while (true)
	{
		mainWindow.clear(Color::Black); //Czyœci okno i wype³nia na czarno
		
		Event mainEvent;//Pobiera eventy z okna
		
		mainWindow.pollEvent(mainEvent); //Obs³uguje eventy dotycz¹ce okna 

		
	//----------Eventy----------
		if (mainEvent.type == Event::Closed || pac.getLifes() == 0) //Sprawdza czy naciœniêto przycisk zamkniêcia okna.
			break; 
		if (ballVector.size() == 0 && bonusVector.size() == 0)
			break;

		animationMan.GhostAnimationRunner(clock,ghostVector);//Animacja duszków

	//------------Kolizje-----------
		
		//Kolizja duszek œciany i zmiana ich polozenia
		collsionMan.GhostWallCollision(ghostVector, wallVector, animationMan, clock);

		//Kolizje pacmana z bonusami (podstawowymi)
		collsionMan.PacBonusCollsion(pac, bonusVector);
		removeFromVector<bonus>(bonusVector);
		
		//Kolizja pacman bonus specjalny.
		if (animationMan.checkSpecialBonusDrawing(pac.getScore(), specialBonus.isDestroyed())) //Je¿eli jest narysowany na ekranie
			collsionMan.PacSpecialBonusCollision(pac, specialBonus);
			
		//Kolizja duszek pacman
		collsionMan.PacGhostCollision(pac,ghostVector,animationMan);

		//Kolizje pacmana z kulka
		collsionMan.PacBallCollision(pac, ballVector);
		removeFromVector<ball>(ballVector);

	//-----------Zmiany polozenia----------	
		
		//Sprawdzanie mozliwych ruchow pacmana
		collision collisionChecker = collsionMan.PacWallCollision(pac, wallVector);

		//Zmiana po³o¿enia Pacmana
		//Bazujac na informacjach z obiektu klasy collision
		pac.update(collisionChecker.left, collisionChecker.right, collisionChecker.top, collisionChecker.bottom, clock);

		strap.update(pac.getScore(), pac.getLifes()); //Ustawienie nowego wyniku i ilosci pozostalych zyc


																			  
	//----------Rysowanie----------
		
		
		for (auto& it : wallVector) //Œciany
			mainWindow.draw(it);

		for (auto& it : ballVector) //Kulki
			mainWindow.draw(it);

		

		mainWindow.draw(strap); //Pasek wyniku i zycia

		//Bonusy + miganie
		if (animationMan.checkBonusBlinking(clock.getElapsedTime()))
		{
			for (auto& it : bonusVector) 
				mainWindow.draw(it);
		}
		
		//Bonus specjalny + warunek wyniku  
		if (animationMan.checkSpecialBonusDrawing(pac.getScore(), specialBonus.isDestroyed()))
		{
			specialBonus.changeToNotDestroyed();
			mainWindow.draw(specialBonus);
		}

		mainWindow.draw(pac); //Pacman

		for (auto& it : ghostVector)//Duszki
			mainWindow.draw(it);

		mainWindow.display(); //Wyœwietla okno
	}
}
