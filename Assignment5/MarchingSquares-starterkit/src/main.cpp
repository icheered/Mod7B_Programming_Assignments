// Program that draws contour lines of scalar potential field.
// Pressing 'm' or 's' switches between the marching ('m') and scanning ('s') algorithms.
// Pressing 'm' or 's' a second time switches to the multithreaded or improved version of the algorithms.
// Also prints the time needed to draw one frame to stdout.

/*
 *  Created on: May 14, 2018
 *      Author: Johan Engelen
 *  Ported from D source by same author.
 */

#include "UI.h"

#include <SDL2/SDL.h>

#include <chrono>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <thread>

constexpr bool capFramerate = false;
//constexpr float thresholds[] = [0.015];
// constexpr float thresholds[] = {0.015, 0.02, 0.03};
constexpr float thresholds[] = {0.015};



struct Point
{
    float x;
    float y;

    bool operator==(Point a) const{
        if(a.x==x && a.y== y)return true;
        else return false;
    }
};

struct Blob
{
    float wells[2][2] = {{-100, -50}, {100, 50}};

    float potential(Point p)
    {
        return potential(p.x, p.y);
    }

    float potential(float x, float y)
    {
        const float scale = 100;
        float potential = 0.0f;
        for (auto well : wells) {
            potential += scale / (pow(x - well[0], 2) + pow(y - well[1], 2));
        }
        return potential;
    }

    void update(float time)
    {
        // Move the wells a little
        wells[0][0] = -100 + 30 * sinf(time / 7);
        wells[0][1] = -50 * cosf(time / 5);
        wells[1][0] = -wells[0][0];
        wells[1][1] = -wells[0][1];
    }
};

/// Scans full screen area. Complexity?
// Around 258874ms
void drawContourScanning(UI &ui, Blob &blob, float threshold = 0.015)
{
    const int sizeX = ui.sizeX;
    const int sizeY = ui.sizeY;

    //int counter = 0;
    for(int i = -sizeX/2; i < sizeX/2; i++){
        for(int j = -sizeY/2; j < sizeY/2; j++){
            //counter++;
            if(blob.potential(i, j) > threshold){
                ui.drawPixel(i,j);
            }
        }
    }
    //std::cout << "Counter: " << counter << std::endl;
}

/// Scans full screen area multithreaded. Complexity?
void drawContourScanningThreaded(UI &ui, Blob &blob, float threshold = 0.015)
{
    // YOUR CODE HERE
}








