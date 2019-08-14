#include "mapGenerator.h"


std::vector<wall> mapGenerator::createVector2(std::string fileName, sf::Texture* _texture)
{
	{
		std::ifstream file;
		file.open(fileName, std::ios::in);
		if (!file.is_open())
		{
			std::string error = "Unable to open file at mapGenerator|createWallMapVector()\n";
			throw error;
		}
		else
		{
			std::vector<wall> Vector;
			float x, y;
			while (file >> x)
			{
				file >> y;

				Vector.push_back(wall{ x,y,_texture });
			}
			file.close();
			return Vector;
		}


	}
}

mapGenerator::mapGenerator(Texture * _texture)
{
	fillMapCreator(_texture);
}

void mapGenerator::saveLastMapStateMapCreator()
{
	for (int i = 0; i < SIZEX; i++)
		restoreShapeVector[i]=shapeVector[i];
	std::cout << "Zapisuje\n";
}

void mapGenerator::restorePreviousStateMapCreator()
{
	for (int i = 0; i < SIZEX; i++)
		shapeVector[i] = restoreShapeVector[i];
	std::cout << "Zwracam\n";
}

void mapGenerator::fillMapCreator(Texture* _texture)
{
	float x = 0;
	float y = 0;
	for (int i = 0; i < SIZEX; i++)
	{
		for (int j = 0; j < SIZEY; j++)
		{
			shapeVector[i].push_back(mapGeneratorShape{x,y,_texture});
			y+=(float)OFFSET;
		}
		x+=(float)OFFSET;
		y = 0;
	}
}

void mapGenerator::renderWindowMapCreator()
{
	RenderWindow Window(VideoMode(600, 800), "Map Generator");
	Window.setFramerateLimit(60);

	while (true)
	{
		Event mapEvent;
		Window.clear(Color::Black); //Czyœci okno i wype³nia na czarno
		Window.pollEvent(mapEvent); //Obs³uguje eventy dotycz¹ce okna 


		//Sprawdza czy naciœniêto przycisk zamkniêcia okna i obs³uguje to zdarzenie
		if (mapEvent.type == Event::Closed)
		{
			Window.close();
			break;
		}
		else if (mapEvent.type == Event::MouseButtonPressed) //Sprawdzenie kolizji myszka/obiekt
		{
			if (mapEvent.mouseButton.button == Mouse::Right) //Edycja mapy prawym przyciskiem myszy
			{	
				for (auto& it : shapeVector) //Iteruje po wektorach
					for (auto& it2 : it) //Iteruje po elemntach w wektorze
						it2.collisoionTest(mapEvent.mouseButton.x, mapEvent.mouseButton.y); 


				for (auto& it : shapeVector)
				{
					auto removalBeginningIterator = remove_if(it.begin(), it.end(), [](mapGeneratorShape& shape) {return shape.isDestroyed(); }); //Wyznaczenie iteratora na pocz¹tek zakresu usuwania
					it.erase(removalBeginningIterator, it.end());
				}
			}
			
				
		}
		else if (mapEvent.type == Event::KeyPressed) //Przywracanie stanu poprzedniego
		{
			if (mapEvent.key.code == Keyboard::S)
			{
				saveLastMapStateMapCreator();
			}
			else if (mapEvent.key.code == Keyboard::Z)
			{
				restorePreviousStateMapCreator();
			}
			else if (mapEvent.key.code == Keyboard::P)
			{
				putToFileMapCreator();
			}
		}
		//Usuwanie odpowiednich obiektów

		
		
		//Rysowanie kulek
		for (auto& it1 : shapeVector) //Po wektorze wektorów
		{
			for (auto& it2 : it1) //Po elemntach w kolumnie
			{
					Window.draw(it2);
			}
		}

		

		Window.display(); //Wyœwietla okno
	}

}

void mapGenerator::putToFileMapCreator()
{
	std::ofstream file;

	file.open("mapGeneratorResult.txt",std::ios::out);

	if (!file.is_open())
	{
		std::cout << "unable to open file at mapGenerator|putToFIle()\n";
	}
	else
	{
		for (auto& it : shapeVector)
			for (auto& it2 : it)
			{
				Vector2f tmp = it2.getPosition();

				file << tmp.x << " " << tmp.y << std::endl;
			}
		file.close();
		std::cout << "Zapisano do pliku\n";
	}
	

}

