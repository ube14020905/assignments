#include <iostream>
#include <map>
using namespace std;
void search(map<string, string> dict)
{
	string word;
	cout << "Enter A word to search: ";
	cin >> word;
	auto it = dict.find(word);
	if (it != dict.end())
	{
		cout << it->first << " : " << it->second << endl;
	}
	else
	{
		cout << "NO such word found!!!" << endl;
	}
}
void display(map<string, string> dict)
{
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		cout << it->first << "\t:\t" << it->second << endl;
	}
}
int main()
{
	map<string, string> dict;
	dict["cat"] = "a small domesticated carnivorous mammal with soft fur";
	dict["tree"] = "a woody perennial plant, typically having a single stem or trunk";
	dict["rainbow"] = "a meteorological phenomenon that is caused by reflection, refraction, and dispersion of light";
	dict["bicycle"] = "a human-powered vehicle with two wheels";
	dict["cloud"] = "a visible mass of water droplets or ice crystals suspended in the atmosphere";
	dict["house"] = "a building for human habitation, especially one that is lived in by a family or small group of people";
	dict["river"] = "a natural flowing watercourse, typically freshwater, flowing towards an ocean, sea, lake, or another river";
	dict["flower"] = "the seed-bearing part of a plant, consisting of reproductive organs";
	dict["book"] = "a set of written or printed pages, usually bound with a protective cover";
	dict["sun"] = "the star around which the Earth orbits, providing light and heat";

	cout << "Content of in the Dictionary: " << endl;
	display(dict);
	search(dict);
	return 0;
}
