#include "menu.h"

int test()
{
	menu m;
	while (m.menu_ativo)
	{
		int menuOP;
		menuOP = m.principal();
		if (menuOP != -1)
		{
			switch (menuOP)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;

			default:
				break;
			}
		}
		else {

		}

	}
	return 0;
}