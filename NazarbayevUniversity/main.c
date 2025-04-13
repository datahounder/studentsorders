#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct { //creating a struct called Team
    char name[20];
    char city[20];
    int points;
    int goalFor;
    int goalAgainst;
} Team;

typedef struct { //creating a struct called Match
    int matchDay;
    Team* *host;
    Team* *guest;
    int hostScore;
    int guestScore;
} Match;


int initTeams(Team teams[32]) { //function to read data from a file and to store it in array called teams
    FILE * file = fopen("teams.txt" , "r");
    int i = 0;      
    
    do {   // scanning a file, by intializing initial scores to 0
        if(fscanf(file,"%s %s", teams[i].name, teams[i].city)<2){
           break;
          }
          teams[i].points = 0;
          teams[i].goalFor=0;
          teams[i].goalAgainst=0;
          i++;
          if(!EOF) {
            break;
          }
       } while(!feof(file));

   fclose(file);
   return i;
} 

int addResults(int n, Team teams[32]){

      FILE * file = fopen("match-results.txt" , "r");

      int i, j=0, day, goals1, goals2; 
      char team1name[20], team2name[20], team1city[20], team2city[20]; // declaring a char to store information from a file

       do { // scanning a file
           if(fscanf(file,"%d %s %s %d %d %s %s", &day, team1name, team1city, &goals1, &goals2, team2name, team2city)<7){
              break;
          }
           for(i=0; i<n; i++){
            if((strcmp(team1name, teams[i].name)==0)&&(strcmp(team1city, teams[i].city)==0)) // comparing a team names with given ones using a function strcmp
            {
              if(goals1>goals2){ // comparing a scores of host and guest teams
                teams[i].points+=3; // adding a 3 point to a winner team
              }
              else if(goals1==goals2){
                teams[i].points+=1; // adding a 1 point in case of a draw
              }
                teams[i].goalFor+=goals1;
                teams[i].goalAgainst+=goals2;
            }

            if((strcmp(team2name, teams[i].name)==0)&&(strcmp(team2city, teams[i].city)==0)){
              if(goals1<goals2){
                teams[i].points+=3;
              }
              else if(goals1==goals2){
                teams[i].points+=1;
              }
                teams[i].goalFor+=goals2;
                teams[i].goalAgainst+=goals1;
            }
          }
          j++;        
    } while(!feof(file));
      fclose(file);

   return j; // returns a number of matches processed
}

