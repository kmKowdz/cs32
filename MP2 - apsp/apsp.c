/*
Student No.:	2016-90653
Student Name:	KAREN MICHELLE A. ALARCON

REFERENCES:
- Deitel, Paul, and Harvey Deitel. "How To Program C". 7th ed. USA: Pearson Education, 2013. Print.
- "Undefined reference to `pow' and `floor'" C - Undefined reference to `pow' and `floor' - Stack Overflow. N.p., 29 Dec. 2011. Web. 10 Apr. 2017. <http://stackoverflow.com/questions/8671366/undefined-reference-to-pow-and-floor>. Adapted the -lm flag to properly compile the program when using math.h library.
- "Graph and its representations." GeeksforGeeks. N.p., 22 Mar. 2017. Web. 10 Apr. 2017. <http://www.geeksforgeeks.org/graph-and-its-representations/>. 
- "C program to implement Floyd's algorithm which will produce shortest distance between all vertex pairs of a weighted graph." C program to implement Floyd's algorithm which will produce shortest distance between all vertex pairs of a weighted graph. | My Computer Science. N.p., n.d. Web. 25 Mar. 2017. <http://www.mycomputerscience.net/2012/10/c-program-implement-floyd-algorithm.html#>. Adapted the idea on how to represent x as infinite integer.
- "Copy C multi-dimensional array." Stack Overflow. N.p., n.d. Web. 22 Mar. 2017. <http://stackoverflow.com/questions/9096473/copy-c-multi-dimensional-array>. 
- "Initializing a 2D array inside a struct error." C - Initializing a 2D array inside a struct error - Stack Overflow. N.p., n.d. Web. 22 Mar. 2017. <http://stackoverflow.com/questions/10491401/initializing-a-2d-array-inside-a-struct-error>.
- "Initializing entire 2D array with one value." C - Initializing entire 2D array with one value - Stack Overflow. N.p., n.d. Web. 22 Mar. 2017. <http://stackoverflow.com/questions/15520880/initializing-entire-2d-array-with-one-value>.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "floyd.h"
#define MAX_SIZE 100

int main(){
	//declaration and initialization of variables
	char inputfile[20];
	char buf[MAX_SIZE];
	int i = 1;
	Graph G;

	printf("Program Started.\n\n");		//program start prompt
	printf("Enter file name> ");		//ask user to type in the file to read
	scanf("%s", inputfile);			//assign the file name to inputfile variable

	FILE *file = fopen(inputfile,"r");	//call to fopen function to open and read the file

	while(!feof(file)){			//loop until end of file is reached
		fgets(buf, sizeof(buf), file);	//function to get the string from the current line
		G = GET_VALUES(buf, G, i);	//function to get the values from the current line and return a graph
		i++;				//iterate i
	}
	
	
	printf("Floyd:\n");			
	G = FLOYD(G);				//call to Floyd Algorithm to find the shortest path; return the graph
	for(int i = 1; i <= G.n; i++){		//loop until G.n is reached
		for(int j = 1; j <= G.n; j++){	//another loop until G.n is reached
			DISPLAY_PATH(G,i,j);	//call to DISPLAY_PATH
		}				
	}

	printf("\nProgram Terminated.\n");	//program termination prompt

	fclose(file);				//close the file
}


