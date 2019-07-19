

    #include <stdio.h> 

    int my_strcmp(const char *str1, const char *str2) { 

      //간단한 주석 부탁드립니다.
	  for(int i = 1; *str1 || *str2; i++, str1++, str2++) {
		  if(*str1 < *str2) return -i;
		  else if(*str1 > *str2) return i;
	  }
	  return 0;
    } 

    int main() 

    { 

      char str1[100], str2[100]; 

      int  result; 

      while (1) 

      { 

        printf("Enter string 1.\n"); 

        //fgets(str1, 100, stdin); 
		int i, input;
		for(i=0; (input = getchar()) != '\n'; str1[i++] = input);
		str1[i] = 0;
        if (my_strcmp(str1, "quit") == 0) 

        break; 

        printf("Enter string 2.\n"); 

		for(i=0; (input = getchar()) != '\n'; str2[i++] = input);
        //fgets(str2, 100, stdin); 
		str2[i] = 0;
        result = my_strcmp(str1, str2); 

        printf("Result of strcmp(str1, str2) is %d\n", result); 

     } 

     return 0; 

    } 


