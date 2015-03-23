


class Factory
{
public:
	Factory* MakeFactoryOf(char *factType)
	{
		if (strcmp(factType, "GUI") == 0)
			return new GuiFactory;
		else
			return NULL;
	}

};