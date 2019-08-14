#pragma once
//Szablon funkcji odpowiedzialnej za usuwanie z obiekt�w z wektora po kolizji
//Wymagana metoda isDestroyed()

template <typename T>
void removeFromVector(std::vector <T>& Vector)
{
	//Iterator na pocz�tek zakresu usuwania z vectora
	auto removalBeginningIterator = std::remove_if(Vector.begin(), Vector.end(), [](T & vectorElement) {return vectorElement.isDestroyed(); });
	//Usuwanie zjedzonych kulek z mapy
	Vector.erase(removalBeginningIterator, Vector.end());
}