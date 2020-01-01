/**********************************************************************************
 * File: worldcup.c                                                               *
 * Name: Mihir Patel                                                              *
 * Following program displays the sorted csv files & gives choices for selection. * 
 **********************************************************************************/

#include <stdio.h>
#include <string.h>
#include "country.h"

int main(int argc, char *argv[])
{
  struct country countries[NUM_COUNTRIES];
  char code;
  FILE *f;
  int i=0;
  char buff[27];
  
  if(argc < 2){ 
	printf("Type: ./worldcup filename\n");
	return 1;
  }

  if((f = fopen(argv[1], "r")) == NULL){
	printf("%s can't be opened.\n", argv[1]);
	return 1;
  }
  //Removes the header
  fgets(buff, 27, f);
 
 while(fscanf(f, " %[^,],%c,%d,%d", countries[i].name, &countries[i].group, &countries[i].goals, &countries[i].points))
  {	
	if(i > 31)
	{break;}

	i++;
  }
  
  print_sorted_by_goals(countries); 
  
  for (;;) {
    printf("Search by country: c\n");
    printf("Search by group:   g\n");
    printf("Search by points:  p\n");
    printf("Quit:              q\n");
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'c': search_by_country(countries);
                break;
      case 'g': search_by_group(countries);
                break;
      case 'p': search_by_points(countries);
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }

  fclose(f);
  return 0;
}