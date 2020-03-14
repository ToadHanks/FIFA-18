Author
-------
Mihir Patel   

Description
-------------   
This projet is based on an old FIFA cup stats. There were 32 competing nations in the tournament, divided into 8 groups, A through H, with each group having 4 countries. The stats used in this program contains the group stage games, with each country playing exactly 3 matches. 
   
A CSV file *worldcup.csv*, contains 32 records retrieved from general google search, one for each country. Each record has 4 fields – the name of the country, the group the country belongs to, goals scored, and points earned.
    
The program begins with reading in the CSV file into an array of structure and implementing functions that will search this array based on the country name, group, or points earned (input by user).   
Following are some base files which I have made:

- *country.h*   
   - This file contains definitions and prototypes of functions that are defined in country.c. The structure country is also defined to store information about a country. 

- *country.c*     
   - This file contains the function definitions. There are three functions, search_by_country, search_by_group, and search_by_points. In each of these function, I prompt the user to enter country/group/points and print out the records that match. If there is no match, no print is shown. 

- *worldcup.c*     
   - This file has the main function. You can see an array of structure country here. The main function reads in the records from the CSV file (name is passed from command line by the user) into this array"        

Please use the premade make file to get an executable. Then do gcc -Wall ./worldcup worldcup.csv in a linux or minGW environment. 
    
Status
-------
Completed   
   
Examples   
--------   
Below are some examples of how this code runs. 
````````c
$ make 
$ ./worldcup worldcup.csv  
Country        Group Goals Points
Australia        C     2     1 
Panama           G     2     0 
... 
England          G     8     6 
Belgium          G     9     9 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: c 

Enter country name: Saudi Arabia 
Country        Group Goals Points 
Saudi Arabia     A     2     3 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: g 
Enter group: D 

Country        Group Goals Points 
Argentina        D     3     4 
Croatia          D     7     9 
Iceland          D     2     1 
Nigeria          D     3     3 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: p 
Enter points: 9 

Country        Group Goals Points
Belgium          G     9     9 
Croatia          D     7     9 
Uruguay          A     5     9 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: c 
Enter country name: China 

Country        Group Goals Points 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: g 
Enter group: F 

Country        Group Goals Points 
Germany          F     2     3
Mexico           F     3     6 
South Korea      F     3     3 
Sweden           F     5     6 

Search by country: c 
Search by group:   g 
Search by points:  p 
Quit:              q 
Enter operation code: q
````````
