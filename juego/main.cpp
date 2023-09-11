#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <time.h>

typedef enum Estado
{
    MENU,
    JUGANDO,
    PAUSA, 
    FIN
} Estado;

typedef enum Tipo_objeto
{
    FRUTA,
    OBJETO
} Tipo_objeto;

bool menu(void);
bool game(void);
bool pausa(void); 
bool fin(void);

const int screen_width = 1280;
const int screen_height = 720;
Font font_def;

bool exit_game = false;
bool objeto1_act = false;
bool objeto2_act = false;
bool objeto3_act = false;

int num1, num2, num3;
int puntaje = 0, tiempo = 60;
float objeto1_vel, objeto2_vel, objeto3_vel;
int posi = 0;

Vector2 fondo_pos = (Vector2){0,0};
Vector2 tiempo_pos = (Vector2){1015,5};
Vector2 punto_pos = (Vector2){2,5};

Vector2 option_pos = (Vector2){553,300};
Vector2 player_pos = (Vector2){screen_width/2, 564};
Vector2 objeto1_pos = (Vector2){0, -48};
Vector2 objeto2_pos = (Vector2){0, -48};
Vector2 objeto3_pos = (Vector2){0, -48};

Texture2D monkey;
Texture2D manzana, mango, coco, platano, manzana_verde, kiwi, sandia, picos;
Texture2D objeto1, objeto2, objeto3;
Texture2D fondo;

Tipo_objeto tipo_objeto1, tipo_objeto2, tipo_objeto3;

Music musica, musica_menu;
Sound sonido_inicio;
Image monki = LoadImage("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\Chango.png");

Estado estado = MENU;