/// Improved marching squares algorithm.
/// Should have better complexity than the initial algorithm described in the manual :)
// Between 49ms and 390760ms
void drawContourMarchingBetter(UI &ui, Blob &blob, float threshold = 0.015)
{
    // YOUR CODE HERE

    const int sizeX = ui.sizeX;
    const int sizeY = ui.sizeY;


    bool searching = true;

    int gridX = sizeX;
    int gridY = sizeY;
    std::vector<Point> worklist;
    worklist.reserve(100000);
    
    // Find one pixel on the curve by scanning in a smart way
    int counter = 0;
    while(searching) {
        for(int i = 0; i < sizeX/gridX; i++){
            for(int j = 0; j < sizeY/gridY; j++){
                counter++;
                

                int posX = -(sizeX / 2) + (i + 1) * gridX/2;
                int posY = -(sizeY / 2) + (j + 1) * gridY/2;

                if(blob.potential(posX, posY) > threshold) {
                    bool searchingEdge = true;
                    while(searchingEdge){
                        if(!(blob.potential(posX, posY) > threshold)){
                            posY += 1;
                            searchingEdge = false;
                        }
                        if(searchingEdge){
                            posY -= 1;
                        }
                    }
                    searching = false;
                    Point firstPoint;
                    firstPoint.x = posX;
                    firstPoint.y = posY;
                    worklist.emplace_back(firstPoint);
                    break;
                }
                if(!searching) break;
            }
            if(!searching) break;
        }
        gridX = gridX / 2;
        gridY = gridY / 2;
    }
    

    std::vector<Point> visitedlist;
    visitedlist.reserve(10000);
    int workCounter = 0;
    while(worklist.size() > 0){
        
        // Take a point from the worklist and remove it from the worklist
        Point point = worklist.back();
        worklist.pop_back();

        // Check if the point is already in the visitedlist
        bool wasVisited = false;
        if (std::find(visitedlist.begin(), visitedlist.end(),point)!=visitedlist.end()) {
            wasVisited = true;
        }

        if(wasVisited) continue;
        workCounter++;

        visitedlist.emplace_back(point);

        std::vector<float> corners;
        corners.reserve(4);
        corners.emplace_back(blob.potential(point.x-0.5,point.y-0.5));  // Left top
        corners.emplace_back(blob.potential(point.x+0.5,point.y-0.5));  // Right top
        corners.emplace_back(blob.potential(point.x-0.5,point.y+0.5));  // Left bottom
        corners.emplace_back(blob.potential(point.x+0.5,point.y+0.5));  // Right bottom

        std::vector<bool> cornerBools;
        cornerBools.reserve(4);
        cornerBools.emplace_back((corners.at(0) > threshold));
        cornerBools.emplace_back((corners.at(1) > threshold));
        cornerBools.emplace_back((corners.at(2) > threshold));
        cornerBools.emplace_back((corners.at(3) > threshold));


        // If not all pixel corners are the same color (black/white), it's an edge
        bool crossesBorder = !(
                        (cornerBools.at(0) == cornerBools.at(1)) && 
                        (cornerBools.at(0) == cornerBools.at(2)) &&
                        (cornerBools.at(0) == cornerBools.at(3)));
        
        if(!crossesBorder) continue;



        if(crossesBorder){
            // Line passed through an edge, draw pixel
            ui.drawPixel(point.x,point.y);

            // Add all 8 neightbours of pixel to worklist


            // Edges: 1200-1300, Time: 14k - 16k
            // Edges: 2200-2500, Time: 48k - 60k
            if(cornerBools.at(0) != cornerBools.at(1)) {
                Point newPixel;
                newPixel.x = point.x;
                newPixel.y = point.y - 1;
                worklist.emplace_back(newPixel);
            }
            if(cornerBools.at(1) != cornerBools.at(2)){
                Point newPixel;
                newPixel.x = point.x + 1;
                newPixel.y = point.y;
                worklist.emplace_back(newPixel);
            }
            if(cornerBools.at(2) != cornerBools.at(3)){
                Point newPixel;
                newPixel.x = point.x;
                newPixel.y = point.y + 1;
                worklist.emplace_back(newPixel);
            }
            if(cornerBools.at(3) != cornerBools.at(0)){
                Point newPixel;
                newPixel.x = point.x - 1;
                newPixel.y = point.y;
                worklist.emplace_back(newPixel);
            }
            if( (cornerBools.at(0) == cornerBools.at(2)) &&
                (cornerBools.at(1) != cornerBools.at(3))){
                Point newPixel;
                newPixel.x = point.x - 1;
                newPixel.y = point.y - 1;
                worklist.emplace_back(newPixel);
                newPixel.x = point.x + 1;
                newPixel.y = point.y + 1;
                worklist.emplace_back(newPixel);
            }
            if( (cornerBools.at(1) == cornerBools.at(3)) &&
                (cornerBools.at(0) != cornerBools.at(2))){
                Point newPixel;
                newPixel.x = point.x - 1;
                newPixel.y = point.y + 1;
                worklist.emplace_back(newPixel);
                newPixel.x = point.x + 1;
                newPixel.y = point.y - 1;
                worklist.emplace_back(newPixel);
            }




            // Edges: 1800-1900, Time: 40k - 50k
            // Edges: 3000-3500, Time: 100k - 120k

            // for(int a = -1; a < 2; a++){
            //     for(int b = -1; b < 2; b++){
            //         if(a != b){
            //             Point newPixel;
            //             newPixel.x = point.x + a;
            //             newPixel.y = point.y + b;
            //             worklist.emplace_back(newPixel);
            //         }
            //     }
            // }
        }
    }
    std::cout << "Pixels checked: " << counter <<"\t Edge pixels: " << workCounter << "  \t Time: ";
}


