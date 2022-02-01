# EasyEffectPrinting
This .hpp file can help you output things by using some functions to make it colorful. 

## Introduction
This .hpp file is used for printing content with some effects.It's based on ANSI code, which can make some great effects. And here are something about how to use this .hpp file.
I'm so sorry because I'm not good at coding, maybe there will be some bugs. Anyway I hope you'll like this.  
And because I'm not from an English-speaking country, my expressions may be wrong, hope you can forgive me. :)

## How to use it
1. Add the file to your folder
2. Include this file by using code 
```C++
#include "Printing.hpp"
```
3. Use namespace Output by using code 
```C++
using namespace Output;
```
4. If you want to add effects, please create an object of Effect.

## Available Functions and Variables
### Constants
As for front colors, here are some constants:
```C++
const int
		F_BLACK = 30,   //black
		F_RED = 31,     //red
		F_GREEN = 32,   //green
		F_YELLOW = 33,  //yellow
		F_BLUE = 34,    //blue
		F_PURPLE = 35,  //purple
		F_AQUA = 36,    //aqua
		F_WHITE = 37;   //white
```

And as for background colors, here are some constants as well:
```C++
const int
		B_BLACK = 40,   //black
		B_RED = 41,     //red
		B_GREEN = 42,   //green
		B_YELLOW = 43,  //yellow
		B_BLUE = 44,    //blue
		B_PURPLE = 45,  //purple
		B_AQUA = 46,    //aqua
		B_WHITE = 47;   //white
```

And Here are some effects:
```C++
const int
		EFF_DEFAULT = 0,    //default
		EFF_HIGHLIGHT = 1,  //highlight
		EFF_UNDERLINE = 4,  //underline
		EFF_REVERSE = 7;    //reverse front color and back color
```

We also set a default Effect object:
```C++
const Effect DEFAULT(37,40,vector<int>(1)); //This is default effect
```

### In class Effect
#### Variables
```C++
public:
		int m_f_color;
		int m_b_color;
		vector<int> m_effect_set;
```
`m_f_color` is used as front color, and `m_b_color` is used as background color.

The vector `m_effect_set` is used to store effects.

#### Effect
This is used to initialize the object
```C++
Effect(int f_color = 37, int b_color = 40, vector<int> effect_set = vector<int>(1,1));
```
`f_color` is front color, `b_color` is background color, `effect_set` is the vector to store effects.

#### AddEffect & RemoveEffect
```C++
void AddEffect(int effect);
void RemoveEffect(int effect);
```
AddEffect can add an effect to the effect set, and RemoveEffect can remove the effect in the effect set.
`effect` is the effect you want to add.
For example:
```C++
Effect e;
e.AddEffect(EFF_UNDERLINE);
e.RemoveEffect(EFF_UNDERLINE);
```

#### SetColor
```C++
void SetColor(int f_color = 37, int b_color = 40);
```
SetColor can set the color of the Effect.
`f_color` is for front color and `b_color` is for background color.
For example:
```C++
Effect e;
e.AddEffect(F_RED,B_WHITE);
```

#### Reset & ResetColor & ResetEffect
```C++
void Reset();
void ResetColor();
void ResetEffect();
```
These functions are used to reset some variables.
Reset is used to reset the whole Effect,
ResetColor is used to reset `m_f_color` and `m_b_color`,
ResetEffect is sued to reset `m_effect_set`.

#### GetANSI
```C++
string GetANSI();
```
This can turn the Effect into ANSI code such as `\033[1;30m`.

#### operator<<
```C++
friend ostream& operator<<(ostream& cout, Effect effect);
```
This function is used to output the effect by using `cout`.
For example:
```C++
cout << e << "Hello World" << DEFAULT << endl;
```

### EffectPrint
```C++
void EffectPrint(string content, Effect effect = DEFAULT);
```
This is a function to output content with an effect.

`content` is the texts you want to output, `effect` is the effect to output it.

For example:
```C++
Effect e(F_AQUA,B_GREEN);
EffectPrint("Hello World\n",e);
```

## Example Program
```C++
#include <iostream>
#include "Printing.hpp"

using namespace std;
using namespace Output;

int main()
{
	Effect e(F_AQUA,B_GREEN);
	e.AddEffect(EFF_UNDERLINE);
	EffectPrint("Output A\n",e);

	e.RemoveEffect(EFF_UNDERLINE);
	EffectPrint("Output B\n", e);

	e.AddEffect(EFF_UNDERLINE);
	EffectPrint("Output C\n", e);

	e.SetColor(F_AQUA, B_YELLOW);
	e.ResetEffect();
	EffectPrint("Output D\n", e);

	e.SetColor(F_AQUA,B_YELLOW);
	e.ResetColor();
	cout << e << "Output E" << DEFAULT << endl;

	e.SetColor(F_AQUA, B_YELLOW);
	e.AddEffect(EFF_UNDERLINE);
	e.Reset();
	cout << e << "Output F" << DEFAULT << endl;
}
```
