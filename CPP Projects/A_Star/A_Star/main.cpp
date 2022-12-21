#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"

class cNode
{
	public:
		bool bObstacle = false;
		bool bVisited = false;
		bool bIsPath = false;

		float fLocalGoal;
		float fGlobalGoal;

		int ix = -1;
		int iy = -1;
		int iUpperNeighbour = -1;
		int iLowerNeighbour = -1;
		int iLeftNeighbour = -1;
		int iRightNeighbour = -1;
		int iParent = -1;

		sf::RectangleShape Drawable;

		std::vector<int> vNeighbourIndex;
};

std::vector<cNode> vNode;

int iNodeSize = 30;
int iNodeBorderSize = 1;
int iWinWidth = 452, iWinHeight = 452;
int iMapWidth = 15, iMapHeight = 15;
int iStartNode = 1, iEndNode = 213;

void Execute_AStar()
{
	for(int i = 0; i < vNode.size(); i++)
	{
		vNode[i].bVisited = false;
		vNode[i].fGlobalGoal = INFINITY;
		vNode[i].fLocalGoal = INFINITY;
		vNode[i].iParent = -1;
	}

	auto distance = [](int a, int b)
	{
		return sqrtf((vNode[a].ix - vNode[b].iy) * (vNode[a].ix - vNode[b].ix) + (vNode[a].iy - vNode[b].iy) * (vNode[a].iy - vNode[b].iy));
	};

	auto heuristic = [distance](int a, int b) // So we can experiment with heuristic
	{
		return distance(a, b);
	};

	int iCurrentNode = iStartNode;
	vNode[iStartNode].fLocalGoal = 0.0f;
	vNode[iStartNode].fGlobalGoal = heuristic(iStartNode, iEndNode);

	std::list<int> listToTest;
	listToTest.push_back(iStartNode);

	while(!listToTest.empty() && iCurrentNode != iEndNode)
	{
		listToTest.sort([](const int lhs, const int rhs) {return vNode[lhs].fGlobalGoal < vNode[rhs].fGlobalGoal; });

		while(!listToTest.empty() && vNode[listToTest.front()].bVisited)
		{
			listToTest.pop_front();
		}

		if(listToTest.empty())
		{
			break;
		}

		iCurrentNode = listToTest.front();
		vNode[iCurrentNode].bVisited = true;
		//vNode[iCurrentNode].Drawable.setFillColor(sf::Color::Yellow);

		for(auto nodeNeighbour : vNode[iCurrentNode].vNeighbourIndex)
		{
			if(!vNode[nodeNeighbour].bVisited && vNode[nodeNeighbour].bObstacle == 0)
			{
				listToTest.push_back(nodeNeighbour);
			}

			float fPossiblyLowerGoal = vNode[iCurrentNode].fLocalGoal + distance(iCurrentNode, nodeNeighbour);

			if(fPossiblyLowerGoal < vNode[nodeNeighbour].fLocalGoal)
			{
				vNode[nodeNeighbour].iParent = iCurrentNode;
				vNode[nodeNeighbour].fLocalGoal = fPossiblyLowerGoal;

				vNode[nodeNeighbour].fGlobalGoal = vNode[nodeNeighbour].fLocalGoal + heuristic(nodeNeighbour, iEndNode);
			}
		}
	}
}