/// Scans screen area until it finds a pixel on the edge.
/// From then on, uses marching squares algorithm to find other pixels on the edge.
/// Caveat: only draws one of the potentially more than one contour losed loops.
/// Complexity?
void drawContourMarching(UI &ui, Blob &blob, float threshold = 0.015)
{
    const int sizeX = ui.sizeX;
    const int sizeY = ui.sizeY;

    bool searching = true;

    int gridX = sizeX;
    int gridY = sizeY;
    std::vector<Point> worklist;
    worklist.reserve(100000);

    // Find one pixel on the curve by scanning
    
    int counter = 0;
    for(int i = -sizeX/2; i < sizeX/2; i++){
        for(int j = -sizeY/2; j < sizeY/2; j++){
            counter++;
            if(blob.potential(i, j) > threshold){
                Point firstPoint;
                firstPoint.x = i;
                firstPoint.y = j;
                worklist.push_back(firstPoint);
                break;
            }
        }
    }

    std::vector<Point> visitedlist;
    visitedlist.reserve(10000);
    int workCounter = 0;
    while(worklist.size() > 0){
        
        // Take a point from the worklist and remove it from the worklist
        Point point = worklist.back();
        worklist.pop_back();

        // Check if the point is already in the visitedlist
        bool wasVisited = false;
        if (std::find(visitedlist.begin(), visitedlist.end(),point)!=visitedlist.end()) {
            wasVisited = true;
        }

        if(wasVisited) continue;
        workCounter++;
        visitedlist.emplace_back(point);

        std::vector<float> corners;
        corners.reserve(4);
        corners.emplace_back(blob.potential(point.x-0.5,point.y-0.5));  // Left top
        corners.emplace_back(blob.potential(point.x+0.5,point.y-0.5));  // Right top
        corners.emplace_back(blob.potential(point.x-0.5,point.y+0.5));  // Left bottom
        corners.emplace_back(blob.potential(point.x+0.5,point.y+0.5));  // Right bottom


        bool crossesBorder = 
            ((corners.at(0) > threshold) && (corners.at(1) < threshold) || // It passes through the top
            (corners.at(0) < threshold) && (corners.at(1) > threshold)) || 
            ((corners.at(1) > threshold) && (corners.at(2) < threshold) || // It passes through the right
            (corners.at(1) < threshold) && (corners.at(2) > threshold)) ||
            ((corners.at(2) > threshold) && (corners.at(3) < threshold) || // It passes through the bottom
            (corners.at(2) < threshold) && (corners.at(3) > threshold)) ||
            ((corners.at(3) > threshold) && (corners.at(0) < threshold) || // It passes through the left
            (corners.at(3) < threshold) && (corners.at(0) > threshold));
            


        if(crossesBorder){
            // Line passed through an edge, draw pixel
            ui.drawPixel(point.x,point.y);

            // Add all 8 neightbours of pixel to worklist
            for(int a = -1; a < 2; a++){
                for(int b = -1; b < 2; b++){
                    if(a != b){
                        Point newPixel;
                        newPixel.x = point.x + a;
                        newPixel.y = point.y + b;
                        worklist.emplace_back(newPixel);
                    }
                }
            }
        }
    }
    std::cout << "Pixels checked: " << counter <<", Workcounter: " << workCounter << std::endl;
}

int main(int /*argc*/, char ** /*argv*/)
{
    using namespace std::chrono;

    UI gui(1000, 600);
    Blob blob;

    unsigned long frameCounter = 0;
    auto drawContour = &drawContourScanning;

    bool pause = false;
    bool quit = false;
    while (!quit)
    {
        // Set timeout to limit frame rate
        auto timeout = SDL_GetTicks() + 20;

        if (!pause)
        {
            blob.update(frameCounter++ / 2.0);
        }

        gui.clear();


        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        for (auto t: thresholds)
        {
            drawContour(gui, blob, t);
        }
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        gui.present();
        auto duration = duration_cast<microseconds>(t2 - t1).count();
        std::cout << duration << " ms" << std::endl;

        // Handle the input.
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Quit button.
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            // All keydown events
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                case SDLK_m:
                    drawContour = &drawContourMarchingBetter;
                    // drawContour = (drawContour == &drawContourMarching) ? &drawContourMarchingBetter
                    //     : &drawContourMarching;
                    break;
                case SDLK_s:
                    drawContour = (drawContour == &drawContourScanning) ? &drawContourScanningThreaded
                        : &drawContourScanning;
                    break;
                case SDLK_SPACE:
                    pause = !pause;
                    break;
                default:
                    break;
                }
            }
        }
        while (capFramerate && !SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
        {
            // do nothing
        }
    }

    return 0;
}
