#pragma once

/*
	Easy Effect Printing By BWLMemo
	==============================================================

	This .hpp file is used for printing content with some effects.
	It's based on ANSI code, which can make some great effects.
	And here are something about how to use this .hpp file.

	I'm so sorry because I'm not good at coding, maybe there will be
	some bugs. I hope you'll like this.

	==============================================================
	########################## Tutorial ##########################
	==============================================================
	1. Include this file by using code " #include "Printing.hpp" ".
	2. Use namespace Output by using code " using namespace Output; ".
	3. If you want to add effects, please create an object of Effect.
*/

//Codes:

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

namespace Output
{
	const int
		F_BLACK = 30,
		F_RED = 31,
		F_GREEN = 32,
		F_YELLOW = 33,
		F_BLUE = 34,
		F_PURPLE = 35,
		F_AQUA = 36,
		F_WHITE = 37;

	const int
		B_BLACK = 40,
		B_RED = 41,
		B_GREEN = 42,
		B_YELLOW = 43,
		B_BLUE = 44,
		B_PURPLE = 45,
		B_AQUA = 46,
		B_WHITE = 47;

	const int
		EFF_DEFAULT = 0,
		EFF_HIGHLIGHT = 1,
		EFF_UNDERLINE = 4,
		EFF_REVERSE = 7;

	class Effect
	{
	public:
		int m_f_color;
		int m_b_color;
		vector<int> m_effect_set;

		Effect(int f_color = 37, int b_color = 40, vector<int> effect_set = vector<int>(1,1))
		{
			m_f_color = f_color;
			m_b_color = b_color;
			m_effect_set = effect_set;
		} //Initialize

		void AddEffect(int effect)
		{
			m_effect_set.push_back(effect);
		} //Add an effect to the effect set

		void RemoveEffect(int effect)
		{
			vector<int>::iterator it = find(m_effect_set.begin(), m_effect_set.end(), effect);
			if (it != m_effect_set.end()) m_effect_set.erase(it);
		} //Remove an effect of the effect set

		void SetColor(int f_color = 37, int b_color = 40)
		{
			m_f_color = f_color;
			m_b_color = b_color;
		} //Set the color of text

		void Reset()
		{
			m_f_color = 37;
			m_b_color = 40;
			m_effect_set = vector<int>(1,1);
		} //Reset all the options

		void ResetColor()
		{
			m_f_color = 37;
			m_b_color = 40;
		} //Reset the color

		void ResetEffect()
		{
			m_effect_set = vector<int>(1, 1);
		} //Reset the effect set

		string GetANSI()
		{
			string ansi = "\033[";
			ansi = ansi + to_string(m_f_color) + ";" + to_string(m_b_color) + ";";
			for (vector<int>::iterator it = m_effect_set.begin(); it != m_effect_set.end() - 1; it++)
			{
				ansi = ansi + to_string(*it) + ";";
			}
			ansi = ansi + to_string(*(m_effect_set.end() - 1)) + "m";
			return ansi;
		} //Turn to ANSI code

		friend ostream& operator<<(ostream& cout, Effect effect)
		{
			cout << effect.GetANSI();
			return cout;
		} //Use cout to output texts
	};

	const Effect DEFAULT(37,40,vector<int>(1)); //This is default effect

	void EffectPrint(string content, Effect effect = DEFAULT)
	{
		cout << effect.GetANSI() + content + "\033[0m";
	} //You can use this function to output texts as well.
}

