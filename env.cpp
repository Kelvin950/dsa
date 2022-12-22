#include <iostream>

int main(int argc, char **argv, char **envp)
{
  for (char **env = envp; *env != 0; env++)
  {
    char *thisEnv = *env;
    std::cout<< thisEnv <<std::endl;    
  }

  int *p  ; int  a =  21  ;

   p= &a ;


    std::cout<<*p<<std::endl; 

  return 0;
}