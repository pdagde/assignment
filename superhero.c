#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

struct node{
  int mobileButton;
  char buttoncharacter[4];
  struct node *next;
};


struct node *recursiveReverseLL(struct node *first){
   if(first == NULL) return NULL; 
   if(first->next == NULL) return first; 
   struct node* rest = recursiveReverseLL(first->next); 
   first->next->next = first; 
   first->next = NULL; 
   return rest; 
}


  struct node *createKeyPad(){
    int i=2,j=0,k='A';
    struct node *temp = NULL,*head=NULL,*final=NULL;
    for(i=2;i<=9;i++){ //mobile button should be 2 to 9 having charactor
              temp = (struct node *)malloc(sizeof(struct node));
                            temp->mobileButton = i;
                            temp->next = NULL;
                            int index=0;
  
              if(i!=7 && i!=9){
                    	for(j=i;j<i+3;j++){
                                        temp->buttoncharacter[index]=k;
                              	  k++;
                              	  index++; 
                             }

                            temp->next = head;
                            head = temp;
                            final = temp;
                            
                    	
              }else if(i==7 || i==9){
                      for(j=i;j<i+4;j++){
                                        temp->buttoncharacter[index]=k;
                                  k++;
                                  index++; 
                             }

                            temp->next = head;
                            head = temp;
                            final = temp;
                             
              
              }
     }

    final = recursiveReverseLL(final);
    return final;
}


void findsuperhero(char *secretcode, struct node *head){
  char *superhero[] = {"SUPERMAN","THOR","ROBIN","IRONMAN","GHOSTRIDER","CAPTAINAMERICA","FLASH","WOLVERINE","BATMAN","HULK","BLADE","PHANTOM","SPIDERMAN","BLACKWIDOW","HELLBOY","PUNISHER"};
  
  int i = 0,j=0,k=0;
  struct  node *temp = NULL;
  char bufferarray[100][100];
  int length = sizeof(superhero)/sizeof(superhero[0]);
  char Newfiltersuperhero[100][100];
  for(i=0;i<length;i++){
      strcpy(bufferarray[i],superhero[i]);
  }
    

  for(i=0;i<strlen(secretcode);i++){
        char filtersuperhero[100][100];
        int index = 0;
         while(head->next){
          char button = head->mobileButton +'0';
          if(secretcode[i] == button){

              temp = head;
          }
            head = head->next;
         }

       for(j=0;j<length;j++){
           if(temp->buttoncharacter[0] == bufferarray[j][i] || temp->buttoncharacter[3] == bufferarray[j][i] || temp->buttoncharacter[1] == bufferarray[j][i] || temp->buttoncharacter[2] == bufferarray[j][i] ){
             strcpy(Newfiltersuperhero[index],bufferarray[j]); 
              index++;
           }  
       }
  }  

printf("%s\n",Newfiltersuperhero[0] );
  
}



int main(){
  struct node *head = NULL;
  char secretcode[20] = "228626"; // can put any code like "228626" 
  head = createKeyPad();  
  findsuperhero(secretcode,head); 
}
