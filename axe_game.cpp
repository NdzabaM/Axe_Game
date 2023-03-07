#include <cstdio>
#include "raylib.h"
// remember to download raygui.h

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    // circle coordinates
    int circleX{200};
    int circleY{200};
    int circleRadius{25};

    // circle edges
    int circleEdgeL{circleX - circleRadius}; // left edge
    int circleEdgeR{circleX + circleRadius}; // right edge
    int circleEdgeT{circleY - circleRadius}; // top edge
    int circleEdgeB{circleY + circleRadius}; // bottom edge

    // rectangle coordinates
    int rectX{400};
    int rectY{0};
    int rectW{50};
    int rectH{50};

    int rect2X{0};
    int rect2Y{350};
    int rect2W{80};
    int rect2H{80};

    // rectangle edges
    int rectTop{rectY};
    int rectBottom{rectY + rectH};
    int rectLeft{rectX};
    int rectRight{rectX + rectW};

    int rect2Top{rect2Y};
    int rect2Bottom{rect2Y + rect2H};
    int rect2Left{rect2X};
    int rect2Right{rect2X + rect2W};

    int direction{10};
    int direction2{7};

    bool collision_with_axe =
        (rectBottom >= circleEdgeT) &&
        (rectTop <= circleEdgeB) &&
        (rectRight >= circleEdgeL) &&
        (rectLeft <= circleEdgeR);

    bool collision_with_axe2 =
        (rect2Bottom >= circleEdgeT) &&
        (rect2Top <= circleEdgeB) &&
        (rect2Right >= circleEdgeL) &&
        (rect2Left <= circleEdgeR);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 350, 225, 20, RED);
        }
        else if (collision_with_axe2)
        {
            DrawText("Game Over!", 350, 225, 20, RED);
        }
        else
        {
            // Game logic begins
            // update edges
            circleEdgeL = circleX - circleRadius;
            circleEdgeR = circleX + circleRadius;
            circleEdgeT = circleY - circleRadius;
            circleEdgeB = circleY + circleRadius;

            rectTop = rectY;
            rectBottom = rectY + rectH;
            rectLeft = rectX;
            rectRight = rectX + rectW;

            rect2Top = rect2Y;
            rect2Bottom = rect2Y + rect2H;
            rect2Left = rect2X;
            rect2Right = rect2X + rect2W;
            // update collision with rect
            collision_with_axe =
                (rectBottom >= circleEdgeT) &&
                (rectTop <= circleEdgeB) &&
                (rectRight >= circleEdgeL) &&
                (rectLeft <= circleEdgeR);

            collision_with_axe2 =
                (rect2Bottom >= circleEdgeT) &&
                (rect2Top <= circleEdgeB) &&
                (rect2Right >= circleEdgeL) &&
                (rect2Left <= circleEdgeR);

            DrawCircle(circleX, circleY, circleRadius, BLUE);

            DrawRectangle(rectX, rectY, rectW, rectH, RED);
            DrawRectangle(rect2X, rect2Y, rect2W, rect2H, GREEN);

            // move rectangle
            rectY += direction;
            if ((rectY + rectH) > height || rectY < 0)
            {
                direction = -direction;
            }

            rect2X += direction2;
            if ((rect2X + rect2W) > width || rect2X < 0)
            {
                direction2 = -direction2;
            }
            // move circle
            if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && circleEdgeR <= width)
            {
                circleX += 10;
            }
            if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && circleEdgeL >= 0)
            {
                circleX -= 10;
            }
            if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && circleEdgeT >= 0)
            {
                circleY -= 10;
            }
            if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && circleEdgeB <= height)
            {
                circleY += 10;
            }

            // Game logic ends
        }
        EndDrawing();
    }
}