int main() 
{
    int i = 0;
    InitWindow(screen_width, screen_height, "Fruit Monkey"); 
    SetWindowIcon(monki);
    InitAudioDevice(); 

    fondo = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\Fondo.png");
    monkey = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\Chango2.png");
    manzana = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\apple.png");
    manzana_verde = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\green_apple.png");
    mango = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\mango.png");
    coco = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\coco.png");
    platano = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\banana.png");
    kiwi = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\kiwi.png");
    sandia = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\sandia.png");
    picos = LoadTexture("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\picos.png");
    font_def = LoadFont("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\Minecraft-Regular.ttf");
    musica_menu = LoadMusicStream("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\menumusic.wav");
    musica = LoadMusicStream("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\monkeymusic.wav");
    sonido_inicio = LoadSound("C:\\Users\\Templo el Calvario\\Documents\\ESTRUCTURADA 2023 1\\juego\\res\\coin_sf.wav");
    
    SetMasterVolume(0.7);
    PlayMusicStream(musica);
    PlayMusicStream(musica_menu);

    SetTargetFPS(60);

    while(!exit_game)
    {
        UpdateMusicStream(musica);
        UpdateMusicStream(musica_menu);

        if(estado == MENU)
        {
            PauseMusicStream(musica);
            ResumeMusicStream(musica_menu);
            exit_game = menu();
        }
        else
        {
            if(estado == JUGANDO)
            {
                StopMusicStream(musica_menu);
                ResumeMusicStream(musica);
                exit_game = game();
                i++;
                if(i == 60)
                {
                    tiempo--;
                    i = 0;
                }
            }
            else
            {
                if(estado == PAUSA)
                {
                    exit_game = pausa();
                }
                else
                {
                    if(estado == FIN)
                    {
                        exit_game = fin();
                    }
                }
            }
        }
    }

    UnloadTexture(monkey);
    UnloadTexture(manzana);
    UnloadTexture(manzana_verde);
    UnloadTexture(mango);
    UnloadTexture(coco);
    UnloadTexture(platano);
    UnloadTexture(sandia);
    UnloadTexture(kiwi);
    UnloadTexture(picos);
    UnloadFont(font_def);
    UnloadSound(sonido_inicio);
    UnloadMusicStream(musica_menu);
    UnloadMusicStream(musica);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

bool menu(void)
{
    int title_size = MeasureTextEx(font_def, "Fruit Monkey", 50, 1).x;
    int play_size = MeasureTextEx(font_def, "Jugar", 50, 1).x;
    int exit_size = MeasureTextEx(font_def, "Salir", 50, 1).x;

    Vector2 title_pos; 
    title_pos.x = (screen_width/2) - (title_size/2);
    title_pos.y = 120;

    Vector2 play_pos; 
    play_pos.x = (screen_width/2) - (play_size/2);
    play_pos.y = 300;

    Vector2 exit_pos;
    exit_pos.x = (screen_width/2) - (exit_size/2);
    exit_pos.y = 530;

    ClearBackground(WHITE);

    if(IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
    {
        option_pos.x = exit_pos.x-20;
        option_pos.y = exit_pos.y;
        posi = 1;
    }

    if(IsKeyDown(KEY_W) || IsKeyPressed(KEY_UP))
    {
        option_pos.x = play_pos.x-20;
        option_pos.y = play_pos.y;
        posi = 0;
    }

    if(WindowShouldClose())
    {
        return true;
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        if(posi == 1)
        {
            return true;
        }
        else
        {
            if(posi == 0)
            {
                PauseMusicStream(musica);
                PlaySound(sonido_inicio);
                estado = JUGANDO;
            }  
        }
    }
    else
    {

        BeginDrawing();
            DrawTextureEx(fondo, fondo_pos, 0, 1, WHITE);
            DrawTextEx(font_def, TextFormat("Fruit Monkey"), title_pos, 50, 1, BLACK);
            DrawTextEx(font_def, "Jugar", play_pos, 50, 1, BLACK);
            DrawTextEx(font_def, "Salir", exit_pos, 50, 1, BLACK);
            DrawText(">     ", option_pos.x, option_pos.y, 50, RED);
        EndDrawing();

    }

    return false;
}

bool game(void)
{
    int selec_objeto1_textu, selec_objeto2_textu, selec_objeto3_textu;

    Rectangle suelo_hitbox{0, 660, 1280, 60};
    Rectangle player_hitbox{player_pos.x, player_pos.y, 96, 96};
    Rectangle objeto1_hitbox{objeto1_pos.x, objeto1_pos.y, 48, 48};
    Rectangle objeto2_hitbox{objeto2_pos.x, objeto2_pos.y, 48, 48};
    Rectangle objeto3_hitbox{objeto3_pos.x, objeto3_pos.y, 48, 48};
    ResumeMusicStream(musica);

    if(WindowShouldClose())
    {
        return true;
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        estado = PAUSA;
    }

    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        if(player_pos.x > 0)
        {
            player_pos.x -= 7.5;
        }
    }

    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        if(player_pos.x < screen_width-96)
        {
            player_pos.x += 7.5;
        }
    }

    if(!objeto1_act)
    {
        objeto1_vel = GetRandomValue(3, 4);
        objeto1_pos.x = GetRandomValue(0, screen_width-48);
        num1 = GetRandomValue(10, 99);

        int tipo_obj = GetRandomValue(1, 100);
        if(tipo_obj <= 75)
        {
            tipo_objeto1 = FRUTA;
            selec_objeto1_textu = GetRandomValue(3, 7);
            switch(selec_objeto1_textu)
            {
            case 3:
                objeto1 = mango;
                break;
            case 4:
                objeto1 = platano;
                break;
            case 5:
                objeto1 = kiwi;
                break;
            case 6:
                objeto1 = sandia;
                break;
            case 7:
                objeto1 = coco;
                break;
            }
        }
        else
        {
            num1 = 0;
            tipo_objeto1 = OBJETO;
            objeto1 = picos;
        }

        objeto1_act = true;
    }

    if(!objeto2_act)
    {
        objeto2_vel = GetRandomValue(3, 4);
        do
        {
            objeto2_pos.x = GetRandomValue(0, screen_width-48);
        }while(objeto1_pos.x == objeto2_pos.x);
        num2 = GetRandomValue(10, 99);

        int tipo_obj = GetRandomValue(1, 100);
        if(tipo_obj <= 75)
        {
            tipo_objeto2 = FRUTA;
            selec_objeto2_textu = GetRandomValue(3, 7);
            switch(selec_objeto2_textu)
            {
            case 3:
                objeto2 = mango;
                break;
            case 4:
                objeto2 = platano;
                break;
            case 5:
                objeto2 = kiwi;
                break;
            case 6:
                objeto2 = sandia;
                break;
            case 7:
                objeto2 = coco;
                break;
            }
        }
        else
        {
            num2 = 0;
            tipo_objeto2 = OBJETO;
            objeto2 = picos;
        }

        objeto2_act = true;
    }

    if(!objeto3_act)
    {
        objeto3_vel = GetRandomValue(3, 4);
        do
        {
            objeto3_pos.x = GetRandomValue(0, screen_width-48);
        }while(objeto1_pos.x == objeto3_pos.x && objeto2_pos.x == objeto3_pos.x);
        num3 = GetRandomValue(10, 99);

        int tipo_obj = GetRandomValue(1, 100);
        if(tipo_obj <= 75)
        {
            tipo_objeto3 = FRUTA;
            selec_objeto3_textu = GetRandomValue(3, 7);
            switch(selec_objeto3_textu)
            {
            case 3:
                objeto3 = mango;
                break;
            case 4:
                objeto3 = platano;
                break;
            case 5:
                objeto3 = kiwi;
                break;
            case 6:
                objeto3 = sandia;
                break;
            case 7:
                objeto3 = coco;
                break;
            }
        }
        else
        {
            num3 = 0;
            tipo_objeto3 = OBJETO;
            objeto3 = picos;
        }

        objeto3_act = true;
    }

    ClearBackground(WHITE);

    BeginDrawing();
        DrawTextureEx(fondo, fondo_pos, 0, 1, WHITE);
        //DrawRectangleRec(suelo_hitbox, ColorAlpha(WHITE, 0.0));
        DrawTextureEx(monkey, player_pos, 0, 1.5, WHITE);
        //DrawRectangleRec(player_hitbox, ColorAlpha(RED, 0.5));
        if(objeto1_act)
        {
            if(tipo_objeto1 == FRUTA)
            {
                if(!CheckCollisionRecs(player_hitbox, objeto1_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto1_hitbox))
                    {
                        DrawTextureEx(objeto1, objeto1_pos, 0, 0.7, WHITE);
                        //DrawRectangleRec(objeto1_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto1_pos.y += objeto1_vel;
                    }
                    else
                    {
                        objeto1_pos.x = GetRandomValue(0, screen_width-64);
                        objeto1_pos.y = -92;
                        objeto1_act = false;
                    }
                    
                }
                else
                {
                    puntaje += num1;
                    objeto1_pos.x = GetRandomValue(0, screen_width-64);
                    objeto1_pos.y = -92;
                    objeto1_act = false;
                }
            }
            else
            {
                if(!CheckCollisionRecs(player_hitbox, objeto1_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto1_hitbox))
                    {
                        DrawTextureEx(objeto1, objeto1_pos, 0, 1, WHITE);
                        //DrawRectangleRec(objeto1_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto1_pos.y += objeto1_vel;
                    }
                    else
                    {
                        objeto1_pos.x = GetRandomValue(0, screen_width-64);
                        objeto1_pos.y = -92;
                        objeto1_act = false;
                    }
                    
                }
                else
                {
                    estado = FIN;
                }
            }        
        }

        if(objeto2_act)
        {
            if(tipo_objeto2 == FRUTA)
            {
                if(!CheckCollisionRecs(player_hitbox, objeto2_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto2_hitbox))
                    {
                        DrawTextureEx(objeto2, objeto2_pos, 0, 0.7, WHITE);
                        //DrawRectangleRec(objeto2_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto2_pos.y += objeto2_vel;
                    }
                    else
                    {
                        objeto2_pos.x = GetRandomValue(0, screen_width-64);
                        objeto2_pos.y = -92;
                        objeto2_act = false;
                    }
                    
                }
                else
                {
                    puntaje += num2;
                    objeto2_pos.x = GetRandomValue(0, screen_width-64);
                    objeto2_pos.y = -92;
                    objeto2_act = false;
                }
            }
            else
            {
                if(!CheckCollisionRecs(player_hitbox, objeto2_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto2_hitbox))
                    {
                        DrawTextureEx(objeto2, objeto2_pos, 0, 1, WHITE);
                        //DrawRectangleRec(objeto2_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto2_pos.y += objeto2_vel;
                    }
                    else
                    {
                        objeto2_pos.x = GetRandomValue(0, screen_width-64);
                        objeto2_pos.y = -92;
                        objeto2_act = false;
                    }
                    
                }
                else
                {
                    estado = FIN;
                }
            }
        }

        if(objeto3_act)
        {
            if(tipo_objeto3 == FRUTA)
            {
                if(!CheckCollisionRecs(player_hitbox, objeto3_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto3_hitbox))
                    {
                        DrawTextureEx(objeto3, objeto3_pos, 0, 0.7, WHITE);
                        //DrawRectangleRec(objeto3_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto3_pos.y += objeto3_vel;
                    }
                    else
                    {
                        objeto3_pos.x = GetRandomValue(0, screen_width-64);
                        objeto3_pos.y = -92;
                        objeto3_act = false;
                    }
                    
                }
                else
                {
                    puntaje += num3;
                    objeto3_pos.x = GetRandomValue(0, screen_width-64);
                    objeto3_pos.y = -92;
                    objeto3_act = false;
                }
            }
            else
            {
                if(!CheckCollisionRecs(player_hitbox, objeto3_hitbox))
                {
                    if(!CheckCollisionRecs(suelo_hitbox, objeto3_hitbox))
                    {
                        DrawTextureEx(objeto3, objeto3_pos, 0, 1, WHITE);
                        //DrawRectangleRec(objeto3_hitbox, ColorAlpha(GREEN, 0.5));
                        objeto3_pos.y += objeto3_vel;
                    }
                    else
                    {
                        objeto3_pos.x = GetRandomValue(0, screen_width-64);
                        objeto3_pos.y = -92;
                        objeto3_act = false;
                    }
                    
                }
                else
                {
                    estado = FIN;
                }
            }   
        }

        DrawTextEx(font_def, TextFormat("Puntaje: %-4d", puntaje), punto_pos, 50, 1, BLACK);
        DrawTextEx(font_def, TextFormat("Tiempo: %-2d", tiempo), tiempo_pos, 50, 1, BLACK);
    EndDrawing();

    if(tiempo == 0)
    {
        estado = FIN;
    }
        
    return false;
}

