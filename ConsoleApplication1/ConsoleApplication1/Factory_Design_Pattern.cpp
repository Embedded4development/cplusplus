#include<iostream>
using namespace std;

//Factory Design Pattern

// *** Button *** //
class Button
{
public:
	virtual void paint() = 0;
};

class OSXButton:public Button
{
	public:
	void paint()
	{
		cout << "OSXButton Paint Called" << endl;
	}
};

class WinButton :public Button
{
public:
	void paint()
	{
		cout << "Windows Paint Called" << endl;
	}
};


// *** Gui Factory *** //

class GuiFactory
{
public:
	virtual Button* CreateButton(char *) = 0;

};

// *** Button Factory *** //
class ButtonFactory : public GuiFactory
{
public:
	Button *CreateButton(char *type)
	{
		if (strcmp(type, "OSX") == 0)
			return new OSXButton;
		else if (strcmp(type, "WIN") == 0)
			return new WinButton;
		else
			return NULL;
	}

};

int main()
{
	GuiFactory *gui;
	Button *btn;

	gui = new ButtonFactory;
	btn = gui->CreateButton("OSX");
	btn->paint();

	btn = gui->CreateButton("WIN");
	btn->paint();


	return 0;
}