void mapGenerator::putBallVectorToFile()
{
	std::vector<mapGeneratorPlacer> bonus;
	std::vector<mapGeneratorPlacer> specialBonus;
	std::ofstream file;

	file.open("ballVectorGeneratorResult.txt", std::ios::out);

	if (!file.is_open())
	{
		std::cout << "unable to open file at mapGenerator|putBallVectorToFile()\n";
	}
	else
	{
		for (auto& it : ballVector)
		{
			if (it.isBonus() == false && it.isSpecialBonus() == false)
			{
				Vector2f tmp = it.getPosition();
				if (tmp.x != 0 && tmp.y != 0)
					file << tmp.x << " " << tmp.y << std::endl;
			}
			else if (it.isBonus())
			{
				bonus.push_back(it);
			}
			else if (it.isSpecialBonus())
			{
				specialBonus.push_back(it);
			}
		}
		file << std::endl << std::endl << std::endl << "BONUS" << std::endl;
		for (auto& it : bonus)
		{
			Vector2f tmp = it.getPosition();
			if (tmp.x != 0 && tmp.y != 0)
				file << tmp.x << " " << tmp.y << std::endl;
		}
		file << std::endl << std::endl << std::endl << "BONUS SPECIAL" << std::endl;
		for (auto& it : specialBonus)
		{
			Vector2f tmp = it.getPosition();
			if (tmp.x != 0 && tmp.y != 0)
				file << tmp.x << " " << tmp.y << std::endl;
		}


		file.close();
		std::cout << "Zapisano do pliku\n";
	}
}

void mapGenerator::saveLastBallVector()
{
	restoreBallVector.clear();
	for (auto& it : ballVector)
	{
		restoreBallVector.push_back(it);
	}
}

void mapGenerator::restoreLastBallVector()
{
	std::swap(this->restoreBallVector, this->ballVector);
}

void mapGenerator::renderWindowBallVectorCreator(Texture* _texture,std::string mapFile)
{
	ballVector.push_back(mapGeneratorPlacer{});
	int index = 0;
	RenderWindow Window(VideoMode(600, 800), "Ball Filler");
	Window.setFramerateLimit(20);
	
	while (true)
	{
		Event mapEvent;
		Window.clear(Color::Black); //Czyœci okno i wype³nia na czarno
		Window.pollEvent(mapEvent); //Obs³uguje eventy dotycz¹ce okna 
		
			//Sprawdza czy naciœniêto przycisk zamkniêcia okna i obs³uguje to zdarzenie
			if (mapEvent.type == Event::Closed)
			{
				Window.close();
				break;
			}
			if (mapEvent.type == Event::KeyPressed) //Zapis wyniku do pliku
			{
				if (mapEvent.key.code == Keyboard::S)
				{
					this->saveLastBallVector();
					savedIndex = index;
				}
				else if (mapEvent.key.code == Keyboard::Z)
				{
					this->restoreLastBallVector();
					index = savedIndex;
					this->saveLastBallVector();
				}
				else if (mapEvent.key.code == Keyboard::P)
				{
					this->putBallVectorToFile();
				}
				else if (mapEvent.key.code == Keyboard::Enter)
				{
					ballVector[index].stopMovement();
				}
				else if (mapEvent.key.code == Keyboard::B)
				{
					ballVector[index].makeBonus();
					ballVector[index].stopMovement();
				}
				else if (mapEvent.key.code == Keyboard::V)
				{
					ballVector[index].makeSpecialBonus();
					ballVector[index].stopMovement();
				}

			}


			std::vector <wall> map= createVector2(mapFile, _texture); //Wektor mapy wczytany z pliku
			for (auto& it : map) //Rysowanie mapy
				Window.draw(it);

			if (!ballVector[index].checkMovement())//Dodanie nowego miejsca kulki
			{
				ballVector.push_back(mapGeneratorPlacer{});
				index++;
			}

			ballVector[index].update();

			for (auto& it : ballVector)//Rysuje miejsca gdzie bêd¹ pojawiaæ siê kulki
				Window.draw(it);

			

			Window.display(); //Wyœwietla okno

		
		
	}
}



