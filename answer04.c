#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "pa04.h"

double func1(double x)
{ 
  return x; 
}
double func2(double x)
{
  return x * x;
}
double func3(double x)
{
  return x * x - 3 * x;
}
double func4(double x)
{
  return sin(x);
}
double func5(double x)
{
  return cos(x) + sin(x);
}



// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  
  double lower = (*intrg).lowerlimit;
  double upper = (*intrg).upperlimit;
  int intvl = (*intrg).intervals;
  double intvlwidth = (upper - lower) / intvl;
  double answer = (*intrg).answer;
  double sum = 0;
  int cnt;
  
  for (cnt = 0; cnt < intvl; cnt ++)
    {
      sum += ( (*intrg).func )(lower);
      lower += intvlwidth;
    }
  sum *= intvlwidth;
  
  (*intrg).answer = sum;
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
  FILE * fptr = fopen(infilename, "r");  
  
  // if fopen fails, return false
  if(fptr == NULL)
    {
      return false;
    }

  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration function; 
  
  int check1 = fscanf(fptr, "%lf\n", &function.lowerlimit);
  if (check1 != 1)
   {
    fclose (fptr);
    return false; // should this be EXIT_FAILURE ?
   }

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  
  int check2 = fscanf(fptr, "%lf\n", &function.upperlimit);
  if (check2 != 1)
   {
    fclose (fptr);
    return false; // should this be EXIT_FAILURE ?
   }

  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  
  int check3 = fscanf(fptr, "%lf\n", &function.lowerlimit);
  if (check3 != 1)
   {
    fclose(fptr);
    return false; // should this be EXIT_FAILURE ?
   }

  // close the input file
  fclose (fptr);

  // open the output file for writing
  // if fopen fails, return false
  FILE * out_file = fopen(outfilename, "w");

  if(fptr == NULL)
    {
      return false;
    }

  // create an array of funcptr called funcs with five elements:
  funcptr funcs[] = { func1, func2, func3, func4, func5 };
  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
  int retValue;
  int i; // inedx counter through loop
  int numElements = sizeof(funcs) / sizeof(funcptr);        
  for( i = 0; i < numElements; i++)
   {
    Integration functionA;	
    functionA.func = funcs[i];
    integrate( &functionA ); // do i need the & for individual elements.... yes right 
    retValue = fprintf(out_file, "%lf\n", functionA.answer ); 
    if(retValue < 1) // check the return value of fprintf. 
     {
       fclose(out_file);// If it is less one one, close the output
       return false; // file and return false
     }
   }
  // after going through all functions in funcs
  // close the output file
  fclose(out_file);

  // if the function reaches here, return true
  return true;
}
#endif // RUN_INTEGRATE
