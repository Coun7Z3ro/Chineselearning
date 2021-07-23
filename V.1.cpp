#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "iostream"
#include "time.h"

int GetLessonRus (int free_place, char (*strR)[100]);
int GetLessonChi (int free_place, char (*strC)[100]);
void NaturalOrder (int lesson_size, int order[]);
void Shuffle (int lesson_size, int order[], int random);
void PrintNumbers (int lesson_size, int order[]);
void PrintLesson (char (*strR)[100], int lesson_size, int order[], int pause);
void sleep (int sec);

void swap (int *a, int *b);

int main()
{
    printf ("Welcome to the Chinese learning application by CountZero \n");

    int pause = 0;
    /*printf ("How much time do u need? Plz enter: ");
    scanf ("%d", &pause);
    printf ("\n"); */

    int random = (clock()/CLOCKS_PER_SEC)%1000;
    /*printf ("Also plz help me out and enter a number: )
    scanf ("%d", &random);*/

    const int free_place = 100;
    char strR[free_place][free_place]= {};
    char strC[free_place][free_place]= {};

    int lesson_size = GetLessonRus (free_place, strR);
    int lesson_size1 = GetLessonChi (free_place, strC);
    printf ("lesson loaded. it's size was %d \n", lesson_size);
    int order[free_place] = {};
    /*NaturalOrder (lesson_size, order);
    Shuffle (lesson_size, order, random);
    PrintNumbers (lesson_size, order);
    PrintLesson (strR, lesson_size, order, pause); */
}

int GetLessonRus (int free_place, char (*strR)[100])
    {
    FILE *lesson = 0;
    int lesson_size = 0;

    setlocale(LC_ALL, "Rus");
    lesson = fopen ("C:\\Users\\CountZero\\Documents\\Chinese\\Lesson1R.txt", "r");

    for (int i = 0; i < free_place; i++)
    {
        fgets (strR[i], free_place, lesson);

        //printf ("readout cycle phase %d \n", i);
        lesson_size++;
        //printf ("%d %s\n", i, strR[i]);
        if (feof(lesson))
        {
            //printf ("lesson is over\n");
            break;
        }
    }

    fclose (lesson);

    return lesson_size;
    }

int GetLessonChi (int free_place, char (*strC)[100])
    {
    FILE *lesson = 0;
    int lesson_size = 0;

    setlocale(LC_ALL, "zh_CN.UTF-8");
    lesson = fopen ("C:\\Users\\CountZero\\Documents\\Chinese\\Lesson1C.txt", "r");

    for (int i = 0; i < free_place; i++)
    {
        fgets (strC[i], free_place, lesson);

        printf ("readout cycle phase %d \n", i);
        lesson_size++;
        printf ("%d %s\n", i, strC[i]);
        if (feof(lesson))
        {
            printf ("lesson is over \n");
            break;
        }
    }

    fclose (lesson);

    return lesson_size;
    }

void PrintLesson (char (*strR)[100], int lesson_size, int order[], int pause)
{
    for (int i = 0; i < lesson_size; i++)
    {
        int place = order[i];
        printf ("%d %s\n", i+1, strR[place]);
        if (order[i] == lesson_size-1)
        {
            printf ("\n");
        }
        sleep (pause);
    }
}

void NaturalOrder (int lesson_size, int order[])
{
    for (int i = 0; i < lesson_size; i++)
    {
    order[i] = i;
    }
}

void Shuffle (int lesson_size, int order[], int random)
{
    int twin = 0;
    int repeat = random;
    //printf ("i'll shuffle it %d times \n", repeat);

    while (repeat > 0)
    {
        for(int i = 0; i < lesson_size; i++)
        {
            twin = rand()%lesson_size;
            swap (&order[i], &order[twin]);
        }
    repeat = repeat - 1;
    }

}

void swap (int *a, int *b)
    {
    int temp = *a;
    *a = *b;
    *b = temp;
    }

void PrintNumbers (int lesson_size, int order[])
{
    printf ("this is the way: ");
    for (int i = 0; i < lesson_size; i++)
    {
        printf ("%d ", order[i]);
    }
    printf ("\n");
}

void sleep (int sec)
    {
    int wake = clock()+sec*1000;
    while (clock() < wake);
    }
