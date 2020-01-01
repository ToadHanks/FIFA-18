/**********************************************************************************
 * File: country.c                                                                *
 * Name: Mihir Patel                                                              *
 * Following program has function definitions that is used by main function.      * 
 **********************************************************************************/
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "country.h"

/**********************************************************
 * search_by_country: Prompts the user to enter a country *
 *                    name, then prints the record of     *
 *                    that country if it exists.          *
 **********************************************************/
void search_by_country(struct country countries[])
{
	int i, target = -1;
	
	char countryStr[NAME_LEN+1];
		
	printf("Enter Country Name: ");
	
	read_line(countryStr, NAME_LEN);
	
	for (i = 0; i < 32; i++) 
	{
		if (strcmp(countries[i].name, countryStr) == 0){
			target = i;
			break;
		}	
	}
	printf("Country\t\tGroup\tGoals\tPoints\n");

	if(target == -1){
		return;
	}
	if(target < 32){
		
		printf("%-12s%7c%9d%9d\n", countries[target].name, countries[target].group, countries[target].goals, countries[target].points);
	}	
}

/**********************************************************
 * search_by_group: Prompts the user to enter a group,    *
 *                  then prints the records of that group *
 *                  if it exists.                         *
 **********************************************************/
void search_by_group(struct country countries[])
{ 
	int i;
	
	char byGroup;
		
	printf("Enter group: ");
		scanf(" %c", &byGroup);
	
	printf("Country\t\tGroup\tGoals\tPoints\n");
	
	for (i=0; i<NUM_COUNTRIES; i++)
	{
		if (countries[i].group == toupper(byGroup))
		{
			printf("%-12s%7c%9d%9d\n", countries[i].name, countries[i].group, countries[i].goals, countries[i].points);
		}
	}	
}

/**********************************************************
 * search_by_points: Prompts the user to enter a point,   *
 *                   then prints the records having       *
 *                   that many points, if it exists.      *
 **********************************************************/
void search_by_points(struct country countries[])
{
	int i;
	
	int byPoints = 0;
	
	printf("Enter Point/s: ");
		scanf("%d", &byPoints);
  	
	printf("Country\t\tGroup\tGoals\tPoints\n");
	
	for (i=0; i<NUM_COUNTRIES; i++)
	{
		if (countries[i].points ==byPoints)
		{
			printf("%-12s%7c%9d%9d\n", countries[i].name, countries[i].group, countries[i].goals, countries[i].points);
		}
	}
}

/**********************************************************
 * print_sorted_by_goals: Sorts the records in acending   *
 *                        order according to goal scored  *
 *                        and prints them                 *
 **********************************************************/

void print_sorted_by_goals(struct country countries[])
{
	int i;
	
	selection_sort(countries, NUM_COUNTRIES);
	
	printf("Country\t\tGroup\tGoals\tPoints\n");
	printf("**************************************\n");
	
	for (i=0; i<NUM_COUNTRIES; i++)
	{
		printf("%-12s%7c%9d%9d\n", countries[i].name, countries[i].group, countries[i].goals, countries[i].points);
	}
}

void selection_sort(struct country countries[], int n)
{
    int i, max = 0;
	struct country secMax;
	
	if (n == 0) {return;}
 
    for (i = 0; i < n; i++) 
	{
        if (countries[i].goals> countries[max].goals)
            max = i;	
    }

    secMax = countries[max]; 

    countries[max] = countries[n-1];

    countries[n-1] = secMax;

    selection_sort(countries, n-1);
}
/**********************************************************
 * read_line: reads a line and scan input per chracter.   *
 **********************************************************/
int read_line(char *str, int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      *str++ = ch;
    ch = getchar();
  }
  *str = '\0';
  return i;
}