int main()
{
	std::string Message = std::string("Pathfinding Test - SFML - ") + std::to_string(iMapWidth) + ", " + std::to_string(iMapHeight);
	sf::RenderWindow window(sf::VideoMode(iWinWidth, iWinHeight), Message);

	std::vector<int> Path;

	for(int x = 0; x < iMapWidth; x++)
	{
		for(int y = 0; y < iMapHeight; y++)
		{
			cNode newNode;

			newNode.bObstacle = false;
			newNode.bVisited = false;
			newNode.ix = x;
			newNode.iy = y;
			newNode.iParent = -1;
			newNode.Drawable.setSize(sf::Vector2f(iNodeSize, iNodeSize));
			newNode.Drawable.setOutlineThickness(iNodeBorderSize);
			newNode.Drawable.setOutlineColor(sf::Color::White);
			newNode.Drawable.setFillColor(sf::Color::Blue);
			newNode.Drawable.setPosition(x * iNodeSize + iNodeBorderSize, y * iNodeSize + iNodeBorderSize);

			vNode.push_back(newNode);
		}
	}

	for(int i = 0; i < vNode.size(); i++)
	{
		if(vNode[i].iy > 0)
		{
			vNode[i].vNeighbourIndex.push_back(i - 1);
			vNode[i].iUpperNeighbour = i - 1;
		}

		if(vNode[i].iy < iMapHeight - 1)
		{
			vNode[i].vNeighbourIndex.push_back(i + 1);
			vNode[i].iLowerNeighbour = i + 1;
		}

		if(vNode[i].ix > 0)
		{
			vNode[i].vNeighbourIndex.push_back(i - iMapWidth);
			vNode[i].iLeftNeighbour = i - iMapWidth;
		}

		if(vNode[i].ix < iMapWidth - 1)
		{
			vNode[i].vNeighbourIndex.push_back(i + iMapWidth);
			vNode[i].iRightNeighbour = i + iMapWidth;
		}
	}

	while(window.isOpen())
	{
		sf::Event event;

		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			else if(event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

			else if(event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2f Mouse_Position;
				Mouse_Position.x = (float)sf::Mouse::getPosition(window).x;
				Mouse_Position.y = (float)sf::Mouse::getPosition(window).y;

				for(int i = 0; i < vNode.size(); i++)
				{
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if(vNode[i].Drawable.getGlobalBounds().contains(Mouse_Position.x, Mouse_Position.y))
						{
							vNode[i].bObstacle = !vNode[i].bObstacle;
							vNode[i].Drawable.setFillColor(vNode[i].bObstacle ? sf::Color::Black : sf::Color::Blue);
							break;
						}
					}

					if(sf::Mouse::isButtonPressed(sf::Mouse::Middle))
					{
						if(vNode[i].Drawable.getGlobalBounds().contains(Mouse_Position.x, Mouse_Position.y))
						{
							if(iStartNode != -1) vNode[iStartNode].Drawable.setFillColor(sf::Color::Blue);

							iStartNode = i;
							vNode[iStartNode].Drawable.setFillColor(sf::Color::Green);
							break;
						}
					}

					if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
					{
						if(vNode[i].Drawable.getGlobalBounds().contains(Mouse_Position.x, Mouse_Position.y))
						{
							if(iEndNode != -1) vNode[iEndNode].Drawable.setFillColor(sf::Color::Blue);

							iEndNode = i;
							vNode[iEndNode].Drawable.setFillColor(sf::Color::Red);
							break;
						}
					}
				}
			}

			else if(event.type == sf::Event::KeyPressed)
			{
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					if(iStartNode != -1 && iEndNode != -1) Execute_AStar();
					else std::cout << "\nInvalid start and end nodes.";
				}

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				{
					iStartNode = -1;
					iEndNode = -1;

					for(int i = 0; i < vNode.size(); i++)
					{
						vNode[i].bObstacle = false;
						vNode[i].bVisited = false;
						vNode[i].Drawable.setFillColor(sf::Color::Blue);
					}
				}
			}
		}

		window.clear();

		for(int i = 0; i < vNode.size(); i++)
		{
			if(vNode[i].bVisited) vNode[i].Drawable.setFillColor(sf::Color(255, 255, 0, 25));
			if(vNode[i].bIsPath) vNode[i].Drawable.setFillColor(sf::Color::White);
			if(i == iStartNode) vNode[i].Drawable.setFillColor(sf::Color::Green);
			if(i == iEndNode) vNode[i].Drawable.setFillColor(sf::Color::Red);
		}

		for(int drawOrder = 0; drawOrder < 2; drawOrder++)
		{
			if(drawOrder == 1)
			{
				if(iEndNode != -1)
				{
					std::cout << "1\n";
					int p = iEndNode;
					while(vNode[p].iParent != -1)
					{
						std::cout << "2\n";

						/*sf::Vertex line[] =
						{
							sf::Vertex(sf::Vector2f(0, 0)),
							sf::Vertex(sf::Vector2f(300, 300))
						};

						window.draw(line, 2, sf::Lines);*/

						vNode[p].bIsPath = true;

						//vNode[p].Drawable.setFillColor(sf::Color::Cyan);

						//window.draw(line);
						//DrawLine(p->x * nNodeSize + nNodeSize / 2, p->y * nNodeSize + nNodeSize / 2,
								 //p->parent->x * nNodeSize + nNodeSize / 2, p->parent->y * nNodeSize + nNodeSize / 2, PIXEL_SOLID, FG_YELLOW);

						// Set next node to this node's parent
						p = vNode[p].iParent;
					}
				}
			}

			if(drawOrder == 0)
			{
				for(int i = 0; i < vNode.size(); i++)
				{
					window.draw(vNode[i].Drawable);
				}
			}
		}

		window.display();
	}

	return 0;
}