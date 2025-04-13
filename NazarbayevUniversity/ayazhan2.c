#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    char city[20];
    int points;
    int goalFor;
    int goalAgainst;
} Team;
typedef struct {
    int matchDay;
    Team* *host;
    Team* *guest;
    int hostScore;
    int guestScore;
} Match;


int initTeams(Team teams[32]) {
    FILE * file = fopen("teams.txt" , "r");
    int i = 0;      
    
    do {
        if(fscanf(file,"%s %s", teams[i].name, teams[i].city)<2){
          break;
        }
        //fscanf(file,"%s %s", teams[i].name, teams[i].city);
        //if(strcmp(teams[i].name, "\n")==0){break;}
        teams[i].points = 0;
        teams[i].goalFor=0;
        teams[i].goalAgainst=0;
        //printf("%s %s\n", teams[i].name, teams[i].city);
        i++;
        if(!EOF) {
            break;
        }
    } while(!feof(file));
   return i;
} 

int addResults(int n, Team teams[32]){
      FILE * file = fopen("match-results.txt" , "r");
      int i, j, day, goals1, goals2; 
      char team1name[20], team2name[20], team1city[20], team2city[20];
       do {
        if(fscanf(file,"%d %s %s %d %d %s %s", &day, team1name, team1city, &goals1, &goals2, team2name, team2city)<7){
          break;
        }
        for(i=0; i<n; i++){
          if((strcmp(team1name, teams[i].name)==0)&&(strcmp(team1city, teams[i].city)==0)){
            if(goals1>goals2){
              teams[i].points+=3;
            }
            else if(goals1==goals2){
              teams[i].points+=1;
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
      
        printf("%d %s %s %d %d %s %s \n", day, team1name, team1city, goals1, goals2, team2name, team2city);
        j++;        
    } while(!feof(file));
    return j; 
}

Team* printStandings(int n, Team teams[32], char fileName[20]){
  int j, DF, max, id; 
    FILE * file = fopen(fileName, "w");
     printf("TEAM                 P    GF   GA   GD\n");
     fprintf(file, "TEAM                 P    GF   GA   GD\n");
     for (j =0; j<n; j++){
       DF=teams[j].goalFor-teams[j].goalAgainst;
       if(DF>max){
         max=DF;
         id=j;
       }
      if(DF>0){
      printf("%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);  
      }
       else{
      printf("%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
       }
    }
    printf("Champion team is %s\n", teams[id].name);
}


Match* storeResult(Team *host, Team *guest){
      FILE * file = fopen("match-results.txt" , "r");
      int i, j, day, goals1, goals2; 
      Team** hostp;
      Team** guestp;
      char team1name[20], team2name[20], team1city[20], team2city[20];
       do {
        if(fscanf(file,"%d %s %s %d %d %s %s", &day, team1name, team1city, &goals1, &goals2, team2name, team2city)<7){
          break;        
          }               
          if((strcmp(team1name, host->name)==0)&&(strcmp(team2name, guest->name)==0)){
            Match * Find = (Match *) malloc(sizeof(Match));
            Find->host=hostp;
            Find->guest=guestp;
            Find->matchDay=day;
            Find->hostScore=goals1;
            Find->guestScore=goals2;
            printf("find ");
            printf("day:= %d host_goals: %d guest_score: %d\n", Find->matchDay, Find->hostScore, Find->guestScore);
            
            return Find;
            }           
         
                        
    } while(!feof(file));
    //printf("NO\n");
    //printf("%s %s", host->name, guest->name);
    return NULL; 
}

Team* printOrderedStandings(int n, Team teams[32], char fileName[20]) {
  int i, j;   
  FILE * file = fopen(fileName, "w");
  printf("TEAM                 P    GF   GA   GD\n");
  fprintf(file,"TEAM                 P    GF   GA   GD\n");
  for(i = 0 ; i < n - 1; i++) {        
       for(j = 0 ; j < n - i - 1 ; j++) { 
          Team Temp_Team;             
           if(teams[j].points < teams[j+1].points) {             
              Temp_Team=teams[j];
              teams[j]=teams[j+1];
              teams[j+1]=Temp_Team;
           }
           else if(((teams[j].goalFor-teams[j].goalAgainst)<(teams[j+1].goalFor-teams[j+1].goalAgainst))&&teams[j].points==teams[j+1].points){  
             //printf("sdds2");          
            Temp_Team=teams[j];
            teams[j]=teams[j+1];
            teams[j+1]=Temp_Team;
           }
           else if((teams[j].goalFor<teams[j+1].goalFor)&&((teams[j].goalFor-teams[j].goalAgainst)==(teams[j+1].goalFor-teams[j+1].goalAgainst))&&teams[j].points==teams[j+1].points) {
            //printf("sdds3");
            Temp_Team=teams[j];
            teams[j]=teams[j+1];
            teams[j+1]=Temp_Team;
           }
           else if((int)teams[j].name[0]>(int)teams[j+1].name[0]&&teams[j].goalFor==teams[j+1].goalFor&&(teams[j].goalFor-teams[j].goalAgainst==teams[j+1].goalFor-teams[j+1].goalAgainst)&&teams[j].points==teams[j+1].points){
           Temp_Team=teams[j];
           teams[j]=teams[j+1];
           teams[j+1]=Temp_Team;
           
           /*{
            int s1, s2, k;
            s1 = strlen(teams[j].name);
            s2 = strlen(teams[j+1].name);
            //printf("sdds4");
            if(s1>s2){
              for(k=0; k<s2; k++){
                if((int)teams[j].name[k]<(int)teams[j+1].name[k]){
                  printf("%s %s\n", teams[j].name,  teams[j+1].name);
                  //printf("%c", teams[j+1].name[k]);
                  Temp_Team=teams[j];
                  teams[j]=teams[j+1];
                  teams[j+1]=Temp_Team;
                  break;
                }
                else if((int)teams[j].name[k]==(int)teams[j+1].name[k]){
                  continue;
                }              
              }              
            }
            else if(s1==s2){
              for(k=0; k<s2; k++){
                if((int)teams[j].name[k]<(int)teams[j+1].name[k]){
                  printf("%s %s\n", teams[j].name,  teams[j+1].name);
                  //printf("%c", teams[j+1].name[k]);
                  Temp_Team=teams[j];
                  teams[j]=teams[j+1];
                  teams[j+1]=Temp_Team;
                  break;
                }
               else if((int)teams[j].name[k]==(int)teams[j+1].name[k]){
                  continue;
                }              
              }              
            }
            else{
              for(k=0; k<s1; k++){
                if((int)teams[j].name[k]>(int)teams[j+1].name[k]){
                  
                  Temp_Team=teams[j];
                  teams[j]=teams[j+1];
                  teams[j+1]=Temp_Team;
                  break;
                }
                else if((int)teams[j].name[k]==(int)teams[j+1].name[k]){
                  continue;
                }               
              }              
            }*/
            }
        }
    
  }
  for (j =0; j<n; j++){
    int DF;
    DF=teams[j].goalFor-teams[j].goalAgainst;
    if(DF>0){
      printf("%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d+%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);  
      }
     else{
      printf("%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
      fprintf(file, "%-20s %-5d%-5d%-5d%-5d\n", teams[j].name, teams[j].points, teams[j].goalFor, teams[j].goalAgainst, DF);
       }
   
    }
    
}

int main() {    
    Team teams[32];
    
    printf("<TESTING OF TASK 1>\n");
    
    int j, number;
    number = initTeams(teams);    

    for (j =0; j<number; j++){
      printf("%s %s\n", teams[j].name, teams[j].city);
    }

    printf("<TESTING OF TASK 2>\n");

    addResults(number, teams);   

    for (j =0; j<number; j++){
      printf("%s %s %d %d %d\n", teams[j].name, teams[j].city, teams[j].points, teams[j].goalFor, teams[j].goalAgainst);
    }
    
    printStandings(number, teams, "newfile.txt");
    if(storeResult(&teams[0], &teams[1])==NULL){
      printf("!!!\n");
    };
    if(storeResult(&teams[9], &teams[3])==NULL){
      printf("!!!\n");
    };
    printOrderedStandings(number, teams, "newfile.txt");
    //printf("%d", New->matchDay);
   
    return 0;
} 

  /*char *a;
    char str[40];
    while(1){
      a = fgets(str, sizeof(str), file);
      
      if(a==NULL){
        if(feof(file) !=0){
          printf("File opened succesfully!");
          break;
        }
        else{
           printf("Problem opening a file!");
          break;
        }
      }
      
      //scanf(str,"%s %s", teams[i].name, teams[i].city);
      teams[i].points = 0;
      teams[i].goalFor=0;
      teams[i].goalAgainst=0;
      printf("%s %s\n", teams[i].name, teams[i].city);
    }*/
     /*int tmp = teams[j].points;
              char tmp_name[21];
              strcpy(teams[j+1].name, tmp_name);
              char tmp_city[20]; 
              strcpy(teams[j+1].city, tmp_city);             
              int tmp_goalFor = teams[j].goalFor;
              int tmp_goalAgainst = teams[j].goalAgainst;
              teams[j].points = teams[j+1].points ;
              teams[j+1].points = tmp; 
              teams[j].points = teams[j+1].points ;
              teams[j+1].points = tmp; 
              teams[j].points = teams[j+1].points ;
              teams[j+1].points = tmp; 
              teams[j].points = teams[j+1].points ;
              teams[j+1].points = tmp; */