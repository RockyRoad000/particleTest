/*
	Copyright 2021 Andrew Morse
	apache 2.0 license
	
	Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
			http://www.apache.org/licenses/LICENSE-2.0
			
	this is distributed under the License, which is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
	
	this source code for this software is available on github, https://github.com/RockyRoad000/particeTest/
*/

// this software uses SFML for graphics, which is available at https://www.sfml-dev.org/download.php
// I did not write SFML, and I am not tring to take credit for it, a license for SFML is available at https://www.sfml-dev.org/license.php#extlibs, it is distributed under the zlib/png license

#include <iostream>
#include <SFML/Graphics.hpp>

float winWidth = 1280, winHeight = 950;
sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "particle demo", sf::Style::Close);

#include "particles.hpp"

// for sleeping seconds
#include <chrono>
#include<thread>
bool particlesStillDrawing = true;

int main()
{
	std::cout << "this is distributed on an \"AS IS\" BASIS,\nWITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.\nSee the License for the specific language governing permissions and\n" << "limitations under the License.\n";
	
	std::cout << "this is available on github, https://github.com/RockyRoad000/particeTest/ under the Apache License, Version 2.0. you may obtain a copy of the license at http://www.apache.org/licenses/LICENSE-2.0\nCopyright (c) 2021 Andrew Morse\n";
	
	window.clear();



    ParticleSystem particleSystemDemo;

    window.setFramerateLimit(30);

    particleSystemDemo.createParticleSystem(640.0f, 475.0f, 114000, 26.0f, 0.02f, 7.9f);
	
	std::this_thread::sleep_for(std::chrono::seconds(6));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
				window.clear();
                window.close();
			}
        }
		window.clear();
        particleSystemDemo.updateParticleSystem();
        particlesStillDrawing = particleSystemDemo.drawParticleSystem(2, 6, 100, 100, 255, 60, 0.63, 0.84);
		std::cout << particlesStillDrawing << "\n";
		window.display();
    }

    return 0;
}