Team* printStandings(int n, Team teams[32], char fileName[20]){

    Team* x =&teams[0];
    int j=0, DF=0, max=0, id, flag=0; 
    FILE * file = fopen(fileName, "w"); 

    printf("TEAM                 P    GF   GA   GD\n");
    fprintf(file, "TEAM                 P    GF   GA   GD\n"); // writing to a file
    
    for (j=0; j<n; j++){
  
        DF=teams[j].goalFor-teams[j].goalAgainst;
        if(teams[j].points>x->points){
           x = &teams[j];
           flag=0;
        }
        else if(teams[j].points==x->points){              
             if(DF>max){
                x=&teams[j];
                max=DF;
                flag=0;
              }
              else if(DF==max){
                if(teams[j].goalFor>x->goalFor){
                   x=&teams[j];
                   flag=0;
                }
                else{
                  flag=1;
                }
              }
         }
    
      if(DF>0){ // printing an information to both console and file, "+" if goal difference is more than 0
      printf("%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);  
      }
       else{ // printing an information to both console and file, "-" if goal difference is less than 0
      printf("%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      }
    }
    fclose(file);
    
    if(flag==1){
    x = NULL;
    }
     return x; // returning a NULL, if there are more the one champion team
}

Match* storeResult(Team *host, Team *guest){

      FILE * file = fopen("match-results.txt" , "r"); // reading a file
      int i, j, day, goals1, goals2; 
      Team** hostp;
      Team** guestp;
      char team1name[20], team2name[20], team1city[20], team2city[20];
      Match *Find = (Match*) malloc(sizeof(Match)); // memory allocation

       do // scanning a file
          { 
          if(fscanf(file,"%d %s %s %d %d %s %s", &day, team1name, team1city, &goals1, &goals2, team2name, team2city)<7){
          break;        
          }               
          if((strcmp(team1name, host->name)==0)&&(strcmp(team2name, guest->name)==0)) // comparing team names for existence 
          {
            Find->host=hostp;
            Find->guest=guestp;
            Find->matchDay=day;
            Find->hostScore=goals1;
            Find->guestScore=goals2;
           
            printf("Match day was on day %d, between host %s and guest %s\n", Find->matchDay, team1name, team2name);
            printf("Host score is %d guest score is %d\n", Find->hostScore, Find->guestScore);
            return Find;
          }   
              
        } while(!feof(file));
        fclose(file);
        free(Find);
    return NULL; 
}

Team* printOrderedStandings(int n, Team teams[32], char fileName[20]) {
  int i, j;   
 
  FILE * file = fopen(fileName, "w"); // writing to a file
  printf("TEAM                 P    GF   GA   GD\n");
  fprintf(file,"TEAM                 P    GF   GA   GD\n");
  for(i = 0 ; i < n - 1; i++) {   
      int flag = 0;     
      for(j = 0 ; j < n - i - 1 ; j++) { // ordering in decreasing order by a number of points
         Team Temp_Team;             
          if(teams[j].points < teams[j+1].points) {             
            Temp_Team=teams[j];
            teams[j]=teams[j+1];
            teams[j+1]=Temp_Team;
           }
           else if(((teams[j].goalFor-teams[j].goalAgainst)<(teams[j+1].goalFor-teams[j+1].goalAgainst))&&teams[j].points==teams[j+1].points){  // by goal difference
                       
            Temp_Team=teams[j];
            teams[j]=teams[j+1];
            teams[j+1]=Temp_Team;
           }
           else if((teams[j].goalFor<teams[j+1].goalFor)&&((teams[j].goalFor-teams[j].goalAgainst)==(teams[j+1].goalFor-teams[j+1].goalAgainst))&&teams[j].points==teams[j+1].points) { // by scored goals
            
            Temp_Team=teams[j];
            teams[j]=teams[j+1];
            teams[j+1]=Temp_Team;
           } 
            else if((teams[j].goalFor==teams[j+1].goalFor)&&((teams[j].goalFor-teams[j].goalAgainst)==(teams[j+1].goalFor-teams[j+1].goalAgainst))&&(teams[j].points==teams[j+1].points)){ // checking for a whole team name
             int k;
            
              for(k=0; k<strlen(teams[j].name); k++){
                  if((int)teams[j].name[k]>(int)teams[j+1].name[k]){
                                        
                      Temp_Team=teams[j];
                      teams[j]=teams[j+1];
                      teams[j+1]=Temp_Team;
                      break;}
                    else if((int)teams[j].name[k]==(int)teams[j+1].name[k]){
                      continue;
                    }
                    else{
                      break;
                    }
               }
            }  
       }
   }
  for (j =0; j<n; j++){
    int DF;
    DF=teams[j].goalFor-teams[j].goalAgainst;
    if(DF>0){ // printing an information to both console and file, "+" if goal difference is more than 0
      printf("%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);  
      }
     else{ // printing an information to both console and file, "-" if goal difference is less than 0
      printf("%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      }
    } 
   fclose(file);
   return NULL;
}

int main() {   
    
    setvbuf(stdout, NULL, _IONBF, 0);

    char firstName[] = "Ayazhan";
    char lastName[] = "Abdirakhym";
    char studentID[] = "201960514\n";
    printf("Student: %s %s\n\n", firstName, lastName);

    Team teams[32]; //initializing an array of teams
    
    printf("<TESTING OF TASK 1>\n");
    printf("\n");

    int j, number;
    number = initTeams(teams); // calling a function, a number of teams returned by a function is saved in integer called "number"   
  
    printf("Number of teams: %d\n", number);
    for(j =0; j<number; j++){ // printing information stored in array 
        printf("%s %s %d %d %d\n", teams[j].name, teams[j].city, teams[j].points, teams[j].goalFor, teams[j].goalAgainst);
    }

    printf("\n");
    printf("<TESTING OF TASK 2>\n");
    printf("\n");

    int n_match = addResults(number, teams); // calling a function, a number of matches processed returned by a function is saved in integer called "n_match"   
    printf("Number of matches processed: %d\n", n_match);
    for(j =0; j<number; j++){ // printing information after calling a function
        printf("%s %s %d %d %d\n", teams[j].name, teams[j].city, teams[j].points, teams[j].goalFor, teams[j].goalAgainst);
    }

    printf("\n");
    printf("<TESTING OF TASK 3>\n");
    printf("\n");

    Team* x;
    x = printStandings(number, teams, "newfile.txt");
    if(x==NULL){ // calling a function, if function will return NULL then program will print this output
      printf("More than 1 champion\n");
    } else {
      printf("Champion team is %s\n", x->name); // if not it will print the champion team
    }
    
    printf("\n");
    printf("<TESTING OF TASK 4>\n");
    printf("\n");
    /*
    Testing case shows that match between host Astana and guest Ordabasy exists, while there was no match between host Ordabasy and guest Astana.
    */
    if(storeResult(&teams[0], &teams[3])==NULL){ // calling a function and checking whether such match exist or not
      printf("Such match does not exist or no memory can be allocated.\n");
    };
    printf("\n");
    if(storeResult(&teams[3], &teams[0])==NULL) // taking and address of team locations in array as parameters
    { 
      printf("Such match does not exist or no memory can be allocated.\n");
    };
    
    printf("\n");
    printf("<TESTING OF TASK 5>\n");
    printf("\n");
    /*
    Testing case firstly sorts by points, then by goal difference, then by number of goals, at the end by alphabetical order A-Z.
    For example, Ordabasy and Okzhetpes have the same score, so they were sorted by alphabet.
    Irtysh and Astana have the same points, goal difference, so they were sorted by goals earned.
    Zhetysu and Aktobe have the same points and goals earned, so they are sorted by goal difference.
    */
    printOrderedStandings(number, teams, "newfile.txt"); // calling a function
   
    return 0;
} 

  