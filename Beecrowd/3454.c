#include <stdio.h>
#include <string.h>

int main(){
    char str[10];
    
    scanf(" %s",str); 
    
    
  if(!strcmp(str,"OOX") || !strcmp(str,"XOO") || !strcmp(str,"OXO") || 
      !strcmp(str,"OOO") || !strcmp(str,"XXX"))
        printf("?\n");    
    
  else if(!strcmp(str,"XOX"))
        printf("*\n");
    
  else if(!strcmp(str,"XXO") || !strcmp(str,"OXX"))
        printf("Alice\n");
  
  return 0;
}
