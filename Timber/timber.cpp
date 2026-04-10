#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

void updateBranches(int);

const int NUM_BRANCHES = 6;
enum class side
{
    LEFT,
    RIGHT,
    NONE
};
side branchPositions[NUM_BRANCHES];
Sprite Branches[NUM_BRANCHES];

int main()
{
    Vector2f resolution;
    // resolution.x = VideoMode::getDesktopMode().width;
    // resolution.y = VideoMode::getDesktopMode().height;
    resolution.x = 1920;
    resolution.y = 1080;
    float x = VideoMode::getDesktopMode().width;


    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "The Timber Game");
    
    View view(FloatRect(0,0,resolution.x,resolution.y));
    // view.setCenter(Vector2f(1100,600));

    Texture backgroundTexture;
    Texture treeTexture;

    Texture beeTexture;
    Texture cloudsTexture;
    Texture branchTexture;
    Texture playerTexture;
    Texture graveTexture;
    Texture axeTexture;
    Texture logTexture;
    backgroundTexture.loadFromFile("./Sprites/graphics/background.png");
    treeTexture.loadFromFile("./Sprites/graphics/tree.png");
    branchTexture.loadFromFile("./Sprites/graphics/branch.png");
    beeTexture.loadFromFile("./Sprites/graphics/bee.png");
    cloudsTexture.loadFromFile("./Sprites/graphics/cloud.png");
    branchTexture.loadFromFile("./Sprites/graphics/branch.png");
    playerTexture.loadFromFile("./Sprites/graphics/player.png");
    graveTexture.loadFromFile("./Sprites/graphics/rip.png");
    axeTexture.loadFromFile("./Sprites/graphics/axe.png");
    logTexture.loadFromFile("./Sprites/graphics/log.png");

    Sprite backgroundSprite;
    Sprite treeSprite;

    Sprite beeSprite, beeSprite2, beeSprite3, beeSprite4;
    Sprite cloudsSprite, cloudsSprite2, cloudsSprite3;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition((resolution.x / 2) - 150, 0);

    beeSprite.setTexture(beeTexture);
    beeSprite.setPosition((resolution.x) + 300, (resolution.y / 2) - 65);

    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition((resolution.x) + 250, (resolution.y / 2) - 105);

    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition((resolution.x) + 200, (resolution.y / 2) + 45);

    cloudsSprite.setTexture(cloudsTexture);
    cloudsSprite.setPosition(0, 150);

    cloudsSprite2.setTexture(cloudsTexture);
    cloudsSprite2.setPosition(0, 300);

    cloudsSprite3.setTexture(cloudsTexture);
    cloudsSprite3.setPosition(0, 450);

    for (int i = 0; i < NUM_BRANCHES; i++)
    {
        Branches[i].setTexture(branchTexture);
        Branches[i].setOrigin(220, 20); // According to book
        Branches[i].setPosition(-2000, -2000);
    }
    updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5);

    float bspeed = 0.0f;
    // float bspeed2 = 0.0f;
    // float bspeed3 = 0.0f;

    float bheight = 0.0f;
    // float bheight2 = 0.0f;
    // float bheight3 = 0.0f;

    bool beeActive = false;
    // bool beeActive2 = false;
    // bool beeActive3 = false;

    bool cloudActive = false;
    bool cloudActive2 = false;
    bool cloudActive3 = false;

    float cloudSpeed = 0.0;
    float cloudSpeed2 = 0.0;
    float cloudSpeed3 = 0.0;

    float cloudHeight = 0.0f;
    float cloudHeight2 = 0.0f;
    float cloudHeight3 = 0.0f;

    RectangleShape timeBar;
    float timeBarWidth = 400.0f;
    float timeBarHeight = 80.0f;

    timeBar.setSize(Vector2f(timeBarWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((resolution.x / 2.0 - timeBarWidth / 2.0f), resolution.y - 100);

    Clock clock;
    float timeRemaining = 10.0f;
    float timeBarWidthPerSecond = timeBarWidth / timeRemaining;

    bool pause = true;

    // message Text

    Font font;
    font.loadFromFile("./Sprites/fonts/KOMIKAP_.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setFillColor(Color::Yellow);
    messageText.setCharacterSize(100);
    messageText.setString("Press Enter To Start");
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin((textRect.left + textRect.width) / 2, (textRect.top + textRect.height) / 2);
    messageText.setPosition(resolution.x / 2, resolution.y / 2);

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition((resolution.x / 2 - 400), resolution.y/2 );
    
    side sidePlayer = side ::LEFT;

    // Score
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(80);
    scoreText.setFillColor(Color::Red);
    scoreText.setPosition(20, 20); // top-left corner
    scoreText.setString("Score = 0");

    Sprite graveSprite;
    graveSprite.setTexture(graveTexture);
    graveSprite.setPosition(600, 860);

    Sprite axeSprite;
    axeSprite.setTexture(axeTexture);
    axeSprite.setPosition(700, 830);

    const int AXE_POSITION_LEFT = 700;
    const int AXE_POSITION_RIGHT = 1075;

    Sprite logSprite;
    logSprite.setTexture(logTexture);
    logSprite.setPosition(810, 720);

    bool logActive = false;
    float logspeedX = 1000;
    float logspeedY = -1500;
    bool acceptInput = false;

    // Chop sound out of time death

    int score = 0;

    // Vector2f position = beeSprite3.getPosition();
    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("./sound/death.wav");
    Sound deathSound;
    deathSound.setBuffer(deathBuffer);

    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            pause = false;
            timeRemaining = 9.0f;
            score = 0;
            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                branchPositions[i] = side::NONE;
            }
            

            graveSprite.setPosition(2000, 2000);
            playerSprite.setPosition((resolution.x/2)-400,(resolution.y/2)+150);
            acceptInput = true;
        }
        Event event; // {Discreet Event Handing--------

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            // if(event.type==Event::KeyReleased && !pause){
            //     acceptInput=true;
            //     axeSprite.setPosition(2000,axeSprite.getPosition().y);
            // }
            // if(event.type==Event::KeyPressed && !pause){
            //     acceptInput=true;
            //     axeSprite.setPosition
            // }
            // if(event.type==Event::KeyPressed && event.key.code==Keyboard::Enter){
            //     pause = false;
            //    timeRemaining = 9.0f;

            // }
        }
        //---------}
        Time dt = clock.restart();
        if (acceptInput)
        {
            // handle right cursor key
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                score++;
                //Added score
                scoreText.setString("Score = " + to_string(score));
                // Remoed time remaining  
                // timeRemaining -= dt.asSeconds();
                sidePlayer = side::RIGHT;
                playerSprite.setPosition((resolution.x/2)+200,(resolution.y/2)-100);
                axeSprite.setPosition(playerSprite.getPosition().x-140, playerSprite.getPosition().y+150);
                // logSprite.setPosition(810,720);
                logSprite.setPosition(treeSprite.getPosition().x, treeSprite.getPosition().y + 600);
                logspeedX = 5000;
                //
                logActive = true;
                updateBranches(score);
                // acceptInput=false;
                // chopping sound played
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                score++;
                //Added score
                scoreText.setString("Score = " + to_string(score));
                //
                // timeRemaining -= dt.asSeconds();
                sidePlayer = side::LEFT;
                playerSprite.setPosition((resolution.x/2)-400,(resolution.y/2)-150);
                axeSprite.setPosition(playerSprite.getPosition().x+140, playerSprite.getPosition().y+150);
                // logSprite.setPosition(810,720);
                logSprite.setPosition(treeSprite.getPosition().x, treeSprite.getPosition().y + 600);
                logspeedX = -5000;
                logActive = true;
                //
                updateBranches(score);
                // acceptInput=false;
                // chopping sound played
            }
        }

        if (!pause)
        {

            timeRemaining -= dt.asSeconds();
            if (timeRemaining <= 0.0)
            {
                pause = true;
            }
            timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

            if (!beeActive)
            {
                srand(time(0) * 10);
                bspeed = rand() % 200 + 200;
                srand(time(0) * 20);
                bheight = rand() % 500 + 500;
                beeSprite.setPosition(2000, bheight);
                beeActive = true;
            }
            else
            {
                beeSprite.setPosition(beeSprite.getPosition().x - (bspeed * dt.asSeconds()), beeSprite.getPosition().y);
                if (beeSprite.getPosition().x < (-100))
                {
                    beeActive = false;
                }
            }

            // if (!beeActive2)
            // {
            //     srand(time(0) * 20);
            //     bspeed2 = rand() % 200 + 200;
            //     srand(time(0) * 30);
            //     bheight2 = rand() % 500 + 500;
            //     beeSprite2.setPosition(2000, bheight2);
            //     beeActive2 = true;
            // }
            // else
            // {
            //     beeSprite2.setPosition(beeSprite2.getPosition().x - (bspeed2 * dt.asSeconds()), beeSprite2.getPosition().y);
            //     if (beeSprite2.getPosition().x < (-100))
            //     {
            //         beeActive2 = false;
            //     }
            // }

            // if (!beeActive3)
            // {
            //     srand(time(0) * 20);
            //     bspeed3 = rand() % 200 + 200;
            //     srand(time(0) * 30);
            //     bheight3 = rand() % 500 + 500;
            //     beeSprite3.setPosition(2000, bheight3);
            //     beeActive3 = true;
            // }
            // else
            // {
            //     beeSprite3.setPosition(beeSprite3.getPosition().x - (bspeed3 * dt.asSeconds()), beeSprite3.getPosition().y);
            //     if (beeSprite3.getPosition().x < (-100))
            //     {
            //         beeActive3 = false;
            //     }
            // }
            if (!cloudActive)
            {
                srand(time(0) * 10);
                cloudSpeed = rand() % 200 + 10;
                srand(time(0) * 20);
                cloudHeight = rand() % 150;
                cloudsSprite.setPosition(-200, cloudHeight);
                cloudActive = true;
            }
            else
            {
                cloudsSprite.setPosition(cloudsSprite.getPosition().x + (cloudSpeed * dt.asSeconds()), cloudsSprite.getPosition().y);
                if (cloudsSprite.getPosition().x > resolution.x + 100)
                {
                    cloudActive = false;
                }
            }
            if (!cloudActive2)
            {
                srand(time(0) * 10);
                cloudSpeed2 = rand() % 200 + 10;
                srand(time(0) * 20);
                cloudHeight2 = rand() % 300 + 150;
                cloudsSprite2.setPosition(-200, cloudHeight2);
                cloudActive2 = true;
            }
            else
            {
                cloudsSprite2.setPosition(cloudsSprite2.getPosition().x + (cloudSpeed2 * dt.asSeconds()), cloudsSprite2.getPosition().y);
                if (cloudsSprite2.getPosition().x > resolution.x + 100)
                {
                    cloudActive2 = false;
                }
            }

            if (!cloudActive3)
            {
                srand(time(0) * 10);
                cloudSpeed3 = rand() % 200 + 20;
                srand(time(0) * 20);
                cloudHeight3 = rand() % 300 + 150;
                cloudsSprite3.setPosition(-200, cloudHeight3);
                cloudActive3 = true;
            }
            else
            {
                cloudsSprite3.setPosition(cloudsSprite3.getPosition().x + (cloudSpeed3 * dt.asSeconds()), cloudsSprite3.getPosition().y);
                if (cloudsSprite3.getPosition().x > resolution.x + 100)
                {
                    cloudActive3 = false;
                }
            }

            for (int i = 0; i < NUM_BRANCHES; i++)
            {

                float branchHeight = i * 150;
                if (branchPositions[i] == side::LEFT)
                {

                    Branches[i].setPosition(resolution.x / 2 - 220, branchHeight); // 810(tree size)-220
                    Branches[i].setRotation(180);
                }
                else if (branchPositions[i] == side::RIGHT)
                {

                    Branches[i].setPosition(resolution.x / 2 + 220, branchHeight); // 1110(tree size)+220
                    Branches[i].setRotation(0);
                }
                else
                {
                    Branches[i].setPosition(3000, branchHeight);
                }
            }
            // updateBranches(1);
            // updateBranches(2);
            // updateBranches(3);
            // updateBranches(4);
            // updateBranches(5);
            // We have already used it in left right

            if (logActive)
            {
                logSprite.setPosition(logSprite.getPosition().x + (dt.asSeconds() * logspeedX), logSprite.getPosition().y + (dt.asSeconds() * logspeedY));
                if (logSprite.getPosition().x < -100 || logSprite.getPosition().x > resolution.x + 90)
                {
                    logSprite.setPosition(810, 720);
                    logActive = false;
                }
            }

            if (branchPositions[5] == sidePlayer)
            {
                // pause the game
                pause = true;

                // Accetiong no input
                acceptInput = false;

                // hide the player
                playerSprite.setPosition(2000, 2000);

                // show grave stone
                graveSprite.setPosition(600, 860);

                // show game over message
                messageText.setString("Game Over");
                textRect = messageText.getLocalBounds();
                messageText.setOrigin((textRect.left + textRect.width) / 2.0, ((textRect.top + textRect.height) / 2.0));
                messageText.setPosition(resolution.x / 2, resolution.y / 2);

                // play sound of death
                deathSound.play();
            }
        }
        window.setView(view);
        window.clear();

        window.draw(backgroundSprite);
        
        window.draw(cloudsSprite);
        window.draw(cloudsSprite2);
        window.draw(cloudsSprite3);
        for (int i = 0; i < NUM_BRANCHES; i++)
        {
            window.draw(Branches[i]);
        }
        window.draw(treeSprite);

        window.draw(playerSprite);

        window.draw(axeSprite);

        window.draw(logSprite);

        window.draw(graveSprite);

        window.draw(beeSprite);
        // window.draw(beeSprite2);

        // window.draw(beeSprite3);
        window.draw(timeBar);
        window.draw(messageText);
        window.draw(scoreText);
        window.display();
    }
    return 0;
}

void updateBranches(int seed)
{
    // SHIFT Positions to the right

    for (int i = NUM_BRANCHES - 1; i > 0; i--)
    {
        branchPositions[i] = branchPositions[i - 1];
    }

    srand(time(0) + seed);
    int r = rand() % 3;
    switch (r)
    {
    case 0:
        branchPositions[0] = side::LEFT;
        break;

    case 1:
        branchPositions[0] = side::RIGHT;
        break;

    default:
        branchPositions[0] = side::NONE;
        break;
    }
}