bool pausa(void)
{
    float text_size = MeasureTextEx(font_def, "Pausa 'Espacio' para reanudar", 50, 1).x;
    Vector2 text_pos = (Vector2){(screen_width/2) - (text_size/2), screen_height/2};

    if(IsKeyPressed(KEY_SPACE))
    {
        estado = JUGANDO;
    }

    if(WindowShouldClose())
    {
        return true;
    }

    ClearBackground(WHITE);

    BeginDrawing();
        DrawTextureEx(fondo, fondo_pos, 0, 1, WHITE);
        DrawTextureEx(monkey, player_pos, 0, 1.5, WHITE);
        if(tipo_objeto1 == FRUTA)
        {
            DrawTextureEx(objeto1, objeto1_pos, 0, 0.7, WHITE);
        }
        else
        {
            DrawTextureEx(objeto1, objeto1_pos, 0, 1, WHITE);
        }

        if(tipo_objeto2 == FRUTA)
        {
            DrawTextureEx(objeto2, objeto2_pos, 0, 0.7, WHITE);
        }
        else
        {
            DrawTextureEx(objeto2, objeto2_pos, 0, 1, WHITE);
        }

        if(tipo_objeto3 == FRUTA)
        {
            DrawTextureEx(objeto3, objeto3_pos, 0, 0.7, WHITE);
        }
        else
        {
            DrawTextureEx(objeto3, objeto3_pos, 0, 1, WHITE);
        }
        DrawTextEx(font_def, TextFormat("Puntaje: %-4d", puntaje), punto_pos, 50, 1, BLACK);
        DrawTextEx(font_def, TextFormat("Tiempo: %-2d", tiempo), tiempo_pos, 50, 1, BLACK);
        DrawTextEx(font_def, "Pausa 'Espacio' para reanudar", text_pos, 50, 1, BLACK);
    EndDrawing();

    return false;
}

