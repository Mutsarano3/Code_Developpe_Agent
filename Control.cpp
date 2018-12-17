#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../Shape.h"

using namespace std;

sf::RenderWindow window; //VARIABLE GLOBALE
sf::RectangleShape rectangle;
int speed = 2;
sf::Vector2i positionSouris;// Variable position souris
sf::Texture Mypersonnage; //Pour charger la texture
sf::Sprite sprite_perso;  //Pour faire le sprite
bool UpdateFps= true;

enum Dir{Down,Left,Right,Up};
sf::Vector2i animations(1,Down);
void Gestion_clavier();
int main()
{



   window.create(sf::VideoMode(800,600),"Tuto"); // Creation de fenêtre
   window.setPosition(sf::Vector2i(192,0));             //Modifier la position de la window
   window.setSize(sf::Vector2u(800,600));               //Attribuer taille de fenêtre
   window.setFramerateLimit(60);//Choisir les fps
   cout <<"Lancement du jeu"<<endl;
   //*****************************************//
   sf::Clock time;
   float Fps_Count = 0;
   float switchFps = 100;
   float fps_Speed= 500;

   if(!Mypersonnage.loadFromFile("player1.png"))      //CHAREGEMENT TEXTURE
   {
       cout << "erreur de chargement du png"<<endl;
   }
    Mypersonnage.setSmooth(true);
    sprite_perso.setTexture(Mypersonnage);
    rectangle.setSize(sf::Vector2f(200,100));
    rectangle.setPosition(sf::Vector2f(192,25));
    rectangle.setFillColor(sf::Color(255,0,0));
    while(window.isOpen())
    {
        sf::Event event;  //Creation d'evenement
        while(window.pollEvent(event)) //Deetecter un evenement et remplir dans event
        {
            if(event.type == sf::Event::Closed)    //Si event le type est égale a l'evenement de fermeture alors on retire la window
            {
                window.close();
            }

        }
        //Gestion du clavier
        Gestion_clavier();
        /************************************************************/
        //Gestioo souris

        /***********************************************/
        /*if(sf::Mouse::isButtonPressed(sf::Mouse::Right));
        {
            positionSouris = sf::Mouse::getPosition(window);
           int mousex = positionSouris.x;
           int mousey = positionSouris.y;
           rectangle.setPosition(mousex,mousey);

        }*/
        if(UpdateFps)
        {
            Fps_Count+= fps_Speed*time.restart().asSeconds();
        }
        else
        {
            Fps_Count = 0;
        }
        if(Fps_Count >=switchFps)
        {
            animations.x++;
        if(animations.x*32 >= Mypersonnage.getSize().x)
        {
            animations.x = 0;


        }

        }

        /*sprite_perso.setTextureRect(sf::IntRect(animations.x * 3,animations.y * 32,32,32));*/

       window.draw(rectangle);
       window.draw(sprite_perso);
       window.display();    // activé la fenetre
       window.clear();
    }

	return 0;
}
void Gestion_clavier()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            animations.y = Right ;
            sprite_perso.move(0,-speed);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
             animations.y = Down;
            sprite_perso.move(0,speed);

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
             animations.y = Left;
            sprite_perso.move(-speed,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
             animations.y =Up;
            sprite_perso.move(speed,0);

        }

}