bool fin(void)
{
    Vector2 text_size = MeasureTextEx(font_def, "Juego terminado", 50, 1);
    Vector2 text_pos = (Vector2){(screen_width/2) - (text_size.x/2), screen_height/2};

    Vector2 text_size2 = MeasureTextEx(font_def, "Presione 'Enter' para regresar al menu", 50, 1);
    Vector2 text_pos2 = (Vector2){(screen_width/2) - (text_size2.x/2), (screen_height/2) + (text_size.y + 20)};

    Vector2 punt_size = MeasureTextEx(font_def, TextFormat("Puntaje: %4d", puntaje), 50, 1);
    Vector2 punt_pos = (Vector2){(screen_width/2) - (punt_size.x/2), (screen_height/2) - (text_size.y + text_size2.y + 10)};

    objeto1_pos.y = -92;
    objeto1_act = false;
    objeto2_pos.y = -92;
    objeto3_act = false;
    objeto3_pos.y = -92;
    objeto3_act = false;
    player_pos.x = screen_width/2;
    StopMusicStream(musica);
    PlayMusicStream(musica);
    PauseMusicStream(musica);
    PlayMusicStream(musica_menu);

    if(WindowShouldClose())
    {
        return true;
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        estado = MENU;
        tiempo = 60;
        puntaje = 0;
    }

    ClearBackground(WHITE);

    BeginDrawing();
        DrawTextureEx(fondo, fondo_pos, 0, 1, WHITE);
        DrawTextEx(font_def, TextFormat("Puntaje: %-4d", puntaje), punt_pos, 50, 1, BLACK);
        DrawTextEx(font_def, "Juego terminado", text_pos, 50, 1, BLACK);
        DrawTextEx(font_def, "Presione 'Enter' para regresar al menu", text_pos2, 50, 1, BLACK);
    EndDrawing();

    return false;
}